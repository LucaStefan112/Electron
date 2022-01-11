#ifndef REZISTOR_H
#define REZISTOR_H

#include "Electronic Components/ElectronicComponent.h"

class Resistor : public ElectronicComponent{

private:
    double resistance = 0;

public:
    Resistor();

    //Setter:
    void setResistance(double thisResistance);

    //Getters:
    double getResistance();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();

    std::vector<std::pair<std::string, double>> getValues();
    void setValue(std::string name, double value);
};

#endif // REZISTOR_H
