#include "Electronic Components/Logic Gates/NandGate.h"

Helper NandGate_Helper;

NandGate::NandGate(): ElectronicComponent(200, 50, "Nand Gate", 3){}

//Drawing the component:
void NandGate::Show(){
        double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    NandGate_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y - height / 4, getPositionCenter(), height / 10,
        rotateState);

    NandGate_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y - height / 4, center_x - thisHeight / 2, center_y - height / 4, getPositionCenter(),
        rotateState);

    NandGate_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y + height / 4, getPositionCenter(), height / 10,
        rotateState);

    NandGate_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y + height / 4, center_x - thisHeight / 2, center_y + height / 4, getPositionCenter(),
        rotateState);

    NandGate_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x, up_left_y, getPositionCenter(),
        rotateState);

    NandGate_Helper.rotationalLine(
        center_x - thisHeight / 2, down_right_y, center_x, down_right_y, getPositionCenter(),
        rotateState);

    NandGate_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x - thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    NandGate_Helper.rotationalEllipse(
        center_x, center_y, getPositionCenter(), -90, 90, height / 2, height / 2,
        rotateState, flipped);

    NandGate_Helper.rotationalCircle(
        center_x + thisHeight / 2 + thisHeight / 5, center_y, getPositionCenter(), height / 5,
        rotateState);

    NandGate_Helper.rotationalLine(
        center_x + thisHeight / 2 + 2 * thisHeight / 5, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    NandGate_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void NandGate::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x;
    double center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = NandGate_Helper.rotatePointToReference(
        NandGate_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y - height / 4),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = NandGate_Helper.rotatePointToReference(
        NandGate_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y + height / 4),
        getPositionCenter(),
        rotateState);

    connectionPoints[2].position = NandGate_Helper.rotatePointToReference(
        NandGate_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);
}
