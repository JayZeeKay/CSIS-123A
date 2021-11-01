#ifndef MENU
#define MENU

int MAXCOUNT = 20;
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