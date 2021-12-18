#include <stdlib.h>
#include <iostream>
#include "CheckedArray.h"

using namespace std;

CheckedArray::CheckedArray()
    //:CheckedArray(10)
{
    this->initialize(10);
}

CheckedArray::CheckedArray(int size)
{
    this->initialize(size);
}

CheckedArray::~CheckedArray()
{
    if (this->ar != NULL)
    {
        this->ar = NULL;
        this->size = 0;
    }

    cout << "CheckedArray deleted" << endl;
}

/*
CheckedArrayException::CheckedArrayException(std::string msg)
{
    this->message = msg;
}
*/

bool CheckedArray::initialize(int size, int val)
{
    //if (*ar != NULL)
        //delete &ar;
    try 
    {
        this->ar = new int[size];
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

int CheckedArray::at(int index) const
{
    if (index > size || index < 0 || this->ar == NULL)
        throw CheckedArrayException("Index out of bounds");
    return this->ar[index];
}

void CheckedArray::set(int index, int value)
{
    if (index > size || index < 0 || this->ar == NULL)
        throw CheckedArrayException("Index out of bounds");
    this->ar[index] = value;
}

int CheckedArray::operator[](int index)
{
    return this->at(index);
}

string CheckedArray::toString()
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