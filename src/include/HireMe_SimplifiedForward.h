#ifndef HireMe_SimplifiedForward
#define HireMe_SimplifiedForward

#include "HireMe_u8.h"

void SimplifiedForwardDiffusion(u8 *input_, u8 *tmp_input, u8 last_input_to_save[16]);

void SimplifiedForwardConfusion(u8 input_[32], u8 output_[32], u8 last_input_to_save[16]);

void SimplifiedForward(u8 input_[32], u8 output_[32]);

#endif // HireMe_SimplifiedForward