#ifndef DIODE_VARACTOR_H
#define DIODE_VARACTOR_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Varactor : public ElectronicComponent
{

public:
    Diode_Varactor();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_VARACTOR_H
