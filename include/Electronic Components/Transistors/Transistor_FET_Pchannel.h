#ifndef TRANSISTOR_FET_PCHANNEL_H
#define TRANSISTOR_FET_PCHANNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_FET_Pchannel : public ElectronicComponent
{

public:
    Transistor_FET_Pchannel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_FET_PCHANNEL_H
