#ifndef DIODE_GUNN_H
#define DIODE_GUNN_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Gunn : public ElectronicComponent
{

public:
    Diode_Gunn();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_GUNN_H
