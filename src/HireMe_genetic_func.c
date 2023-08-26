#include <stdio.h>
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

u8 HammingDistBits(u8 *str, u8 target[16])
{
    u8 count = 0;
    for(u8 i = 0; i < 16; i++)
        for(u8 bit = 0; bit < 8; bit++)
            if(bitcheck(str[i],bit) != bitcheck(target[i],bit))
                count++;
    
    return count;
}

void FindScore(u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16])
{
    for(u32 i = 0; i < pool_size; i++)
        score_pool[i] = HammingDistBits(&forward_pool[i*32], target);
}

void PoolSort(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16])
{
    for(u32 i = 0; i < pool_size; i++)
        SimplifiedForward(&pool[i*32], &forward_pool[i*32]);
    
    FindScore(forward_pool, score_pool, pool_size, target);
    
    SelectionSort(score_pool, pool, pool_size);

}

void PoolInit(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate)
{
    for(u32 i = 0; i < pool_size; i++)
        urandomu8Str32(&pool[i*32], mystate);
    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

void PoolReplaceBadests(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u32 elminiation_size, u8 target[16], u32 *mystate)
{
    for(u32 i = pool_size - elminiation_size; i < pool_size; i++)
        urandomu8Str32(&pool[i*32], mystate);
    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

void PoolReplaceSames(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate)
{
    for(u32 i = 0; i < pool_size; i++)
        for(u32 j = 0; j < i; j++)
            if(memcmp(&pool[i*32], &pool[j*32], 32) == 0)
                urandomu8Str32(&pool[j*32], mystate);
    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

void Reproduce(u8 *parent1, u8 *parent2, u8 *child)
{
    for(u8 i = 0; i < 32; i++)
        child[i] = ((int) (parent1[i] + parent2[i])) / 2;
}

void PoolReproduceBests(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u32 reproduce_size, u8 target[16])
{
    for(long int i = 0, child = pool_size - 1; i < reproduce_size && child > 0 ; i+=2, child--)
        Reproduce(&pool[i*32], &pool[(i+1)*32], &pool[child*32]);
    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

void RandomMutations(u8 *parent, u8 *child, u32 *mystate)
{
    memmove(child, parent, 32);
    // bitsetclear(child[urandomu8Mod(32, mystate)], urandomu8Mod(8, mystate), urandomu8Mod(2, mystate));
    bitflip(child[urandomu8Mod(32, mystate)], urandomu8Mod(8, mystate));
}

void PoolRandomMutations(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate)
{
    u32 number_of_rand = urandomu32Mod(pool_size/2, mystate);
    for(u32 i = pool_size - 1; i > pool_size - 1 - number_of_rand; i--)
        RandomMutations(&pool[urandomu32Mod(number_of_rand, mystate)*32], &pool[i*32], mystate);

    PoolSort(pool, forward_pool, score_pool, pool_size, target);
}

void printScores(u8 *score_pool, u32 pool_size, u128 iter)
{
    printf("==============================\n");
    printf("I = ");
    printu128(iter);
    printf(" :\n");
    u32 max_show = 10;
    if((pool_size/10) < max_show)
        max_show = (pool_size/10);
    for(u32 i = 0; i < max_show; i++)
        printf("score[%d] = %d;\n", i, score_pool[i]);
}

u8 CountScore0(u8 *score_pool, u32 pool_size)
{
    u8 num_score_0 = 0;
    for(u8 i = 0; i < pool_size; i++)
        if(score_pool[i] == 0)
            num_score_0++;
        else
            break;
    return num_score_0;
}