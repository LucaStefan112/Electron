#ifndef BUZZER_H
#define BUZZER_H

#include "ElectronicComponent.h"

class Buzzer : public ElectronicComponent{

public:
    Buzzer();

    //Drawing the component:
    void Show();
};

#endif // BUZZER_H
