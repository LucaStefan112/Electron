#ifndef DIODE_LASER_H
#define DIODE_LASER_H

#include "ElectronicComponent.h"

class Diode_Laser : public ElectronicComponent{

public:
    Diode_Laser();

    //Drawing the component:
    void Show();
};

#endif // DIODE_LASER_H
