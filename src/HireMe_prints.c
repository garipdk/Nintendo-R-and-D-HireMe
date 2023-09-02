#include <ctype.h>
#include <stdio.h>
#include "HireMe_u8.h"
#include "HireMe_u128.h"
#include "HireMe_strings.h"
#include "HireMe_prints.h"

void printu128(u128 n)
{
    u128 rem;

    if(n>1000000000000000000)
    {
        printu128(n/1000000000000000000);
        rem=n%1000000000000000000;
        printf("%018llu",(unsigned long long) rem); 
    }
    else
        printf("%llu",(unsigned long long) n); 

    return;
}

void prints128(__int128 n)
{
    if(n<0)
    {
        printf("-");
        n*=-1;
    }

    printu128((u128) n); 

    return;
}

void printCoherantParts(u8 *str, u8 size)
{
    for(u8 i = 0; i < size; i++)
        if(isprint(str[i]))
            printf("%c",str[i]);
    printf("\n");
    return;
}

void printDetail(u8 *s, u8 size, u8 nb_per_line, u8 print_mode)
{
    printCoherantParts(s, 32);
    if(print_mode == 'A')
    {
        if(size>1)
        {
            for(u8 i = 0; i < size; i++)
                printf("%c",s[i]);
            printf("\n");
        }
        for(u8 i = 0; i < size; i++)
        {
            printf("%03d", s[i]);
            if(i+1<size)
                printf(", ");

            if((i+1)%nb_per_line==0)
                printf("\n");
        }
    }
}

void printOneGenerated(u8 str[32], u8 print_mode, u128 it_all, u128 iterration)
{
    if(TrueCoherantString(str, 32))
    {
        printf("Itteration = ");
        printu128(it_all);
        printf(";\n");
        printf("Input Found Number = ");
        printu128(iterration);
        printf(";\n\n");
        printf("===================================================\n");
        printf("===================================================\n");
        printf("FOUND A TRUE COHERRANT !!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
        printDetail(str, 32, 8, 'A');
        printf("\nFOUND A TRUE COHERRANT !!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("===================================================\n");
        printf("===================================================\n\n");
        // EXIT WHEN FIND A TRUE COHERANT !!!
        exit(0);
    }
    if(print_mode != 'O')
    {
        if(CoherantString(str, 32))
        {
            if(print_mode == 'C' || print_mode == 'A')
            {
                printf("Itteration = ");
                printu128(it_all);
                printf(";\n");
                printf("Input Found Number = ");
                printu128(iterration);
                printf(";\n");
                printf("===================================================\n");
                printf("FOUND A COHERRANT !!!!!!!!!!!!\n");
                printDetail(str, 32, 8, print_mode);
                printf("FOUND A COHERRANT !!!!!!!!!!!!\n");
                printf("===================================================\n");
            }
        }
        else
        {
            if(print_mode == 'N' || print_mode == 'A')
            {
                printf("Itteration = ");
                printu128(it_all);
                printf(";\n");
                printf("Input Found Number = ");
                printu128(iterration);
                printf(";\n");
                printDetail(str, 32, 8, print_mode);
            }
        }
    }
}