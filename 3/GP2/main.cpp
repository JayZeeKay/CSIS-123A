/*
ID: 0602306

Jacob Marinas

27 October 2021

Guided Practice 2 - Constructors

How to create a constructor to be able to build an object in multiple states
*/
#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction f1(1,4), f2(1,2), f3;
    string fraction;

    f3 = f1.add(f2);
    f3.printFraction();

    f3 = f1.mul(f2);
    f3.printFraction();

    f1.setFraction(1, 2);
    f2.setFraction(-3, 4);
    f3 = f1.div(f2);
    f3.printFraction();

    cout << "Enter a fraction \" Use spaces to separate the num and den \"" << endl;
    getline(cin, fraction);

    Fraction f4(fraction);
    f4.printFraction();

    return 0;
}