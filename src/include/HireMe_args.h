#ifndef HireMe_args
#define HireMe_args

#include "HireMe_u8.h"
#include "HireMe_u128.h"

void VerifLenTarget(const char *s, u8 ret[16]);

void VerifLenInput(const char *s, u8 ret[32]);

u8 VerifPrintMode(const char *s);

u128 atou128(const char *s);

#endif // HireMe_args