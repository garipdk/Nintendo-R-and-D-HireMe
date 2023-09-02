#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_u128.h"
#include "HireMe_bit_calculs.h"
#include "HireMe_SimplifiedForward.h"
#include "HireMe_randoms.h"
#include "HireMe_sorting.h"
#include "HireMe_prints.h"
#include "HireMe_genetic_func.h"

u8 Levenshtein(u8 *string1, u8 string2[16])
{
    u8 w = 1, s = 1, a = 1, d = 1;
	u8 len1 = 16, len2 = 16;
	u8 r0[len2+1];
    u8 r1[len2+1];
    u8 r2[len2+1];
    u8 *row0, *row1, *row2;
    row0 = r0;
    row1 = r1;
    row2 = r2;
	u8 i, j;
	for (j = 0; j <= len2; j++)
		row1[j] = j * a;
	for (i = 0; i < len1; i++) {
		u8 *dummy;
		row2[0] = (i + 1) * d;
		for (j = 0; j < len2; j++) {
			/* substitution */
			row2[j + 1] = row1[j] + s * (string1[i] != string2[j]);
			/* swap */
			if (i > 0 && j > 0 && string1[i - 1] == string2[j] &&
					string1[i] == string2[j - 1] &&
					row2[j + 1] > row0[j - 1] + w)
				row2[j + 1] = row0[j - 1] + w;
			/* deletion */
			if (row2[j + 1] > row1[j + 1] + d)
				row2[j + 1] = row1[j + 1] + d;
			/* insertion */
			if (row2[j + 1] > row2[j] + a)
				row2[j + 1] = row2[j] + a;
		}
		dummy = row0;
		row0 = row1;
		row1 = row2;
		row2 = dummy;
	}

	return row1[len2];
}

u8 HammingDistBits(u8 *str, u8 target[16])
{
    u8 count = 0;
    for(u8 i = 0; i < 16; i++)
        for(u8 bit = 0; bit < 8; bit++)
            if(bitcheck(str[i],bit) != bitcheck(target[i],bit))
                count++;
    
    return count;
}

u8 HammingDist(u8 *str, u8 target[16])
{
    u8 count = 0;
    for(u8 i = 0; i < 16; i++)
        if(str[i] != target[i])
            count++;
    
    return count;
}
u8 Score(u8 *str1, u8 target[16], u8 score_func)
{
    u8 ret;
    switch(score_func)
    {
        case 0:
            ret = HammingDistBits(str1, target);
            break;
        case 1:
            ret = HammingDist(str1, target);
            break;
        case 2:
            ret = Levenshtein(str1, target);
            break;
        default:
            ret = HammingDistBits(str1, target);
    }
    return ret;
}
void FindScore(u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16])
{
    for(u32 i = 0; i < pool_size; i++)
        score_pool[i] = Score(&forward_pool[i*32], target, 0);
}

void PoolSort(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16])
{
    u8 dummy[32];
    for(u32 i = 0; i < pool_size; i++)
    {
        for(u8 j = 0; j < 32; j++)
            dummy[j] = pool[(i*32)+j];
        SimplifiedForward(dummy, &forward_pool[i*32]);
    }
    FindScore(forward_pool, score_pool, pool_size, target);
    
    SelectionSort(score_pool, pool, pool_size);
}

#ifdef _OPENMP
void PoolInit(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate)
#else
void PoolInit(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16])
#endif
{
    for(u32 i = 0; i < pool_size; i++)
        #ifdef _OPENMP
        urandomu8Str32(&pool[i*32], mystate);
        #else
        urandomu8Str32(&pool[i*32]);
        #endif
    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

#ifdef _OPENMP
void PoolReplaceBadests(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u32 elminiation_size, u8 target[16], u32 *mystate)
#else
void PoolReplaceBadests(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u32 elminiation_size, u8 target[16])
#endif
{
    for(u32 i = pool_size - elminiation_size; i < pool_size; i++)
        #ifdef _OPENMP
        urandomu8Str32(&pool[i*32], mystate);
        #else
        urandomu8Str32(&pool[i*32]);
        #endif
    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

#ifdef _OPENMP
void PoolReplaceSames(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate)
#else
void PoolReplaceSames(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16])
#endif
{
    for(u32 i = 0; i < pool_size; i++)
        for(u32 j = 0; j < i; j++)
            if(memcmp(&pool[i*32], &pool[j*32], 32) == 0)
                #ifdef _OPENMP
                urandomu8Str32(&pool[j*32], mystate);
                #else
                urandomu8Str32(&pool[j*32]);
                #endif
    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

u8 ReproduceOneu8(u8 p1, u8 p2, u8 strategy)
{
    u8 ret;

    switch(strategy)
    {
        case 0:
            ret = ((u32)p1 + (u32)p2) / 2;
            break;
        case 1:
            ret = p1 ^ p2;
            break;
        case 2:
            ret = p1 & p2;
            break;
        case 3:
            ret = p1 | p2;
            break;
        case 4:
            ret = ~(p1 ^ p2);
            break;
        case 5:
            ret = ~(p1 & p2);
            break;
        case 6:
            ret = ~(p1 | p2);
            break;
        default:
            ret = ((u32)p1 + (u32)p2) / 2;
            break;
    }
    return ret;
}

void Reproduce(u8 *parent1, u8 *parent2, u8 *child, u8 r)
{
    for(u8 i = 0; i < 32; i++)
        child[i] = ReproduceOneu8(parent1[i], parent2[i], r);
}

#ifdef _OPENMP
void PoolReproduceBests(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u32 reproduce_size, u8 target[16], u32 *mystate)
#else
void PoolReproduceBests(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u32 reproduce_size, u8 target[16])
#endif
{
    long int child;
    u32 r, i;
    static u8 rand = 0;
    u8 last_min = score_pool[0];
    for(i = 0, child = pool_size - 1; i < reproduce_size && child > 0 ; i+=2, child--)
    {
        #ifdef _OPENMP
        while(i == (r=urandomu32Mod(pool_size/2, mystate)));
        #else
        while(i == (r=urandomu32Mod(pool_size/2)));
        #endif
        Reproduce(&pool[i*32], &pool[r*32], &pool[child*32], rand);
    }
    PoolSort(pool, forward_pool, score_pool, pool_size, target);
    if(score_pool[0] >= last_min)
        rand = (rand + 1) % 7;
}

#ifdef _OPENMP
void RandomMutations(u8 *parent, u8 *child, u32 *mystate)
#else
void RandomMutations(u8 *parent, u8 *child)
#endif
{
    for(u8 i = 0; i < 32; i++)
        child[i] = parent[i];
    #ifdef _OPENMP
    // bitsetclear(child[urandomu8Mod(32, mystate)], urandomu8Mod(8, mystate), urandomu8Mod(2, mystate));
    bitflip(child[urandomu8Mod(32, mystate)], urandomu8Mod(8, mystate));
    #else
    // bitsetclear(child[urandomu8Mod(32)], urandomu8Mod(8), urandomu8Mod(2));
    bitflip(child[urandomu8Mod(32)], urandomu8Mod(8));
    #endif
}

#ifdef _OPENMP
void PoolRandomMutations(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate)
#else
void PoolRandomMutations(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16])
#endif
{
    #ifdef _OPENMP
    u32 number_of_rand = urandomu32Mod(pool_size/2, mystate);
    #else
    u32 number_of_rand = urandomu32Mod(pool_size/2);
    #endif
    for(u32 i = pool_size - 1; i > pool_size - 1 - number_of_rand; i--)
        #ifdef _OPENMP
        RandomMutations(&pool[urandomu32Mod(number_of_rand, mystate)*32], &pool[i*32], mystate);
        #else
        RandomMutations(&pool[urandomu32Mod(number_of_rand)*32], &pool[i*32]);
        #endif

    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

void printScores(u8 *score_pool, u32 pool_size, u128 iter)
{
    printf("==============================\n");
    printf("I = ");
    printu128(iter);
    printf(" :\n");
    u32 max_show = 10;
    if(pool_size < max_show)
        max_show = pool_size;
    for(u32 i = 0; i < max_show; i++)
        printf("score[%d] = %d;\n", i, score_pool[i]);
}

u32 CountScore0(u8 *score_pool, u32 pool_size)
{
    u32 num_score_0 = 0;
    for(u32 i = 0; i < pool_size; i++)
        if(score_pool[i] == 0)
            num_score_0++;
        else
            break;
    return num_score_0;
}