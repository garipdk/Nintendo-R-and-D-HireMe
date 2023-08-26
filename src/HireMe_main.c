
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>
#include <limits.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_u128.h"
#include "HireMe_errors.h"
#include "HireMe_args.h"
#include "HireMe_strings.h"
#include "HireMe_prints.h"
#include "HireMe_globals.h"
#include "HireMe_AllsCommon.h"
#include "HireMe_SimplifiedForward.h"
#include "HireMe_SolverAllRand.h"
#include "HireMe_SolverAllIt.h"
#include "HireMe_SolverGenetic.h"
#include "HireMe_SolverRandom.h"

void Forward(u8 input_[32], u8 output_[32])
{
    for(u32 i=0;i<256;i++)
    {
        for(u8 j=0;j<32;j++)
        {
            output_[j]=confusion[input_[j]];
            input_[j]=0;
        }
        for(u8 j=0;j<32;j++)
            for(u8 k=0;k<32;k++)
                input_[j]^=output_[k]*((diffusion[j]>>k)&1);
    }
    for(u8 i=0;i<16;i++)
        output_[i]=confusion[input_[i*2]]^confusion[input_[i*2+1]+256];
}
/*
The solutions to this challenge belong to different levels :

Level 1 : an iterative algorithm which typically takes more than a second to
find a solution (for any given output).

Most people stop here, which is fine, but if you want to go further, there is :

Level 2 : a non-iterative algorithm which typically takes less than a
millisecond to find a solution (for any given output).

Few people have reached this level. But if you want to beat it completely,
there's yet another castle...

Level 3 : an algorithm which can provide any of the 2^128 solutions (for any
given output).

Even fewer people have reached this final level. Congratulations to them!

*/
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf(error_solver);
        exit(1);
    }
    tolowerStr(argv[1]);
    if(strcmp(argv[1], "base") == 0)
    {
        if(argc != 4)
        {
            printf(error_base);
            exit(1);
        }
        u8 print_mode = VerifPrintMode(argv[2]);
        u8 input[32];
        VerifLenInput(argv[3], input);
        #ifdef _OPENMP
            omp_set_num_threads(8);
        #endif
        u8 output_base[32];
        // u8 output[32];
        u8 input_save[32];
        memcpy(input_save, input, 32);
        if(print_mode != 'O')
        {
            printf("Base Input :\n");
            printDetail(input, 32, 8, print_mode);
        }
        SimplifiedForward(input, output_base);
        if(print_mode != 'O')
        {
            printf("Forward Input :\n");
            printDetail(input, 32, 8, print_mode);
        }
        Backward(input, output_base, 0);
        if(print_mode != 'O')
        {
            printf("Backward Input :\n");
            printDetail(input, 32, 8, print_mode);
        }
        return memcmp(input, input_save, 32);
    }
    else if(strcmp(argv[1], "allit") == 0)
    {
        if(argc != 5)
        {
            printf(error_allit);
            exit(1);
        }
        u8 print_mode = VerifPrintMode(argv[2]);
        u8 target[16];
        VerifLenTarget(argv[3], target);
        u128 gen_input_num = atou128(argv[4]);
        u8 count;
        for(u8 j = 0; j < 32; j++)
        {
            count = 0;
            for(u8 k = 0; k < 32; k++)
                if((diffusion[j] >> k) & 1)
                    diffusion_indices[j][1+count++] = k;
            diffusion_indices[j][0] = count + 1;
        }
        #ifdef _OPENMP
            omp_set_num_threads(8);
        #endif
        u8 input_generated[32];
        u8 output[32];

        SolverAllIt(input_generated, target, print_mode, gen_input_num);

        if(print_mode == 'O')
            SimplifiedForward(input_generated, output);
        else
            Forward(input_generated, output);

        return memcmp(output, target, 16); // => contact apply(at)nerd.nintendo.com
    }
    else if(strcmp(argv[1], "allrand") == 0)
    {
        if(argc != 5)
        {
            printf(error_allrand);
            exit(1);
        }
        u8 print_mode = VerifPrintMode(argv[2]);
        u8 target[16];
        VerifLenTarget(argv[3], target);
        u128 gen_input_num = atou128(argv[4]);
        u8 count;
        for(u8 j = 0; j < 32; j++)
        {
            count = 0;
            for(u8 k = 0; k < 32; k++)
                if((diffusion[j] >> k) & 1)
                    diffusion_indices[j][1+count++] = k;
            diffusion_indices[j][0] = count + 1;
        }
        #ifndef _OPENMP
            srand(time(NULL)^getpid());
            urandom = fopen("/dev/urandom", "r");
            if(urandom != NULL)
                urandom_set = true;
        #else
            omp_set_num_threads(8);
        #endif

        u8 input_generated[32];
        u8 output[32];

        SolverAllRand(input_generated, target, print_mode, gen_input_num);

        if(print_mode == 'O')
            SimplifiedForward(input_generated, output);
        else
            Forward(input_generated, output);

        #ifndef _OPENMP
            fclose(urandom);
        #endif

        return memcmp(output, target, 16); // => contact apply(at)nerd.nintendo.com
    }
    else if(strcmp(argv[1], "genetic") == 0)
    {
        if(argc != 8)
        {
            printf(error_allrand);
            exit(1);
        }
        u8 print_mode = VerifPrintMode(argv[2]);
        u8 target[16];
        VerifLenTarget(argv[3], target);
        
        char *verif_ptr;
        long long placeholder;
        if(argv[4][0] == 0)
        {
            printf(error_pool_size);
            exit(1);
        }
        placeholder = strtoull(argv[4],&verif_ptr, 10);
        if(verif_ptr[0] != 0 || placeholder < 2 || placeholder > UINT_MAX)
        {
            printf(error_pool_size);
            exit(1);
        }
        u32 pool_size = (u32) placeholder;

        if(argv[5][0] == 0)
        {
            printf(err_input_num_gen);
            exit(1);
        }
        placeholder = strtoull(argv[5],&verif_ptr, 10);
        if(verif_ptr[0] != 0 || placeholder < 1 || placeholder > pool_size)
        {
            printf(err_input_num_gen);
            exit(1);
        }
        u32 gen_input_num = (u32) placeholder;
        
        if(argv[6][0] == 0)
        {
            printf(error_elimination_size);
            exit(1);
        }
        placeholder = strtoul(argv[6],&verif_ptr, 10);
        if(verif_ptr[0] != 0 || placeholder < 1 || placeholder > (pool_size-1))
        {
            printf(error_elimination_size);
            exit(1);
        }
        u32 elimination_size = (u32) placeholder;
        
        if(argv[7][0] == 0)
        {
            printf(error_reproduce_size);
            exit(1);
        }
        placeholder = strtoul(argv[7],&verif_ptr, 10);
        if(verif_ptr[0] != 0 || placeholder < 1 || placeholder > (pool_size/3))
        {
            printf(error_reproduce_size);
            exit(1);
        }
        u32 reproduce_size = (u32) placeholder;

        u8 count;
        for(u8 j = 0; j < 32; j++)
        {
            count = 0;
            for(u8 k = 0; k < 32; k++)
                if((diffusion[j] >> k) & 1)
                    diffusion_indices[j][1+count++] = k;
            diffusion_indices[j][0] = count + 1;
        }
        #ifndef _OPENMP
            srand(time(NULL)^getpid());
            urandom = fopen("/dev/urandom", "r");
            if(urandom != NULL)
                urandom_set = true;
        #else
            omp_set_num_threads(8);
        #endif

        u8 input_generated[32];
        u8 output[32];

        SolverGenetic(input_generated, target, print_mode, gen_input_num, pool_size, elimination_size, reproduce_size);

        if(print_mode == 'O')
            SimplifiedForward(input_generated, output);
        else
            Forward(input_generated, output);

        #ifndef _OPENMP
            fclose(urandom);
        #endif
        return memcmp(output, target, 16); // => contact apply(at)nerd.nintendo.com
    }
    else if(strcmp(argv[1], "rand") == 0)
    {
        if(argc != 5)
        {
            printf(error_allrand);
            exit(1);
        }

        u8 print_mode = VerifPrintMode(argv[2]);

        u8 target[16];

        VerifLenTarget(argv[3], target);

        u128 gen_input_num = atou128(argv[4]);

        u8 count;
        for(u8 j = 0; j < 32; j++)
        {
            count = 0;
            for(u8 k = 0; k < 32; k++)
                if((diffusion[j] >> k) & 1)
                    diffusion_indices[j][1+count++] = k;
            diffusion_indices[j][0] = count + 1;
        }

        #ifndef _OPENMP
            srand(time(NULL)^getpid());
            urandom = fopen("/dev/urandom", "r");
            if(urandom != NULL)
                urandom_set = true;
        #else
            omp_set_num_threads(8);
        #endif

        u8 input_generated[32];
        u8 output[32];

        SolverRandom(input_generated, target, print_mode, gen_input_num);

        if(print_mode == 'O')
            SimplifiedForward(input_generated, output);
        else
            Forward(input_generated, output);

        #ifndef _OPENMP
            fclose(urandom);
        #endif

        return memcmp(output, target, 16); // => contact apply(at)nerd.nintendo.com
    }

    printf(error_solver);

    return 1;
}
