#include "Electronic Components/Logic Gates/NotGate.h"

Helper NotGate_Helper;

NotGate::NotGate(): ElectronicComponent(200, 50, "Not Gate", 2){}

//Drawing the component:
void NotGate::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    NotGate_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    NotGate_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    NotGate_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x - thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    NotGate_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    NotGate_Helper.rotationalLine(
        center_x - thisHeight / 2, down_right_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    NotGate_Helper.rotationalCircle(
        center_x + thisHeight / 2 + thisHeight / 5, center_y, getPositionCenter(), height / 5,
        rotateState);

    NotGate_Helper.rotationalLine(
        center_x + thisHeight / 2 + 2 * thisHeight / 5, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    NotGate_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void NotGate::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = NotGate_Helper.rotatePointToReference(
        NotGate_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = NotGate_Helper.rotatePointToReference(
        NotGate_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

}
