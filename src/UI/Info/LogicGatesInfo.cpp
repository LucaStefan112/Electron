#include "UI/Info/LogicGatesInfo.h"

LogicGatesInfo::LogicGatesInfo()
{
    //ctor
}

void LogicGatesInfo::Show(double w, double h) {
        Helper helper;

        AndGate andGate;
        andGate.setWidth(w / 2);
        andGate.setPositionUpLeft(helper.makeVector_2D(w,h));
        andGate.Show();
        outtextxy(2 * w, h, strdup(andGate.name.c_str()));

        NandGate nandGate;
        nandGate.setWidth(w / 2);
        nandGate.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
        nandGate.Show();
        outtextxy(5 * w, h, strdup(nandGate.name.c_str()));

        NorGate norGate;
        norGate.setWidth(w / 2);
        norGate.setPositionUpLeft(helper.makeVector_2D(w,h*2));
        norGate.Show();
        outtextxy(2 * w, 2 * h, strdup(norGate.name.c_str()));

        NotGate notGate;
        notGate.setWidth(w / 2);
        notGate.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 2));
        notGate.Show();
        outtextxy(5 * w, 2 * h, strdup(notGate.name.c_str()));

        OrGate orGate;
        orGate.setWidth(w / 2);
        orGate.setPositionUpLeft(helper.makeVector_2D(w,h*3));
        orGate.Show();
        outtextxy(2 * w, 3 * h, strdup(orGate.name.c_str()));

        XorGate xorGate;
        xorGate.setWidth(w / 2);
        xorGate.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 3));
        xorGate.Show();
        outtextxy(5 * w, 3 * h, strdup(xorGate.name.c_str()));
}
