#ifndef TRANSISTOR_FET_PCHANNEL_H
#define TRANSISTOR_FET_PCHANNEL_H

#include "ElectronicComponent.h"

class Transistor_FET_Pchannel : public ElectronicComponent{

public:
    Transistor_FET_Pchannel();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_FET_PCHANNEL_H
