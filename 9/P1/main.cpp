/*

ID: 0602306

Jacob Marinas

18 November 2021

Midterm Project - Better Random Number Generator
*/

#include <iostream>
#include "Random.h"

using namespace std;

int main()
{
    int seed, min, max;
    Random *r = new Random(0, 100);
    cout << "Generating 250 random numbers from 0 to 100" << endl;
    r->printVect();

    cout << "The first number of the list as an int is " << r->nextInt() << endl;
    cout << "The second number of the list as a double is " << r->nextDbl() << endl;

    cout << "\n\n\n";

    cout << "Redoing the list" << endl;
    r->setRange(0, 100);
    r->printVect();

    cout << "\n\n\n";

    Random *r2 = new Random();
    cout << "Generating 250 random numbers from 0 to RAND_MAX" << endl;
    r2->printVect();

    cout << "The first number of the list as an int is " << r2->nextInt() << endl;
    cout << "The second number of the list as a double is " << r2->nextDbl() << endl;

    cout << "\n\n\n";

    cout << "Enter a number for the seed" << endl;
    cin >> seed;

    cout << "Enter a number for the min" << endl;
    cin >> min;
    cout << "Enter a number for the max" << endl;
    cin >> max;

    Random *r3 = new Random(seed);
    cout << "Generating 250 random numbers from " << min << " to " << max << endl;
    r3->setRange(min, max);
    r3->printVect();

    cout << "The first number of the list as an int is " << r3->nextInt() << endl;
    cout << "The second number of the list as a double is " << r3->nextDbl() << endl;

    return 0;
}