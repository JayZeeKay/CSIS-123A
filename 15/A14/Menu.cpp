#include <iostream>
#include <cstdlib>

#include "Menu.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

namespace jacob
{
    int MAXCOUNT = 20;

    Menu::Menu()
    : count(0)
    {
        mi.resize(0);
    }

    void Menu::addMenu(std::string Description, void (*f) (void))
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
                std::cout << this->mi[i].descript << std::endl;
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
        std::cout << "Press any key to continue" << std::endl;
        getchar();
    }

    Menu *Menu::pInstance = NULL;

    Menu *Menu::Instance()
    {
        if (pInstance == NULL)
            pInstance = new Menu;

        return pInstance;
    }

}

