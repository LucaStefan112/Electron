#ifndef NORGATE_H
#define NORGATE_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class NorGate : public ElectronicComponent
{

public:
    NorGate();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // NORGATE_H
