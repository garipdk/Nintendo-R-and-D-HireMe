#ifndef HireMe_randoms
#define HireMe_randoms

#include "HireMe_u8.h"
#include "HireMe_u32.h"

#ifdef _OPENMP
void urandomu8Str32(u8 *str, u32 *mystate);

u8 urandomu8(u32 *mystate);

u8 urandomu8Mod(u8 mod, u32 *mystate);

u32 urandomu32Mod(u32 mod, u32 *mystate);
#else
void urandomu8Str32(u8 *str);

u8 urandomu8();

u8 urandomu8Mod(u8 mod);

u32 urandomu32Mod(u32 mod);
#endif

#endif // HireMe_randoms