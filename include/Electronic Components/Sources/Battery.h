#ifndef BATTERY_H
#define BATTERY_H

#include "ElectronicComponent.h"

class Battery : public ElectronicComponent{

public:
    Battery();

    //Drawing the component:
    void Show();
};

#endif // BATTERY_H