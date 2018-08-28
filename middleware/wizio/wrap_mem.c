#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "umm_malloc.h"

void *umm_last_fail_alloc_addr = NULL;
int umm_last_fail_alloc_size = 0;

void * _malloc_r(void* unused, size_t size) {
    (void) unused;
    void *ret = malloc(size);
    if (0 != size && 0 == ret) {
        umm_last_fail_alloc_addr = __builtin_return_address(0);
        umm_last_fail_alloc_size = size;
    }
    return ret;
}

void _free_r(void* unused, void* ptr) {
    (void) unused;
    return free(ptr);
}

void * _realloc_r(void* unused, void* ptr, size_t size) {
    (void) unused;
    void *ret = realloc(ptr, size);
    if (0 != size && 0 == ret) {
        umm_last_fail_alloc_addr = __builtin_return_address(0);
        umm_last_fail_alloc_size = size;
    }
    return ret;
}

void * _calloc_r(void* unused, size_t count, size_t size) {
    (void) unused;
    void *ret = calloc(count, size);
    if (0 != (count * size) && 0 == ret) {
        umm_last_fail_alloc_addr = __builtin_return_address(0);
        umm_last_fail_alloc_size = count * size;
    }
    return ret;
}

void vPortFree(void *ptr) {
    free(ptr);
}

void* pvPortMalloc(size_t size) {
    return malloc(size);
}

void* pvPortCalloc(size_t count, size_t size) {
    return calloc(count, size);
}

void* pvPortRealloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}

size_t xPortGetFreeHeapSize(void) {
    return umm_free_heap_size();
}

size_t xPortWantedSizeAlign(size_t size) {
    return (size + 3) & ~((size_t) 3);
}

void * __wrap_malloc(size_t s) {
    return umm_malloc(s);
}

void __wrap_free(void * ptr) {
    umm_free(ptr);
}

#if 0
void * __wrap_calloc(size_t a, size_t b) {
    size_t s = a * b;
    void * p = umm_malloc(s);
    if (p)
        memset(p, 0, s);
    return p;
}

void * __wrap_realloc(void *ptr, size_t size) {
    return umm_realloc(ptr, size);
}
#endif
