#include "UI/Info/SourcesInfo.h"

SourcesInfo::SourcesInfo(): Screen()
{
    //ctor
}

void SourcesInfo::Show(double w, double h) {
        Helper helper;

        exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
        exit.setWidth(75);
        exit.setHeight(25);
        exit.setTitle("Exit");
        exit.Show();

        Source_Voltage_AC sourceAC;
        sourceAC.setWidth(w / 2);
        sourceAC.setPositionUpLeft(helper.makeVector_2D(w,h));
        outtextxy(2 * w, h, strdup(sourceAC.name.c_str()));

        Source_Voltage_DC sourceDC;
        sourceDC.setWidth(w / 2);
        sourceDC.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
        outtextxy(5 * w, h, strdup(sourceDC.name.c_str()));

        Battery battery;
        battery.setWidth(w / 2);
        battery.setPositionUpLeft(helper.makeVector_2D(5 * w / 2,h*2));
        outtextxy(7 * w / 2, 2 * h, strdup(battery.name.c_str()));
}
