/*
ID: 0620306

Jacob Marinas

27 October 2021

Lab Assignment 3 - Overloaded Constructors

Creating constructors for the Byte class
*/
#include <iostream>
#include "Byte.h"

using namespace std;

int main()
{
    
    Byte bite(7);

    cout << "Int:    " << bite.toInt() << endl;
	cout << "String: " << bite.toString() << endl;

    Byte b1 = bite.add(2);

    cout << "Int:    " << b1.toInt() << endl;
	cout << "String: " << b1.toString() << endl;

    Byte b2 = bite.sub(4);

    cout << "Int:    " << b2.toInt() << endl;
	cout << "String: " << b2.toString() << endl;

    Byte b3 = bite.mul(5);

    cout << "Int:    " << b3.toInt() << endl;
	cout << "String: " << b3.toString() << endl;

    Byte b4 = bite.div(2);

    cout << "Int:    " << b4.toInt() << endl;
	cout << "String: " << b4.toString() << endl;
    
    Byte b5;

    cout << "Int:    " << b5.toInt() << endl;
	cout << "String: " << b5.toString() << endl;

    int num[8] = { 0, 1, 0, 1, 1, 0, 0, 1 };

    Byte b6(num);

    cout << "Int:    " << b6.toInt() << endl;
	cout << "String: " << b6.toString() << endl;

    return 0;
}