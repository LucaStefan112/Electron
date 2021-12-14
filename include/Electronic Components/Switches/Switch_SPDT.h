#ifndef SWITCH_SPDT_H
#define SWITCH_SPDT_H

#include "ElectronicComponent.h"

class Switch_SPDT : public ElectronicComponent{

public:
    Switch_SPDT();

    //Drawing the component:
    void Show();
};

#endif // SWITCH_SPDT_H
