#ifndef SWITCH_SPDT_H
#define SWITCH_SPDT_H

#include "Electronic Components/ElectronicComponent.h"

class Switch_SPDT : public ElectronicComponent
{

public:
    Switch_SPDT();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SWITCH_SPDT_H
