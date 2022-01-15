#ifndef INDUCTOR_H
#define INDUCTOR_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Inductor : public ElectronicComponent
{

public:
    Inductor();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // INDUCTOR_H
