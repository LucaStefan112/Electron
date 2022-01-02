#ifndef BUZZER_H
#define BUZZER_H

#include "Electronic Components/ElectronicComponent.h"

class Buzzer : public ElectronicComponent{

public:
    Buzzer();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // BUZZER_H
