#ifndef AMMETER_H
#define AMMETER_H

#include "Electronic Components/ElectronicComponent.h"

class Ammeter : public ElectronicComponent{

public:
    Ammeter();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // AMMETER_H
