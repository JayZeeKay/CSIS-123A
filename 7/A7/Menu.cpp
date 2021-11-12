#include <iostream>
#include <cstdlib>

using namespace std;

#include "Menu.h"

int MAXCOUNT = 20;

Menu::Menu()
: count(0)
{
    mi.resize(0);
}

void Menu::addMenu(string Description, void (*f) (void))
{
    if(count < MAXCOUNT)
    {
        menuItem newMenuItem = { f, Description };
        mi.push_back(newMenuItem);
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

