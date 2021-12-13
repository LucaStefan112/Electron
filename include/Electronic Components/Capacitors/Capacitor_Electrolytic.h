#ifndef CAPACITOR_ELECTROLYTIC_H
#define CAPACITOR_ELECTROLYTIC_H

#include "ElectronicComponent.h"

class Capacitor_Electrolytic : public ElectronicComponent{

public:
    Capacitor_Electrolytic();

    //Drawing the component:
    void Show();
};

#endif // CAPACITOR_ELECTROLYTIC_H
