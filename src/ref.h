
#ifndef WREN2D_REF_H
#define WREN2D_REF_H

#include <stddef.h>


// http://stackoverflow.com/questions/10269685/kernels-container-of-any-way-to-make-it-iso-conforming
// Non-type-safe generic implementation of container_of
#define container_of(ptr, type, member) \
    ((type*) ((char*)(ptr) - offsetof(type, member)))


typedef struct Ref_s {
    void (*free)(const struct Ref_s*);
    int count;
} Ref;


// Cast const pointer to mutable pointer
static inline void incRef(const struct Ref_s* ref) {
    ((struct Ref_s*)ref)->count++;
}


static inline void decRef(const struct Ref_s* ref) {
    if (--((struct Ref_s*)ref)->count == 0)
        ref->free(ref);
}


#endif