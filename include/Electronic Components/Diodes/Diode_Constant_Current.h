#ifndef DIODE_CONSTANT_CURRENT_H
#define DIODE_CONSTANT_CURRENT_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Constant_Current : public ElectronicComponent{

public:
    Diode_Constant_Current();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_CONSTANT_CURRENT_H
