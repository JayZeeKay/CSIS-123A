#include <iostream>
#include <string>
#include "Byte.h"

using namespace std;

void Byte::setValue(int value)
{
    int tmp = 1;
    for (int i = 0; i <= 7; i++)
    {
        // Checking to see if the bit in the value and the bit in tmp are both 1
        // tmp starts at 00000001 and is left shifted, increasing by powers of two
        if (value & tmp)
            bits[i] = 1;
        else
            bits[i] = 0;
        tmp = tmp << 1;
    }
}

int Byte::bitsToInt()
{
    int tmp = 0;
    int binaryPow = 1;
    for (int i = 0; i <= 7; i++)
    {
        if (bits[i])
            tmp += binaryPow;
        binaryPow *= 2;    // Number used to sum decimal number, as each digit higher in binary is multiplying by 2
    }
    return tmp;
}

int Byte::at(int index)
{
    return bits[index];
}

int Byte::toInt()
{
    return bitsToInt();
}

std::string Byte::toString()
{
    string byteString = "00000000";
    for (int i = 7; i >= 0; i--)
    {
        if (bits[i])
            byteString[7-i] = '1';
        else
            byteString[7-i] = '0';
    }
    return byteString;
}