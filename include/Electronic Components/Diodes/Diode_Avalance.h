#ifndef DIODE_AVALANCE_H
#define DIODE_AVALANCE_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Avalance : public ElectronicComponent{

public:
    Diode_Avalance();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_AVALANCE_H
