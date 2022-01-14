#ifndef TRANSISTORSINFO_H
#define TRANSISTORSINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

//daria
class TransistorsInfo
{
public:
    TransistorsInfo();

    Button exit;
    Transistor_Bipolar_NPN transistorBipolarNPN;
    Transistor_Bipolar_PNP transistorBipolarPNP;
    Transistor_Dual_Gate_MOSFET_Nchannel transistorDualN;
    Transistor_Dual_Gate_MOSFET_Pchannel transistorDualP;
    Transistor_FET_Nchannel transistorFETN;
    Transistor_FET_Pchannel transistorFETP;
    Transistor_Inductive_Channel_MOSFET_Nchannel transistorInductiveN;
    Transistor_Inductive_Channel_MOSFET_Pchannel transistorInductiveP;
    Transistor_MOSFET_Nchannel transistorMOSFETN;
    Transistor_MOSFET_Pchannel transistorMOSFETP;
    Transistor_Single_Connection_Nchannel transistorSingleN;
    Transistor_Single_Connection_Pchannel transistorSingleP;


    int window_code;
    void Show(double w, double h);
    int WatchClick();
    int WatchExit();
};

#endif // TRANSISTORSINFO_H
