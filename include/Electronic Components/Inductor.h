#ifndef INDUCTOR_H
#define INDUCTOR_H

#include "Electronic Components/ElectronicComponent.h"

class Inductor : public ElectronicComponent{

public:
    Inductor();

    //Drawing the component:
    void Show();
};

#endif // INDUCTOR_H
