#include "Electronic Components/Switches/Switch_Thermal_Magnetic_Breaker.h"
//Tamas Luca-Stefan
Helper Switch_Thermal_Magnetic_Breaker_Helper;

Switch_Thermal_Magnetic_Breaker::Switch_Thermal_Magnetic_Breaker(): ElectronicComponent(200, 50, "Thermal Magnetic Breaker Switch", 2) {}

//Drawing the component:
void Switch_Thermal_Magnetic_Breaker::Show()
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

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2 - thisHeight / 10, center_y, getPositionCenter(),
        rotateState);

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalCircle(
        center_x - thisHeight / 2, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalLine(
        center_x - thisHeight  * 0.41, center_y - height * 0.044721, center_x + thisHeight / 2 - thisHeight / 9, up_left_y, getPositionCenter(),
        rotateState);

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalCircle(
        center_x + thisHeight / 2, center_y, getPositionCenter(), height / 10,
        rotateState);

    int points[] =
    {
        int(center_x - thisHeight / 5), int(up_left_y),
        int(center_x - thisHeight / 5 - height / 10), int(up_left_y + height / 5),
        int(center_x - thisHeight / 5 + height / 10), int(up_left_y + height / 5)
    };

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalFillPoly(
        3, points, getPositionCenter(),
        rotateState);

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalLine(
        center_x - thisHeight / 5, center_y - height / 6, center_x - thisHeight / 5, up_left_y, getPositionCenter(),
        rotateState);

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalLine(
        center_x + thisHeight / 2 + thisHeight / 10, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Switch_Thermal_Magnetic_Breaker_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Switch_Thermal_Magnetic_Breaker::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Switch_Thermal_Magnetic_Breaker_Helper.rotatePointToReference(
                                       Switch_Thermal_Magnetic_Breaker_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Switch_Thermal_Magnetic_Breaker_Helper.rotatePointToReference(
                                       Switch_Thermal_Magnetic_Breaker_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}
