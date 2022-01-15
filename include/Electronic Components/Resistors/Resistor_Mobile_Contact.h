#ifndef RESISTOR_MOBILE_CONTACT_H
#define RESISTOR_MOBILE_CONTACT_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Resistor_Mobile_Contact : public ElectronicComponent
{

private:
    double resistance = 0;

public:
    Resistor_Mobile_Contact();

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

#endif // RESISTOR_MOBILE_CONTACT_H
