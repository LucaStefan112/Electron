#ifndef SWITCH_TELEGRAPH_H
#define SWITCH_TELEGRAPH_H

#include "Electronic Components/ElectronicComponent.h"

class Switch_Telegraph : public ElectronicComponent
{

public:
    Switch_Telegraph();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SWITCH_TELEGRAPH_H
