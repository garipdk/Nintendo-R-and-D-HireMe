#ifndef HireMe_AllsCommon
#define HireMe_AllsCommon

#include <stdbool.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"

bool Backward(u8 demanded_input[32], u8 target[16], /*u16*/ u32 i);

void GeneratePairs(u8 target[16], u8 all_pairs[16][256][2]);

#endif // HireMe_AllsCommon