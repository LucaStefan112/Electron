#include "Electronic Components/Sources/Battery.h"

Helper Battery_Helper;

Battery::Battery(): ElectronicComponent(200, 50, "Battery", 2) {}

//Drawing the component:
void Battery::Show()
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

    Battery_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Battery_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalLine(
        center_x - thisHeight / 2 - thisHeight / 5, center_y - height / 5 - height / 12, center_x - thisHeight / 2 - thisHeight / 5 - thisHeight / 6, center_y - height / 5 - height / 12, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalLine(
        center_x - thisHeight / 2 - thisHeight / 5 - thisHeight / 12, center_y - height / 5, center_x - thisHeight / 2 - thisHeight / 5 - thisHeight / 12, center_y - height / 5 - height / 6, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalLine(
        center_x - thisHeight / 2, up_left_y, center_x - thisHeight / 2, down_right_y, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalLine(
        center_x - thisHeight / 6, up_left_y + height / 4, center_x - thisHeight / 6, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalLine(
        center_x + thisHeight / 6, up_left_y, center_x + thisHeight / 6, down_right_y, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalLine(
        center_x + thisHeight / 2, up_left_y + height / 4, center_x + thisHeight / 2, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalLine(
        center_x + thisHeight / 2 + thisHeight / 5, center_y - height / 5 - height / 12, center_x + thisHeight / 2 + thisHeight / 5 + thisHeight / 6, center_y - height / 5 - height / 12, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalLine(
        center_x + thisHeight / 2, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Battery_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Battery::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Battery_Helper.rotatePointToReference(
                                       Battery_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Battery_Helper.rotatePointToReference(
                                       Battery_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}

void Battery::setVolts(double thisVolts)
{
    volts = thisVolts;
}

void Battery::setAmpers(double thisAmpers)
{
    ampers = thisAmpers;
}

double Battery::getVolts()
{
    return volts;
}

double Battery::getAmpers()
{
    return ampers;
}

std::vector<std::pair<std::string, double>> Battery::getValues()
{
    return std::vector<std::pair<std::string, double>> { std::make_pair("volts", volts), std::make_pair("ampers", ampers) };
};

void Battery::setValue(std::string name, double value)
{
    if (name == "volts") volts = value;
    if (name == "ampers") ampers = value;
}
