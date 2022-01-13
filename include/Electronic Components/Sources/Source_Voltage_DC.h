#ifndef SOURCE_VOLTAGE_DC_H
#define SOURCE_VOLTAGE_DC_H

#include "Electronic Components/ElectronicComponent.h"

class Source_Voltage_DC : public ElectronicComponent
{

public:
    double volts = 0, ampers = 0;

public:
    Source_Voltage_DC();

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

    std::vector<std::pair<std::string, double>> getValues();
    void setValue(std::string name, double value);
};

#endif // SOURCE_VOLTAGE_DC_H
