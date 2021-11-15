/*
Jacob Marinas

ID: 0602306

14 November 2021

Lab Assignment 8 - Namespaces, static variables

Creating our own namespace and using the Singleton design pattern
*/

#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::cin;
using std::endl;

#include "Menu.h"
#include "Byte.h"


// Created jacob namespace, wraps the Byte and Menu classes
// Also changed 'using namespace std;' to using 'std::cout', and etc.
using namespace jacob;

void add();
void sub();
void mul();
void div();
void bit();

Byte *biteOne, *biteTwo, *biteThree;

int main()
{ 
    // Menu is out of global scope, and is single instance that can be referenced elsewhere with the function
    Menu *m = Menu::Instance();
    int biteOneVal, biteTwoVal;

    cout << "Enter the value of the first byte" << endl;
    cin >> biteOneVal;

    cout << "Enter the value of the second bite" << endl;
    cin >> biteTwoVal;

    biteOne = new Byte(biteOneVal);
    biteTwo = new Byte(biteTwoVal);
    biteThree = new Byte;
    
    if (biteOne == NULL || biteTwo == NULL || biteThree == NULL)
    {
        cout << "Unable to allocate memory for Byte object" << endl;
        m->waitKey();
        return 0;
    }

    cout << "What operation would you like to do?" << endl;

    m->addMenu("1, Add ", add);
    m->addMenu("2, Subtract ", sub);
    m->addMenu("3, Multiply ", mul);
    m->addMenu("4, Divide ", div);
    m->addMenu("5, Bit Location", bit);
    m->addMenu("6, Abort", abort);

    m->runMenu();

    return 0;
}

void add()
{
    *biteThree = *biteOne + *biteTwo;
    cout << "Adding them equals: " << biteThree->toInt() << endl;
    Menu *m = Menu::Instance();
    m->waitKey();
}

void sub()
{
    *biteThree = *biteOne - *biteTwo;
    cout << "Subtracting them equals: " << biteThree->toInt() << endl;
    Menu *m = Menu::Instance();
    m->waitKey();
}

void mul()
{
    *biteThree = *biteOne * *biteTwo;
    cout << "Multiplying them  equals: " << biteThree->toInt() << endl;
    Menu *m = Menu::Instance();
    m->waitKey();
}

void div()
{
    *biteThree = *biteOne / *biteTwo;
    cout << "Dividing them  equals: " << biteThree->toInt() << endl;
    Menu *m = Menu::Instance();
    m->waitKey();
}

void bit()
{
    int index;
    int input;

    cout << "Which byte do you want to view the location of a bit from?" << endl;
    cout << "1 or 2" << endl;
    cin >> input;
    
    cout << "Enter a value (1 - 8) to get the desired bit of the byte" << endl;
    cin >> index;

    Menu *m = Menu::Instance();

    switch (input)
    {
        case 1:
            cout << "Bit " << index << " of byte one was: " << biteOne->at(index-1) << endl << endl;
            break;
        case 2:
            cout << "Bit " << index << " of byte two was: " << biteTwo->at(index-1) << endl << endl;
            break;
        default:
            cout << "Not a valid input" << endl;
            m->waitKey();
            return;
    }

    m->waitKey();
}

void abort()
{
    cout << "Goodbye" << endl;

    // Prints a message saying that the byte has been deleted in the destructor
    delete biteOne;
    delete biteTwo;
    delete biteThree;

    exit(0);  
}