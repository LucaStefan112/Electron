#ifndef BATTERY_H
#define BATTERY_H

#include "Electronic Components/ElectronicComponent.h"

class Battery : public ElectronicComponent{

public:
    double volts = 0, ampers = 0;

public:
    Battery();

    //Setters:
    void setVolts(double thisVolts);
    void setAmpers(double thisAmpers);

    //Getters:
    double getVolts();
    double getAmpers();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // BATTERY_H
