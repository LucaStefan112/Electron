#ifndef TRANSISTOR_BIPOLAR_NPN_H
#define TRANSISTOR_BIPOLAR_NPN_H

#include "ElectronicComponent.h"

class Transistor_Bipolar_NPN : public ElectronicComponent{

public:
    Transistor_Bipolar_NPN();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_BIPOLAR_NPN_H
