#include "Electronic Components/Switches/Switch_Telegraph.h"

Helper Switch_Telegraph_Helper;

Switch_Telegraph::Switch_Telegraph(): ElectronicComponent(200, 50, "Telegraph Switch", 2){}

//Drawing the component:
void Switch_Telegraph::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Switch_Telegraph_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_Telegraph_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2 - thisHeight / 10, center_y, getPositionCenter(),
        rotateState);

    Switch_Telegraph_Helper.rotationalCircle(
        center_x - thisHeight / 2, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_Telegraph_Helper.rotationalLine(
        center_x - thisHeight  * 0.41, center_y - height * 0.044721, center_x + thisHeight / 2 - thisHeight / 9, up_left_y, getPositionCenter(),
        rotateState);

    Switch_Telegraph_Helper.rotationalCircle(
        center_x + thisHeight / 2, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_Telegraph_Helper.rotationalLine(
        center_x - thisHeight / 5, center_y - height / 6, center_x - thisHeight / 5, up_left_y + height / 10, getPositionCenter(),
        rotateState);

    Switch_Telegraph_Helper.rotationalLine(
        center_x - thisHeight / 5 - thisHeight / 10, up_left_y + height / 10, center_x - thisHeight / 10, up_left_y + height / 10, getPositionCenter(),
        rotateState);

    Switch_Telegraph_Helper.rotationalLine(
        center_x + thisHeight / 2 + thisHeight / 10, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Switch_Telegraph_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Switch_Telegraph::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x;
    double center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Switch_Telegraph_Helper.rotatePointToReference(
        Switch_Telegraph_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Switch_Telegraph_Helper.rotatePointToReference(
        Switch_Telegraph_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);
}
