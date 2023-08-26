#ifndef HireMe_globals
#define HireMe_globals

#include <stdio.h>
#include <stdbool.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"

extern u8 confusion[512];
extern u32 diffusion[32];
extern u8 input0[32];
extern u8 input_hire[32];
extern u8 input_test[32];
extern u8 input_base[32];
extern u8 diffusion_indices[32][16];
extern bool urandom_set;
extern FILE* urandom;

#endif // HireMe_globals