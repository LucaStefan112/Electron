#include "UI/Info/DiodesInfo.h"

DiodesInfo::DiodesInfo(): Screen()
{
    //ctor
}

void DiodesInfo::Show(double w, double h) {
        Helper helper;

        exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
        exit.setWidth(75);
        exit.setHeight(25);
        exit.setTitle("Exit");
        exit.Show();

        Diode_Avalance diodeAvalance;
        diodeAvalance.setWidth(w / 2);
        diodeAvalance.setPositionUpLeft(helper.makeVector_2D(w,h));
        outtextxy(2 * w, h, strdup(diodeAvalance.name.c_str()));

        Diode_Constant_Current diodeConstantCurrent;
        diodeConstantCurrent.setWidth(w / 2);
        diodeConstantCurrent.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
        outtextxy(5 * w, h, strdup(diodeConstantCurrent.name.c_str()));

        Diode_Gunn diodeGunn;
        diodeGunn.setWidth(w / 2);
        diodeGunn.setPositionUpLeft(helper.makeVector_2D(w,h*2));
        outtextxy(2 * w, 2 * h, strdup(diodeGunn.name.c_str()));

        Diode_Junction_PN diodeJunction;
        diodeJunction.setWidth(w / 2);
        diodeJunction.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 2));
        outtextxy(5 * w, 2 * h, strdup(diodeJunction.name.c_str()));

        Diode_Laser diodeLaser;
        diodeLaser.setWidth(w / 2);
        diodeLaser.setPositionUpLeft(helper.makeVector_2D(w,h*3));
        outtextxy(2 * w, 3 * h, strdup(diodeLaser.name.c_str()));

        Diode_Light_Emitting diodeLightEmitting;
        diodeLightEmitting.setWidth(w / 2);
        diodeLightEmitting.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 3));
        outtextxy(5 * w, 3 * h, strdup(diodeLightEmitting.name.c_str()));

        Diode_Photo diodePhoto;
        diodePhoto.setWidth(w / 2);
        diodePhoto.setPositionUpLeft(helper.makeVector_2D(w,h*4));
        outtextxy(2 * w, 4 * h, strdup(diodePhoto.name.c_str()));

        Diode_PIN diodePin;
        diodePin.setWidth(w / 2);
        diodePin.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 4));
        outtextxy(5 * w, 4 * h, strdup(diodePin.name.c_str()));

        Diode_Schottky diodeSchottky;
        diodeSchottky.setWidth(w / 2);
        diodeSchottky.setPositionUpLeft(helper.makeVector_2D(w,h*5));
        outtextxy(2 * w, 5 * h, strdup(diodeSchottky.name.c_str()));

        Diode_Shockley diodeShockley;
        diodeShockley.setWidth(w / 2);
        diodeShockley.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 5));
        outtextxy(5 * w, 5 * h, strdup(diodeShockley.name.c_str()));

        Diode_Transient_Voltage_Suppression diodeVoltage;
        diodeVoltage.setWidth(w / 2);
        diodeVoltage.setPositionUpLeft(helper.makeVector_2D(w,h*6));
        outtextxy(2 * w, 6 * h, strdup(diodeVoltage.name.c_str()));

        Diode_Tunnel diodeTunnel;
        diodeTunnel.setWidth(w / 2);
        diodeTunnel.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 6));
        outtextxy(5 * w, 6 * h, strdup(diodeTunnel.name.c_str()));

        Diode_Varactor diodeVaractor;
        diodeVaractor.setWidth(w / 2);
        diodeVaractor.setPositionUpLeft(helper.makeVector_2D(w,h*7));
        outtextxy(2 * w, 7 * h, strdup(diodeVaractor.name.c_str()));

        Diode_Zener diodeZener;
        diodeZener.setWidth(w / 2);
        diodeZener.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 7));
        outtextxy(5 * w, 7 * h, strdup(diodeZener.name.c_str()));
}
