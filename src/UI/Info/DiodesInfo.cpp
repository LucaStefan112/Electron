#include "UI/Info/DiodesInfo.h"

DiodesInfo::DiodesInfo()
{
    //ctor
}

void DiodesInfo::Show(double w, double h)
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

    diodeAvalance.setWidth(w / 2);
    diodeAvalance.setPositionUpLeft(helper.makeVector_2D(w, h));
    outtextxy(2 * w, h, strdup(diodeAvalance.name.c_str()));

    diodeConstantCurrent.setWidth(w / 2);
    diodeConstantCurrent.setPositionUpLeft(helper.makeVector_2D(w * 4, h));
    outtextxy(5 * w, h, strdup(diodeConstantCurrent.name.c_str()));

    diodeGunn.setWidth(w / 2);
    diodeGunn.setPositionUpLeft(helper.makeVector_2D(w, h * 2));
    outtextxy(2 * w, 2 * h, strdup(diodeGunn.name.c_str()));

    diodeJunction.setWidth(w / 2);
    diodeJunction.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 2));
    outtextxy(5 * w, 2 * h, strdup(diodeJunction.name.c_str()));

    diodeLaser.setWidth(w / 2);
    diodeLaser.setPositionUpLeft(helper.makeVector_2D(w, h * 3));
    outtextxy(2 * w, 3 * h, strdup(diodeLaser.name.c_str()));

    diodeLightEmitting.setWidth(w / 2);
    diodeLightEmitting.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 3));
    outtextxy(5 * w, 3 * h, strdup(diodeLightEmitting.name.c_str()));

    diodePhoto.setWidth(w / 2);
    diodePhoto.setPositionUpLeft(helper.makeVector_2D(w, h * 4));
    outtextxy(2 * w, 4 * h, strdup(diodePhoto.name.c_str()));

    diodePin.setWidth(w / 2);
    diodePin.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 4));
    outtextxy(5 * w, 4 * h, strdup(diodePin.name.c_str()));

    diodeSchottky.setWidth(w / 2);
    diodeSchottky.setPositionUpLeft(helper.makeVector_2D(w, h * 5));
    outtextxy(2 * w, 5 * h, strdup(diodeSchottky.name.c_str()));

    diodeShockley.setWidth(w / 2);
    diodeShockley.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 5));
    outtextxy(5 * w, 5 * h, strdup(diodeShockley.name.c_str()));

    diodeVoltage.setWidth(w / 2);
    diodeVoltage.setPositionUpLeft(helper.makeVector_2D(w, h * 6));
    outtextxy(2 * w, 6 * h, strdup(diodeVoltage.name.c_str()));

    diodeTunnel.setWidth(w / 2);
    diodeTunnel.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 6));
    outtextxy(5 * w, 6 * h, strdup(diodeTunnel.name.c_str()));

    diodeVaractor.setWidth(w / 2);
    diodeVaractor.setPositionUpLeft(helper.makeVector_2D(w, h * 7));
    outtextxy(2 * w, 7 * h, strdup(diodeVaractor.name.c_str()));

    diodeZener.setWidth(w / 2);
    diodeZener.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 7));
    outtextxy(5 * w, 7 * h, strdup(diodeZener.name.c_str()));
}

int DiodesInfo::WatchClick()
{
    int ok = 1;

    Helper helper;

    int cType = _none;
    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (diodeAvalance.isCursorPointInButton())
            {
                cType = _diodeAvalance;
                ok = 0;
            }
            else if (diodeConstantCurrent.isCursorPointInButton())
            {
                cType = _diodeConstantCurrent;
                ok = 0;
            }
            else if (diodeGunn.isCursorPointInButton())
            {
                cType = _diodeGunn;
                ok = 0;
            }
            else if (diodeJunction.isCursorPointInButton())
            {
                cType = _diodeJunction;
                ok = 0;
            }
            else if (diodeLaser.isCursorPointInButton())
            {
                cType = _diodeLaser;
                ok = 0;
            }
            else if (diodeLightEmitting.isCursorPointInButton())
            {
                cType = _diodeLightEmitting;
                ok = 0;
            }
            else if (diodePhoto.isCursorPointInButton())
            {
                cType = _diodePhoto;
                ok = 0;
            }
            else if (diodePin.isCursorPointInButton())
            {
                cType = _diodePin;
                ok = 0;
            }
            else if (diodeSchottky.isCursorPointInButton())
            {
                cType = _diodeSchottky;
                ok = 0;
            }
            else if (diodeShockley.isCursorPointInButton())
            {
                cType = _diodeShockley;
                ok = 0;
            }
            else if (diodeVoltage.isCursorPointInButton())
            {
                cType = _diodeVoltage;
                ok = 0;
            }
            else if (diodeTunnel.isCursorPointInButton())
            {
                cType = _diodeTunnel;
                ok = 0;
            }
            else if (diodeVaractor.isCursorPointInButton())
            {
                cType = _diodeVaractor;
                ok = 0;
            }
            else if (diodeZener.isCursorPointInButton())
            {
                cType = _diodeZener;
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

int DiodesInfo::WatchExit()
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
    return 1;
}
