#ifndef BATTERY_H
#define BATTERY_H

#include "Electronic Components/ElectronicComponent.h"

class Battery : public ElectronicComponent{

public:
    Battery();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // BATTERY_H
