#ifndef HireMe_prints
#define HireMe_prints

#include "HireMe_u8.h"
#include "HireMe_u128.h"

void printu128(u128 n);

void prints128(__int128 n);

void printCoherantParts(u8 *str, u8 size);

void printDetail(u8 *s, u8 size, u8 nb_per_line, u8 print_mode);

void printOneGenerated(u8 str[32], u8 print_mode, u128 it_all, u128 iterration);

#endif // HireMe_prints