#include "UI/Info/OtherInfo.h"

OtherInfo::OtherInfo()
{
    //ctor
}
void OtherInfo::Show(double w, double h)
{
    Helper helper;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int wc = initwindow(screenWidth/2, screenHeight/2, "", -3, -3);
    this->window_code = wc;
    setlinestyle(0, 0, 3);
    settextstyle(3, 0, 1);

    exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
    exit.setWidth(75);
    exit.setHeight(25);
    exit.setTitle("Exit");
    exit.Show();

    buzzer.setWidth(w / 2);
    buzzer.setPositionUpLeft(helper.makeVector_2D(w, h));
    outtextxy(2 * w, h, strdup(buzzer.name.c_str()));

    ground.setWidth(w / 2);
    ground.setPositionUpLeft(helper.makeVector_2D(w * 4, h));
    outtextxy(5 * w, h, strdup(ground.name.c_str()));

    inductor.setWidth(w / 2);
    inductor.setPositionUpLeft(helper.makeVector_2D(w, h * 2));
    outtextxy(2 * w, 2 * h, strdup(inductor.name.c_str()));

    lamp.setWidth(w / 2);
    lamp.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 2));
    outtextxy(5 * w, 2 * h, strdup(lamp.name.c_str()));

    microphone.setWidth(w / 2);
    microphone.setPositionUpLeft(helper.makeVector_2D(w, h * 3));
    outtextxy(2 * w, 3 * h, strdup(microphone.name.c_str()));

    motor.setWidth(w / 2);
    motor.setPositionUpLeft(helper.makeVector_2D(w * 4, h * 3));
    outtextxy(5 * w, 3 * h, strdup(motor.name.c_str()));

    speaker.setWidth(w / 2);
    speaker.setPositionUpLeft(helper.makeVector_2D(5 * w / 2, h * 4));
    outtextxy(7 * w / 2, 4 * h, strdup(speaker.name.c_str()));
}

int OtherInfo::WatchClick()
{
    int ok = 1;

    Helper helper;

    clearmouseclick(WM_LBUTTONDOWN);
    int cType = _none;
    while (ok)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            if (buzzer.isCursorPointInButton())
            {
                cType = _buzzer;
                ok = 0;
            }
            else if (ground.isCursorPointInButton())
            {
                cType = _ground;
                ok = 0;
            }
            else if (inductor.isCursorPointInButton())
            {
                cType = _inductor;
                ok = 0;
            }
            else if (lamp.isCursorPointInButton())
            {
                cType = _lamp;
                ok = 0;
            }
            else if (microphone.isCursorPointInButton())
            {
                cType = _microphone;
                ok = 0;
            }
            else if (motor.isCursorPointInButton())
            {
                cType = _motor;
                ok = 0;
            }
            else if (speaker.isCursorPointInButton())
            {
                cType = _speaker;
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

   // closegraph(this->window_code);
    return cType;
}

void OtherInfo::WatchExit()
{

    int ok = 1;

    Helper helper;

    clearmouseclick(WM_LBUTTONDOWN);
    while (ok)
    {
        if (ismouseclick(WM_LBUTTONDOWN) && exit.isCursorPointInButton())
        {
            ok = 0;
        }
        delay(200);
    }
    closegraph(this->window_code);
}
