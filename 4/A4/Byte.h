#ifndef BYTE
#define BYTE

class Byte
{
    private:
        std::vector <int> bits;
        int bitsToInt();
    public:
        void setValue(int value);
        int at(int index);
        std::string toString();
        int toInt();

        Byte add(int num);
        Byte add(Byte byte);
        Byte sub(int num);
        Byte sub(Byte byte);
        Byte mul(int num);
        Byte mul(Byte byte);
        Byte div(int num);
        Byte div(Byte byte);

        // Constructors

        Byte();
        Byte(int val);
        Byte(vector <int> ar);
};

#endif