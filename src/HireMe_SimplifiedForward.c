#include <string.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_globals.h"
#include "HireMe_SimplifiedForward.h"

void SimplifiedForwardDiffusion(u8 *input_, u8 *tmp_input, u8 last_input_to_save[16])
{
    u8* temp;
    for (u32 i = 0; i < 255; i++)
    {
        for (u8 j = 0; j < 32; j++)
        { 
            tmp_input[j] = 0;
            for(u8 k = 1; k < diffusion_indices[j][0]; k++)
                tmp_input[j] ^= confusion[input_[diffusion_indices[j][k]]];
        }
        // Swap input_ and tmp_input to avoid copying
        temp = input_;
        input_ = tmp_input;
        tmp_input = temp;
    }

    for (u8 j = 0; j < 32; j++)
    { 
        tmp_input[j] = 0;
            for(u8 k = 1; k < diffusion_indices[j][0]; k++)
                tmp_input[j] ^= confusion[input_[diffusion_indices[j][k]]];
    }
    // Now input_ contains the final diffusion result

    // Save the last input values
    memcpy(last_input_to_save, &input_[16], 16);
}

void SimplifiedForwardConfusion(u8 input_[32], u8 output_[32], u8 last_input_to_save[16])
{
    for (u8 i = 0; i < 16; i++)
    {
        output_[i] = confusion[input_[i * 2]] ^ confusion[input_[i * 2 + 1] +256];
        output_[i+16] = confusion[last_input_to_save[i]];
    }
}

void SimplifiedForward(u8 input_[32], u8 output_[32])
{
    u8 last_input_to_save[16];
    u8 tmp_input[32];
    SimplifiedForwardDiffusion(input_, tmp_input, last_input_to_save);
    SimplifiedForwardConfusion(input_, output_, last_input_to_save);
}