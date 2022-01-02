#ifndef POTENTIOMETER_MOBILE_CONTACT_H
#define POTENTIOMETER_MOBILE_CONTACT_H

#include "Electronic Components/ElectronicComponent.h"

class Potentiometer_Mobile_Contact : public ElectronicComponent{

public:
    Potentiometer_Mobile_Contact();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // POTENTIOMETER_MOBILE_CONTACT_H
