#ifndef TRANSISTOR_BIPOLAR_NPN_H
#define TRANSISTOR_BIPOLAR_NPN_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_Bipolar_NPN : public ElectronicComponent
{

public:
    Transistor_Bipolar_NPN();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_BIPOLAR_NPN_H
