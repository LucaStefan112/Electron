#ifndef DIODE_PIN_H
#define DIODE_PIN_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Diode_PIN : public ElectronicComponent
{

public:
    Diode_PIN();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_PIN_H
