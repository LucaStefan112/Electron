#ifndef CAPACITOR_TRIMMER_H
#define CAPACITOR_TRIMMER_H

#include "Electronic Components/ElectronicComponent.h"

class Capacitor_Trimmer : public ElectronicComponent{

private:
    double capacitance = 0;

public:
    Capacitor_Trimmer();

    //Setters:
    void setCapacitance(double thisCapacitance);

    //Getters:
    double getCapacitance();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // CAPACITOR_TRIMMER_H
