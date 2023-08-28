#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_u128.h"
#include "HireMe_globals.h"
#include "HireMe_AllsCommon.h"
#include "HireMe_randoms.h"
#include "HireMe_prints.h"
#include "HireMe_SolverAllRand.h"

void SolverAllRand(u8 demanded_input[32], u8 target[16], u8 print_mode, u128 gen_input_num)
{
    u8 all_pairs[16][256][2];

    GeneratePairs(target, all_pairs);
    if(print_mode != 'O')
        printf("All pairs computed!\n");
    
    u128 iterration = 0;
    bool is_found = false;
    u128 it_all = 0;
    #pragma omp parallel default(shared)
    while(true)
    {
        if(is_found)
        #ifdef _OPENMP
            continue;
        #else
            return;
        #endif
        #ifdef _OPENMP
        u32 mystate = (u32) (time(NULL) ^ getpid() ^ omp_get_thread_num());
        #endif
        u8 demanded_input0[32];
        for(u8 i = 0; i < 16; i++)
        {
            #ifdef _OPENMP
            demanded_input0[i*2] = all_pairs[i][urandomu8(&mystate)][0];
            demanded_input0[i*2+1] = all_pairs[i][urandomu8(&mystate)][1];
            #else
            demanded_input0[i*2] = all_pairs[i][urandomu8()][0];
            demanded_input0[i*2+1] = all_pairs[i][urandomu8()][1];
            #endif
        }
        if(Backward(demanded_input0, target, 0))
        {
            #pragma omp critical
            {
                if(is_found == false)
                {
                    // #pragma omp atomic update
                        iterration++;
                    if(iterration == gen_input_num)
                    {
                        is_found = true;
                        memcpy(demanded_input, demanded_input0, 32);
                    }
                }
                printOneGenerated(demanded_input0, print_mode, it_all, iterration);
            }
        }
        if(print_mode != 'O')
        {
            #pragma omp atomic update
                it_all++;
        }
    }
    return;
}