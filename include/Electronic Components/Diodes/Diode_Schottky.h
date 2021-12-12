#ifndef DIODE_SCHOTTKY_H
#define DIODE_SCHOTTKY_H

#include "ElectronicComponent.h"

class Diode_Schottky : public ElectronicComponent{

public:
    Diode_Schottky();

    //Drawing the component:
    void Show();
};

#endif // DIODE_SCHOTTKY_H
