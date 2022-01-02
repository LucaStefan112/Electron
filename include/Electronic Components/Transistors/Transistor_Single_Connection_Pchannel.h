#ifndef TRANSISTOR_SINGLE_CONNECTION_PCHANNEL_H
#define TRANSISTOR_SINGLE_CONNECTION_PCHANNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_Single_Connection_Pchannel : public ElectronicComponent{

public:
    Transistor_Single_Connection_Pchannel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_SINGLE_CONNECTION_PCHANNEL_H
