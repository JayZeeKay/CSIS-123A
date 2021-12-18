#include <exception>

#ifndef CHECKEDARRAY
#define CHECKEDARRAY

using std::string;
using std::exception;

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
        //int at(int index) const;
        void set(int index, int value);
        //int operator[](int index);

        virtual int at(int index) const;
        virtual int operator[](const int index);
        virtual std::string toString();
};

class CheckedArrayException : public std::exception 
{
    private:
        std::string message;
    public:
        // Constructors
        CheckedArrayException() : message("Undefined error") {};
        CheckedArrayException(std::string msg) : message(msg) {};

        virtual const char *what() { return message.c_str(); }
};

#endif