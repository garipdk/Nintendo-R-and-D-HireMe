#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_globals.h"
#include "HireMe_randoms.h"

#ifdef _OPENMP
u8 urandomu8(u32 *mystate)
#else
u8 urandomu8()
#endif
{
    #ifdef _OPENMP
        return (u8) (rand_r(mystate) % ((u8) -1));
    #else
        if(urandom_set)
            return (u8) (fgetc(urandom) % ((u8) -1));
        else
            return 42;
    #endif
}

#ifdef _OPENMP
void urandomu8Str32(u8 *str, u32 *mystate)
#else
void urandomu8Str32(u8 *str)
#endif
{
    for(u8 i = 0; i < 32; i++)
        #ifdef _OPENMP
            str[i] = urandomu8(mystate);
        #else
            str[i] = urandomu8();
        #endif
}

#ifdef _OPENMP
u8 urandomu8Mod(u8 mod, u32 *mystate)
#else
u8 urandomu8Mod(u8 mod)
#endif
{
    #ifdef _OPENMP
        return (u8) (rand_r(mystate) % mod);
    #else
        if(urandom_set)
            return (u8) (fgetc(urandom) % mod);
        else
            return 42;
    #endif
}

#ifdef _OPENMP
u32 urandomu32Mod(u32 mod, u32 *mystate)
#else
u32 urandomu32Mod(u32 mod)
#endif
{
    #ifdef _OPENMP
        return (u32) (rand_r(mystate) % mod);
    #else
        return (u32) (rand() % mod);
    #endif
}