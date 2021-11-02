#include <iostream>
#include "string"
#include "Fraction.h"

using namespace std;

Fraction::Fraction()
{
    this->setFraction(1, 1);
}

Fraction::Fraction(int num, int den)
{
    this->setFraction(num, den);
}

Fraction::Fraction(string fraction)
{
    int tmpNum, tmpDen;
    // Split up the string into two parts, using substring
    // Finding the space character in the string, using that as the index for
    // the end of the numerator and beginning of the denominator
    // Then turn the string into an int with atof
    int space = fraction.find(" ");
    cout << space << endl;
    tmpNum = atof(fraction.substr(0, space).c_str());
    tmpDen = atof(fraction.substr(space).c_str());  // No need to include second parameter in substr, goes to end of string
    this->setFraction(tmpNum, tmpDen);
}
void Fraction::setFraction(int n, int d)
{
    this->num = n;
    this->den = d;
}

Fraction Fraction::add(const Fraction &f)
{
    Fraction tmp;
    tmp.num = (this->num * f.den) + (f.num * this->den);
    tmp.den = f.den * this->den;
    return tmp;
}

Fraction Fraction::sub(const Fraction &f)
{
    Fraction tmp;
    tmp.num = (this->num * f.den) - (f.num * this->den);
    tmp.den = f.den * this->den;
    return tmp;
}

Fraction Fraction::mul(const Fraction &f)
{
    Fraction tmp;
    tmp.num = f.num * this->num;  // Multiply across
    tmp.den = f.den * this->den;
    if (tmp.den < 0)
        tmp.den *= -1;
    return tmp;
}

Fraction Fraction::div(const Fraction &f)
{
    Fraction tmp;
    tmp.num = this->num * f.den;  // Multiply across, after taking the reciprocal of the second fraction
    tmp.den = this->den * f.num;
    if (tmp.den < 0)
        tmp.den *= -1;
    return tmp;
}

int Fraction::getNum() const
{
    return this->num;
}

int Fraction::getDen() const
{
    return this->den;
}

void Fraction::printFraction()
{
    cout << this->num << "/" << this->den << endl;
}

Fraction Fraction::operator+(const Fraction &f)
{
    return this->add(f);
}

Fraction Fraction::operator-(const Fraction &f)
{
    return this->sub(f);
}

Fraction Fraction::operator*(const Fraction &f)
{
    return this->mul(f);
}

Fraction Fraction::operator/(const Fraction &f)
{
    return this->div(f);
}

Fraction &Fraction::operator=(const Fraction &f)
{
    this->setFraction(f.getNum(), f.getDen());
    return *this;
}
