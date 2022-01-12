#ifndef CAPACITOR_CERAMIC_H
#define CAPACITOR_CERAMIC_H

#include "Electronic Components/ElectronicComponent.h"

class Capacitor_Ceramic : public ElectronicComponent{

private:
    double capacitance = 0;

public:
    Capacitor_Ceramic();

    //Setters:
    void setCapacitance(double thisCapacitance);

    //Getters:
    double getCapacitance();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();

    std::vector<std::pair<std::string, double>> getValues();
    void setValue(std::string name, double value);
};

#endif // CAPACITOR_CERAMIC_H
