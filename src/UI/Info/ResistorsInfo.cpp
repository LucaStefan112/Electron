#include "UI/Info/ResistorsInfo.h"

ResistorsInfo::ResistorsInfo(): Screen()
{
    //ctor
}

void ResistorsInfo::Show(double w, double h) {
        Helper helper;

        exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
        exit.setWidth(75);
        exit.setHeight(25);
        exit.setTitle("Exit");
        exit.Show();

        Potentiometer_Mobile_Contact potentiometer;
        potentiometer.setWidth(w / 2);
        potentiometer.setPositionUpLeft(helper.makeVector_2D(w,h));
        outtextxy(2 * w, h, strdup(potentiometer.name.c_str()));

        Resistor_Mobile_Contact_Stop_Position resistorMobileStop;
        resistorMobileStop.setWidth(w / 2);
        resistorMobileStop.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
        outtextxy(5 * w, h, strdup(resistorMobileStop.name.c_str()));

        Resistor_Mobile_Contact resistorMobile;
        resistorMobile.setWidth(w / 2);
        resistorMobile.setPositionUpLeft(helper.makeVector_2D(w,h*2));
        outtextxy(2 * w, 2 * h, strdup(resistorMobile.name.c_str()));

        Resistor_Variable_Resistance resistorVariableResistance;
        resistorVariableResistance.setWidth(w / 2);
        resistorVariableResistance.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 2));
        outtextxy(5 * w, 2 * h, strdup(resistorVariableResistance.name.c_str()));

        Resistor resistor;
        resistor.setWidth(w / 2);
        resistor.setPositionUpLeft(helper.makeVector_2D(5 * w / 2,h*3));
        outtextxy(7 * w / 2, 3 * h, strdup(resistor.name.c_str()));
}
