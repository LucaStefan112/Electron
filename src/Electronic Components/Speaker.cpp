#include "Electronic Components/Speaker.h"

Helper Speaker_Helper;

Speaker::Speaker() : ElectronicComponent(200, 100, "Speaker", 2){}

//Drawing the component:
void Speaker::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Speaker_Helper.rotationalCircle(
        up_left_x + thisHeight / 20, center_y + 3 * height / 8, getPositionCenter(), height / 20,
        rotateState);

    Speaker_Helper.rotationalLine(
        up_left_x + thisHeight / 10, center_y + 3 * height / 8, center_x - thisHeight / 2, center_y + 3 * height / 8, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalLine(
        center_x - thisHeight / 1.5, up_left_y, center_x + thisHeight / 1.5, up_left_y, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalLine(
        center_x - thisHeight / 1.5, up_left_y, center_x - thisHeight / 4, center_y + height / 4, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalLine(
        center_x + thisHeight / 1.5, up_left_y, center_x + thisHeight / 4, center_y + height / 4, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalLine(
        center_x - thisHeight / 2, down_right_y, center_x + thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalLine(
        center_x - thisHeight / 2, center_y + height / 4, center_x + thisHeight / 2, center_y + height / 4, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalLine(
        center_x - thisHeight / 2, down_right_y, center_x - thisHeight / 2, center_y + height / 4, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalLine(
        center_x + thisHeight / 2, down_right_y, center_x + thisHeight / 2, center_y + height / 4, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalLine(
        center_x + thisHeight / 2, center_y + 3 * height / 8, down_right_x - thisHeight / 10, center_y + 3 * height / 8, getPositionCenter(),
        rotateState);

    Speaker_Helper.rotationalCircle(
        down_right_x - thisHeight / 20, center_y + 3 * height / 8, getPositionCenter(), height / 20,
        rotateState);

    showElements();
}

void Speaker::updateConnectionPointsPosition(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Speaker_Helper.rotatePointToReference(
        Speaker_Helper.makeVector_2D(up_left_x + thisHeight / 20, center_y + 3 * height / 8),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Speaker_Helper.rotatePointToReference(
        Speaker_Helper.makeVector_2D(down_right_x - thisHeight / 20, center_y + 3 * height / 8),
        getPositionCenter(),
        rotateState);
}
