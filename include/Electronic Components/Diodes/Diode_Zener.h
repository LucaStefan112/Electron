#ifndef DIODE_ZENER_H
#define DIODE_ZENER_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Zener : public ElectronicComponent
{

public:
    Diode_Zener();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_ZENER_H
