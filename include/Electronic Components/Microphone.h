#ifndef MICROPHONE_H
#define MICROPHONE_H

#include "Electronic Components/ElectronicComponent.h"

class Microphone : public ElectronicComponent
{

public:
    Microphone();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // MICROPHONE_H
