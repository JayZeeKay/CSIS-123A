#ifndef BYTE
#define BYTE

#include <vector>

using std::istream;
using std::ostream;

class Byte
{
    private:
        std::vector <int> bits;
        int bitsToInt() const;
    public:
        void setValue(int value);
        int at(int index);
        std::string toString();
        int toInt();

        Byte add(int num);
        Byte add(const Byte &byte);
        Byte sub(int num);
        Byte sub(const Byte &byte);
        Byte mul(int num);
        Byte mul(const Byte &byte);
        Byte div(int num);
        Byte div(const Byte &byte);

        // Constructors

        Byte();
        Byte(int val);
        Byte(std::vector <int> ar);

        // Operator Overloads

        Byte operator +(const Byte &b);
        Byte operator -(const Byte &b);
        Byte operator *(const Byte &b);
        Byte operator /(const Byte &b);
        Byte &operator =(const Byte &b);
        bool operator ==(const Byte &b);
        bool operator !=(const Byte &b);
        int operator [](const int index);

        // Friend functions

        friend istream &operator >>(istream &input, Byte &b);
        friend ostream &operator <<(ostream &output, Byte &b);
};

#endif