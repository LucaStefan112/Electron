#include "Electronic Components/Switches/Switch_Closed.h"

Helper Switch_Closed_Helper;

Switch_Closed::Switch_Closed(): ElectronicComponent(200, 50, "Closed Switch", 2){}

//Drawing the component:
void Switch_Closed::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Switch_Closed_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_Closed_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2 - thisHeight / 10, center_y, getPositionCenter(),
        rotateState);

    Switch_Closed_Helper.rotationalCircle(
        center_x - thisHeight / 2, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_Closed_Helper.rotationalLine(
        center_x - thisHeight / 2 + thisHeight / 10, center_y, center_x + thisHeight / 2 - thisHeight / 10, center_y, getPositionCenter(),
        rotateState);

    Switch_Closed_Helper.rotationalCircle(
        center_x + thisHeight / 2, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_Closed_Helper.rotationalLine(
        center_x + thisHeight / 2 + thisHeight / 10, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Switch_Closed_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Switch_Closed::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Switch_Closed_Helper.rotatePointToReference(
        Switch_Closed_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Switch_Closed_Helper.rotatePointToReference(
        Switch_Closed_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);
}
