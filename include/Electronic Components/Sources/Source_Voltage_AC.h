#ifndef SOURCE_VOLTAGE_AC_H
#define SOURCE_VOLTAGE_AC_H

#include "ElectronicComponent.h"

class Source_Voltage_AC : public ElectronicComponent{

public:
    Source_Voltage_AC();

    //Drawing the component:
    void Show();
};

#endif // SOURCE_VOLTAGE_AC_H
