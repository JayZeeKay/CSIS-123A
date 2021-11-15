/*
Jacob Marinas

ID: 0602306

3 November 2021

Lab Assignment 5 - Operator Overloading

Overloading functions in the Byte class
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Menu.h"
#include "Byte.h"

void add();
void sub();
void mul();
void div();

Menu m;
Byte biteOne, biteTwo, biteThree;

int main()
{
    int firstBite, secondBite;
    int firstBiteIndex = 0;
    cout << "Enter a number to set the first byte" << endl;
    cin >> firstBite;
    biteOne.setValue(firstBite);

    cout << "Int:    " << biteOne.toInt() << endl;
	cout << "String: " << biteOne.toString() << endl;

    cout << "Enter a number to set the second byte" << endl;
    cin >> secondBite;
    biteTwo.setValue(secondBite);

    cout << "Int:    " << biteTwo.toInt() << endl;
	cout << "String: " << biteTwo.toString() << endl;

    if (firstBite == secondBite)
    {
        cout << "The first byte is the same value as the second byte" << endl;
    }
    else
    {
        cout << "The first byte is not the same value as the second byte" << endl;
    }

    while (!(firstBiteIndex >= 1 && firstBiteIndex <= 8))
    {
        cout << "Enter a value (1 - 8) to get the desired bit of the first byte" << endl;
        cin >> firstBiteIndex;
    }

    cout << "Bit " << firstBiteIndex << " of byte one was: " << biteOne[firstBiteIndex-1] << endl << endl;

    cout << "What operation do you want the second byte to perform on the first byte?" << endl;

    m.addMenu("1, Add ", add);
    m.addMenu("2, Subtract ", sub);
    m.addMenu("3, Multiply ", mul);
    m.addMenu("4, Divide ", div);
    m.addMenu("5, Abort", abort);

    m.runMenu();

    return 0;
}

void add()
{
    biteThree = biteOne + biteTwo;
    cout << "Adding them equals: " << biteThree.toInt() << endl;
    m.waitKey();
}

void sub()
{
    biteThree = biteOne - biteTwo;
    cout << "Subtracting them equals: " << biteThree.toInt() << endl;
    m.waitKey();
}

void mul()
{
    biteThree = biteOne * biteTwo;
    cout << "Multiplying them  equals: " << biteThree.toInt() << endl;
    m.waitKey();
}

void div()
{
    biteThree = biteOne / biteTwo;
    cout << "Dividing them  equals: " << biteThree.toInt() << endl;
    m.waitKey();
}

void abort()
{
    cout << "Goodbye" << endl;
    exit(0);  
}