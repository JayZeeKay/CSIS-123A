#pragma once 
#ifndef MENU
#define MENU

#include <vector>

//int MAXCOUNT;

struct menuItem
{
    void (*func) ();
    string descript;
};

class Menu
{
    private:
        std::vector <menuItem> mi;
        int count;
        void runSelection();
    public:
        Menu();
        void addMenu(string Description, void (*f) ());
        void runMenu();
        void waitKey();
};

#endif