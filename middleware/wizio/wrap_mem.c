/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include <stddef.h>
#include <string.h>

//#define UMM_MALLOC

#ifdef UMM_MALLOC
#include "umm_malloc.h"

void* pvPortMalloc(size_t size) {
    return (void*) umm_malloc(size);
}

void vPortFree(void * ptr) {
    umm_free(ptr);
}

void * pvPortRealloc(void * ptr, size_t size) {
    return (void*) umm_realloc(ptr, size);
}

size_t xPortWantedSizeAlign(size_t size) {
    return (size + 3) & ~((size_t) 3);
}

#else

void * pvPortRealloc(void *mem, size_t newsize) {
    if (newsize == 0) {
        vPortFree(mem);
        return NULL;
    }
    void * p;
    p = (void *) pvPortMalloc(newsize);
    if (p) {
        if (mem != NULL) {
            memcpy(p, mem, newsize);
            vPortFree(mem);
        }
    }
    return p;
}

#endif

void * pvPortCalloc(size_t nelem, size_t elsize) {
    void * pvReturn = NULL;
    size_t len = nelem * elsize;
    pvReturn = (void*) pvPortMalloc(len);
    if (pvReturn != NULL)
        memset(pvReturn, 0, len);
    return (void*) pvReturn;
}

void *pvPortZalloc(size_t size) {
    return pvPortCalloc(1, size);
}

void * __wrap_malloc(size_t s) {
    return (void*) pvPortMalloc(s);
}

void __wrap_free(void * ptr) {
    vPortFree(ptr);
}


//void * malloc(size_t s)__attribute__((alias("pvPortMalloc")));
//void free(void * ptr)__attribute__((alias("vPortFree")));

void *realloc(void *ptr, size_t nbytes) __attribute__((alias("pvPortRealloc")));
void *calloc(size_t count, size_t nbytes) __attribute__((alias("pvPortCalloc")));
void *zalloc(size_t nbytes) __attribute__((alias("pvPortZalloc")));

