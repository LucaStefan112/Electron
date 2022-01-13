#ifndef TRANSISTOR_MOSFET_NCHANNEL_H
#define TRANSISTOR_MOSFET_NCHANNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_MOSFET_Nchannel : public ElectronicComponent
{

public:
    Transistor_MOSFET_Nchannel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_MOSFET_NCHANNEL_H
