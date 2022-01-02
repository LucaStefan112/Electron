#ifndef SOURCE_VOLTAGE_DC_H
#define SOURCE_VOLTAGE_DC_H

#include "Electronic Components/ElectronicComponent.h"

class Source_Voltage_DC : public ElectronicComponent{

public:
    Source_Voltage_DC();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SOURCE_VOLTAGE_DC_H
