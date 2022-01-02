#ifndef SWITCH_OPEN_H
#define SWITCH_OPEN_H

#include "Electronic Components/ElectronicComponent.h"

class Switch_Open : public ElectronicComponent{

public:
    Switch_Open();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SWITCH_OPEN_H
