#include "UI/Info/CapacitorsInfo.h"

CapacitorsInfo::CapacitorsInfo()
{
    //ctor
}

void CapacitorsInfo::Show(double w, double h)
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

    capacitorCeramic.setWidth(w / 2);
    capacitorCeramic.setPositionUpLeft(helper.makeVector_2D(w, h));
    outtextxy(2 * w, h, strdup(capacitorCeramic.name.c_str()));

    capacitorElectrolyt.setWidth(w / 2);
    capacitorElectrolyt.setPositionUpLeft(helper.makeVector_2D(w * 4, h));
    outtextxy(5 * w, h, strdup(capacitorElectrolyt.name.c_str()));

    capacitorTrimmer.setWidth(w / 2);
    capacitorTrimmer.setPositionUpLeft(helper.makeVector_2D(w, h * 2));
    outtextxy(2 * w, h * 2, strdup(capacitorTrimmer.name.c_str()));

    capacitorVariable.setWidth(w / 2);
    capacitorVariable.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 2));
    outtextxy(5 * w, h * 2, strdup(capacitorVariable.name.c_str()));
}

int CapacitorsInfo::WatchClick()
{
    int ok = 1;
    int cType = _none;
    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (capacitorCeramic.isCursorPointInButton())
            {
                cType = _capacitorCeramic;
                ok = 0;
            }
            else if (capacitorElectrolyt.isCursorPointInButton())
            {
                cType = _capacitorElectrolyt;
                ok = 0;
            }
            else if (capacitorTrimmer.isCursorPointInButton())
            {
                cType = _capacitorTrimmer;
                ok = 0;
            }
            else if (capacitorVariable.isCursorPointInButton())
            {
                cType = _capacitorVariable;
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

int CapacitorsInfo::WatchExit()
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
