#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_u64.h"
#include "HireMe_u128.h"
#include "HireMe_AllsCommon.h"
#include "HireMe_globals.h"
#include "HireMe_SimplifiedForward.h"

void realloc_s(u8 **ptr, u128 taille)
{
    u8 *ptr_realloc = realloc(*ptr, taille);
    if(taille != 0)
    {
        if(ptr_realloc != NULL)
            *ptr = ptr_realloc;
        else
        {
            *ptr = realloc(*ptr, 0);
            printf("REALLOC RETURNED NULL !\n");
            exit(1);
        }
    }
    else
        *ptr = ptr_realloc;
}

void Backward(u8 demanded_input[32], u8 target[16], u32 i, u8 **input_possibles, u128 *number_in)
{
    if(i == 256)
        return;

    u8 output_[32];
    u8 found_num[32];

    for(u8 j=0;j<32;j++)
    {
        output_[j]=0;
        for(u8 k = 1; k < diffusion_indices[j][0]; k++)
            output_[j]^=demanded_input[diffusion_indices[j][k]];
        
        if(output_[j] == 15  || output_[j] == 17  || output_[j] == 32  || output_[j] == 62
        || output_[j] == 68  || output_[j] == 90  || output_[j] == 107 || output_[j] == 117
        || output_[j] == 128 || output_[j] == 158 || output_[j] == 175 || output_[j] == 177
        || output_[j] == 203 || output_[j] == 213 || output_[j] == 228 || output_[j] == 250)
            return;
    }
    u8 found_two_total = 0;

    for(u8 j = 0; j < 32; j++)
    {
        found_num[j] = 0;
        for(u32 k = 0; k < 256; k++)
            if(output_[j] == confusion[k])
                found_num[j]++;
        
        if(found_num[j]==2)
            found_two_total++;
    }
    
    u8 found[found_two_total][2];

    for(u8 j = 0; j < found_two_total; j++)
    {
        found[j][0]=0;
        found[j][1]=0;
    }
    u8 num_found_two = 0;

    for(u8 j = 0; j < 32; j++)
    {
        if(found_num[j]==2)
        {
            u8 num_found_two0 = 0;
            for(u32 k = 0; k < 256; k++)
            {
                if(num_found_two0==2)
                    break;
                if(output_[j] == confusion[k])
                {
                    found[num_found_two][num_found_two0]=k;
                        num_found_two0++;
                }
            }
                num_found_two++;
        }
    }

    for(u8 j = 0; j < 32; j++)
    {
        if(found_num[j]==1)
        {
            u8 omp_region_finished = 0;
            for(u32 k = 0; k < 256; k++)
            {
                if(omp_region_finished)
                    break;
                if(output_[j] == confusion[k])
                {
                    demanded_input[j] = k;
                    omp_region_finished++;
                }
            }
        }
    }

    u64 power = 1 << found_two_total;
    u8 demanded_input0[32];
    if(power>1)
    {
        for(u64 i1 = 0; i1 < power; i1++)
        {
            num_found_two = 0;
            memcpy(demanded_input0, demanded_input, 32);
            for(u8 j = 0; j < 32; j++)
            {
                if(found_num[j]==2)
                {
                    if((i1>>num_found_two)&1)
                        demanded_input[j] = found[num_found_two][1];
                    else
                        demanded_input[j] = found[num_found_two][0];
                    num_found_two++;
                }
            }
            Backward(demanded_input, target, i+1, input_possibles, number_in);
            memcpy(demanded_input, demanded_input0, 32);
        }
    }
    else
    {
        memcpy(demanded_input0, demanded_input, 32);
        Backward(demanded_input, target, i+1, input_possibles, number_in);
        memcpy(demanded_input, demanded_input0, 32);

    }

    if(i == 255)
    {
        u8 output0_[32];
        memcpy(demanded_input0, demanded_input, 32);
        SimplifiedForward(demanded_input0, output0_);
        if(memcmp(output0_, target, 16)==0)
        {
            realloc_s(input_possibles, (*number_in) + 32);
            u8 num;
            u128 i; 
            for(i = (*number_in), num = 0; i < ((*number_in) + 32) && num < 32; i++, num++)
                (*input_possibles)[i] = demanded_input[num];
            *number_in += 32;
        }
    }
    return;
}

void GeneratePairs(u8 target[16], u8 all_pairs[16][256][2])
{
    #pragma omp parallel for schedule(static) default(shared)
    for(u8 i = 0; i < 16; i++)
    {
        u32 found = 0;
        for(u32 k = 0; k < 256; k++)
        {
            for(u32 j = 256; j < 512; j++)
            {
                if((confusion[k]^confusion[j]) == target[i])
                {
                    all_pairs[i][found][0] = k;
                    all_pairs[i][found][1] = j-256;
                    found++;
                }
                if(found==256)
                    break;
            }
            if(found==256)
                break;
        }
    }
}