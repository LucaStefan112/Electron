#ifndef ORGATE_H
#define ORGATE_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class OrGate : public ElectronicComponent
{

public:
    OrGate();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // ORGATE_H
