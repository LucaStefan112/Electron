#include "UI/Info/LogicGatesInfo.h"

LogicGatesInfo::LogicGatesInfo()
{
    //ctor
}

void LogicGatesInfo::Show(double w, double h)
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

    andGate.setWidth(w / 2);
    andGate.setPositionUpLeft(helper.makeVector_2D(w, h));
    outtextxy(2 * w, h, strdup(andGate.name.c_str()));

    nandGate.setWidth(w / 2);
    nandGate.setPositionUpLeft(helper.makeVector_2D(w * 4, h));
    outtextxy(5 * w, h, strdup(nandGate.name.c_str()));

    norGate.setWidth(w / 2);
    norGate.setPositionUpLeft(helper.makeVector_2D(w, h * 2));
    outtextxy(2 * w, 2 * h, strdup(norGate.name.c_str()));

    notGate.setWidth(w / 2);
    notGate.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 2));
    outtextxy(5 * w, 2 * h, strdup(notGate.name.c_str()));

    orGate.setWidth(w / 2);
    orGate.setPositionUpLeft(helper.makeVector_2D(w, h * 3));
    outtextxy(2 * w, 3 * h, strdup(orGate.name.c_str()));

    xorGate.setWidth(w / 2);
    xorGate.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 3));
    outtextxy(5 * w, 3 * h, strdup(xorGate.name.c_str()));
}

int LogicGatesInfo::WatchClick()
{
    int ok = 1;
    int cType = _none;
    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (andGate.isCursorPointInButton())
            {
                cType = _andGate;
                ok = 0;
            }
            else if (nandGate.isCursorPointInButton())
            {
                cType = _nandGate;
                ok = 0;
            }
            else if (norGate.isCursorPointInButton())
            {
                cType = _norGate;
                ok = 0;
            }
            else if (notGate.isCursorPointInButton())
            {
                cType = _notGate;
                ok = 0;
            }
            else if (orGate.isCursorPointInButton())
            {
                cType = _orGate;
                ok = 0;
            }
            else if (xorGate.isCursorPointInButton())
            {
                cType = _xorGate;
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

int LogicGatesInfo::WatchExit()
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
