#ifndef DIODE_LIGHT_EMITTING_H
#define DIODE_LIGHT_EMITTING_H

#include "ElectronicComponent.h"

class Diode_Light_Emitting : public ElectronicComponent{

public:
    Diode_Light_Emitting();

    //Drawing the component:
    void Show();
};

#endif // DIODE_LIGHT_EMITTING_H