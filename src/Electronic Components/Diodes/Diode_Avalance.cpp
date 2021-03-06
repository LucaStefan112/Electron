#include "Electronic Components/Diodes/Diode_Avalance.h"
//Tamas Luca-Stefan
Helper Diode_Avalance_Helper;

Diode_Avalance::Diode_Avalance(): ElectronicComponent(200, 50, "Avalance Diode", 2) {}

//Drawing the component:
void Diode_Avalance::Show()
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

    Diode_Avalance_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Diode_Avalance_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Diode_Avalance_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x - thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    Diode_Avalance_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Diode_Avalance_Helper.rotationalLine(
        center_x - thisHeight / 2, down_right_y, center_x + thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Diode_Avalance_Helper.rotationalLine(
        center_x + thisHeight / 2, up_left_y, center_x + thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    Diode_Avalance_Helper.rotationalLine(
        center_x + thisHeight / 2, up_left_y, center_x + thisHeight / 4, up_left_y, getPositionCenter(),
        rotateState);

    Diode_Avalance_Helper.rotationalLine(
        center_x + thisHeight / 2, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Diode_Avalance_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();

}

void Diode_Avalance::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Diode_Avalance_Helper.rotatePointToReference(
                                       Diode_Avalance_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Diode_Avalance_Helper.rotatePointToReference(
                                       Diode_Avalance_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}
