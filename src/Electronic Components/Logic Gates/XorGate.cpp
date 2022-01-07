#include "Electronic Components/Logic Gates/XorGate.h"

Helper XorGate_Helper;

XorGate::XorGate(): ElectronicComponent(200, 50, "Xor Gate", 3){}

//Drawing the component:
void XorGate::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    XorGate_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y - height / 4, getPositionCenter(), height / 10,
        rotateState);

    XorGate_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y - height / 4, center_x - thisHeight / 1.8, center_y - height / 4, getPositionCenter(),
        rotateState);

    XorGate_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y + height / 4, getPositionCenter(), height / 10,
        rotateState);

    XorGate_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y + height / 4, center_x - thisHeight / 1.8, center_y + height / 4, getPositionCenter(),
        rotateState);

    XorGate_Helper.rotationalArc(
        center_x - thisHeight / 1.5, center_y + 1.5 * height, getPositionCenter(), 49, 89, 2 * height,
        rotateState, flipped);

    XorGate_Helper.rotationalArc(
        center_x - thisHeight / 1.5, center_y - 1.5 * height, getPositionCenter(), -89, -49, 2 * height,
        rotateState, flipped);

    XorGate_Helper.rotationalArc(
        center_x - thisHeight, center_y, getPositionCenter(), -72, 72, height / 1.9,
        rotateState, flipped);

    XorGate_Helper.rotationalArc(
        center_x - thisHeight / 1.3, center_y, getPositionCenter(), -72, 72, height / 1.9,
        rotateState, flipped);

    XorGate_Helper.rotationalLine(
        center_x + thisHeight / 1.6, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    XorGate_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void XorGate::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = XorGate_Helper.rotatePointToReference(
        XorGate_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y - height / 4),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = XorGate_Helper.rotatePointToReference(
        XorGate_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y + height / 4),
        getPositionCenter(),
        rotateState);

    connectionPoints[2].position = XorGate_Helper.rotatePointToReference(
        XorGate_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);
}
