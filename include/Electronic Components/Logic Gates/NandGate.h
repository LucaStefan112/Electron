#ifndef NANDGATE_H
#define NANDGATE_H

#include "Electronic Components/ElectronicComponent.h"

class NandGate : public ElectronicComponent{

public:
    NandGate();

    //Drawing the component:
    void Show();
};

#endif // NANDGATE_H
