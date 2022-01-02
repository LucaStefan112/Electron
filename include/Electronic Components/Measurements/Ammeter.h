#ifndef AMMETER_H
#define AMMETER_H

#include "Electronic Components/ElectronicComponent.h"

class Ammeter : public ElectronicComponent{

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
};

#endif // AMMETER_H
