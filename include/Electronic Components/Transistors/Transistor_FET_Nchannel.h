#ifndef TRANSISTOR_FET_NCHANNEL_H
#define TRANSISTOR_FET_NCHANNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_FET_Nchannel : public ElectronicComponent{

public:
    Transistor_FET_Nchannel();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_FET_NCHANNEL_H
