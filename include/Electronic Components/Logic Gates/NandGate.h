#ifndef NANDGATE_H
#define NANDGATE_H

#include "Electronic Components/ElectronicComponent.h"

class NandGate : public ElectronicComponent
{

public:
    NandGate();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // NANDGATE_H
