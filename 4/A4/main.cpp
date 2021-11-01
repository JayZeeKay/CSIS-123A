/*
Jacob Marinas

ID: 0602306

31 October 2021

Lab Assignment 4 - Vectors

Modifying the Menu and Byte classes to be more dynamic and flexible
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
Byte biteOne, biteTwo;

int main()
{
    int firstBite, secondBite;
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

    cout << "What operation do you want the second byte to perform on the first byte?" << endl;

    m.addMenu("1, Add ", add);
    m.addMenu("2, Subtract ", sub);
    m.addMenu("3, Multiply ", mul);
    m.addMenu("4, Divide ", div);
    m.addMenu("5, Exit", Exit);

    m.runMenu();

    return 0;
}

void add()
{
    Byte biteThree(biteOne.add(biteTwo));
    cout << "Adding them equals: " << biteThree.toInt() << endl;
    m.waitKey();
}

void sub()
{
    Byte biteThree(biteOne.sub(biteTwo));
    cout << "Subtracting them equals: " << biteThree.toInt() << endl;
    m.waitKey();
}

void mul()
{
    Byte biteThree(biteOne.mul(biteTwo));
    cout << "Multiplying them  equals: " << biteThree.toInt() << endl;
    m.waitKey();
}

void div()
{
    Byte biteThree(biteOne.div(biteTwo));
    cout << "Dividing them  equals: " << biteThree.toInt() << endl;
    m.waitKey();
}

void Exit()
{
    cout << "Goodbye" << endl;
    exit(0);  
}