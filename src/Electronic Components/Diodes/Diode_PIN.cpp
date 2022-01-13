#include "Electronic Components/Diodes/Diode_PIN.h"

Helper Diode_PIN_Helper;

Diode_PIN::Diode_PIN(): ElectronicComponent(200, 50, "PIN Diode", 2) {}

//Drawing the component:
void Diode_PIN::Show()
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

    Diode_PIN_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Diode_PIN_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Diode_PIN_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x - thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    Diode_PIN_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Diode_PIN_Helper.rotationalLine(
        center_x - thisHeight / 2, down_right_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    int points[] =
    {
        int(center_x + thisHeight), int(center_y),
        int(center_x + thisHeight - thisHeight / 4), int(center_y - height / 3),
        int(center_x + thisHeight - thisHeight / 4 - thisHeight / 3), int(center_y - height / 3),
        int(center_x + thisHeight - thisHeight / 3), int(center_y)
    };

    Diode_PIN_Helper.rotationalFillPoly(
        4, points, getPositionCenter(), rotateState);

    Diode_PIN_Helper.rotationalLine(
        center_x + thisHeight + thisHeight / 10, up_left_y, center_x + thisHeight + thisHeight / 10, down_right_y, getPositionCenter(),
        rotateState);

    Diode_PIN_Helper.rotationalLine(
        center_x + thisHeight / 2, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Diode_PIN_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Diode_PIN::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Diode_PIN_Helper.rotatePointToReference(
                                       Diode_PIN_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Diode_PIN_Helper.rotatePointToReference(
                                       Diode_PIN_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}
