#ifndef LAMP_H
#define LAMP_H

#include "Electronic Components/ElectronicComponent.h"

class Lamp : public ElectronicComponent{

public:
    Lamp();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // LAMP_H
