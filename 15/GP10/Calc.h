#ifndef CALC
#define CALC
#include <exception>
#include <string>

using std::string;

class calcException : public std::exception
{
    private:
        string message;
    public:
        calcException(string msg) : message(msg) {};
        const char *what() { return message.c_str(); }
};

template <class T>
class Calc
{
    private:
        T x, y;
    public:
        Calc() { x = 0, y = 0; }
        Calc(T a, T b) { x = a; y = b; }

        T add();
        T sub();
        T mul();
        T div();
};

template <class T>
T Calc<T>::add()
{   
    return this->x + this->y;
}

template <class T>
T Calc<T>::sub()
{   
    return this->x - this->y;
}

template <class T>
T Calc<T>::mul()
{   
    return this->x * this->y;
}

template <class T>
T Calc<T>::div()
{   
    if (y == 0)
        throw (calcException("Can't divide by zero"));
    return this->x / this->y;
}

#endif