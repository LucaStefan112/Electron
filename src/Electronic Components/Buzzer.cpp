#include "Electronic Components/Buzzer.h"

Helper Buzzer_Helper;

Buzzer::Buzzer() : ElectronicComponent(100, 100, "Buzzer", 2){}

//Drawing the component:
void Buzzer::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Buzzer_Helper.rotationalCircle(
        center_x - thisHeight / 4, down_right_y - height / 20, getPositionCenter(), height / 20,
        rotateState);

    Buzzer_Helper.rotationalLine(
        up_left_x, up_left_y, down_right_x, up_left_y, getPositionCenter(),
        rotateState);

    Buzzer_Helper.rotationalArc(
        center_x, up_left_y, getPositionCenter(), 180, 360, height / 2,
        rotateState, flipped);

    Buzzer_Helper.rotationalLine(
        center_x - thisHeight / 4, up_left_y + height / 2.3, center_x - thisHeight / 4, down_right_y - height / 10, getPositionCenter(),
        rotateState);

    Buzzer_Helper.rotationalLine(
        center_x + thisHeight / 4, up_left_y + height / 2.3, center_x + thisHeight / 4, down_right_y - height / 10, getPositionCenter(),
        rotateState);

    Buzzer_Helper.rotationalCircle(
        center_x + thisHeight / 4, down_right_y - height / 20, getPositionCenter(), height / 20,
        rotateState);

    showElements();
}

void Buzzer::updateConnectionPointsPosition(){
    double up_left_x = getPositionUpLeft().x;
    double center_x = getPositionCenter().x;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Buzzer_Helper.rotatePointToReference(
        Buzzer_Helper.makeVector_2D(center_x - thisHeight / 4, down_right_y - height / 20),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Buzzer_Helper.rotatePointToReference(
        Buzzer_Helper.makeVector_2D(center_x + thisHeight / 4, down_right_y - height / 20),
        getPositionCenter(),
        rotateState);
}
