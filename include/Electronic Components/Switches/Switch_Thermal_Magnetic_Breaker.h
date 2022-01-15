#ifndef SWITCH_THERMAL_MAGNETIC_BREAKER_H
#define SWITCH_THERMAL_MAGNETIC_BREAKER_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Switch_Thermal_Magnetic_Breaker : public ElectronicComponent
{

public:
    Switch_Thermal_Magnetic_Breaker();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SWITCH_THERMAL_MAGNETIC_BREAKER_H
