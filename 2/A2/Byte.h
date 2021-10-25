#ifndef BYTE
#define BYTE

class Byte
{
    private:
        int bits[7];
        int bitsToInt();
    public:
        void setValue(int value);
        int at(int index);
        std::string toString();
        int toInt();
};

#endif