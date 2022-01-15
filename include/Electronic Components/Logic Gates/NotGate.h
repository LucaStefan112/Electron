#ifndef NOTGATE_H
#define NOTGATE_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class NotGate : public ElectronicComponent
{

public:
    NotGate();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // NOTGATE_H
