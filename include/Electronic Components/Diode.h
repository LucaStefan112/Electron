#ifndef DIODE_H
#define DIODE_H

#include <string>
#include "ElectronicComponent.h"

class Diode : public ElectronicComponent{

public:
    Diode();

    //Drawing the component:
    void Show();

    std::string toString();
};

#endif // DIODE_H

