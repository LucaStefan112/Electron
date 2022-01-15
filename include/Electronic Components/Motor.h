#ifndef MOTOR_H
#define MOTOR_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Motor : public ElectronicComponent
{

public:
    Motor();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // MOTOR_H
