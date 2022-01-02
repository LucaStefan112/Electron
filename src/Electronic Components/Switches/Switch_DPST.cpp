#include "Electronic Components/Switches/Switch_DPST.h"

Helper Switch_DPST_Helper;

Switch_DPST::Switch_DPST(): ElectronicComponent(200, 100, "DPST Switch", 4){}

//Drawing the component:
void Switch_DPST::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Switch_DPST_Helper.rotationalCircle(
        up_left_x + thisHeight / 20, center_y - height / 20 - height / 12, getPositionCenter(),  height / 20,
        rotateState);

    Switch_DPST_Helper.rotationalLine(
        up_left_x + thisHeight / 10, center_y - height / 20 - height / 12, center_x - 3 * thisHeight / 10, center_y - height / 20 - height / 12, getPositionCenter(),
        rotateState);

    Switch_DPST_Helper.rotationalCircle(
        center_x - thisHeight / 4, center_y - height / 20 - height / 12, getPositionCenter(),  height / 20,
        rotateState);

    Switch_DPST_Helper.rotationalLine(
        center_x - thisHeight / 4 + thisHeight / 30, center_y - height / 30 - height / 20 - height / 12, center_x + thisHeight / 4 - thisHeight / 10, up_left_y + height / 12, getPositionCenter(),
        rotateState);

    Switch_DPST_Helper.rotationalCircle(
        center_x + thisHeight / 4, center_y - height / 20 - height / 12, getPositionCenter(),  height / 20,
        rotateState);

    Switch_DPST_Helper.rotationalLine(
        center_x + thisHeight / 4 + thisHeight / 20, center_y - height / 20 - height / 12, down_right_x - thisHeight / 10, center_y - height / 20 - height / 12, getPositionCenter(),
        rotateState);

    Switch_DPST_Helper.rotationalCircle(
        down_right_x - thisHeight / 20, center_y - height / 20 - height / 12, getPositionCenter(),  height / 20,
        rotateState);

    Switch_DPST_Helper.rotationalCircle(
        up_left_x + thisHeight / 20, down_right_y - height / 20 - height / 12, getPositionCenter(),  height / 20,
        rotateState);

    Switch_DPST_Helper.rotationalLine(
        up_left_x + thisHeight / 10, down_right_y - height / 20 - height / 12, center_x - 3 * thisHeight / 10, down_right_y - height / 20 - height / 12, getPositionCenter(),
        rotateState);

    Switch_DPST_Helper.rotationalCircle(
        center_x - thisHeight / 4, down_right_y - height / 20 - height / 12, getPositionCenter(),  height / 20,
        rotateState);

    Switch_DPST_Helper.rotationalLine(
        center_x - thisHeight / 4 + thisHeight / 30, down_right_y - height / 30 - height / 20 - height / 12, center_x + thisHeight / 4 - thisHeight / 10, center_y + height / 12, getPositionCenter(),
        rotateState);

    Switch_DPST_Helper.rotationalCircle(
        center_x + thisHeight / 4, down_right_y - height / 20 - height / 12, getPositionCenter(),  height / 20,
        rotateState);

    Switch_DPST_Helper.rotationalLine(
        center_x + thisHeight / 4 + thisHeight / 20, down_right_y - height / 20 - height / 12, down_right_x - thisHeight / 10, down_right_y - height / 20 - height / 12, getPositionCenter(),
        rotateState);

    Switch_DPST_Helper.rotationalCircle(
        down_right_x - thisHeight / 20, down_right_y - height / 20 - height / 12, getPositionCenter(),  height / 20,
        rotateState);

    showElements();
}

void Switch_DPST::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Switch_DPST_Helper.rotatePointToReference(
        Switch_DPST_Helper.makeVector_2D(up_left_x + thisHeight / 20, center_y - height / 20 - height / 12),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Switch_DPST_Helper.rotatePointToReference(
        Switch_DPST_Helper.makeVector_2D(down_right_x - thisHeight / 20, center_y - height / 20 - height / 12),
        getPositionCenter(),
        rotateState);

    connectionPoints[2].position = Switch_DPST_Helper.rotatePointToReference(
        Switch_DPST_Helper.makeVector_2D(up_left_x + thisHeight / 20, down_right_y - height / 20 - height / 12),
        getPositionCenter(),
        rotateState);

    connectionPoints[3].position = Switch_DPST_Helper.rotatePointToReference(
        Switch_DPST_Helper.makeVector_2D(down_right_x - thisHeight / 20, down_right_y - height / 20 - height / 12),
        getPositionCenter(),
        rotateState);
}
