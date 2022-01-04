#ifndef VOLTMETER_H
#define VOLTMETER_H

#include "Electronic Components/ElectronicComponent.h"

class Voltmeter : public ElectronicComponent{

private:
    double voltage = 0;

public:
    Voltmeter();

    //Setters:
    void setVoltage(double thisVoltage);

    //Getters:
    double getVoltage();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // VOLTMETER_H
