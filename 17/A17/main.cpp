/*
ID: 0620306

Jacob Marinas

17 December 2021

Final Project 

Creating a HashNames class that prints out the names hashed to certain locations
*/

#include <iostream>

#include "HashNames.h"

using namespace std;

int main()
{
    //HashNames n();
    HashNames n("names.txt");

    //n.hash();
    n.printNames();

    return 0;
}