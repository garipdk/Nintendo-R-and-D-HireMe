#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_strings.h"
#include "HireMe_prints.h"
#include "HireMe_genetic_func.h"
#include "HireMe_SolverGenetic.h"

void SolverGenetic(u8 demanded_input[32], u8 target[16], u8 print_mode, u32 gen_input_num, u32 pool_size, u32 elminiation_size, u32 reproduce_size)
{
    u8 p[pool_size*32];
    u8 *pool = p;
    u8 fp[pool_size*32];
    u8 *forward_pool = fp;
    u8 sp[pool_size];
    u8 *score_pool = sp;

    u32 mystate0;
    #ifdef _OPENMP
        mystate0 = (u32) (time(NULL) ^ getpid() ^ omp_get_thread_num());
    #endif
    
    PoolInit(pool, forward_pool, score_pool, pool_size, target, &mystate0);
    
    u128 it = 0;
    u8 min_score = 255;
    u32 count_0 = 0;
    
    u32 mystate;
    while(true)
    {
        // u32 mystate;
        #ifdef _OPENMP
            mystate = (u32) (time(NULL) ^ getpid() ^ omp_get_thread_num());
        #endif
        count_0 = CountScore0(score_pool, pool_size);
        if(score_pool[0] < min_score)
        {
            printScores(score_pool, pool_size, it);
            min_score = score_pool[0];
            if(print_mode != 'O')
            {
                if(CoherantString(pool, 32))
                {
                    if(print_mode == 'C' || print_mode == 'A')
                    {
                        printf("===================================================\n");
                        printf("FOUND A COHERRANT!!!!!!!!!!!!\n");
                        printDetail(pool, 32, 8, print_mode);
                        printf("FOUND A COHERRANT!!!!!!!!!!!!\n");
                        printf("===================================================\n");
                    }
                }
                else
                    if(print_mode == 'N' || print_mode == 'A')
                        printDetail(pool, 32, 8, print_mode);
            }
        }
        if(count_0 >= gen_input_num)
            break;
        PoolReplaceSames(pool, forward_pool, score_pool, pool_size, target, &mystate);
        PoolReplaceBadests(pool, forward_pool, score_pool, pool_size, elminiation_size, target, &mystate);
        PoolReplaceSames(pool, forward_pool, score_pool, pool_size, target, &mystate);
        PoolReproduceBests(pool, forward_pool, score_pool, pool_size, reproduce_size, target, &mystate);
        PoolReplaceSames(pool, forward_pool, score_pool, pool_size, target, &mystate);
        PoolRandomMutations(pool, forward_pool, score_pool, pool_size, target, &mystate);
        PoolReplaceSames(pool, forward_pool, score_pool, pool_size, target, &mystate);
        it++;
        if(print_mode != 'O')
        {
            for(u8 i = 0; i < count_0; i++)
            {
                if(CoherantString(&pool[i], 32))
                {
                    if(print_mode == 'C' || print_mode == 'A')
                    {
                        printf("===================================================\n");
                        printf("FOUND A COHERRANT!!!!!!!!!!!!\n");
                        printDetail(&pool[i], 32, 8, print_mode);
                        printf("FOUND A COHERRANT!!!!!!!!!!!!\n");
                        printf("===================================================\n");
                    }
                }
                else
                    if(print_mode == 'N' || print_mode == 'A')
                        printDetail(&pool[i], 32, 8, print_mode);
            }
        }
    }
    memcpy(demanded_input, pool, 32);

}