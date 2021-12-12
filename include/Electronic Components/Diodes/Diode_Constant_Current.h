#ifndef DIODE_CONSTANT_CURRENT_H
#define DIODE_CONSTANT_CURRENT_H

#include "ElectronicComponent.h"

class Diode_Constant_Current : public ElectronicComponent{

public:
    Diode_Constant_Current();

    //Drawing the component:
    void Show();
};

#endif // DIODE_CONSTANT_CURRENT_H
