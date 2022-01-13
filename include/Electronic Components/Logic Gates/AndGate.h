#ifndef ANDGATE_H
#define ANDGATE_H

#include "Electronic Components/ElectronicComponent.h"

class AndGate : public ElectronicComponent
{

public:
    AndGate();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // ANDGATE_H
