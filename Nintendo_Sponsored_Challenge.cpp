#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <bitset>

using namespace std;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef uint64_t u64;
typedef unsigned __int128 u128;

stringstream s0;
u32* decode(u32 *b, u32 size)
{

    u32* a = new u32[size / 16];

    for(u32 i = 0; i < size / 16; ++i)
        a[i] = 0;//xffffffff;
    u32* b_prev = new u32[size / 16];
    
    for (u32 i = 0; i < size / 16; i++)
        b_prev[i] = b[i];

    // for (int i = size-1; i >= 0; i--)
    //     for (int j = size-1; j >= 0; j--)
    for (u32 i = 0; i < size; i++)
        for (u32 j = 0; j < size; j++)
        {
            if((b_prev[(i + j) / 32] >> ((i+j) % 32)) & 1)
            {
                a[i / 32] |= 1 << (i % 32);
                a[j / 32 + size / 32] |= 1 << (j % 32);
                b_prev[(i + j) / 32] ^= 1 << ((i+j) % 32);
            }
        }
    return a;
}

u32* encode(u32 *a, u32 size)
{
    u32* b = new u32[size / 16]; // <- output tab

    for (u32 i = 0; i < size / 16; i++)
    {   // Write size / 16 zeros to b
        b[i] = 0;
    }

    for (u32 i = 0; i < size; i++)
        for (u32 j = 0; j < size; j++)
        {
            b[(i + j) / 32] ^= ( (a[i / 32] >> (i % 32)) & (a[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);   // Magic centaurian operation
            // if(i == 31 && j == 31)
            //     cout << "i = " << setfill('0') << setw(2) << i << "; j = " << setfill('0') << setw(2) << j << "; b[" << dec << (i+j)/32 << "] = " << (std::bitset<32>(b[(i + j) / 32])) << ";" << endl;
        }
    for(u32 i = 0; i < size / 16; i++)
    {
        if (i > 0)
        {
            s0 << ' ';
        }
        s0 << setfill('0') << setw(8) << hex << b[i];       // print result
    }
    s0 << endl;

    /* 
    Good luck humans     
    */
    return b;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    u32 s = 32;
    // cin >> s; cin.ignore();
    string word1 = "46508fb7";
    string word2 = "6677e201";
    istringstream converter1(word1);
    istringstream converter2(word2);
    u32* b = new u32[2];
    converter1 >> hex >> b[0];
    converter2 >> hex >> b[1];

    u32* a = decode(b, s);
    for(u32 i = 0; i < s / 16; i++)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << setfill('0') << setw(8) << hex << a[i];       // print result
    }
    cout << endl;
    //cout << s0.str();
    cout << "b 0 : " << (std::bitset<32>(a[0])) << ";" << endl;
    cout << "b 1 : " << (std::bitset<32>(a[1])) << ";" << endl;
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "ANSWER" << endl;
}