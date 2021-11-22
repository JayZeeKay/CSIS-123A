/*
ID: 0602306

Jacob Marinas

21 November 2021

Guided Practice 7 - File IO

Writing random fractions into a text file and reading it
*/
#include <iostream>
#include <fstream>
#include "Fraction.h"
#include <time.h>

using namespace std;

//void setNumDen(Fraction &f);
istream &operator >>(istream &input, Fraction &f);
ostream &operator <<(ostream &output, Fraction &f);

void writeNumbers(int amount);
void readNumbers();
void writeFraction(int amount);
void readFraction();

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    writeFraction(10);
    readFraction();

    return 0;
}

void writeFraction(int amount)
{
    Fraction *f;
    int num, den;

    num = rand() % 100 + 1;
    den = rand() & 100 + 1;

    ofstream outfile("Fractions.txt");
    if (!outfile)
    {
        cout << "Unable to open the file for writing" << endl;
        exit(1);
    }
    
    for (int i = 0 ; i < amount; i++)
    {
        f = new Fraction(num, den);
        outfile << f->getFraction() << endl;
        num = rand() % 100 + 1;
        den = rand() & 100 + 1;
    }
    outfile.close();
}

void readFraction()
{
    ifstream infile("Fractions.txt");
    char input[44];
    while (infile >> input)
    {
        cout << input << endl;
    }
}

/*
void writeNumbers(int amount)
{
    ofstream outfile("Numbers.txt");
    if (!outfile)
    {
        cout << "Unable to open the file for writing" << endl;
        exit(1);
    }

    for (int i = 0; i < amount; i++)
    {
        outfile << rand() % 100 << endl;
    }
    outfile.close();
}

void readNumbers()
{
    ifstream infile("Numbers.txt");
    char input(100);
    while (infile >> input)
        cout << input << endl;
}
*/

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
