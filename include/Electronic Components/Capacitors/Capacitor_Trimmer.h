#ifndef CAPACITOR_TRIMMER_H
#define CAPACITOR_TRIMMER_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Capacitor_Trimmer : public ElectronicComponent
{

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

    std::vector<std::pair<std::string, double>> getValues();
    void setValue(std::string name, double value);
};

#endif // CAPACITOR_TRIMMER_H
