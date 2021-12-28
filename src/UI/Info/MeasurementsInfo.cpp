#include "UI/Info/MeasurementsInfo.h"

MeasurementsInfo::MeasurementsInfo()
{
    //ctor
}

void MeasurementsInfo::Show(double w, double h) {
    Helper helper;

    exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
    exit.setWidth(75);
    exit.setHeight(25);
    exit.setTitle("Exit");
    exit.Show();

    Ammeter ammeter;
    ammeter.setWidth(w / 2);
    ammeter.setPositionUpLeft(helper.makeVector_2D(w,h));
    outtextxy(2 * w, h, strdup(ammeter.name.c_str()));

    Voltmeter voltmeter;
    voltmeter.setWidth(w / 2);
    voltmeter.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
    outtextxy(5 * w, h, strdup(voltmeter.name.c_str()));
}
