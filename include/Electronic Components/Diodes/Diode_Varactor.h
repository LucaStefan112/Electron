#ifndef DIODE_VARACTOR_H
#define DIODE_VARACTOR_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Varactor : public ElectronicComponent{

public:
    Diode_Varactor();

    //Drawing the component:
    void Show();
};

#endif // DIODE_VARACTOR_H
