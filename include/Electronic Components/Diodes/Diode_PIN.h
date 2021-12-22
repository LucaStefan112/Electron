#ifndef DIODE_PIN_H
#define DIODE_PIN_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_PIN : public ElectronicComponent{

public:
    Diode_PIN();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_PIN_H
