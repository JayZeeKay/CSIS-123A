/*
Jacob Marinas

ID: 0602306

20 October 2021

Lab Assignment 1 - Creating a Menu

Create a simple menu class and instantiate an object to use its behaviors
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Menu.h"

void func1();
void func2();
void func3();
void Exit();

Menu m;

int main()
{
    m.addMenu("1, Function1 ", func1);
    m.addMenu("2, Function2 ", func2);
    m.addMenu("3, Function3 ", func3);
    m.addMenu("4, Exit ", Exit);

    m.runMenu();
}

void func1()
{
    char c;
    cout << "Hello from function 1";
    cin >> c;
    m.waitKey();
}

void func2()
{
    char c;
    cout << "Hello from function 2";
    cin >> c;
}

void func3()
{
    char c;
    cout << "Hello from function 3";
    cin >> c;
}

void Exit()
{
    cout << "Goodbye" << endl;
    exit(0);
}