#include "UI/Info/SwitchesInfo.h"

//daria
SwitchesInfo::SwitchesInfo()
{
    //ctor
}

void SwitchesInfo::Show(double w, double h)
{
    Helper helper;
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int wc = initwindow(screenWidth, screenHeight, "", -3, -3);
    this->window_code = wc;
    setlinestyle(0, 0, 3);
    settextstyle(3, 0, 1);

    exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
    exit.setWidth(75);
    exit.setHeight(25);
    exit.setTitle("Exit");
    exit.Show();

    switchClosed.setWidth(w / 2);
    switchClosed.setPositionUpLeft(helper.makeVector_2D(w, h));
    outtextxy(2 * w, h, strdup(switchClosed.name.c_str()));

    switchSPDT.setWidth(w / 2);
    switchSPDT.setPositionUpLeft(helper.makeVector_2D(w * 4, h));
    outtextxy(5 * w, h, strdup(switchSPDT.name.c_str()));

    switchOpen.setWidth(w / 2);
    switchOpen.setPositionUpLeft(helper.makeVector_2D(w, h * 2));
    outtextxy(2 * w, 2 * h, strdup(switchOpen.name.c_str()));

    switchDPST.setWidth(w / 2);
    switchDPST.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 2));
    outtextxy(5 * w, 2 * h, strdup(switchDPST.name.c_str()));

    switchTelegraph.setWidth(w / 2);
    switchTelegraph.setPositionUpLeft(helper.makeVector_2D(w, h * 3));
    outtextxy(2 * w, 3 * h, strdup(switchTelegraph.name.c_str()));

    switchThermal.setWidth(w / 2);
    switchThermal.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 3));
    outtextxy(5 * w, 3 * h, strdup(switchThermal.name.c_str()));
}

int SwitchesInfo::WatchClick()
{
    int ok = 1;

    int cType = _none;
    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (switchClosed.isCursorPointInButton())
            {
                cType = _switchClosed;
                ok = 0;
            }
            else if (switchSPDT.isCursorPointInButton())
            {
                cType = _switchSPDT;
                ok = 0;
            }
            else if (switchOpen.isCursorPointInButton())
            {
                cType = _switchOpen;
                ok = 0;
            }
            else if (switchDPST.isCursorPointInButton())
            {
                cType = _switchDPST;
                ok = 0;
            }
            else if (switchTelegraph.isCursorPointInButton())
            {
                cType = _switchTelegraph;
                ok = 0;
            }
            else if (switchThermal.isCursorPointInButton())
            {
                cType = _switchThermal;
                ok = 0;
            }
            else if (exit.isCursorPointInButton())
            {
                cType = _none;
                ok = 0;
            }
        }
        delay(200);
    }

    closegraph(this->window_code);
    return cType;
}

int SwitchesInfo::WatchExit()
{
    int ok = 1;

    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON) && exit.isCursorPointInButton())
        {
            ok = 0;
        }
        delay(200);
    }
    closegraph(this->window_code);
    return 1;
}
