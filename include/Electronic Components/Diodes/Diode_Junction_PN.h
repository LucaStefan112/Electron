#ifndef DIODE_JUNCTION_PN_H
#define DIODE_JUNCTION_PN_H

#include "ElectronicComponent.h"

class Diode_Junction_PN : public ElectronicComponent{

public:
    Diode_Junction_PN();

    //Drawing the component:
    void Show();
};

#endif // DIODE_JUNCTION_PN_H
