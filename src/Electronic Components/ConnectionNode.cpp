#include "Electronic Components/ConnectionNode.h"

Helper ConnectionNode_Helper;

ConnectionNode::ConnectionNode() : ElectronicComponent(10, 10, "Connection Node", 1){}

//Drawing the component:
void ConnectionNode::Show(){
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;

    fillellipse(center_x, center_y, height, width);

    showElements();
}

void ConnectionNode::updateConnectionPointsPosition(){
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;

    connectionPoints[0].position = ConnectionNode_Helper.rotatePointToReference(
        ConnectionNode_Helper.makeVector_2D(center_x, center_y),
        getPositionCenter(),
        rotateState);
}
