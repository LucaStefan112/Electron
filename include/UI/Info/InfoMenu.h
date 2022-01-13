#ifndef INFOMENU_H
#define INFOMENU_H

#include <graphics.h>
#include <winbgim.h>
#include <windows.h>

#include "UI/UI.h"

class InfoMenu
{
protected:
    Button capacitors, diodes, logicGates, measurements, resistors, sources, switches, transistors, other, exit;
public:
    InfoMenu();

    int window_code;

    void Show();
    void WatchClick();
};

#endif // INFOMENU_H
