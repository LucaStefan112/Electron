#ifndef TRANSISTOR_FET_NCHANNEL_H
#define TRANSISTOR_FET_NCHANNEL_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Transistor_FET_Nchannel : public ElectronicComponent
{

public:
    Transistor_FET_Nchannel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_FET_NCHANNEL_H
