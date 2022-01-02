#ifndef SOURCE_VOLTAGE_AC_H
#define SOURCE_VOLTAGE_AC_H

#include "Electronic Components/ElectronicComponent.h"

class Source_Voltage_AC : public ElectronicComponent{

public:
    Source_Voltage_AC();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SOURCE_VOLTAGE_AC_H
