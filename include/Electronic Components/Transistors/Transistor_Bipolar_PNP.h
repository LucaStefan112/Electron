#ifndef TRANSISTOR_BIPOLAR_PNP_H
#define TRANSISTOR_BIPOLAR_PNP_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Transistor_Bipolar_PNP : public ElectronicComponent
{

public:
    Transistor_Bipolar_PNP();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_BIPOLAR_PNP_H
