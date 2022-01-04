#include "UI/Info/MeasurementsInfo.h"

MeasurementsInfo::MeasurementsInfo()
{
    //ctor
}

void MeasurementsInfo::Show(double w, double h)
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

    ammeter.setWidth(w / 2);
    ammeter.setPositionUpLeft(helper.makeVector_2D(w, h));
    outtextxy(2 * w, h, strdup(ammeter.name.c_str()));

    voltmeter.setWidth(w / 2);
    voltmeter.setPositionUpLeft(helper.makeVector_2D(w * 4, h));
    outtextxy(5 * w, h, strdup(voltmeter.name.c_str()));
}

int MeasurementsInfo::WatchClick()
{
    int ok = 1;

    int cType = _none;
    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (ammeter.isCursorPointInButton())
            {
                cType = _ammeter;
                ok = 0;
            }
            else if (voltmeter.isCursorPointInButton())
            {
                cType = _voltmeter;
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

int MeasurementsInfo::WatchExit()
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
