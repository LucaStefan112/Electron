#include "UI/TransistorsInfo.h"

TransistorsInfo::TransistorsInfo(): InfoScreen()
{
    //ctor
}

void TransistorsInfo::Show(double w, double h) {
        Helper helper;

        double th = 13 * h / 10;

        Transistor_Bipolar_NPN transistorBipolarNPN;
        transistorBipolarNPN.setWidth(w / 3);
        transistorBipolarNPN.setPositionUpLeft(helper.makeVector_2D(w/2,h));
        transistorBipolarNPN.Show();
        outtextxy(w, th, strdup(transistorBipolarNPN.name.c_str()));

        Transistor_Bipolar_PNP transistorBipolarPNP;
        transistorBipolarPNP.setWidth(w / 3);
        transistorBipolarPNP.setPositionUpLeft(helper.makeVector_2D(9*w/2,h));
        transistorBipolarPNP.Show();
        outtextxy(5 * w, th, strdup(transistorBipolarPNP.name.c_str()));

        Transistor_Dual_Gate_MOSFET_Nchannel transistorDualN;
        transistorDualN.setWidth(w / 3);
        transistorDualN.setPositionUpLeft(helper.makeVector_2D(w/2,h*2));
        transistorDualN.Show();
        outtextxy(w, h + th, strdup(transistorDualN.name.c_str()));

        Transistor_Dual_Gate_MOSFET_Pchannel transistorDualP;
        transistorDualP.setWidth(w / 3);
        transistorDualP.setPositionUpLeft(helper.makeVector_2D(9*w/2,h * 2));
        transistorDualP.Show();
        outtextxy(5 * w, h + th, strdup(transistorDualP.name.c_str()));

        Transistor_FET_Nchannel transistorFETN;
        transistorFETN.setWidth(w / 3);
        transistorFETN.setPositionUpLeft(helper.makeVector_2D(w/2,h*3));
        transistorFETN.Show();
        outtextxy(w, 2 * h + th, strdup(transistorFETN.name.c_str()));

        Transistor_FET_Pchannel transistorFETP;
        transistorFETP.setWidth(w / 3);
        transistorFETP.setPositionUpLeft(helper.makeVector_2D(9*w/2,h * 3));
        transistorFETP.Show();
        outtextxy(5 * w, 2 * h + th, strdup(transistorFETP.name.c_str()));

        Transistor_Inductive_Channel_MOSFET_Nchannel transistorInductiveN;
        transistorInductiveN.setWidth(w / 3);
        transistorInductiveN.setPositionUpLeft(helper.makeVector_2D(w/2,h*4));
        transistorInductiveN.Show();
        outtextxy(w, 3 * h + th, strdup(transistorInductiveN.name.c_str()));

        Transistor_Inductive_Channel_MOSFET_Pchannel transistorInductiveP;
        transistorInductiveP.setWidth(w / 3);
        transistorInductiveP.setPositionUpLeft(helper.makeVector_2D(9*w/2,h * 4));
        transistorInductiveP.Show();
        outtextxy(5 * w, 3 * h + th, strdup(transistorInductiveP.name.c_str()));

        Transistor_MOSFET_Nchannel transistorMOSFETN;
        transistorMOSFETN.setWidth(w / 3);
        transistorMOSFETN.setPositionUpLeft(helper.makeVector_2D(w/2,h*5));
        transistorMOSFETN.Show();
        outtextxy(w, 4 * h + th, strdup(transistorMOSFETN.name.c_str()));

        Transistor_MOSFET_Pchannel transistorMOSFETP;
        transistorMOSFETP.setWidth(w / 3);
        transistorMOSFETP.setPositionUpLeft(helper.makeVector_2D(9*w/2,h * 5));
        transistorMOSFETP.Show();
        outtextxy(5 * w, 4 * h + th, strdup(transistorMOSFETP.name.c_str()));

        Transistor_Single_Connection_Nchannel transistorSingleN;
        transistorSingleN.setWidth(w / 3);
        transistorSingleN.setPositionUpLeft(helper.makeVector_2D(w/2,h*6));
        transistorSingleN.Show();
        outtextxy(w, 5 * h + th, strdup(transistorSingleN.name.c_str()));

        Transistor_Single_Connection_Pchannel transistorSingleP;
        transistorSingleP.setWidth(w / 3);
        transistorSingleP.setPositionUpLeft(helper.makeVector_2D(9*w/2,h * 6));
        transistorSingleP.Show();
        outtextxy(5 * w, 5 * h + th, strdup(transistorSingleP.name.c_str()));
}
