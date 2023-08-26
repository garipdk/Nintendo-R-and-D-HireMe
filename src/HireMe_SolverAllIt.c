#include <stdbool.h>
#include <string.h>
#include <omp.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_u128.h"
#include "HireMe_globals.h"
#include "HireMe_AllsCommon.h"
#include "HireMe_prints.h"
#include "HireMe_SolverAllIt.h"

void SolverAllIt(u8 demanded_input[32], u8 target[16], u8 print_mode, u128 gen_input_num)
{
    u8 all_pairs[16][256][2];

    GeneratePairs(target, all_pairs);
    if(print_mode != 'O')
        printf("All pairs computed!\n");
    
    u128 iterration = 0;
    bool is_found = false;
    u128 it_all = 0;
    for(/*u16*/ u32 j0 = 0; j0 < 256; j0++)
    {
        if(is_found)
            return;
    //printf("j0 = %d\n", j0);
    for(/*u16*/ u32 j1 = 0; j1 < 256; j1++)
    {
        if(is_found)
            return;
    //printf("j1 = %d\n", j1);
    for(/*u16*/ u32 j2 = 0; j2 < 256; j2++)
    {
        if(is_found)
            return;
    //printf("j2 = %d\n", j2);
    for(/*u16*/ u32 j3 = 0; j3 < 256; j3++)
    {
        if(is_found)
            return;
    //printf("j3 = %d\n", j3);
    for(/*u16*/ u32 j4 = 0; j4 < 256; j4++)
    {
        if(is_found)
            return;
    //printf("j4 = %d\n", j4);
    for(/*u16*/ u32 j5 = 0; j5 < 256; j5++)
    {
        if(is_found)
            return;
    //printf("j5 = %d\n", j5);
    for(/*u16*/ u32 j6 = 0; j6 < 256; j6++)
    {
        if(is_found)
            return;
    //printf("j6 = %d\n", j6);
    for(/*u16*/ u32 j7 = 0; j7 < 256; j7++)
    {
        if(is_found)
            return;
    //printf("j7 = %d\n", j7);
    for(/*u16*/ u32 j8 = 0; j8 < 256; j8++)
    {
        if(is_found)
            return;
    //printf("j8 = %d\n", j8);
    for(/*u16*/ u32 j9 = 0; j9 < 256; j9++)
    {
        if(is_found)
            return;
    //printf("j9 = %d\n", j9);
    for(/*u16*/ u32 j10 = 0; j10 < 256; j10++)
    {
        if(is_found)
            return;
    //printf("j10 = %d\n", j10);
    for(/*u16*/ u32 j11 = 0; j11 < 256; j11++)
    {
        if(is_found)
            return;
    //printf("j11 = %d\n", j11);
    for(/*u16*/ u32 j12 = 0; j12 < 256; j12++)
    {
        if(is_found)
            return;
    //printf("j12 = %d\n", j12);
    for(/*u16*/ u32 j13 = 0; j13 < 256; j13++)
    {
        if(is_found)
            return;
    //printf("j13 = %d\n", j13);
    #pragma omp parallel for schedule(dynamic,100) default(shared) num_threads(2)
    for(/*u16*/ u32 j14 = 0; j14 < 256; j14++)
    {
    //printf("j14 = %d\n", j14);
        if(is_found)
        #ifdef _OPENMP
            continue;
        #else
            return;
        #endif
    #pragma omp parallel for schedule(dynamic,50) default(shared) num_threads(3)
    for(/*u16*/ u32 j15 = 0; j15 < 256; j15++)
    {
    //printf("j15 = %d\n", j15);
        if(is_found)
        #ifdef _OPENMP
            continue;
        #else
            return;
        #endif
        u8 demanded_input0[32];
        demanded_input0[0] = all_pairs[0][j0][0];
        demanded_input0[1] = all_pairs[0][j0][1];

        demanded_input0[2] = all_pairs[1][j1][0];
        demanded_input0[3] = all_pairs[1][j1][1];

        demanded_input0[4] = all_pairs[2][j2][0];
        demanded_input0[5] = all_pairs[2][j2][1];

        demanded_input0[6] = all_pairs[3][j3][0];
        demanded_input0[7] = all_pairs[3][j3][1];

        demanded_input0[8] = all_pairs[4][j4][0];
        demanded_input0[9] = all_pairs[4][j4][1];

        demanded_input0[10] = all_pairs[5][j5][0];
        demanded_input0[11] = all_pairs[5][j5][1];

        demanded_input0[12] = all_pairs[6][j6][0];
        demanded_input0[13] = all_pairs[6][j6][1];

        demanded_input0[14] = all_pairs[7][j7][0];
        demanded_input0[15] = all_pairs[7][j7][1];

        demanded_input0[16] = all_pairs[8][j8][0];
        demanded_input0[17] = all_pairs[8][j8][1];

        demanded_input0[18] = all_pairs[9][j9][0];
        demanded_input0[19] = all_pairs[9][j9][1];

        demanded_input0[20] = all_pairs[10][j10][0];
        demanded_input0[21] = all_pairs[10][j10][1];

        demanded_input0[22] = all_pairs[11][j11][0];
        demanded_input0[23] = all_pairs[11][j11][1];

        demanded_input0[24] = all_pairs[12][j12][0];
        demanded_input0[25] = all_pairs[12][j12][1];

        demanded_input0[26] = all_pairs[13][j13][0];
        demanded_input0[27] = all_pairs[13][j13][1];

        demanded_input0[28] = all_pairs[14][j14][0];
        demanded_input0[29] = all_pairs[14][j14][1];

        demanded_input0[30] = all_pairs[15][j15][0];
        demanded_input0[31] = all_pairs[15][j15][1];
        if(Backward(demanded_input0, target, 0))
        {
            #pragma omp critical
            {
                if(is_found == false)
                {
                    //#pragma omp atomic update
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
    }}}}}}}}}}}}}}}}
    
    return;
}