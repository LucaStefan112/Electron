#ifndef CAPACITOR_VARIABLE_H
#define CAPACITOR_VARIABLE_H

#include "Electronic Components/ElectronicComponent.h"

class Capacitor_Variable : public ElectronicComponent{

public:
    Capacitor_Variable();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // CAPACITOR_VARIABLE_H
