#include "UI/Info/SwitchesInfo.h"

SwitchesInfo::SwitchesInfo(): Screen()
{
    //ctor
}

void SwitchesInfo::Show(double w, double h) {
        Helper helper;

        exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
        exit.setWidth(75);
        exit.setHeight(25);
        exit.setTitle("Exit");
        exit.Show();

        Switch_Closed switchInfo;
        switchInfo.setWidth(w / 2);
        switchInfo.setPositionUpLeft(helper.makeVector_2D(w,h));
        outtextxy(2 * w, h, strdup(switchInfo.name.c_str()));

        Switch_SPDT switchSPDT;
        switchSPDT.setWidth(w / 2);
        switchSPDT.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
        outtextxy(5 * w, h, strdup(switchSPDT.name.c_str()));

        Switch_Open switchOpen;
        switchOpen.setWidth(w / 2);
        switchOpen.setPositionUpLeft(helper.makeVector_2D(w,h*2));
        outtextxy(2 * w, 2 * h, strdup(switchOpen.name.c_str()));

        Switch_DPST switchDPST;
        switchDPST.setWidth(w / 2);
        switchDPST.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 2));
        outtextxy(5 * w, 2 * h, strdup(switchDPST.name.c_str()));

        Switch_Telegraph switchTelegraph;
        switchTelegraph.setWidth(w / 2);
        switchTelegraph.setPositionUpLeft(helper.makeVector_2D(w,h*3));
        outtextxy(2 * w, 3 * h, strdup(switchTelegraph.name.c_str()));

        Switch_Thermal_Magnetic_Breaker switchThermal;
        switchThermal.setWidth(w / 2);
        switchThermal.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 3));
        outtextxy(5 * w, 3 * h, strdup(switchThermal.name.c_str()));
}
