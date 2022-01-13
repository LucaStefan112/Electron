#include "Electronic Components/Lamp.h"

Helper Lamp_Helper;

Lamp::Lamp() : ElectronicComponent(200, 50, "Lamp", 2) {}

//Drawing the component:
void Lamp::Show()
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

    Lamp_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Lamp_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Lamp_Helper.rotationalLine(
        center_x - thisHeight / 3, center_y - height / 3, center_x + thisHeight / 3, center_y + height / 3, getPositionCenter(),
        rotateState);

    Lamp_Helper.rotationalCircle(
        center_x, center_y, getPositionCenter(), height / 2,
        rotateState);

    Lamp_Helper.rotationalLine(
        center_x - thisHeight / 3, center_y + height / 3, center_x + thisHeight / 3, center_y - height / 3, getPositionCenter(),
        rotateState);

    Lamp_Helper.rotationalLine(
        down_right_x - thisHeight / 5, center_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Lamp_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Lamp::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Lamp_Helper.rotatePointToReference(
                                       Lamp_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Lamp_Helper.rotatePointToReference(
                                       Lamp_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}
