#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_globals.h"
#include "HireMe_randoms.h"

void urandomu8Str32(u8 *str, u32 *mystate)
{
    #ifdef _OPENMP
        for(u8 i = 0; i < 32; i++)
            str[i] = (u8) rand_r(mystate);
    #else
        *mystate = 0;
        if(urandom_set)
            for(u8 i = 0; i < 32; i++)
                str[i] = (u8) fgetc(urandom);
    #endif
}

u8 urandomu8(u32 *mystate)
{
    #ifdef _OPENMP
        return (u8) rand_r(mystate);
    #else
        *mystate = 0;
        if(urandom_set)
            return (u8) fgetc(urandom);
        else
            return 42;
    #endif
}

u8 urandomu8Mod(u8 mod, u32 *mystate)
{
    #ifdef _OPENMP
        return ((u8) rand_r(mystate)) % mod;
    #else
        *mystate = 0;
        if(urandom_set)
            return ((u8) fgetc(urandom)) % mod;
        else
            return 42;
    #endif
}

u32 urandomu32Mod(u32 mod, u32 *mystate)
{
    #ifdef _OPENMP
        return ((u32) rand_r(mystate)) % mod;
    #else
        *mystate = 0;
        return ((u32) rand()) % mod;
    #endif
}