#ifndef DIODE_JUNCTION_PN_H
#define DIODE_JUNCTION_PN_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Diode_Junction_PN : public ElectronicComponent
{

public:
    Diode_Junction_PN();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_JUNCTION_PN_H
