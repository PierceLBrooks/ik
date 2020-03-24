#include "ik/hash.h"
#include <assert.h>

/* ------------------------------------------------------------------------- */
hash32_t
hash32_vec3(const ikreal_t v[3])
{
    int i, j;
    hash32_t hash = 0;
    for (i = 0; i != 3; ++i) /* for every component (xyz) in vector */
        for (j = 0; j != sizeof(ikreal_t)/4; ++j) /* for every 32-bit chunk */
            hash = hash32_combine(hash, ((hash32_t*)&v[i])[j]);
    return hash;
}