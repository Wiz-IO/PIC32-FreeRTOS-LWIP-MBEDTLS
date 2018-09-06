/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include <stddef.h>
#include <string.h>
#include "umm_malloc.h"

void* pvPortMalloc(size_t size) {
    return (void*) umm_malloc(size);
}

void vPortFree(void *ptr) {
    umm_free(ptr);
}

void* pvPortRealloc(void *ptr, size_t size) {
    return (void*) umm_realloc(ptr, size);
}

void * pvPortCalloc(size_t nelem, size_t elsize) {
    void *pvReturn = NULL;
    size_t len = nelem * elsize;
    pvReturn = (void*) pvPortMalloc(len);
    if (pvReturn != NULL)
        memset(pvReturn, 0, len);
    return (void*) pvReturn;
}

size_t xPortWantedSizeAlign(size_t size) {
    return (size + 3) & ~((size_t) 3);
}

void * __wrap_malloc(size_t s) {
    return (void*) pvPortMalloc(s);
}

void __wrap_free(void * ptr) {
    vPortFree(ptr);
}

