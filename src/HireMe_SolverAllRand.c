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
        u32 mystate;
        #ifdef _OPENMP
            mystate = (u32) (time(NULL) ^ getpid() ^ omp_get_thread_num());
        #endif
        u8 demanded_input0[32];
        demanded_input0[0] = all_pairs[0][urandomu8(&mystate)][0];
        demanded_input0[1] = all_pairs[0][urandomu8(&mystate)][1];

        demanded_input0[2] = all_pairs[1][urandomu8(&mystate)][0];
        demanded_input0[3] = all_pairs[1][urandomu8(&mystate)][1];

        demanded_input0[4] = all_pairs[2][urandomu8(&mystate)][0];
        demanded_input0[5] = all_pairs[2][urandomu8(&mystate)][1];

        demanded_input0[6] = all_pairs[3][urandomu8(&mystate)][0];
        demanded_input0[7] = all_pairs[3][urandomu8(&mystate)][1];

        demanded_input0[8] = all_pairs[4][urandomu8(&mystate)][0];
        demanded_input0[9] = all_pairs[4][urandomu8(&mystate)][1];

        demanded_input0[10] = all_pairs[5][urandomu8(&mystate)][0];
        demanded_input0[11] = all_pairs[5][urandomu8(&mystate)][1];

        demanded_input0[12] = all_pairs[6][urandomu8(&mystate)][0];
        demanded_input0[13] = all_pairs[6][urandomu8(&mystate)][1];

        demanded_input0[14] = all_pairs[7][urandomu8(&mystate)][0];
        demanded_input0[15] = all_pairs[7][urandomu8(&mystate)][1];

        demanded_input0[16] = all_pairs[8][urandomu8(&mystate)][0];
        demanded_input0[17] = all_pairs[8][urandomu8(&mystate)][1];

        demanded_input0[18] = all_pairs[9][urandomu8(&mystate)][0];
        demanded_input0[19] = all_pairs[9][urandomu8(&mystate)][1];

        demanded_input0[20] = all_pairs[10][urandomu8(&mystate)][0];
        demanded_input0[21] = all_pairs[10][urandomu8(&mystate)][1];

        demanded_input0[22] = all_pairs[11][urandomu8(&mystate)][0];
        demanded_input0[23] = all_pairs[11][urandomu8(&mystate)][1];

        demanded_input0[24] = all_pairs[12][urandomu8(&mystate)][0];
        demanded_input0[25] = all_pairs[12][urandomu8(&mystate)][1];

        demanded_input0[26] = all_pairs[13][urandomu8(&mystate)][0];
        demanded_input0[27] = all_pairs[13][urandomu8(&mystate)][1];

        demanded_input0[28] = all_pairs[14][urandomu8(&mystate)][0];
        demanded_input0[29] = all_pairs[14][urandomu8(&mystate)][1];

        demanded_input0[30] = all_pairs[15][urandomu8(&mystate)][0];
        demanded_input0[31] = all_pairs[15][urandomu8(&mystate)][1];
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