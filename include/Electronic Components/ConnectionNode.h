#ifndef CONNECTIONNODE_H
#define CONNECTIONNODE_H

#include "Electronic Components/ElectronicComponent.h"

class ConnectionNode : public ElectronicComponent{

public:
    ConnectionNode();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // CONNECTIONNODE_H
