#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
/*
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <climits>
*/
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef uint64_t u64;
typedef unsigned __int128 u128;
/*
15
17
32
62
68
90
107
117
128
158
175
177
203
213
228
250
x[0]^x[7]^x[10]^x[12]^x[13]^x[15]^x[18]^x[19]^x[21]^x[22]^x[25]^x[28]^x[29]^x[30]^x[31] !=

00001111
00010001
00100000
00111110
01000100
01011010
01101011
01110101
10000000
11001011
11010101
11100100
11111010


printf("j0 = %d; j1 = %d; j2 = %d; j3 = %d; j4 = %d; j5 = %d; j6 = %d; j7 = %d;\n"
       "j8 = %d; j9 = %d; j10 = %d; j11 = %d; j12 = %d; j13 = %d; j14 = %d; j15 = %d;\n",
       j0, j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j11, j12, j13, j14, j15);
printf("Itteration Number = %d;\n",
        (j0+1)*(j1+1)*(j2+1)*(j3+1)*(j4+1)*(j5+1)*(j6+1)*(j7+1)*(j8+1)*(j9+1)*(j10+1)*(j11+1)*(j12+1)*(j13+1)*(j14+1)*(j15+1)-1);
*/

/*
void print_u8(u8 ar[], int siz_ar, int number_per_line)
{
    std::stringstream out0;
    std::stringstream out1;
    std::stringstream out2;
    for (int i = 0; i < siz_ar; ++i)
    {
        out0 << std::setfill('0') << std::setw(3) << (int) ar[i];
        if(i+1!=siz_ar)
        {
            if((i+1)%number_per_line == 0)
                out0 << std::endl;
            else 
                out0 << "      ";
        }
    }
    std::stringstream a;
    a << std::hex;
    for (int i = 0; i < siz_ar; ++i)
    {
        a << std::setfill('0') << std::setw(2) << (int) ar[i];
        if(i+1!=siz_ar)
        {
            if((i+1)%number_per_line == 0)
                a << std::endl;
            else 
                a << " ";
        }
    }
    a << std::dec << std::endl;
    for(char b : a.str())
    {
        if(b != ' ' && b != '\n')
            out1 << "   " << b;
        else
            out1 << b;
    }

    for (int i = 0; i < siz_ar; ++i)
    {
        out2 << std::bitset<8>(ar[i]);
        if(i+1!=siz_ar)
        {
            if((i+1)%number_per_line == 0)
                out2 << std::endl;
            else if(i+1!=siz_ar)
                out2 << " ";
        }
    }
    out2 << std::endl;
    if(siz_ar/number_per_line > 0)
    {
        std::cout << std::endl;
        for(int i = 0; i < siz_ar/number_per_line; i++)
        {
            std::string str0, str1, str2;
            std::getline(out0, str0, '\n');
            std::getline(out1, str1, '\n');
            std::getline(out2, str2, '\n');
            std::cout << str0 << std::endl;
            std::cout << str1 << std::endl;
            std::cout << str2 << std::endl;
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << out0.str() << std::endl;
        std::cout << out1.str() << std::endl;
        std::cout << out2.str() << std::endl;
    }
}

void print_u32(u32 ar[], int siz_ar, int number_per_line)
{
    std::stringstream out0;
    std::stringstream out1;
    std::stringstream out2;
    for (int i = 0; i < siz_ar; ++i)
    {
        out0 << std::setfill('0') << std::setw(10) << ar[i];
        if(i+1!=siz_ar)
        {
            if((i+1)%number_per_line == 0)
                out0 << std::endl;
            else 
                out0 << "                       ";
        }
    }
    std::stringstream a;
    a << std::hex;
    for (int i = 0; i < siz_ar; ++i)
    {
        a << std::setfill('0') << std::setw(8) << ar[i];
        if(i+1!=siz_ar)
        {
            if((i+1)%number_per_line == 0)
                a << std::endl;
            else 
                a << " ";
        }
    }
    a << std::dec << std::endl;
    for(char b : a.str())
    {
        if(b != ' ' && b != '\n')
            out1 << "   " << b;
        else
            out1 << b;
    }

    for (int i = 0; i < siz_ar; ++i)
    {
        out2 << std::bitset<32>(ar[i]);
        if(i+1!=siz_ar)
        {
            if((i+1)%number_per_line == 0)
                out2 << std::endl;
            else if(i+1!=siz_ar)
                out2 << " ";
        }
    }
    out2 << std::endl;
    if(siz_ar/number_per_line > 0)
    {
        std::cout << std::endl;
        for(int i = 0; i < siz_ar/number_per_line; i++)
        {
            std::string str0, str1, str2;
            std::getline(out0, str0, '\n');
            std::getline(out1, str1, '\n');
            std::getline(out2, str2, '\n');
            std::cout << str0 << std::endl;
            std::cout << str1 << std::endl;
            std::cout << str2 << std::endl;
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << out0.str() << std::endl;
        std::cout << out1.str() << std::endl;
        std::cout << out2.str() << std::endl;
    }
}
*/
u8 all_special_k[16][2] =
{
    {55, 64},{24, 94},{83, 113},{36, 124},
    {21, 151},{6, 154},{137, 171},{41, 181},
    {11, 194},{184, 207},{77, 209},{132, 220},
    {166, 224},{111, 237},{58, 243},{98, 254}
};
bool is_special_k(u32 k)
{
    if(k == 55 || k == 64 || k == 24 || k == 94 || k == 83 || k == 113 || k == 36
    || k == 124 || k == 21 || k == 151 || k == 6 || k == 154 || k == 137 || k == 171
    || k == 41 || k == 181 || k == 11 || k == 194 || k == 184 || k == 207 || k == 77
    || k == 209 || k == 132 || k == 220 || k == 166 || k == 224 || k == 111
    || k == 237 || k == 58 || k == 243 || k == 98 || k == 254)
        return true;
    return false;
}
/*
unsigned long long i00 = 0; 
int Backward_rec(u8 input_[32],u8 output_[32], u8 target[16], u32 i)
{
    u32 i0 = i;
    for(; i < 256; i++)
    {
        for(u8 j=0;j<16;j++)
            output_[j]=0;

        for(u8 j=0;j<16;j++)
            for(u8 k=0;k<32;k++)
                output_[j]^=input_[k]*((diffusion[j]>>k)&1);
        
        for(u8 j=0;j<32;j++)
        {
            for(u32 k=0;k < 256;k++)
            {
                if(output_[j] == confusion[k])
                {
                    if(!is_special_k(k))
                        input_[j]=k;
                    else
                    {
                        for(u8 l=0;l<16;l++)
                        {
                            if(all_special_k[l][0] == k)
                            {
                                input_[j]=all_special_k[l][0];
                                if(i+1 == 256)
                                {
                                    if(memcmp(output_,target,16) == 0)
                                        return true;
                                    return false;
                                }
                                if(!Backward_rec(input_, output_, target, i+1))
                                {
                                    input_[j]=all_special_k[l][1];
                                    if(!Backward_rec(input_, output_, target, i+1))
                                        return false;
                                }
                                return true;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    if(memcmp(output_,target,16) == 0)
        return true;
    if(i00%1000000==0)
    {
        printf("Output = false; num = %d; lvl = %lld;\n",i0, i00);
        printf("%s\n",output_);

//        print_u8(output, 32);
//        std::cout << std::endl;
    }
    i00++;
    return false;
}

void Backward(u8 input_[32],u8 output_[32], u8 target[16])
{
    Backward_rec(input_, output_, target, 0);
}
*/
void print_extend_ascii(u8 str[], u32 size)
{

    setlocale(LC_ALL, "");
    for (u32 a = 0; a < size; a++)
        wprintf(L"%lc", (wchar_t)str[a]);
    wprintf(L"\n");
    return;
}
void print_hex_u128(u128 x)
{
    u64 high = (x >> 64);
    char buf[] = { "18446744073709551615" };
    sprintf(buf, "%" PRIX64, high);
    printf("%s", buf);
    u64 low = (u64)x;
    sprintf(buf, "%" PRIX64, low);
    printf("%s", buf);

}
void print_hex(u8 s[],u32 size, u32 nb_per_line)
{
    printf("%s\n", s);
    for(u32 i = 0; i < size; i++)
    {
        printf("0x%02hhx,", s[i]);

        if((i+1)%nb_per_line==0)
            printf("\n");
    }
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
bool coherant_string(u8 str[], u32 size)
{
    for(u32 i = 0; i < size; i++)
    {
        if(str[i]< 31 || str[i]>127)
        {
            if(str[i]==0)
                return true;
            else
                return false;
        }
    }
    return false;
}
/*
void print_dec_u128(u128 x)
{
    u64 high = (x >> 64);
    char buf[] = { "18446744073709551615" };
    sprintf(buf, "%" PRIX64, high);
    printf("%s", buf);
    u64 low = (u64)x;
    sprintf(buf, "%" PRIX64, low);
    printf("%s", buf);

}
*/
void Forward(u8 input_[32],u8 output_[32],u8 confusion_[512],u32 diffusion_[32])
{
/*
        if((is_out = memcmp(output_,save_out[255-i], 32)) || (is_in = memcmp(input_,save_in[255-i], 32)) )
        {
            printf("i == %d\n\n",i);
            printf("Forward :\n");
            if(is_out)
            {
                printf("Output :\n");
                print_dec(output_, 32, 8);
            }
            if(is_in)
            {
                printf("Input :\n");
                print_dec(input_, 32, 8);
            }
            printf("\nBackward\n");
            if(is_out)
            {
                printf("Output :\n");
                print_dec(save_out[255-i], 32, 8);
            }
            if(is_in)
            {
                printf("Input :\n");
                print_dec(save_in[255-i], 32, 8);
            }
            return;
        }
        if(memcmp(input_,save[1+i],16))
        {
            std::cout << "Forward Input i=" << 255 - i - 1 << " : "<< std::endl;

            printf("%s\n", save[1+i]);

            print_u8(save[1+i], 32, 8);
            std::cout << std::endl;

            std::cout << "Backward Input i=" << i << " : "<< std::endl;

            printf("%s\n", input_);

            print_u8(input_, 32, 8);
            std::cout << std::endl;
            return;
        }
*/
}
bool find_output_i(u8 output_[32], u8 demanded_input[32], u8 j, u8 k0, u8 k1, u8 k2, u8 k3, u8 k4,
                   u8 k5, u8 k6, u8 k7, u8 k8, u8 k9, u8 k10, u8 k11, u8 k12, u8 k13, u8 k14)
{
    output_[j]=(((((((((((((((demanded_input[k0])^demanded_input[k1])^demanded_input[k2])^demanded_input[k3])
              ^demanded_input[k4])^demanded_input[k5])^demanded_input[k6])^demanded_input[k7])
              ^demanded_input[k8])^demanded_input[k9])^demanded_input[k10])^demanded_input[k11])
              ^demanded_input[k12])^demanded_input[k13])^demanded_input[k14]);
    if(output_[j] == 15  || output_[j] == 17  || output_[j] == 32  || output_[j] == 62
    || output_[j] == 68  || output_[j] == 90  || output_[j] == 107 || output_[j] == 117
    || output_[j] == 128 || output_[j] == 158 || output_[j] == 175 || output_[j] == 177
    || output_[j] == 203 || output_[j] == 213 || output_[j] == 228 || output_[j] == 250)
        return false;
    return true;
}
//u32 max_i = 0;
bool Backward(u8 demanded_input[32], u8 target[16], u32 i)
{
// if(i>max_i)
// {
//     max_i = i;
//     printf("i == %d\n", i);
// }
/*
    //u8 output_[32];
    //u8 output_test_[32];
    //u8 all_inputs[65536][32];
    //u8 found2;
    u64 found;
    //u128 i_gen = 0;
    for(u8 i = 0; i < 16; i++)
    {
        found = 0;
        for(u32 k = 0; k < 256; k++)
        {
            for(u32 j = 256; j < 512; j++)
            {
                if((confusion[k]^confusion[j]) == target[i])
                {
                    //printf("%c, %d, %d\n",(confusion[k]^confusion[j]), k, j);
                    //demanded_input[i*2]=k;
                    //demanded_input[i*2+1]=j-256;
                    found++;
                }
            }
        }
        printf("I=%d c=%c\n",i, target[i]);
        printf("%ld\n\n", found);
    }
    return;
    while(memcmp(output_test_, target, 16))
    {
        //print_hex(demanded_input, 32, 8);
        for(u32 i=0;i<256;i++)
        {
            //printf("\ni = %d\n", i);
            for(u8 j=0;j<32;j++)
                output_[j]=0;
            for(u8 j=0;j<32;j++)
                for(u8 k=0;k<32;k++)
                {
                output_[j]^=demanded_input[k]*((diffusion[j]>>k)&1);
                if(i==255 && j == 19)
                {
                        //print_hex(&output_[j], 1, 1);
                }
                }
            found2 = 0;
            for(u8 j=0;j<32;j++)
            {
                for(u32 k = 0; k < 256; k++)
                {
                    if(output_[j] == confusion[k])
                    {
                        demanded_input[j] = k;
                        found2++;
                        break;
                        
                    }

                }
            }
            if(found2!=32)
                break;
        }
        Forward(demanded_input, output_test_, confusion, diffusion);
        i_gen++;
    }
*/
}
void all_input_combinaisons(u8 demanded_input[32], u8 target[16])
{
    /*
    //u64 nb_pair_d=0;
    for(u8 k = 0; k < 16; k++)
    {
        printf("\nLes paires doubles %d :\n", k);
        for(u32 i = 0; i < 256; i++)
        {
            for(u32 j = 0; j < i; j++)
            {
                if(all_pairs[k][i][0] == all_pairs[k][j][0] || all_pairs[k][i][1] == all_pairs[k][j][1])
                {
                    printf("i = %d; j = %d; ",i,j);
                    if(all_pairs[k][i][0] == all_pairs[k][j][0])
                        printf("0 -> %d; ",all_pairs[k][j][0]);
                    if(all_pairs[k][i][1] == all_pairs[k][j][1])
                        printf("1 -> %d; ",all_pairs[k][j][1]);
                    printf("\n");
                }
            }
        }
    }
    */
}
/*
template<size_t n>
std::string bitset_to_string(std::bitset<n> bits){
    static_assert(n % CHAR_BIT == 0, "bitset size must be multiple of char");
    std::string toreturn;
    for(size_t j = 0; j < n/CHAR_BIT; ++j)
    {
        char next = 0;
        for(size_t i = 0; i < CHAR_BIT; ++i)
        {
            size_t index = n - (CHAR_BIT*j) - i - 1;
            size_t pos = CHAR_BIT - i - 1;
            if (bits[index])
                next |= (1 << pos); 
        }
        toreturn.push_back(next);
    }
    return toreturn;
}
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
int main()
{
    // print_extend_ascii();
    // return 1;
    /*
    u8 output_[32];
    printf("Input :\n");
    print_dec(input, 32, 8);
    for(u8 j=0;j<32;j++)
    {
        output_[j]=confusion[input[j]];
        input[j]=0;
    }
    printf("Output :\n");
    print_dec(output_, 32, 8);
    for(u8 j=0;j<32;j++)
        for(u8 k=0;k<32;k++)
            input[j]^=output_[k]*((diffusion[j]>>k)&1);
    //printf("Input2 :\n");
    //print_dec(input, 32, 8);
    for(u8 j=0;j<32;j++)
    {
        output_[j]=0;
    }
    for(u8 j=0;j<32;j++)
        for(u8 k=0;k<32;k++)
            output_[j]^=input[k]*((diffusion[j]>>k)&1);
    printf("Output2 :\n");
    print_dec(output_, 32, 8);
    return 0;
    */
    // qsort(confusion, 256, sizeof(u8), compare);

    // u32 k = 0;
    // printf("The sorted array:\n");
    // for(u32 i = 0; i < 256; i++)
    // {
    //     bool is_not_here = false;
    //     for(u32 j = 0; j < 256; j++)
    //     {
    //         if(i != confusion[j])
    //             is_not_here = true;
    //         else
    //         {
    //             is_not_here = false;
    //             break;
    //         }

    //     }
    //     if(is_not_here)
    //     {
    //         printf("%d", i);
    //         if(k < 255) // To prevent a comma(,) after the last element  
    //         {
    //             printf(", ");
    //         }  
            
    //         if((k+1)%16==0)
    //             printf("\n");
    //         k++;
    //     }
    // }
    // return 1;

    //u8 f;
    // f = 0;
    /*
    printf("void find_output_i(u8 output_[32], u8 demanded_input[32], u8 i, u8 k0, u8 k1, u8 k2, u8 k3, u8 k4,\n");
    printf("                   u8 k5, u8 k6, u8 k7, u8 k8, u8 k9, u8 k10, u8 k11, u8 k12, u8 k13, u8 k14)\n");
    printf("{\n");
    printf("    output_[i]=0;\n");
    printf("    output_[i]^=");
    for(u8 k=0;k<32;k++)
    {
        if((diffusion[0]>>k)&1)
        {
            f++;
            printf("demanded_input[k%d]", f-1);
            if(f%4==0)
            {
                printf("\n             ");
                if(k>9)
                    printf(" ");
            }
            if(f<15)
                printf("^");
        }
    }
    printf(";\n");
    printf("    if(output_[i] == 15  || output_[i] == 17  || output_[i] == 32  || output_[i] == 62\n");
    printf("    || output_[i] == 68  || output_[i] == 90  || output_[i] == 107 || output_[i] == 117\n");
    printf("    || output_[i] == 128 || output_[i] == 158 || output_[i] == 175 || output_[i] == 177\n");
    printf("    || output_[i] == 203 || output_[i] == 213 || output_[i] == 228 || output_[i] == 250)\n");
    printf("        return false;\n");
    printf("    return true;\n");
    printf("}\n");
    */
    // f = 0;
    // for(u8 i = 0; i < 32; i++)
    // {
    //     f = 0;
    //     printf("        if(!find_output_i(output_, demanded_input, %d, ", i);
    //     for(u8 k=0;k<32;k++)
    //     {
    //         if((diffusion[i]>>k)&1)
    //         {
    //             f++;
    //             printf("%d", k);
    //             if(f<15)
    //                 printf(", ");
    //         }
    //     }
    //     printf("))\n");
    //     printf("            return false;\n");
    // }
    // return 1;

/*
    std::cout << "Input n0 : "<< std::endl;

    printf("%s\n", input);

    print_u8(input, 32, 8);
    std::cout << std::endl;

    printf("Input (after) :\n");
    print_u8(input, 32);
    std::cout << std::endl;

    printf("Output :\n");
    print_u8(output, 32);
    std::cout << std::endl;

    printf("Output (string) : %s ;\n", output);
    std::cout << std::endl;
    printf("Confusion :\n");
    print_u8(confusion, 512);
    std::cout << std::endl;
    printf("Diffusion :\n");
    print_u32(diffusion, 32, 4);
    std::cout << std::endl;
    printf("Memcmp : %d ;\n", memcmp(output,target,16));
    std::cout << std::endl;
    int a = 1;
    for(u8 j=0;j<32;j++)
        for(u8 k=0;k<32;k++)
        {
            std::cout << ((diffusion[j]>>k)&1);
            if(a%64 == 0)
                std::cout << std::endl;
            else if(a%8 == 0)
                std::cout << " ";
            a++;
        }
    for(u8 j=0;j<32;j++)
    {
        output[j]=confusion[input[j]];
        input[j]=0;
    }

    std::cout << "Output n0 : "<< std::endl;
    printf("%s\n", output);
    
    print_u8(output, 32, 8);
    std::cout << std::endl;

*/
/*
    for(u8 j=0;j<32;j++)
    {
        for(u8 k=0;k<32;k++)
        {
            printf("%d",((diffusion[j]>>k)&1));
            if((k+1)%8==0)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
    */

/*
    std::cout << "Input : "<< std::endl;
    printf("%s\n", input);

    print_u8(input, 32, 8);
    std::cout << std::endl;

    for(u8 i = 0; i < 32; i++)
        test[i] = (input[i]*2 - 4)^input[i];
    std::cout << "Test : "<< std::endl;
    printf("%s\n", test);

    print_u8(test, 32, 8);
    std::cout << std::endl;
    */
/*
    Backward(output_back, target);
    Forward(output_back,output,confusion,diffusion);
*/
/*
    printf("Input TRUE :\n");
    */
    /*
    print_dec(output, 32, 8);
    printf("%d\n",memcmp(output,target,16));
*/
/*
    print_u8(output, 32, 8);
    std::cout << std::endl;
    std::cout << "Output : "<< std::endl;
    printf("%s\n", output);

    print_u8(output, 32, 8);
    std::cout << std::endl;
*/
/*
    for(u32 i = 1; i < 256; ++i)
        for(u32 j = 0; j < i; ++j)
            if(confusion[j] == confusion[i])
                std::cout << "{" << j << ", " << i << "}" << std::endl;
*/
}