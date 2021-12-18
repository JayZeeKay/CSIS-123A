/*
ID: 0602306

Jacob Marinas

12 December 2021

Guided Practice 10 - Templates

Creating a template for the Calc class to use any data type
*/

#include <iostream>
#include "Calc.h"

using namespace std;

int main()
{
    double a, b, sum = 0, dif = 0, prd = 0, quo = 0;
    cout << "Enter two numbers" << endl;
    cin >> a;
    cin >> b;

    Calc<double> c(a, b);

    try 
    {
        sum = c.add();
        dif = c.sub();
        prd = c.mul();
        quo = c.div();
    }
    catch (calcException c)
    {
        cout << c.what() << endl;
    }
    cout << "The sum is " << sum << endl;
    cout << "The difference is " << dif << endl;
    cout << "The product is " << prd << endl;
    cout << "The quotient is " << quo << endl;

    return 0;
}
