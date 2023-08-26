#include "HireMe_u8.h"
#include "HireMe_utils.h"

void swap(u8 *a, u8 *b)
{
    u8 temp = *a;
    *a = *b;
    *b = temp;
}

void swap32(u8 *a, u8 *b)
{
    for(u8 i = 0; i < 32; i++)
        swap(&a[i], &b[i]);
}