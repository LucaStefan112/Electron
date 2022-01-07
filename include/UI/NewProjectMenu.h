#ifndef NEWPROJECTMENU_H
#define NEWPROJECTMENU_H

#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <windows.h>

#include "Electronic Components/Electronics.h"
#include "UI/UI.h"
#include "Data Structures/ColectionOfSnapshots.h"
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

        ColectionOfSnapshots completeSnapshots;
        Snapshot currentSnapshot;

        NameFile nameFileMenu;

        bool iscurrentSnapshotelected;
        ElectronicComponent selectedComponent;


        int window_code;
        std::string filepath;
        //boundaries
        double rl,rt,rr,rb;

        void Show();
        void WatchClick();
};

#endif // NEWPROJECTMENU_H
