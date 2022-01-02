#include "UI/Info/ResistorsInfo.h"

ResistorsInfo::ResistorsInfo()
{
    //ctor
}

void ResistorsInfo::Show(double w, double h)
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

    potentiometer.setWidth(w / 2);
    potentiometer.setPositionUpLeft(helper.makeVector_2D(w, h));
    outtextxy(2 * w, h, strdup(potentiometer.name.c_str()));

    resistorMobileStop.setWidth(w / 2);
    resistorMobileStop.setPositionUpLeft(helper.makeVector_2D(w * 4, h));
    outtextxy(5 * w, h, strdup(resistorMobileStop.name.c_str()));

    resistorMobile.setWidth(w / 2);
    resistorMobile.setPositionUpLeft(helper.makeVector_2D(w, h * 2));
    outtextxy(2 * w, 2 * h, strdup(resistorMobile.name.c_str()));

    resistorVariableResistance.setWidth(w / 2);
    resistorVariableResistance.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 2));
    outtextxy(5 * w, 2 * h, strdup(resistorVariableResistance.name.c_str()));

    resistor.setWidth(w / 2);
    resistor.setPositionUpLeft(helper.makeVector_2D(5 * w / 2, h * 3));
    outtextxy(7 * w / 2, 3 * h, strdup(resistor.name.c_str()));
}

int ResistorsInfo::WatchClick()
{
    int ok = 1;

    Helper helper;
    int cType = _none;
    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (potentiometer.isCursorPointInButton())
            {
                cType = _potentiometer;
                ok = 0;
            }
            else if (resistorMobileStop.isCursorPointInButton())
            {
                cType = _resistorMobileStop;
                ok = 0;
            }
            else if (resistorMobile.isCursorPointInButton())
            {
                cType = _resistorMobile;
                ok = 0;
            }
            else if (resistorVariableResistance.isCursorPointInButton())
            {
                cType = _resistorVariableResistance;
                ok = 0;
            }
            else if (resistor.isCursorPointInButton())
            {
                cType = _resistor;
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

void ResistorsInfo::WatchExit()
{

    int ok = 1;

    Helper helper;

    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON) && exit.isCursorPointInButton())
        {
            ok = 0;
        }
        delay(200);
    }
    closegraph(this->window_code);
}
