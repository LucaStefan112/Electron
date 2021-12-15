#ifndef SPEAKER_H
#define SPEAKER_H

#include "Electronic Components/ElectronicComponent.h"

class Speaker : public ElectronicComponent{

public:
    Speaker();

    //Drawing the component:
    void Show();
};

#endif // SPEAKER_H
