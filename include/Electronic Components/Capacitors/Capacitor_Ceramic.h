#ifndef CAPACITOR_CERAMIC_H
#define CAPACITOR_CERAMIC_H

#include "Electronic Components/ElectronicComponent.h"

class Capacitor_Ceramic : public ElectronicComponent{

public:
    Capacitor_Ceramic();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // CAPACITOR_CERAMIC_H
