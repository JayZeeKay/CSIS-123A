#include <iostream>
#include <string>
#include "Byte.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

namespace jacob
{
    //Default constructor
    Byte::Byte()
        //:Byte(0)
    {
        bits.resize(8);
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
        bits.resize(8);
        for (int i = 0; i <= 7; i++)
        {
            this->bits[i] = ar[i];
        }
    }

    // A cout to confirm that the object has been deleted

    Byte::~Byte()
    {
        std::cout << "A byte object with value " << this->toString() << " has been deleted" << std::endl;
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

    int Byte::bitsToInt() const
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
        std::string byteString = "00000000";
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

    Byte Byte::add(const Byte &byte)
    {
        Byte sum(this->bitsToInt() + byte.bitsToInt());
        return sum;
    }

    Byte Byte::sub(int num)
    {
        Byte difference(this->bitsToInt() - num);
        return difference;
    }


    Byte Byte::sub(const Byte &byte)
    {
        Byte difference(this->bitsToInt() - byte.bitsToInt());
        return difference;
    }

    Byte Byte::mul(int num)
    {
        Byte product(this->bitsToInt() * num);
        return product;
    }

    Byte Byte::mul(const Byte &byte)
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

    Byte Byte::div(const Byte &byte)
    {
        Byte quotient(this->bitsToInt() / byte.bitsToInt());
        return quotient;
    }

    // Reusing existing operator code

    Byte Byte::operator+(const Byte &b)
    {
        return this->add(b);
    }

    Byte Byte::operator-(const Byte &b)
    {
        return this->sub(b);
    }

    Byte Byte::operator*(const Byte &b)
    {
        return this->mul(b);
    }

    Byte Byte::operator/(const Byte &b)
    {
        return this->div(b);
    }

    Byte &Byte::operator=(const Byte &b)
    {
        this->setValue(b.bitsToInt());  // Assigning the value, then returning a Byte 
        return *this;
    }

    bool Byte::operator==(const Byte &b)
    {
        return this->bitsToInt() == b.bitsToInt();  // Comparing them by converting to ints
    }

    bool Byte::operator!=(const Byte &b)
    {
        return !this->operator==(b);    // Reusing == function but inverted (!)
    }

    int Byte::operator[](const int index)
    {
        return this->at(index);
    }

    /*
    // Extraction operator overload
    istream &operator >>(istream &input, Byte &b)
    {
        int bit;
        cout << "Enter a number to set the byte" << endl;
        cin >> bit;
        b.setValue(bit);

        return input;
    }

    // Insertion operator overload
    ostream &operator <<(ostream &output, Byte &b)
    {
        cout << "Int:    " << b.toInt() << endl;
        cout << "String: " << b.toString() << endl;
        return output;
    }
    */

}
