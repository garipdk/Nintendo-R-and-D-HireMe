#ifndef HireMe_AllsCommon
#define HireMe_AllsCommon

#include <stdbool.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_u128.h"

void realloc_s(u8 **ptr, u128 taille);

void Backward(u8 demanded_input[32], u8 target[16], u32 i, u8 **input_possibles, u128 *number_in);

void GeneratePairs(u8 target[16], u8 all_pairs[16][256][2]);

#endif // HireMe_AllsCommon