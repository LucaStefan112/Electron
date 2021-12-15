#ifndef VOLTMETER_H
#define VOLTMETER_H

#include "Electronic Components/ElectronicComponent.h"

class Voltmeter : public ElectronicComponent{

public:
    Voltmeter();

    //Drawing the component:
    void Show();
};

#endif // VOLTMETER_H
