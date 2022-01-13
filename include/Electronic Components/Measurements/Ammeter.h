#ifndef AMMETER_H
#define AMMETER_H

#include "Electronic Components/ElectronicComponent.h"

class Ammeter : public ElectronicComponent
{

private:
    double current = 0;

public:
    Ammeter();

    //Setters:
    void setCurrent(double thisCurrent);

    //Getters:
    double getCurrent();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();

    std::vector<std::pair<std::string, double>> getValues();
    void setValue(std::string name, double value);
};

#endif // AMMETER_H
