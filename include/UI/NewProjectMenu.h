#ifndef NEWPROJECTMENU_H
#define NEWPROJECTMENU_H

#include <graphics.h>
#include <winbgim.h>
#include <windows.h>

#include "UI/UI.h"
#include "Helper.h"

class NewProjectMenu: public Screen
{
    protected:
        Button capacitors, diodes, logicGates, measurements, resistors, sources, switches, transistors, other, exit;
    public:
        NewProjectMenu();
        void Show();
        void WatchClick();
};

#endif // NEWPROJECTMENU_H
