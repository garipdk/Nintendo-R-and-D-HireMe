#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <memory.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef uint64_t u64;
typedef unsigned __int128 u128;


u8 confusion[512]={
0xac,0xd1,0x25,0x94,0x1f,0xb3,0x33,0x28,0x7c,0x2b,0x17,0xbc,0xf6,0xb0,0x55,0x5d,
0x8f,0xd2,0x48,0xd4,0xd3,0x78,0x62,0x1a,0x02,0xf2,0x01,0xc9,0xaa,0xf0,0x83,0x71,
0x72,0x4b,0x6a,0xe8,0xe9,0x42,0xc0,0x53,0x63,0x66,0x13,0x4a,0xc1,0x85,0xcf,0x0c,
0x24,0x76,0xa5,0x6e,0xd7,0xa1,0xec,0xc6,0x04,0xc2,0xa2,0x5c,0x81,0x92,0x6c,0xda,
0xc6,0x86,0xba,0x4d,0x39,0xa0,0x0e,0x8c,0x8a,0xd0,0xfe,0x59,0x96,0x49,0xe6,0xea,
0x69,0x30,0x52,0x1c,0xe0,0xb2,0x05,0x9b,0x10,0x03,0xa8,0x64,0x51,0x97,0x02,0x09,
0x8e,0xad,0xf7,0x36,0x47,0xab,0xce,0x7f,0x56,0xca,0x00,0xe3,0xed,0xf1,0x38,0xd8,
0x26,0x1c,0xdc,0x35,0x91,0x43,0x2c,0x74,0xb4,0x61,0x9d,0x5e,0xe9,0x4c,0xbf,0x77,
0x16,0x1e,0x21,0x1d,0x2d,0xa9,0x95,0xb8,0xc3,0x8d,0xf8,0xdb,0x34,0xe1,0x84,0xd6,
0x0b,0x23,0x4e,0xff,0x3c,0x54,0xa7,0x78,0xa4,0x89,0x33,0x6d,0xfb,0x79,0x27,0xc4,
0xf9,0x40,0x41,0xdf,0xc5,0x82,0x93,0xdd,0xa6,0xef,0xcd,0x8d,0xa3,0xae,0x7a,0xb6,
0x2f,0xfd,0xbd,0xe5,0x98,0x66,0xf3,0x4f,0x57,0x88,0x90,0x9c,0x0a,0x50,0xe7,0x15,
0x7b,0x58,0xbc,0x07,0x68,0x3a,0x5f,0xee,0x32,0x9f,0xeb,0xcc,0x18,0x8b,0xe2,0x57,
0xb7,0x49,0x37,0xde,0xf5,0x99,0x67,0x5b,0x3b,0xbb,0x3d,0xb5,0x2d,0x19,0x2e,0x0d,
0x93,0xfc,0x7e,0x06,0x08,0xbe,0x3f,0xd9,0x2a,0x70,0x9a,0xc8,0x7d,0xd8,0x46,0x65,
0x22,0xf4,0xb9,0xa2,0x6f,0x12,0x1b,0x14,0x45,0xc7,0x87,0x31,0x60,0x29,0xf7,0x73,
0x2c,0x97,0x72,0xcd,0x89,0xa6,0x88,0x4c,0xe8,0x83,0xeb,0x59,0xca,0x50,0x3f,0x27,
0x4e,0xae,0x43,0xd5,0x6e,0xd0,0x99,0x7b,0x7c,0x40,0x0c,0x52,0x86,0xc1,0x46,0x12,
0x5a,0x28,0xa8,0xbb,0xcb,0xf0,0x11,0x95,0x26,0x0d,0x34,0x66,0x22,0x18,0x6f,0x51,
0x9b,0x3b,0xda,0xec,0x5e,0x00,0x2a,0xf5,0x8f,0x61,0xba,0x96,0xb3,0xd1,0x30,0xdc,
0x33,0x75,0xe9,0x6d,0xc8,0xa1,0x3a,0x3e,0x5f,0x9d,0xfd,0xa9,0x31,0x9f,0xaa,0x85,
0x2f,0x92,0xaf,0x67,0x78,0xa5,0xab,0x03,0x21,0x4f,0xb9,0xad,0xfe,0xf3,0x42,0xfc,
0x17,0xd7,0xee,0xa3,0xd8,0x80,0x14,0x2e,0xa0,0x47,0x55,0xc4,0xff,0xe5,0x13,0x3f,
0x81,0xb6,0x7a,0x94,0xd0,0xb5,0x54,0xbf,0x91,0xa7,0x37,0xf1,0x6b,0xc9,0x1b,0xb1,
0x3c,0xb6,0xd9,0x32,0x24,0x8d,0xf2,0x82,0xb4,0xf9,0xdb,0x7d,0x44,0xfb,0x1e,0xd4,
0xea,0x5d,0x35,0x69,0x23,0x71,0x57,0x01,0x06,0xe4,0x55,0x9a,0xa4,0x58,0x56,0xc7,
0x4a,0x8c,0x8a,0xd6,0x6a,0x49,0x70,0xc5,0x8e,0x0a,0x62,0xdc,0x29,0x4b,0x42,0x41,
0xcb,0x2b,0xb7,0xce,0x08,0xa1,0x76,0x1d,0x1a,0xb8,0xe3,0xcc,0x7e,0x48,0x20,0xe6,
0xf8,0x45,0x93,0xde,0xc3,0x63,0x0f,0xb0,0xac,0x5c,0xba,0xdf,0x07,0x77,0xe7,0x4e,
0x1f,0x28,0x10,0x6c,0x59,0xd3,0xdd,0x2d,0x65,0x39,0xb2,0x74,0x84,0x3d,0xf4,0xbd,
0xc7,0x79,0x60,0x0b,0x4d,0x33,0x36,0x25,0xbc,0xe0,0x09,0xcf,0x5b,0xe2,0x38,0x9e,
0xc0,0xef,0xd2,0x16,0x05,0xbe,0x53,0xf7,0xc2,0xc6,0xa2,0x24,0x98,0x1c,0xad,0x04};

u32 diffusion[32]={
0xf26cb481,0x16a5dc92,0x3c5ba924,0x79b65248,0x2fc64b18,0x615acd29,0xc3b59a42,0x976b2584,
0x6cf281b4,0xa51692dc,0x5b3c24a9,0xb6794852,0xc62f184b,0x5a6129cd,0xb5c3429a,0x6b978425,
0xb481f26c,0xdc9216a5,0xa9243c5b,0x524879b6,0x4b182fc6,0xcd29615a,0x9a42c3b5,0x2584976b,
0x81b46cf2,0x92dca516,0x24a95b3c,0x4852b679,0x184bc62f,0x29cd5a61,0x429ab5c3,0x84256b97};

u8 input0[32]={
//change only this :
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31
//
};
u8 input[32]={
//change only this :
0x48, 0x69, 0x72, 0x65, 0x20, 0x6d, 0x65, 0x21,
0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x00,
0x58, 0x8f, 0x22, 0x7a, 0x92, 0x7f, 0x00, 0x00,
0xea, 0xe7, 0x11, 0x7a, 0x92, 0x7f, 0x00, 0x00
//
};
u8 input_test[32]={
//change only this :
0x7a, 0x87, 0xc5, 0xea, 0xfc, 0xfc, 0x60, 0xfa,
0x68, 0x17, 0x72, 0x37, 0x2b, 0xd7, 0x27, 0x5a,
0x39, 0x95, 0xe4, 0xca, 0x0b, 0x7b, 0xb1, 0xf2,
0x29, 0xb4, 0x50, 0x1f, 0x82, 0xa2, 0xcd, 0x25
};
u8 input_base[32]={
//change only this :
0x66,0xd5,0x4e,0x28,0x5f,0xff,0x6b,0x53,0xac,0x3b,0x34,0x14,0xb5,0x3c,0xb2,0xc6,
0xa4,0x85,0x1e,0x0d,0x86,0xc7,0x4f,0xba,0x75,0x5e,0xcb,0xc3,0x6e,0x48,0x79,0x8f
//
};

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

void print_dec(u8 s[],u32 size, u32 nb_per_line)
{
    if(size>1)
        printf("%s\n",s);
    for(u32 i = 0; i < size; i++)
    {
        printf("%03d", s[i]);
        if(i+1<size)
            printf(", ");

        if((i+1)%nb_per_line==0)
            printf("\n");
    }
}

void Forward(u8 input_[32],u8 output_[32],u8 confusion_[512],u32 diffusion_[32])
{
    for(u32 i=0;i<256;i++)
    {
        for(u8 j=0;j<32;j++)
        {
            output_[j]=confusion_[input_[j]];
            input_[j]=0;
        }
        for(u8 j=0;j<32;j++)
            for(u8 k=0;k<32;k++)
                input_[j]^=output_[k]*((diffusion_[j]>>k)&1);
    }
    for(u8 i=0;i<16;i++)
        output_[i]=confusion_[input_[i*2]]^confusion_[input_[i*2+1]+256];
}

bool Backward(u8 demanded_input[32], u8 target[16], u32 i)
{
    u8 output_[32];
    u8 found_num[32];
    if(i == 256)
        return false;

    //printf("i == %d\n", i);
    for(u8 j=0;j<32;j++)
    {
        output_[j]=0;
        for(u8 k=0;k<32;k++)
            output_[j]^=demanded_input[k]*((diffusion[j]>>k)&1);
    }

    for(u8 j=0;j<32;j++)
        if(output_[j] == 15  || output_[j] == 17  || output_[j] == 32  || output_[j] == 62
        || output_[j] == 68  || output_[j] == 90  || output_[j] == 107 || output_[j] == 117
        || output_[j] == 128 || output_[j] == 158 || output_[j] == 175 || output_[j] == 177
        || output_[j] == 203 || output_[j] == 213 || output_[j] == 228 || output_[j] == 250)
            return false;

    u8 found_two_total = 0;
    for(u8 j = 0; j < 32; j++)
    {
        found_num[j] = 0;
    }
    for(u8 j = 0; j < 32; j++)
        for(u32 k = 0; k < 256; k++)
            if(output_[j] == confusion[k])
                found_num[j]++;
    

    for(u8 j = 0; j < 32; j++)
        if(found_num[j]==2)
            found_two_total++;

    
    u8 found[found_two_total][2];


    for(u8 j = 0; j < found_two_total; j++)
        for(u8 k = 0; k < 2; k++)
            found[j][k]=0;

    u8 num_found_two = 0;
    for(u8 j = 0; j < 32; j++)
    {
        if(found_num[j]==2)
        {
            u8 num_found_two0 = 0;
            for(u32 k = 0; k < 256; k++)
            {
                if(output_[j] == confusion[k])
                {
                    found[num_found_two][num_found_two0]=k;
                    num_found_two0++;
                }
            }
            num_found_two++;
        }
        if(found_num[j]==1)
            for(u32 k = 0; k < 256; k++)
                if(output_[j] == confusion[k])
                    demanded_input[j] = k;
    }

    //printf("found_two_total = %d\n", (int) pow((double) 2, (double) found_two_total));
    u64 power = pow((double) 2, (double) found_two_total);
    u8 demanded_input0[32];
    if(power>1)
    {
        for(u64 i1 = 0; i1 < power; i1++)
        {
            num_found_two = 0;
            memcpy(demanded_input0, demanded_input, 32);
            for(u8 j = 0; j < 32; j++)
            {
                if(found_num[j]==2)
                {
                    //printf("%d -> %ld -> %d: %ld\n", i, i1, j, (i1>>num_found_two)&1);
                    if((i1>>num_found_two)&1)
                        demanded_input[j] = found[num_found_two][1];
                    else
                        demanded_input[j] = found[num_found_two][0];
                    num_found_two++;
                }
            }
            if(Backward(demanded_input, target, i+1))
                return true;
            memcpy(demanded_input, demanded_input0, 32);
        }
    }
    else
    {
        memcpy(demanded_input0, demanded_input, 32);
        if(Backward(demanded_input, target, i+1))
            return true;
        memcpy(demanded_input, demanded_input0, 32);

    }

    if(i == 255)
    {
        u8 output0_[32];
        memcpy(demanded_input0, demanded_input, 32);
        Forward(demanded_input0, output0_, confusion, diffusion);
        if(memcmp(output0_, target, 16)==0)
        {
            //print_dec(demanded_input, 32, 8);
            return true;
        }
    }
    return false;
}

bool coherant_string(u8 str[], u32 size)
{
    for(u32 i = 0; i < size; i++)
    {
        if(str[i]< 31 || str[i]>127)
        {
            if(str[i]==0)
            {
                if(i==0)
                    return false;
                return true;
            }
            else
                return false;
        }
    }
    return false;
}

void all_input_combinaisons(u8 demanded_input[32], u8 target[16], u8 gen_mode, u128 gen_input_num)
{
    u32 found2;
    u32 found1=0;
    bool coherant;
    u8 all_pairs[16][256][2];
    for(u8 i = 0; i < 16; i++)
    {
        found2 = 0;
        for(u32 k = 0; k < 256; k++)
        {
            for(u32 j = 256; j < 512; j++)
            {
                if((confusion[k]^confusion[j]) == target[i])
                {
                    all_pairs[i][found2][0] = k;
                    all_pairs[i][found2][1] = j-256;
                    found2++;
                    found1++;
                }
            }
        }
    }
    u128 iterration = 0;
    //printf("All pairs computed!\n");
    for(u32 j0 = 0; j0 < 256; j0++)
    {
        //printf("j0 = %d\n", j0);
        for(u32 j1 = 0; j1 < 256; j1++)
        {
        //printf("j1 = %d\n", j1);
        for(u32 j2 = 0; j2 < 256; j2++)
        {
        //printf("j2 = %d\n", j2);
        for(u32 j3 = 0; j3 < 256; j3++)
        {
        //printf("j3 = %d\n", j3);
        for(u32 j4 = 0; j4 < 256; j4++)
        {
        //printf("j4 = %d\n", j4);
        for(u32 j5 = 0; j5 < 256; j5++)
        {
        //printf("j5 = %d\n", j5);
        for(u32 j6 = 0; j6 < 256; j6++)
        {
        //printf("j6 = %d\n", j6);
        for(u32 j7 = 0; j7 < 256; j7++)
        {
        //printf("j7 = %d\n", j7);
        for(u32 j8 = 0; j8 < 256; j8++)
        {
        //printf("j8 = %d\n", j8);
        for(u32 j9 = 0; j9 < 256; j9++)
        {
        //printf("j9 = %d\n", j9);
        for(u32 j10 = 0; j10 < 256; j10++)
        {
        //printf("j10 = %d\n", j10);
        for(u32 j11 = 0; j11 < 256; j11++)
        {
        //printf("j11 = %d\n", j11);
        for(u32 j12 = 0; j12 < 256; j12++)
        {
        //printf("j12 = %d\n", j12);
        for(u32 j13 = 0; j13 < 256; j13++)
        {
        //printf("j13 = %d\n", j13);
        for(u32 j14 = 0; j14 < 256; j14++)
        {
        //printf("j14 = %d\n", j14);
        for(u32 j15 = 0; j15 < 256; j15++)
        {
        //printf("j15 = %d\n", j15);
            demanded_input[0] = all_pairs[0][j0][0];
            demanded_input[1] = all_pairs[0][j0][1];

            demanded_input[2] = all_pairs[1][j1][0];
            demanded_input[3] = all_pairs[1][j1][1];

            demanded_input[4] = all_pairs[2][j2][0];
            demanded_input[5] = all_pairs[2][j2][1];

            demanded_input[6] = all_pairs[3][j3][0];
            demanded_input[7] = all_pairs[3][j3][1];

            demanded_input[8] = all_pairs[4][j4][0];
            demanded_input[9] = all_pairs[4][j4][1];

            demanded_input[10] = all_pairs[5][j5][0];
            demanded_input[11] = all_pairs[5][j5][1];

            demanded_input[12] = all_pairs[6][j6][0];
            demanded_input[13] = all_pairs[6][j6][1];

            demanded_input[14] = all_pairs[7][j7][0];
            demanded_input[15] = all_pairs[7][j7][1];

            demanded_input[16] = all_pairs[8][j8][0];
            demanded_input[17] = all_pairs[8][j8][1];

            demanded_input[18] = all_pairs[9][j9][0];
            demanded_input[19] = all_pairs[9][j9][1];

            demanded_input[20] = all_pairs[10][j10][0];
            demanded_input[21] = all_pairs[10][j10][1];

            demanded_input[22] = all_pairs[11][j11][0];
            demanded_input[23] = all_pairs[11][j11][1];

            demanded_input[24] = all_pairs[12][j12][0];
            demanded_input[25] = all_pairs[12][j12][1];

            demanded_input[26] = all_pairs[13][j13][0];
            demanded_input[27] = all_pairs[13][j13][1];

            demanded_input[28] = all_pairs[14][j14][0];
            demanded_input[29] = all_pairs[14][j14][1];

            demanded_input[30] = all_pairs[15][j15][0];
            demanded_input[31] = all_pairs[15][j15][1];
            if(Backward(demanded_input, target, 0))
            {
                coherant = coherant_string(demanded_input, 32);
                if(gen_mode == 'C' || gen_mode == 'A')
                {
                    if(coherant)
                    {
                        iterration++;
                        printf("Input Found Number = ");
                        printu128(iterration);
                        printf(";\n");
                        printf("===================================================\n");
                        printf("FOUND A COHERRANT!!!!!!!!!!!!\n");
                        print_dec(demanded_input, 32, 8);
                        printf("FOUND A COHERRANT!!!!!!!!!!!!\n");
                        printf("===================================================\n");
                    }
                }
                if(gen_mode == 'N' || gen_mode == 'A')
                {
                    if(!coherant)
                    {
                        iterration++;
                        printf("Input Found Number = ");
                        printu128(iterration);
                        printf(";\n");
                        print_dec(demanded_input, 32, 8);
                    }
                }

                if(iterration == gen_input_num)
                    return;
            }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
    }
    
}
/*
The solutions to this challenge belong to different levels :

Level 1 : an iterative algorithm which typically takes more than a second to
find a solution (for any given output).

Most people stop here, which is fine, but if you want to go further, there is :

Level 2 : a non-iterative algorithm which typically takes less than a
millisecond to find a solution (for any given output).

Few people have reached this level. But if you want to beat it completely,
there's yet another castle...

Level 3 : an algorithm which can provide any of the 2^128 solutions (for any
given output).

Even fewer people have reached this final level. Congratulations to them!

*/
int compare(const void* num1, const void* num2) // comparing function  
{  
    u8 a = *(u8*) num1;  
    u8 b = *(u8*) num2;  
    if(a > b)  
    {  
        return 1;  
    }  
    else if(a < b)  
    {  
        return -1;  
    }  
    return 0;  
}
#define err_target "<target> Must be at least 16 chars long (the first 0x00 must be at least at the 16th char).\n"
#define err_generate_mode "<Input_Generate_Mode> Can Be only 'A', 'C' or 'N'.\n"
#define err_input_num "<number_of_input> Must be positif and up to unsigned __int128 Max.\n"
#define error_input "The command must be executed like so :\n"\
    "    ./HireMe <target> <Input_Generate_Mode> <number_of_input>\n"\
    "Where :\n"\
    "\t<target> Is the target whanted to be generated by the Forward function must be at least 16 chars long\n"\
    "\t\t   (the first 0x00 must be at least at the 16th char).\n"\
    "\t<Input_Generate_Mode> Can Be only one of the following :\n"\
    "\t\t- A : All inputs.\n"\
    "\t\t- C : Coherents inputs only\n"\
    "\t\t\t  (start with only coherents alphanumeric ascii letter and ends with a 0x00 (at or before the 32th char)).\n"\
    "\t\t- N : Non coherents inputs only.\n"\
    "\t<number_of_input> The number of generated input wanted (up to unsigned __int128 Max) must be positif.\n"

u32 verif_len_target(const char *s, u8 ret[16])
{
    u32 l = strlen(s);
    if(l < 15)
    {
        printf(err_target);
        exit(1);
    }
    for(u8 i = 0; i < 16; i++)
        ret[i] = (u8) s[i];
    return l;
}

u8 verif_gen_mode(const char *s)
{
    if(strlen(s) > 1)
    {
        printf(err_generate_mode);
        exit(1);
    }
    const char c = *s;
    if(c != 'A' && c != 'C' && c != 'N'
    && c != 'a' && c != 'c' && c != 'n')
    {
        printf(err_generate_mode);
        exit(1);
    }
    u8 out = c;
    if(c == 'a')
        out = 'A';
    if(c == 'c')
        out = 'C';
    if(c == 'n')
        out = 'N';

    return out;
}

u128 atou128(const char *s)
{
    const char *p = s;
    
    while((*p == '\n') || (*p == '\t') || (*p == ' ')
       || (*p == '\f') || (*p == '\r') || (*p == '\v')
       || (*p == '0'))
        p++;
    
    if(*p < '0' || *p > '9')
    {
        printf(err_input_num);
        exit(1);
    }
    const char *start_num  = p;
    u32 nb_iter = 0;
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
int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        printf(error_input);
        exit(1);
    }
    u8 target[16];
    verif_len_target(argv[1], target);
    u8 gen_mode = verif_gen_mode(argv[2]);
    u128 gen_input_num = atou128(argv[3]);
    u8 input_generated[32];
    u8 output[32];
    //u8 output_test[32];
    all_input_combinaisons(input_generated, target, gen_mode, gen_input_num);
    //print_dec(input_generated, 32, 8);
    
    Forward(input_generated, output, confusion, diffusion);
    //print_dec(input, 32, 8);
    //printf("%d\n",Backward(input, output, 0));
    //Forward(input, output, confusion, diffusion);
    //memcpy(output, input, 32);
    //print_dec(input, 32, 8);
    //Forward(input,output,confusion,diffusion);
    //print_dec(output, 32, 8);
    return memcmp(output,target,16); // => contact apply(at)nerd.nintendo.com
}
