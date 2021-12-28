#include "UI/Info/CapacitorsInfo.h"

CapacitorsInfo::CapacitorsInfo(): Screen()
{
    //ctor
}

void CapacitorsInfo::Show(double w, double h)
{
    Helper helper;

    exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
    exit.setWidth(75);
    exit.setHeight(25);
    exit.setTitle("Exit");
    exit.Show();

    capacitorCeramic.setWidth(w / 2);
    capacitorCeramic.setPositionUpLeft(helper.makeVector_2D(w,h));
    outtextxy(2 * w, h, strdup(capacitorCeramic.name.c_str()));

    capacitorElectrolyt.setWidth(w / 2);
    capacitorElectrolyt.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
    outtextxy(5 * w, h, strdup(capacitorElectrolyt.name.c_str()));

    capacitorTrimmer.setWidth(w / 2);
    capacitorTrimmer.setPositionUpLeft(helper.makeVector_2D(w,h*2));
    outtextxy(2 * w, h*2, strdup(capacitorTrimmer.name.c_str()));

    capacitorVariable.setWidth(w / 2);
    capacitorVariable.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 2));
    outtextxy(5 * w, h * 2, strdup(capacitorVariable.name.c_str()));
}

int CapacitorsInfo::WatchClick()
{
    int ok = 1;

    Helper helper;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    clearmouseclick(WM_LBUTTONDOWN);
    int cType = _none;
    while (ok)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            if (capacitorCeramic.isCursorPointInButton())
            {
                cType = _capacitorCeramic;
                ok = 0;
            }
            if (capacitorElectrolyt.isCursorPointInButton())
            {
                cType = _capacitorElectrolyt;
                ok = 0;
            }
            if (capacitorTrimmer.isCursorPointInButton())
            {
                cType = _capacitorTrimmer;
                ok = 0;
            }
            if (capacitorVariable.isCursorPointInButton())
            {
                cType = _capacitorVariable;
                ok = 0;
            }
            if(exit.isCursorPointInButton())
            {
                cType = _none;
                ok = 0;
            }
        }
        delay(200);
    }

    closegraph(CURRENT_WINDOW);
    return cType;
}
