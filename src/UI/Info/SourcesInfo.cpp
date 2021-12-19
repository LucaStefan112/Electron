#include "UI/Info/SourcesInfo.h"

SourcesInfo::SourcesInfo(): Screen()
{
    //ctor
}

void SourcesInfo::Show(double w, double h) {
        Helper helper;

        Source_Voltage_AC sourceAC;
        sourceAC.setWidth(w / 2);
        sourceAC.setPositionUpLeft(helper.makeVector_2D(w,h));
        sourceAC.Show();
        outtextxy(2 * w, h, strdup(sourceAC.name.c_str()));

        Source_Voltage_DC sourceDC;
        sourceDC.setWidth(w / 2);
        sourceDC.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
        sourceDC.Show();
        outtextxy(5 * w, h, strdup(sourceDC.name.c_str()));

        Battery battery;
        battery.setWidth(w / 2);
        battery.setPositionUpLeft(helper.makeVector_2D(5 * w / 2,h*2));
        battery.Show();
        outtextxy(7 * w / 2, 2 * h, strdup(battery.name.c_str()));
}
