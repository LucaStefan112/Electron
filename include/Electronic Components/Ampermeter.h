#ifndef AMPERMETER_H
#define AMPERMETER_H

#include "ElectronicComponent.h"

class Ampermeter : public ElectronicComponent{

public:
    Ampermeter();

    //Drawing the component:
    void Show();
};

#endif // AMPERMETER_H
