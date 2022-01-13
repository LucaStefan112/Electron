#ifndef SWITCH_DPST_H
#define SWITCH_DPST_H

#include "Electronic Components/ElectronicComponent.h"

class Switch_DPST : public ElectronicComponent
{

public:
    Switch_DPST();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SWITCH_DPST_H
