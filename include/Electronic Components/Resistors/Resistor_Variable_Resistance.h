#ifndef RESISTOR_VARIABLE_RESISTANCE_H
#define RESISTOR_VARIABLE_RESISTANCE_H

#include "Electronic Components/ElectronicComponent.h"

class Resistor_Variable_Resistance : public ElectronicComponent{

public:
    Resistor_Variable_Resistance();

    //Drawing the component:
    void Show();
};

#endif // RESISTOR_VARIABLE_RESISTANCE_H
