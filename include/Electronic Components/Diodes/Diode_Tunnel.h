#ifndef DIODE_TUNNEL_H
#define DIODE_TUNNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Tunnel : public ElectronicComponent
{

public:
    Diode_Tunnel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_TUNNEL_H
