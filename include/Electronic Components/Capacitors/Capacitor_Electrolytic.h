#ifndef CAPACITOR_ELECTROLYTIC_H
#define CAPACITOR_ELECTROLYTIC_H

#include "Electronic Components/ElectronicComponent.h"

class Capacitor_Electrolytic : public ElectronicComponent{

public:
    Capacitor_Electrolytic();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // CAPACITOR_ELECTROLYTIC_H
