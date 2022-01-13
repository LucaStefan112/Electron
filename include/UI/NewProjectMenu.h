#ifndef NEWPROJECTMENU_H
#define NEWPROJECTMENU_H

#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <windows.h>

#include "Electronic Components/Electronics.h"
#include "UI/UI.h"
#include "Data Structures/Changes.h"
#include "Data Structures/Snapshot.h"

#include "Helper.h"
#include "Enums.h"

class NewProjectMenu
{
public:
    NewProjectMenu();

    Button save, capacitors, diodes, logicGates, measurements, resistors, sources, switches, transistors, other, exit;
    Button rotate_l, rotate_r, flip_h, flip_v;
    Button inc, dec;
    Button undo, redo;
    Button box;
    Button v1, v2, inc_v1, dec_v1, inc_v2, dec_v2;

    Changes changes;
    Snapshot currentSnapshot;

    NameFile nameFileMenu;

    int window_code;
    std::string filepath;
    //boundaries
    double rl,rt,rr,rb;

    bool wiring = false;
    double lastCursorX = -1, lastCursorY = -1;

    void Show();
    void WatchClick();

    void drawWiresForComponent(std::string thisComponentCode, bool eraseMode);

    void implementChangeUndo();
    void implementChangeRedo();

    void refreshScreen();
};

#endif // NEWPROJECTMENU_H
