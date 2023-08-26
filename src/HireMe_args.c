#include <stdio.h>
#include <stdlib.h>
#include "HireMe_errors.h"
#include "HireMe_u8.h"
#include "HireMe_u128.h"
#include "HireMe_args.h"

void VerifLenTarget(const char *s, u8 ret[16])
{
    if(strlen(s) < 15)
    {
        printf(err_target);
        exit(1);
    }
    for(u8 i = 0; i < 16; i++)
        ret[i] = (u8) s[i];
    return;
}

void VerifLenInput(const char *s, u8 ret[32])
{
    if(strlen(s) < 31)
    {
        printf(err_input);
        exit(1);
    }
    for(u8 i = 0; i < 32; i++)
        ret[i] = (u8) s[i];
    return;
}
u8 VerifPrintMode(const char *s)
{
    if(strlen(s) > 1)
    {
        printf(err_print_mode);
        exit(1);
    }
    u8 out = (u8) *s;
    if(out != 'A' && out != 'C' && out != 'N' && out != 'O'
    && out != 'a' && out != 'c' && out != 'n' && out != 'o')
    {
        printf(err_print_mode);
        exit(1);
    }
    if(out == 'a')
        out = 'A';
    if(out == 'c')
        out = 'C';
    if(out == 'n')
        out = 'N';
    if(out == 'o')
        out = 'O';

    return out;
}

u128 atou128(const char *s)
{
    const char *p = s;
    
    while((*p == '\n') || (*p == '\t') || (*p == ' ')
       || (*p == '\f') || (*p == '\r') || (*p == '\v'))
        p++;
    
    if(*p == '+')
        p++;
    
    while(*p == '0')
        p++;

    if(*p < '0' || *p > '9')
    {
        printf(err_input_num);
        exit(1);
    }
    const char *start_num  = p;
    u8 nb_iter = 0;
    u128 val = 0;
    while(*p >= '0' && *p <= '9')
    {
        val = (10 * val) + (*p - '0');
        p++;
        nb_iter++;
    }
    if((*p != 0 && (*p < '0' || *p > '9')) || nb_iter > 39)
    {
        printf(err_input_num);
        exit(1);
    }

    if(nb_iter == 39)
    {
        const char *max_u128 = "340282366920938463463374607431768211456";
        while(*start_num >= '0' && *start_num <= '9')
        {
            if((*start_num - '0') < (*max_u128 - '0'))
                break;
            if((*start_num - '0') > (*max_u128 - '0'))
            {
                printf(err_input_num);
                exit(1);
            }
            max_u128++;
            start_num++;
        }
    }

    return val;
}