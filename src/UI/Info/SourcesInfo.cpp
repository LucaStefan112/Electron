#include "UI/Info/SourcesInfo.h"

SourcesInfo::SourcesInfo()
{
    //ctor
}

void SourcesInfo::Show(double w, double h)
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

    sourceAC.setWidth(w / 2);
    sourceAC.setPositionUpLeft(helper.makeVector_2D(w, h));
    outtextxy(2 * w, h, strdup(sourceAC.name.c_str()));

    sourceDC.setWidth(w / 2);
    sourceDC.setPositionUpLeft(helper.makeVector_2D(w * 4, h));
    outtextxy(5 * w, h, strdup(sourceDC.name.c_str()));

    battery.setWidth(w / 2);
    battery.setPositionUpLeft(helper.makeVector_2D(5 * w / 2, h * 2));
    outtextxy(7 * w / 2, 2 * h, strdup(battery.name.c_str()));
}

int SourcesInfo::WatchClick()
{
    int ok = 1;

    int cType = _none;
    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (sourceAC.isCursorPointInButton())
            {
                cType = _sourceAC;
                ok = 0;
            }
            else if (sourceDC.isCursorPointInButton())
            {
                cType = _sourceDC;
                ok = 0;
            }
            else if (battery.isCursorPointInButton())
            {
                cType = _battery;
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

int SourcesInfo::WatchExit()
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
