#pragma once 
#ifndef MENU
#define MENU

#include <vector>

//int MAXCOUNT;

namespace jacob 
{
    struct menuItem
    {
        void (*func) ();
        std::string descript;
    };

    class Menu
    {
        private:
            std::vector <menuItem> mi;
            int count;
            void runSelection();
            static Menu *pInstance; // static instance
        public:
            Menu();
            void addMenu(std::string Description, void (*f) ());
            void runMenu();
            void waitKey();
            static Menu *Instance();
    };
}

#endif