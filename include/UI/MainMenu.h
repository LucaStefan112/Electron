#ifndef MENU_H
#define MENU_H

#include <graphics.h>
#include <winbgim.h>

#include "Button.h"
#include "Info/InfoMenu.h"

class MainMenu
{
    protected:
        Button newProject, openProject, info, exit;
    public:
        MainMenu();
        void Show();
        void WatchClick();
};

#endif // MENU_H
