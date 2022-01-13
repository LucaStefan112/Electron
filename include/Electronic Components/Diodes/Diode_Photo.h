#ifndef DIODE_PHOTO_H
#define DIODE_PHOTO_H

#include "Electronic Components/ElectronicComponent.h"

class Diode_Photo : public ElectronicComponent
{

public:
    Diode_Photo();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_PHOTO_H
