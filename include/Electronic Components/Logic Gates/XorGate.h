#ifndef XORGATE_H
#define XORGATE_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class XorGate : public ElectronicComponent
{

public:
    XorGate();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // XORGATE_H
