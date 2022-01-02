#ifndef RESISTOR_MOBILE_CONTACT_STOP_POSITION_H
#define RESISTOR_MOBILE_CONTACT_STOP_POSITION_H

#include "Electronic Components/ElectronicComponent.h"

class Resistor_Mobile_Contact_Stop_Position : public ElectronicComponent{

public:
    Resistor_Mobile_Contact_Stop_Position();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // RESISTOR_MOBILE_CONTACT_STOP_POSITION_H
