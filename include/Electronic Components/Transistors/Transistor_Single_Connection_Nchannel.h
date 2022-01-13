#ifndef TRANSISTOR_SINGLE_CONNECTION_NCHANNEL_H
#define TRANSISTOR_SINGLE_CONNECTION_NCHANNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_Single_Connection_Nchannel : public ElectronicComponent
{

public:
    Transistor_Single_Connection_Nchannel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_SINGLE_CONNECTION_NCHANNEL_H
