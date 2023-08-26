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
#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))

#define bitsetclear(byte,nbit,bit)   ((bit) == 0 ? (bitclear((byte),(nbit))) : (bitset(byte,nbit)))
#define bitsetclearcheck(byte1,n1bit,byte2,n2bit) (bitsetclear((byte1),(n1bit),bitcheck((byte2),(n2bit))))

u32* encode(u32 *a, u32 size)
{
    u32* b = new u32[size / 16]; // <- output tab

    for (u32 i = 0; i < size / 16; i++)
        b[i] = 0;

    for (u32 i = 0; i < size; i++)
        for (u32 j = 0; j < size; j++)
        {
            b[(i + j) / 32] ^= ( (a[i / 32] >> (i % 32)) & (a[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);   // Magic centaurian operation
            cout << "i = " << setfill('0') << setw(2) << i << "; j = " << setfill('0') << setw(2) << j << "; b[" << dec << (i+j)/32 << "] = " << (std::bitset<32>(b[(i + j) / 32])) << ";" << endl;
        }
    return b;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.-------------------
 **/

u32* decode(u32 *b, u32 size)
{

    u32* a = new u32[size / 16];

    for(u32 i = 0; i < size / 16; ++i)
    {
        a[i] = 0;
    }
    // u32* b_prev = new u32[size / 16];
    
    // for (u32 i = 0; i < size / 16; i++)
    //     b_prev[i] = b[i];

    for (int i = size-1; i >= 0; i--)
        for (int j = size-1; j >= 0; j--)
        {
            bitsetclearcheck(a[0],31,b[0],30);
            bitsetclearcheck(a[size/32],31,b[size/32],30);
            bitsetclearcheck(a[0],0,b[0],0);
            bitsetclearcheck(a[size/32],0,b[0],0);
            bitflip(b[size/32], 30);
        }
    //bitsetclear(a1[0],1,1);
    //bitsetclear(a2[0],1,0);
    return a;
}

int main()
{
    u32 count[16][32];
    u32 size;
    size = 32;
    // size = 64;
    // size = 128;
    // size = 256;
    cout << "SIZE = " << size << " :" << endl;
    for(u32 i = 0; i < size / 16; ++i)
        for (u32 j = 0; j < 32; j++)
            count[i][j] = 0;
    for (u32 i = 0; i < size; i++)
        for (u32 j = 0; j < size; j++)
            count[(i+j)/32][(i+j)%32]++;
    
    for (u32 i = 0; i < size / 16; i++)
        for (u32 j = 0; j < 32; j++)
            cout << "b[" << i << "][" << setfill('0') << setw(2) << j << "] = " << setfill('0') << setw(2) << count[i][j] << ";" << endl;
    cout << endl;

    u32 s = 32;
    // cin >> s; cin.ignore();
    istringstream convertera("46508fb7 6677e201");
    u32* b = new u32[s / 16];
    cout << "INPUT : " << endl;
    for(u32 i = 0; i < s / 16; i++)
    {
        convertera >> hex >> b[i];
        cout << setfill('0') << setw(8) << hex << b[i] << dec << " : " << (std::bitset<32>(b[i])) << ";" << endl;
    }
    cout << endl;

    cout << "OUTPUT : " << endl;
    u32* a = decode(b, s);
    for(u32 i = 0; i < s / 16; i++)
        cout << setfill('0') << setw(8) << hex << a[i] << dec << " : " << (std::bitset<32>(a[i])) << ";" << endl;
    cout << endl;

    istringstream converterc("b0c152f9 ebf2831f");
    u32* c = new u32[2];
    cout << "OUTPUT GOAL : " << endl;
    for(u32 i = 0; i < s / 16; i++)
    {
        converterc >> hex >> c[i];
        cout << setfill('0') << setw(8) << hex << c[i] << dec << " : " << (std::bitset<32>(c[i])) << ";" << endl;
    }
    encode(c, 32);
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "ANSWER" << endl;
}