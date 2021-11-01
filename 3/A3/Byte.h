#ifndef BYTE
#define BYTE

class Byte
{
    private:
        int bits[8];
        int bitsToInt();
    public:
        void setValue(int value);
        int at(int index);
        std::string toString();
        int toInt();

        Byte add(int num);
        Byte sub(int num);
        Byte mul(int num);
        Byte div(int num);

        // Constructors

        Byte();
        Byte(int val);
        Byte(int ar[]);
};

#endif