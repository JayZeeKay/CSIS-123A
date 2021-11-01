#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Menu.h"

Menu::Menu()
: count(0)
{

}

void Menu::addMenu(string Description, void (*f) (void))
{

    if(count < MAXCOUNT)
    {
        this->mi[count].func = f;
        this->mi[count].descript = Description;
        count++;
    }
}

void Menu::runMenu()
{

    for (;;)
    {
        system("CLS");
        for(int i = 0; i < count; i++)
        {
            cout << this->mi[i].descript << endl;
        }
        runSelection();
    }
}

void Menu::runSelection()
{
    int select;

    cin >> select;
    if (select <= count)
        this->mi[select - 1].func();
}

void Menu::waitKey()
{
	cout << "Press any key to continue" << endl;
	getchar();
}

