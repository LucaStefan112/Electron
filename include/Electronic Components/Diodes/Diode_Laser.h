#ifndef DIODE_LASER_H
#define DIODE_LASER_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Diode_Laser : public ElectronicComponent
{

public:
    Diode_Laser();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_LASER_H
