#ifndef MICROPHONE_H
#define MICROPHONE_H

#include "Electronic Components/ElectronicComponent.h"

class Microphone : public ElectronicComponent{

public:
    Microphone();

    //Drawing the component:
    void Show();
};

#endif // MICROPHONE_H
