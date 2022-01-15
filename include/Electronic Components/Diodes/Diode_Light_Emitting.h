#ifndef DIODE_LIGHT_EMITTING_H
#define DIODE_LIGHT_EMITTING_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Diode_Light_Emitting : public ElectronicComponent
{

public:
    Diode_Light_Emitting();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_LIGHT_EMITTING_H
