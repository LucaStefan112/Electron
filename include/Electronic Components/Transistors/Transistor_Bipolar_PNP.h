#ifndef TRANSISTOR_BIPOLAR_PNP_H
#define TRANSISTOR_BIPOLAR_PNP_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_Bipolar_PNP : public ElectronicComponent{

public:
    Transistor_Bipolar_PNP();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_BIPOLAR_PNP_H
