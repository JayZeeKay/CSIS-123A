#include <iostream>
#include "Fraction.h"

using namespace std;

void Fraction::setFraction(int n, int d)
{
    num = n;
    den = d;
}

Fraction Fraction::add(const Fraction &f)
{
    Fraction tmp;
    tmp.num = (num * f.den) + (f.num * den);
    tmp.den = f.den * den;
    return tmp;
}

Fraction Fraction::sub(const Fraction &f)
{
    Fraction tmp;
    tmp.num = (num * f.den) - (f.num * den);
    tmp.den = f.den * den;
    return tmp;
}

Fraction Fraction::mul(const Fraction &f)
{
    Fraction tmp;
    tmp.num = f.num * num;  // Multiply across
    tmp.den = f.den * den;
    if (tmp.den < 0)
        tmp.den *= -1;
    return tmp;
}

Fraction Fraction::div(const Fraction &f)
{
    Fraction tmp;
    tmp.num = num * f.den;  // Multiply across, after taking the reciprocal of the second fraction
    tmp.den = den * f.num;
    if (tmp.den < 0)
        tmp.den *= -1;
    return tmp;
}

void Fraction::printFraction()
{
    cout << num << "/" << den << endl;
}