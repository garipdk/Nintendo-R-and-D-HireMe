#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_u128.h"
#include "HireMe_globals.h"
#include "HireMe_prints.h"
#include "HireMe_SimplifiedForward.h"
#include "HireMe_randoms.h"
#include "HireMe_SolverRandom.h"

void SolverRandom(u8 demanded_input[32], u8 target[16], u8 print_mode, u128 gen_input_num)
{

    u128 iterration = 0;
    bool is_found = false;
    u128 it_all = 0;
    #pragma omp parallel default(shared)
    while(true)
    {
        u32 mystate;
        #ifdef _OPENMP
            mystate = (u32) (time(NULL) ^ getpid() ^ omp_get_thread_num());
        #endif
        if(is_found)
        #ifdef _OPENMP
            continue;
        #else
            return;
        #endif
        u8 demanded_input0[32];
        urandomu8Str32(demanded_input0, &mystate);
        u8 output_[32];
        SimplifiedForward(demanded_input0, output_);
        if(memcmp(output_, target, 16) == 0)
        {
            #pragma omp critical
            {
                if(is_found == false)
                {
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