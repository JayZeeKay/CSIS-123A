/*
ID: 0602306

Jacob Marinas

11 November 2021

Guided Practice 5 - Dynamic Memory

Practice using pointers and dynamic memory
*/
#include <iostream>
#include "Fraction.h"

using namespace std;

//void setNumDen(Fraction &f);
istream &operator >>(istream &input, Fraction &f);
ostream &operator <<(ostream &output, Fraction &f);


int main()
{
    Fraction *f1;
    f1 = new Fraction;
    Fraction f2(1,2), f3;

    cin >> *f1;
    cout << *f1;

    //setNumDen(f1);
    //f1.printFraction();

    string fraction;

    f3 = *f1 + f2;
    f3.printFraction();

    f3 = *f1 * f2;
    f3.printFraction();

    f1->setFraction(1, 2);
    f2.setFraction(-3, 4);
    f3 = *f1 / f2;
    f3.printFraction();

    delete f1;

    return 0;
}

/*
void setNumDen(Fraction &f)
{
    cout << "Enter a numerator" << endl;
    cin >> f.num;
    cout << "Enter a denominator" << endl;
    cin >> f.den;
}
*/

// Extraction operator overload
istream &operator >>(istream &input, Fraction &f)
{
    cout << "Enter a numerator" << endl;
    cin >> *f.num;
    cout << "Enter a denominator" << endl;
    cin >> *f.den;

    return input;
}

// Insertion operator overload
ostream &operator <<(ostream &output, Fraction &f)
{
    cout << *f.num << "/" << *f.den << endl;
    return output;
}



