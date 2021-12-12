#ifndef DIODE_H
#define DIODE_H

#include "ElectronicComponent.h"

class Diode : public ElectronicComponent{

public:
    Diode();

    //Drawing the component:
    void Show();
};

#endif // DIODE_H
