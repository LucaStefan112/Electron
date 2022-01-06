#include "Electronic Components/Microphone.h"

Helper Microphone_Helper;

Microphone::Microphone() : ElectronicComponent(200, 100, "Microphone", 2){}

//Drawing the component:
void Microphone::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    int points[] = {
        int(up_left_x), int(up_left_y),
        int(up_left_x + thisHeight / 7), int(up_left_y),
        int(up_left_x + thisHeight / 7), int(down_right_y),
        int(up_left_x), int(down_right_y)
    };

    Microphone_Helper.rotationalFillPoly(
        4, points, getPositionCenter(),
        rotateState);

    Microphone_Helper.rotationalCircle(
        up_left_x + thisHeight / 7 + thisHeight / 2, center_y, getPositionCenter(), height / 2,
        rotateState);

    Microphone_Helper.rotationalLine(
        up_left_x + thisHeight / 7 + thisHeight - thisHeight / 10, center_y - height / 4, down_right_x - thisHeight / 10, center_y - height / 4, getPositionCenter(),
        rotateState);

    Microphone_Helper.rotationalLine(
        up_left_x + thisHeight / 7 + thisHeight - thisHeight / 10, center_y + height / 4, down_right_x - thisHeight / 10, center_y + height / 4, getPositionCenter(),
        rotateState);

    Microphone_Helper.rotationalCircle(
        down_right_x - thisHeight / 20, center_y - height / 4, getPositionCenter(), height / 20,
        rotateState);

    Microphone_Helper.rotationalCircle(
        down_right_x - thisHeight / 20, center_y + height / 4, getPositionCenter(), height / 20,
        rotateState);

    showElements();
}

void Microphone::updateConnectionPointsPosition(){
    double up_left_x = getPositionUpLeft().x;
    double center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Microphone_Helper.rotatePointToReference(
        Microphone_Helper.makeVector_2D(down_right_x - thisHeight / 20, center_y - height / 4),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Microphone_Helper.rotatePointToReference(
        Microphone_Helper.makeVector_2D(down_right_x - thisHeight / 20, center_y + height / 4),
        getPositionCenter(),
        rotateState);
}
