#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef uint64_t u64;
typedef unsigned __int128 u128;

stringstream s;
u32* decode(u32 *b, u32 size)
{
    u32* a = new u32[size / 16];
    ( (a[0] >> (31)) & (a[0 + size / 32] >> 0) & 1 ) << (31)
    ^ ( (a[0] >> (30)) & (a[0 + size / 32] >> 1) & 1 ) << (31)
    ^ ( (a[0] >> (30)) & (a[0 + size / 32] >> 0) & 1 ) << (30);

    for (u32 i = 0; i < size / 16; i++)
        a[i] = 0;
    
    (a[0] & a[size/32]) & 1;
    for (u32 i = 0; i < size; i++)
        for (u32 j = 0; j < size; j++)
            for(u8 k = 0; k < 32; k++)
            {
                if((b[(i+j)/32]>>k)&1)
                    a[i/32]&=(1<<k);
            }
    return a;
}
u32* encode(unsigned int *a, unsigned int size)
{
    u32* b = new u32[size / 16]; // <- output tab

    for (int i = 0; i < size / 16; i++)
    {   // Write size / 16 zeros to b
        b[i] = 0;
    }

    for (u32 i = 0; i < size; i++)
        for (u32 j = 0; j < size; j++)
        {
            b[(i + j) / 32] ^= ( (a[i / 32] >> (i % 32)) &
            (a[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);   // Magic centaurian operation
        }

    for(u32 i = 0; i < size / 16; i++)
    {
        if (i > 0)
        {
            s << ' ';
        }
        s << setfill('0') << setw(8) << hex << b[i];       // print result
    }
    s << endl;

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
    u32 s;
    cin >> s; cin.ignore();
    string word;
    unsigned int* b = new unsigned int[s / 16];
    for(u32 i = 0; i < s; i++)
    {
        cin >> word;
        istringstream converter(word);
        converter >> hex >> b[i];
    }


    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "ANSWER" << endl;
}