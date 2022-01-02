#include "Electronic Components/Ground.h"

Helper Ground_Helper;

Ground::Ground(): ElectronicComponent(100, 100, "Ground", 1){}

//Drawing the component:
void Ground::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Ground_Helper.rotationalCircle(
        up_left_x + thisHeight / 20, center_y, getPositionCenter(), height / 20,
        rotateState);

    Ground_Helper.rotationalLine(
        up_left_x + thisHeight / 10, center_y, center_x, center_y, getPositionCenter(),
        rotateState);

    Ground_Helper.rotationalLine(
        center_x, up_left_y, center_x, down_right_y, getPositionCenter(),
        rotateState);

    Ground_Helper.rotationalLine(
        center_x + thisHeight / 4, center_y - height / 4, center_x + thisHeight / 4, center_y + height / 4, getPositionCenter(),
        rotateState);

    Ground_Helper.rotationalLine(
        down_right_x, center_y - height / 8, down_right_x, center_y + height / 8, getPositionCenter(),
        rotateState);

    showElements();
}

void Ground::updateConnectionPointsPosition(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Ground_Helper.rotatePointToReference(
        Ground_Helper.makeVector_2D(up_left_x + thisHeight / 20, center_y),
        getPositionCenter(),
        rotateState);
}
