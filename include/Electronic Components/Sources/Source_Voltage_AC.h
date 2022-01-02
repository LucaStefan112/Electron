#ifndef SOURCE_VOLTAGE_AC_H
#define SOURCE_VOLTAGE_AC_H

#include "Electronic Components/ElectronicComponent.h"

class Source_Voltage_AC : public ElectronicComponent{

public:
    double volts = 0, ampers = 0;

public:
    Source_Voltage_AC();

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

#endif // SOURCE_VOLTAGE_AC_H
