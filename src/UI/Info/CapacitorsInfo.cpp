#include "UI/Info/CapacitorsInfo.h"

CapacitorsInfo::CapacitorsInfo(): Screen()
{
    //ctor
}

void CapacitorsInfo::Show(double w, double h) {
        Helper helper;

        Capacitor_Ceramic capacitorCeramic;
        capacitorCeramic.setWidth(w / 2);
        capacitorCeramic.setPositionUpLeft(helper.makeVector_2D(w,h));
        capacitorCeramic.Show();
        outtextxy(2 * w, h, strdup(capacitorCeramic.name.c_str()));

        Capacitor_Electrolytic capacitorElectrolyt;
        capacitorElectrolyt.setWidth(w / 2);
        capacitorElectrolyt.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
        capacitorElectrolyt.Show();
        outtextxy(5 * w, h, strdup(capacitorElectrolyt.name.c_str()));

        Capacitor_Trimmer capacitorTrimmer;
        capacitorTrimmer.setWidth(w / 2);
        capacitorTrimmer.setPositionUpLeft(helper.makeVector_2D(w,h*2));
        capacitorTrimmer.Show();
        outtextxy(2 * w, h*2, strdup(capacitorTrimmer.name.c_str()));

        Capacitor_Variable capacitorVariable;
        capacitorVariable.setWidth(w / 2);
        capacitorVariable.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 2));
        capacitorVariable.Show();
        outtextxy(5 * w, h * 2, strdup(capacitorVariable.name.c_str()));
}
