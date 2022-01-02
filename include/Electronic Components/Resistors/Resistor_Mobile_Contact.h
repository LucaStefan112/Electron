#ifndef RESISTOR_MOBILE_CONTACT_H
#define RESISTOR_MOBILE_CONTACT_H

#include "Electronic Components/ElectronicComponent.h"

class Resistor_Mobile_Contact : public ElectronicComponent{

public:
    Resistor_Mobile_Contact();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // RESISTOR_MOBILE_CONTACT_H
