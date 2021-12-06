#ifndef CHECKEDARRAY
#define CHECKEDARRAY

class CheckedArray
{
    private:
        int* ar;
    public:
        int size;

        CheckedArray();
        CheckedArray(int size);

        ~CheckedArray();
        bool initialize(int size, int val = 0);
        int at(int index) const;
        void set(int index, int value);
        int operator[](int index);
};

#endif