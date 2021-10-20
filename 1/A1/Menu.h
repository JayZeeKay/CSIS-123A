#ifndef MENU
#define MENU

const int MAXCOUNT = 20;
struct menuItem
{
    void (*func) ();
    char descript[50];
};

class Menu
{
    private:
        menuItem mi[MAXOUNT];
        int count = 0;
        void runSelection();
    public:
        Menu();
        void addMenu(char *Description, void (*f) ());
        void runMenu();
};

#endif