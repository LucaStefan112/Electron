#include "Electronic Components/Resistors/Resistor.h"

Helper Resistor_Helper;

Resistor::Resistor(): ElectronicComponent(200, 50, "Resistor", 2) {}

//Drawing the component:
void Resistor::Show()
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

    Resistor_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Resistor_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight, center_y, getPositionCenter(),
        rotateState);

    Resistor_Helper.rotationalLine(
        center_x - thisHeight + 0 * thisHeight / 3, center_y, center_x - thisHeight + 1 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Helper.rotationalLine(
        center_x - thisHeight + 1 * thisHeight / 3, up_left_y + height / 4, center_x - thisHeight + 2 * thisHeight / 3, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Resistor_Helper.rotationalLine(
        center_x - thisHeight + 2 * thisHeight / 3, down_right_y - height / 4, center_x - thisHeight + 3 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Helper.rotationalLine(
        center_x - thisHeight + 3 * thisHeight / 3, up_left_y + height / 4, center_x - thisHeight + 4 * thisHeight / 3, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Resistor_Helper.rotationalLine(
        center_x - thisHeight + 4 * thisHeight / 3, down_right_y - height / 4, center_x - thisHeight + 5 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Helper.rotationalLine(
        center_x - thisHeight + 5 * thisHeight / 3, up_left_y + height / 4, center_x + thisHeight, center_y, getPositionCenter(),
        rotateState);

    Resistor_Helper.rotationalLine(
        center_x + thisHeight, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Resistor_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Resistor::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Resistor_Helper.rotatePointToReference(
                                       Resistor_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Resistor_Helper.rotatePointToReference(
                                       Resistor_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}

void Resistor::setResistance(double thisResistance)
{
    resistance = thisResistance;
}

double Resistor::getResistance()
{
    return resistance;
}

std::vector<std::pair<std::string, double>> Resistor::getValues()
{
    return std::vector<std::pair<std::string, double>> { std::make_pair("resistance", resistance) };
};

void Resistor::setValue(std::string name, double value)
{
    if (name == "resistance") resistance = value;
}
