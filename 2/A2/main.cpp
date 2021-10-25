/*
ID: 0620306

Jacob Marinas

24 October 2021

Lab Assignment 2 - Class Construction

Creating a Byte class that stores info about one byte of data
*/
#include <iostream>
#include "Byte.h"

using namespace std;

int main()
{
    Byte bite;

    int test[8] = { 99, 0, 1, 255, 256, 300, -1, -100 };

    // 256 and 300 go into overflow, 0 and 44 are stored respectively as bits in the Byte class
    // -1 and -100 overflow "backwards", counting down from 256. 255 and 156 are stored respectively as bits in the Byte class

    for (int i = 0; i < 8; i++)
    {
        cout << "Value to test the Byte class: " << test[i] << endl;

        bite.setValue(test[i]);

        for(int i = 0; i < 8; i++)
            cout << bite.at(i) << endl;

        cout << "Int: " << bite.toInt() << endl;
        cout << "String: " << bite.toString() << endl;
    }

    return 0;
}