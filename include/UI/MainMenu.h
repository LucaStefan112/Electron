#ifndef MENU_H
#define MENU_H

#include "Button.h"


class MainMenu
{
    protected:
        Button NewProject, OpenProject, Info, Exit;
    public:
        MainMenu();
        void Show();
        void WatchClick();
};

#endif // MENU_H
