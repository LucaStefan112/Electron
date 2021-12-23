#ifndef DIODE_SCHOTTKY_H
#define DIODE_SCHOTTKY_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Schottky : public ElectronicComponent{

public:
    Diode_Schottky();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_SCHOTTKY_H
