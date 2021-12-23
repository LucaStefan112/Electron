#include "Electronic Components/Logic Gates/OrGate.h"

Helper OrGate_Helper;

OrGate::OrGate(): ElectronicComponent(200, 50, "Or Gate", 3){}

//Drawing the component:
void OrGate::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    OrGate_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y - height / 4, getPositionCenter(), height / 10,
        rotateState);

    OrGate_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y - height / 4, center_x - thisHeight / 3, center_y - height / 4, getPositionCenter(),
        rotateState);

    OrGate_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y + height / 4, getPositionCenter(), height / 10,
        rotateState);

    OrGate_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y + height / 4, center_x - thisHeight / 3, center_y + height / 4, getPositionCenter(),
        rotateState);

    OrGate_Helper.rotationalArc(
        center_x - thisHeight / 1.5, center_y + 1.5 * height, getPositionCenter(), 49, 89, 2 * height,
        rotateState, flipped);

    OrGate_Helper.rotationalArc(
        center_x - thisHeight / 1.5, center_y - 1.5 * height, getPositionCenter(), -89, -49, 2 * height,
        rotateState, flipped);

    OrGate_Helper.rotationalArc(
        center_x - thisHeight / 1.3, center_y, getPositionCenter(), -72, 72, height / 1.9,
        rotateState, flipped);

    OrGate_Helper.rotationalLine(
        center_x + thisHeight / 1.6, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    OrGate_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void OrGate::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = OrGate_Helper.rotatePointToReference(
        OrGate_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y - height / 4),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = OrGate_Helper.rotatePointToReference(
        OrGate_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y + height / 4),
        getPositionCenter(),
        rotateState);

    connectionPoints[2].position = OrGate_Helper.rotatePointToReference(
        OrGate_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);
}
