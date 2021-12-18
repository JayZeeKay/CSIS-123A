#ifndef CHECKEDARRAY
#define CHECKEDARRAY

#include <exception>

using std::string;
using std::exception;
using std::cout;
using std::endl;

// Moved CheckedArray.cpp code into this header file

namespace jacob
{
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

    template <class T>
    class CheckedArray
    {
        private:
            T* ar;
        public:
            int size;

            CheckedArray();
            CheckedArray(T size);

            ~CheckedArray();

            bool initialize(int size, int val = 0);

            void set(int index, int value);
            //int operator[](int index);

            T at(T index) const;
            virtual T operator[](const T index);
            virtual std::string toString();
    };

    template <class T>
    CheckedArray<T>::CheckedArray()
    {
        initialize(10);
    }

    template <class T>
    CheckedArray<T>::CheckedArray(T size)
    {
        initialize(size);
    }

    template <class T>
    CheckedArray<T>::~CheckedArray()
    {
        if (this->ar != NULL)
        {
            this->ar = NULL;
            this->size = 0;
        }

        cout << "CheckedArray deleted" << endl;
    }

    template <class T>
    bool CheckedArray<T>::initialize(int size, int val)
    {
        try 
        {
            this->ar = new T[size]; // Changed array from int to T
        }
        catch (CheckedArrayException cae)
        {
            throw CheckedArrayException("Unable to allocate memory");
        }
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            this->ar[size] = val;
        }
        return true;
    }

    template <class T>
    void CheckedArray<T>::set(int index, int value)
    {
        if (index > size || index < 0 || this->ar == NULL)
            throw CheckedArrayException("Index out of bounds");
        this->ar[index] = value;
    }

    template <class T>
    T CheckedArray<T>::operator[](const T index)
    {
        return this->at(index);
    }

    template <class T>
    std::string CheckedArray<T>::toString()
    {
        string arrayString = "";
        for (int i = 0; i <= 7; i++)
        {
                //cout << "ar " << i << ": " << ar[i] << endl;
            if (ar[i])
                arrayString[i] = '1';
            else
                arrayString[i] = '0';
        }
        return arrayString;
    }

    template <class T>
    T CheckedArray<T>::at(T index) const
    {
        if (index > size || index < 0 || this->ar == NULL)
            throw CheckedArrayException("Index out of bounds");
        //cout << "index: " << index << endl;
        //cout << "ar[index]: " << ar[index] << endl;
        return ar[index];
    }
}

#endif