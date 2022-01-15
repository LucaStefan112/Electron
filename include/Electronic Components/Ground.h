#ifndef GROUND_H
#define GROUND_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Ground : public ElectronicComponent
{

public:
    Ground();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // GROUND_H
