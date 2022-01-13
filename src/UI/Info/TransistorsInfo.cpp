#include "UI/Info/TransistorsInfo.h"

TransistorsInfo::TransistorsInfo()
{
    //ctor
}

void TransistorsInfo::Show(double w, double h)
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

    double th = 13 * h / 10;

    transistorBipolarNPN.setWidth(w / 3);
    transistorBipolarNPN.setPositionUpLeft(helper.makeVector_2D(w / 2, h));
    outtextxy(w, th, strdup(transistorBipolarNPN.name.c_str()));

    transistorBipolarPNP.setWidth(w / 3);
    transistorBipolarPNP.setPositionUpLeft(helper.makeVector_2D(9 * w / 2, h));
    outtextxy(5 * w, th, strdup(transistorBipolarPNP.name.c_str()));

    transistorDualN.setWidth(w / 3);
    transistorDualN.setPositionUpLeft(helper.makeVector_2D(w / 2, h * 2));
    outtextxy(w, h + th, strdup(transistorDualN.name.c_str()));

    transistorDualP.setWidth(w / 3);
    transistorDualP.setPositionUpLeft(helper.makeVector_2D(9 * w / 2, h * 2));
    outtextxy(5 * w, h + th, strdup(transistorDualP.name.c_str()));

    transistorFETN.setWidth(w / 3);
    transistorFETN.setPositionUpLeft(helper.makeVector_2D(w / 2, h * 3));
    outtextxy(w, 2 * h + th, strdup(transistorFETN.name.c_str()));

    transistorFETP.setWidth(w / 3);
    transistorFETP.setPositionUpLeft(helper.makeVector_2D(9 * w / 2, h * 3));
    outtextxy(5 * w, 2 * h + th, strdup(transistorFETP.name.c_str()));

    transistorInductiveN.setWidth(w / 3);
    transistorInductiveN.setPositionUpLeft(helper.makeVector_2D(w / 2, h * 4));
    outtextxy(w, 3 * h + th, strdup(transistorInductiveN.name.c_str()));

    transistorInductiveP.setWidth(w / 3);
    transistorInductiveP.setPositionUpLeft(helper.makeVector_2D(9 * w / 2, h * 4));
    outtextxy(5 * w, 3 * h + th, strdup(transistorInductiveP.name.c_str()));

    transistorMOSFETN.setWidth(w / 3);
    transistorMOSFETN.setPositionUpLeft(helper.makeVector_2D(w / 2, h * 5));
    outtextxy(w, 4 * h + th, strdup(transistorMOSFETN.name.c_str()));

    transistorMOSFETP.setWidth(w / 3);
    transistorMOSFETP.setPositionUpLeft(helper.makeVector_2D(9 * w / 2, h * 5));
    outtextxy(5 * w, 4 * h + th, strdup(transistorMOSFETP.name.c_str()));

    transistorSingleN.setWidth(w / 3);
    transistorSingleN.setPositionUpLeft(helper.makeVector_2D(w / 2, h * 6));
    outtextxy(w, 5 * h + th, strdup(transistorSingleN.name.c_str()));

    transistorSingleP.setWidth(w / 3);
    transistorSingleP.setPositionUpLeft(helper.makeVector_2D(9 * w / 2, h * 6));
    outtextxy(5 * w, 5 * h + th, strdup(transistorSingleP.name.c_str()));
}

int TransistorsInfo::WatchClick()
{
    int ok = 1;
    int cType = _none;
    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (transistorBipolarNPN.isCursorPointInButton())
            {
                cType = _transistorBipolarNPN;
                ok = 0;
            }
            else if (transistorBipolarPNP.isCursorPointInButton())
            {
                cType = _transistorBipolarPNP;
                ok = 0;
            }
            else if (transistorDualN.isCursorPointInButton())
            {
                cType = _transistorDualN;
                ok = 0;
            }
            else if (transistorDualP.isCursorPointInButton())
            {
                cType = _transistorDualP;
                ok = 0;
            }
            else if (transistorFETN.isCursorPointInButton())
            {
                cType = _transistorFETN;
                ok = 0;
            }
            else if (transistorFETP.isCursorPointInButton())
            {
                cType = _transistorFETP;
                ok = 0;
            }
            else if (transistorInductiveN.isCursorPointInButton())
            {
                cType = _transistorInductiveN;
                ok = 0;
            }
            else if (transistorInductiveP.isCursorPointInButton())
            {
                cType = _transistorInductiveP;
                ok = 0;
            }
            else if (transistorMOSFETN.isCursorPointInButton())
            {
                cType = _transistorMOSFETN;
                ok = 0;
            }
            else if (transistorMOSFETP.isCursorPointInButton())
            {
                cType = _transistorMOSFETP;
                ok = 0;
            }
            else if (transistorSingleN.isCursorPointInButton())
            {
                cType = _transistorSingleN;
                ok = 0;
            }
            else if (transistorSingleP.isCursorPointInButton())
            {
                cType = _transistorSingleP;
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

int TransistorsInfo::WatchExit()
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
