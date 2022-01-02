#ifndef VOLTMETER_H
#define VOLTMETER_H

#include "Electronic Components/ElectronicComponent.h"

class Voltmeter : public ElectronicComponent{

public:
    Voltmeter();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // VOLTMETER_H
