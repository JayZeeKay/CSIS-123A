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

bool CheckedArray::initialize(int size, int val)
{
    //if (*ar != NULL)
        //delete &ar;
    this->ar = new int[size];
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
        return 0;
    return this->ar[index];
}

void CheckedArray::set(int index, int value)
{
    if (index > size || index < 0 || this->ar == NULL)
        return;
    this->ar[index] = value;
}

int CheckedArray::operator[](int index)
{
    return this->at(index);
}