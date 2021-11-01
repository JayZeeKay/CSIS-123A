#include <iostream>
#include <string>
#include <vector>
#include "Byte.h"

using namespace std;

//Default constructor
Byte::Byte()
    //:Byte(0)
{
    setValue(0);
}

// Working constructor 
Byte::Byte(int val)
{
    bits.resize(8);
    setValue(val);
}

Byte::Byte(std::vector <int> ar)
{
    bits.resize(8, 0);
    for (int i = 0; i <= 7; i++)
    {
        this->bits[i] = ar[i];
    }
}

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

Byte Byte::add(int num)
{
    Byte sum(this->bitsToInt() + num);
    return sum;
}

Byte Byte::add(Byte byte)
{
    Byte sum(this->bitsToInt() + byte.bitsToInt());
    return sum;
}

Byte Byte::sub(int num)
{
    Byte difference(this->bitsToInt() - num);
    return difference;
}

Byte Byte::sub(Byte byte)
{
    Byte difference(this->bitsToInt() - byte.bitsToInt());
    return difference;
}

Byte Byte::mul(int num)
{
    Byte product(this->bitsToInt() * num);
    return product;
}

Byte Byte::mul(Byte byte)
{
    Byte product(this->bitsToInt() * byte.bitsToInt());
    return product;
}

Byte Byte::div(int num)
{
    // Decimal part gets removed since its integer division, Byte class only stores whole numbers
    Byte quotient(this->bitsToInt() / num);
    return quotient;
}

Byte Byte::div(Byte byte)
{
    Byte quotient(this->bitsToInt() / byte.bitsToInt());
    return quotient;
}
