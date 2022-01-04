#ifndef MENU_H
#define MENU_H

#include <graphics.h>
#include <winbgim.h>

#include "Button.h"
#include "NewProjectMenu.h"
#include "Info/InfoMenu.h"
//#include "Data Structures/ColectionOfSnapshots.h"

class MainMenu
{
    protected:
        Button newProject, openProject, info, exit;
    public:
        MainMenu();

        //ColectionOfSnapshots importedSnapshot;

        int window_code;
        void Show();
        void WatchClick();
};

#endif // MENU_H
