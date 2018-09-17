/****************************************************************************
 * mm/mm_malloc.c
 *
 *   Copyright (C) 2007, 2009, 2013  Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
//#include <nuttx/mm.h>

#define FAR
#define DEBUGASSERT(AA)
#define mm_takesemaphore(X)
#define mm_givesemaphore(X)

#ifdef CONFIG_MM_SMALL
#define MM_MIN_SHIFT    4  /* 16 bytes */
#define MM_MAX_SHIFT   15  /* 32 Kb */
#else
#define MM_MIN_SHIFT    4  /* 16 bytes */
#define MM_MAX_SHIFT   22  /*  4 Mb */
#endif

#ifdef CONFIG_MM_SMALL
#define SIZEOF_MM_ALLOCNODE   4
#else
#define SIZEOF_MM_ALLOCNODE   8
#endif

/* All other definitions derive from these two */
#define MM_MIN_CHUNK     (1 << MM_MIN_SHIFT)
#define MM_MAX_CHUNK     (1 << MM_MAX_SHIFT)
#define MM_NNODES        (MM_MAX_SHIFT - MM_MIN_SHIFT + 1)
#define MM_GRAN_MASK     (MM_MIN_CHUNK-1)
#define MM_ALIGN_UP(a)   (((a) + MM_GRAN_MASK) & ~MM_GRAN_MASK)
#define MM_ALIGN_DOWN(a) ((a) & ~MM_GRAN_MASK)

struct mm_allocnode_s {
    size_t size; /* Size of this chunk */
    size_t preceding; /* Size of the preceding chunk */
};

#ifdef CONFIG_MM_SMALL
#define MM_ALLOC_BIT    0x8000
#else
#define MM_ALLOC_BIT    0x80000000
#endif
#define MM_IS_ALLOCATED(n) \
  ((int)((struct mm_allocnode_s*)(n)->preceding) < 0))

struct mm_freenode_s {
    size_t size; /* Size of this chunk */
    size_t preceding; /* Size of the preceding chunk */
    FAR struct mm_freenode_s *flink; /* Supports a doubly linked list */
    FAR struct mm_freenode_s *blink;
};

#ifdef CONFIG_MM_SMALL
#ifdef CONFIG_SMALL_MEMORY
#define SIZEOF_MM_FREENODE 8
#else
#define SIZEOF_MM_FREENODE 12
#endif
#else
#define SIZEOF_MM_FREENODE     16
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif


#define CONFIG_MM_REGIONS 1

struct mm_heap_s {
    /* Mutually exclusive access to this data set is enforced with
     * the following un-named semaphore.
     */
    //sem_t mm_semaphore;
    //pid_t mm_holder;
    int mm_counts_held;
    /* This is the size of the heap provided to mm */
    size_t mm_heapsize;
    /* This is the first and last nodes of the heap */
    FAR struct mm_allocnode_s *mm_heapstart[CONFIG_MM_REGIONS];
    FAR struct mm_allocnode_s *mm_heapend[CONFIG_MM_REGIONS];
#if CONFIG_MM_REGIONS > 1
    int mm_nregions;
#endif
    /* All free nodes are maintained in a doubly linked list.  This
     * array provides some hooks into the list at various points to
     * speed searches for free nodes.
     */
    struct mm_freenode_s mm_nodelist[MM_NNODES];
};

struct mm_heap_s g_mmheap;

int mm_size2ndx(size_t size) {
    int ndx = 0;
    if (size >= MM_MAX_CHUNK) {
        return MM_NNODES - 1;
    }
    size >>= MM_MIN_SHIFT;
    while (size > 1) {
        ndx++;
        size >>= 1;
    }
    return ndx;
}

void mm_addfreechunk(FAR struct mm_heap_s *heap, FAR struct mm_freenode_s *node) {
    FAR struct mm_freenode_s *next;
    FAR struct mm_freenode_s *prev;
    /* Convert the size to a nodelist index */
    int ndx = mm_size2ndx(node->size);

    /* Now put the new node int the next */
    for (prev = &heap->mm_nodelist[ndx], next = heap->mm_nodelist[ndx].flink;
            next && next->size && next->size < node->size;
            prev = next, next = next->flink);

    /* Does it go in mid next or at the end? */
    prev->flink = node;
    node->blink = prev;
    node->flink = next;
    if (next) {
        /* The new node goes between prev and next */
        next->blink = node;
    }
}

/****************************************************************************
 * Name: mm_malloc
 *
 * Description:
 *  Find the smallest chunk that satisfies the request. Take the memory from
 *  that chunk, save the remaining, smaller chunk (if any).
 *
 *  8-byte alignment of the allocated data is assured.
 *
 ****************************************************************************/

#ifndef CONFIG_MM_MULTIHEAP

static inline
#endif
FAR void *mm_malloc(FAR struct mm_heap_s *heap, size_t size) {
    FAR struct mm_freenode_s *node;
    void *ret = NULL;
    int ndx;

    /* Handle bad sizes */

    if (size <= 0) {
        return NULL;
    }

    /* Adjust the size to account for (1) the size of the allocated node and
     * (2) to make sure that it is an even multiple of our granule size.
     */

    size = MM_ALIGN_UP(size + SIZEOF_MM_ALLOCNODE);

    /* We need to hold the MM semaphore while we muck with the nodelist. */

    mm_takesemaphore(heap);

    /* Get the location in the node list to start the search. Special case
     * really big allocations
     */

    if (size >= MM_MAX_CHUNK) {
        ndx = MM_NNODES - 1;
    } else {
        /* Convert the request size into a nodelist index */

        ndx = mm_size2ndx(size);
    }

    /* Search for a large enough chunk in the list of nodes. This list is
     * ordered by size, but will have occasional zero sized nodes as we visit
     * other mm_nodelist[] entries.
     */

    for (node = heap->mm_nodelist[ndx].flink;
            node && node->size < size;
            node = node->flink);

    /* If we found a node with non-zero size, then this is one to use. Since
     * the list is ordered, we know that is must be best fitting chunk
     * available.
     */

    if (node) {
        FAR struct mm_freenode_s *remainder;
        FAR struct mm_freenode_s *next;
        size_t remaining;

        /* Remove the node.  There must be a predecessor, but there may not be
         * a successor node.
         */

        DEBUGASSERT(node->blink);
        node->blink->flink = node->flink;
        if (node->flink) {
            node->flink->blink = node->blink;
        }

        /* Check if we have to split the free node into one of the allocated
         * size and another smaller freenode.  In some cases, the remaining
         * bytes can be smaller (they may be SIZEOF_MM_ALLOCNODE).  In that
         * case, we will just carry the few wasted bytes at the end of the
         * allocation.
         */

        remaining = node->size - size;
        if (remaining >= SIZEOF_MM_FREENODE) {
            /* Get a pointer to the next node in physical memory */

            next = (FAR struct mm_freenode_s*) (((char*) node) + node->size);

            /* Create the remainder node */

            remainder = (FAR struct mm_freenode_s*) (((char*) node) + size);
            remainder->size = remaining;
            remainder->preceding = size;

            /* Adjust the size of the node under consideration */

            node->size = size;

            /* Adjust the 'preceding' size of the (old) next node, preserving
             * the allocated flag.
             */

            next->preceding = remaining | (next->preceding & MM_ALLOC_BIT);

            /* Add the remainder back into the nodelist */

            mm_addfreechunk(heap, remainder);
        }

        /* Handle the case of an exact size match */

        node->preceding |= MM_ALLOC_BIT;
        ret = (void*) ((char*) node + SIZEOF_MM_ALLOCNODE);
    }

    mm_givesemaphore(heap);

    /* If CONFIG_DEBUG_MM is defined, then output the result of the allocation
     * to the SYSLOG.
     */

#ifdef CONFIG_DEBUG_MM
    if (!ret) {
        mdbg("Allocation failed, size %d\n", size);
    } else {
        mvdbg("Allocated %p, size %d\n", ret, size);
    }
#endif

    return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: malloc
 *
 * Description:
 *  Find the smallest chunk that satisfies the request. Take the memory from
 *  that chunk, save the remaining, smaller chunk (if any).
 *
 *  8-byte alignment of the allocated data is assured.
 *
 ****************************************************************************/

#if !defined(CONFIG_NUTTX_KERNEL) || !defined(__KERNEL__)

FAR void *malloc(size_t size) {
    return mm_malloc(&g_mmheap, size);
}
#endif


#ifndef CONFIG_MM_MULTIHEAP
static inline
#endif
void mm_free(FAR struct mm_heap_s *heap, FAR void *mem) {
    FAR struct mm_freenode_s *node;
    FAR struct mm_freenode_s *prev;
    FAR struct mm_freenode_s *next;
    //LOG("Freeing %p\n", mem);
    /* Protect against attempts to free a NULL reference */
    if (!mem) {
        return;
    }
    /* We need to hold the MM semaphore while we muck with the
     * nodelist.
     */
    mm_takesemaphore(heap);
    /* Map the memory chunk into a free node */
    node = (FAR struct mm_freenode_s *) ((char*) mem - SIZEOF_MM_ALLOCNODE);
    node->preceding &= ~MM_ALLOC_BIT;
    /* Check if the following node is free and, if so, merge it */
    next = (FAR struct mm_freenode_s *) ((char*) node + node->size);
    if ((next->preceding & MM_ALLOC_BIT) == 0) {
        FAR struct mm_allocnode_s *andbeyond;
        /* Get the node following the next node (which will
         * become the new next node). We know that we can never
         * index past the tail chunk because it is always allocated.
         */
        andbeyond = (FAR struct mm_allocnode_s*) ((char*) next + next->size);
        /* Remove the next node.  There must be a predecessor,
         * but there may not be a successor node.
         */
        DEBUGASSERT(next->blink);
        next->blink->flink = next->flink;
        if (next->flink) {
            next->flink->blink = next->blink;
        }
        /* Then merge the two chunks */
        node->size += next->size;
        andbeyond->preceding = node->size | (andbeyond->preceding & MM_ALLOC_BIT);
        next = (FAR struct mm_freenode_s *) andbeyond;
    }
    /* Check if the preceding node is also free and, if so, merge
     * it with this node
     */
    prev = (FAR struct mm_freenode_s *) ((char*) node - node->preceding);
    if ((prev->preceding & MM_ALLOC_BIT) == 0) {
        /* Remove the node.  There must be a predecessor, but there may
         * not be a successor node.
         */
        DEBUGASSERT(prev->blink);
        prev->blink->flink = prev->flink;
        if (prev->flink) {
            prev->flink->blink = prev->blink;
        }
        /* Then merge the two chunks */
        prev->size += node->size;
        next->preceding = prev->size | (next->preceding & MM_ALLOC_BIT);
        node = prev;
    }
    /* Add the merged node to the nodelist */
    mm_addfreechunk(heap, node);
    mm_givesemaphore(heap);
}

void mm_addregion(FAR struct mm_heap_s *heap, FAR void *heapstart,
        size_t heapsize) {
    FAR struct mm_freenode_s *node;
    uintptr_t heapbase;
    uintptr_t heapend;
#if CONFIG_MM_REGIONS > 1
    int IDX = heap->mm_nregions;
#else
#define IDX 0
#endif
    /* If the MCU handles wide addresses but the memory manager is configured
     * for a small heap, then verify that the caller is  not doing something
     * crazy.
     */
#if defined(CONFIG_MM_SMALL) && !defined(CONFIG_SMALL_MEMORY)
    DEBUGASSERT(heapsize <= MMSIZE_MAX + 1);
#endif
    /* Adjust the provide heap start and size so that they are both aligned
     * with the MM_MIN_CHUNK size.
     */
    heapbase = MM_ALIGN_UP((uintptr_t) heapstart);
    heapend = MM_ALIGN_DOWN((uintptr_t) heapstart + (uintptr_t) heapsize);
    heapsize = heapend - heapbase;
    //LOG("Region %d: base=%p size=%u\n", IDX + 1, heapstart, heapsize);
    /* Add the size of this region to the total size of the heap */
    heap->mm_heapsize += heapsize;
    /* Create two "allocated" guard nodes at the beginning and end of
     * the heap.  These only serve to keep us from allocating outside
     * of the heap.
     * 
     * And create one free node between the guard nodes that contains
     * all available memory.
     */
    heap->mm_heapstart[IDX] = (FAR struct mm_allocnode_s *) heapbase;
    heap->mm_heapstart[IDX]->size = SIZEOF_MM_ALLOCNODE;
    heap->mm_heapstart[IDX]->preceding = MM_ALLOC_BIT;
    node = (FAR struct mm_freenode_s *) (heapbase + SIZEOF_MM_ALLOCNODE);
    node->size = heapsize - 2 * SIZEOF_MM_ALLOCNODE;
    node->preceding = SIZEOF_MM_ALLOCNODE;
    heap->mm_heapend[IDX] = (FAR struct mm_allocnode_s *) (heapend - SIZEOF_MM_ALLOCNODE);
    heap->mm_heapend[IDX]->size = SIZEOF_MM_ALLOCNODE;
    heap->mm_heapend[IDX]->preceding = node->size | MM_ALLOC_BIT;
#undef IDX
#if CONFIG_MM_REGIONS > 1
    heap->mm_nregions++;
#endif
    /* Add the single, large free node to the nodelist */
    mm_addfreechunk(heap, node);
}

void mm_seminitialize(FAR struct mm_heap_s *heap) {
    /* Initialize the MM semaphore to one (to support one-at-a-time access to
     * private data sets.
     */
    //(void) sem_init(&heap->mm_semaphore, 0, 1);
    //heap->mm_holder = -1;
    heap->mm_counts_held = 0;
}

void mm_initialize(FAR struct mm_heap_s *heap, FAR void *heapstart, size_t heapsize) {
    int i;
    //LOG("Heap: start=%p size=%u\n", heapstart, heapsize);
    /* The following two lines have cause problems for some older ZiLog
     * compilers in the past (but not the more recent).  Life is easier if we
     * just the suppress them altogther for those tools.
     */

#ifndef __ZILOG__
    //CHECK_ALLOCNODE_SIZE;
    //CHECK_FREENODE_SIZE;
#endif
    /* Set up global variables */
    heap->mm_heapsize = 0;
#if CONFIG_MM_REGIONS > 1
    heap->mm_nregions = 0;
#endif
    /* Initialize the node array */
    memset(heap->mm_nodelist, 0, sizeof (struct mm_freenode_s) * MM_NNODES);
    for (i = 1; i < MM_NNODES; i++) {
        heap->mm_nodelist[i - 1].flink = &heap->mm_nodelist[i];
        heap->mm_nodelist[i].blink = &heap->mm_nodelist[i - 1];
    }
    /* Initialize the malloc semaphore to one (to support one-at-
     * a-time access to private data sets).
     */
    mm_seminitialize(heap);
    /* Add the initial region of memory to the heap */
    mm_addregion(heap, heapstart, heapsize);
}

void umm_initialize(FAR void *heap_start, size_t heap_size) {
    mm_initialize(&g_mmheap, heap_start, heap_size);
}