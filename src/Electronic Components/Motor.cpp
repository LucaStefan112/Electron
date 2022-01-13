#include "Electronic Components/Motor.h"

Helper Motor_Helper;

Motor::Motor(): ElectronicComponent(200, 50, "Motor", 2) {}

//Drawing the component:
void Motor::Show()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Motor_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Motor_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);
    circle(center_x, center_y, height / 2);

    Motor_Helper.rotationalLine(
        center_x - thisHeight / 5, center_y - height / 5, center_x - thisHeight / 5, center_y + height / 5, getPositionCenter(),
        rotateState);

    Motor_Helper.rotationalLine(
        center_x - thisHeight / 5, center_y - height / 5, center_x, center_y, getPositionCenter(),
        rotateState);

    Motor_Helper.rotationalCircle(
        center_x, center_y, getPositionCenter(), height / 2,
        rotateState);

    Motor_Helper.rotationalLine(
        center_x + thisHeight / 5, center_y - height / 5, center_x + thisHeight / 5, center_y + height / 5, getPositionCenter(),
        rotateState);

    Motor_Helper.rotationalLine(
        center_x + thisHeight / 5, center_y - height / 5, center_x, center_y, getPositionCenter(),
        rotateState);

    Motor_Helper.rotationalLine(
        down_right_x - thisHeight / 5, center_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Motor_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Motor::updateConnectionPointsPosition()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Motor_Helper.rotatePointToReference(
                                       Motor_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Motor_Helper.rotatePointToReference(
                                       Motor_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}
