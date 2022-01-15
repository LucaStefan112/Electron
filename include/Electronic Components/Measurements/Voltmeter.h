#ifndef VOLTMETER_H
#define VOLTMETER_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Voltmeter : public ElectronicComponent
{

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

    std::vector<std::pair<std::string, double>> getValues();
    void setValue(std::string name, double value);
};

#endif // VOLTMETER_H
