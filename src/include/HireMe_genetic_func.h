#ifndef HireMe_genetic_func
#define HireMe_genetic_func

#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_u128.h"

void PoolInit(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate);

void PoolReplaceBadests(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u32 elminiation_size, u8 target[16], u32 *mystate);

void PoolReplaceSames(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate);

void PoolReproduceBests(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u32 reproduce_size, u8 target[16], u32 *mystate);

void PoolRandomMutations(u8 *pool, u8 *forward_pool, u8 *score_pool, u32 pool_size, u8 target[16], u32 *mystate);

void printScores(u8 *score_pool, u32 pool_size, u128 iter);

u32 CountScore0(u8 *score_pool, u32 pool_size);

#endif // HireMe_genetic_func