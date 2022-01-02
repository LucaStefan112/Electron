#ifndef RESISTOR_VARIABLE_RESISTANCE_H
#define RESISTOR_VARIABLE_RESISTANCE_H

#include "Electronic Components/ElectronicComponent.h"

class Resistor_Variable_Resistance : public ElectronicComponent{

private:
    double resistance = 0;

public:
    Resistor_Variable_Resistance();

    //Setter:
    void setResistance(double thisResistance);

    //Getters:
    double getResistance();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // RESISTOR_VARIABLE_RESISTANCE_H
