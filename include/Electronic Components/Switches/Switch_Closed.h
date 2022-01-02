#ifndef SWITCH_CLOSED_H
#define SWITCH_CLOSED_H

#include "Electronic Components/ElectronicComponent.h"

class Switch_Closed : public ElectronicComponent{

public:
    Switch_Closed();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SWITCH_CLOSED_H
