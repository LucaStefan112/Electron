#include "UI/MeasurementsInfo.h"

MeasurementsInfo::MeasurementsInfo()
{
    //ctor
}

void MeasurementsInfo::Show(double w, double h) {
    Helper helper;

    Ammeter ammeter;
    ammeter.setWidth(w / 2);
    ammeter.setPositionUpLeft(helper.makeVector_2D(w,h));
    ammeter.Show();
    outtextxy(2 * w, h, strdup(ammeter.name.c_str()));

    Voltmeter voltmeter;
    voltmeter.setWidth(w / 2);
    voltmeter.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
    voltmeter.Show();
    outtextxy(5 * w, h, strdup(voltmeter.name.c_str()));
}
