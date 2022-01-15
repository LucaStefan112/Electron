#ifndef SPEAKER_H
#define SPEAKER_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Speaker : public ElectronicComponent
{

public:
    Speaker();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // SPEAKER_H
