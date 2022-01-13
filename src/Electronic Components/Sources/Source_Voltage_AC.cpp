#include "Electronic Components/Sources/Source_Voltage_AC.h"

Helper Source_Voltage_AC_Helper;

Source_Voltage_AC::Source_Voltage_AC() : ElectronicComponent(200, 50, "AC Voltage Source", 2) {}

//Drawing the component:
void Source_Voltage_AC::Show()
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

    Source_Voltage_AC_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Source_Voltage_AC_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Source_Voltage_AC_Helper.rotationalCircle(
        center_x, center_y, getPositionCenter(), height / 2,
        rotateState);

    Source_Voltage_AC_Helper.rotationalArc(
        center_x - thisHeight / 4.7, center_y - height / 15, getPositionCenter(), 30, 160, height / 7,
        rotateState, flipped);

    Source_Voltage_AC_Helper.rotationalArc(
        center_x + thisHeight / 4.7, center_y + height / 15, getPositionCenter(), 210, 340, height / 7,
        rotateState, flipped);

    Source_Voltage_AC_Helper.rotationalLine(
        center_x - thisHeight / 13 - thisHeight / 20, center_y - height / 9 - height / 20, center_x + thisHeight / 13 + thisHeight / 20, center_y + height / 9 + height / 20, getPositionCenter(),
        rotateState);

    Source_Voltage_AC_Helper.rotationalLine(
        center_x + thisHeight / 2, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Source_Voltage_AC_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Source_Voltage_AC::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Source_Voltage_AC_Helper.rotatePointToReference(
                                       Source_Voltage_AC_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Source_Voltage_AC_Helper.rotatePointToReference(
                                       Source_Voltage_AC_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}

void Source_Voltage_AC::setVolts(double thisVolts)
{
    volts = thisVolts;
}

void Source_Voltage_AC::setAmpers(double thisAmpers)
{
    ampers = thisAmpers;
}

double Source_Voltage_AC::getVolts()
{
    return volts;
}

double Source_Voltage_AC::getAmpers()
{
    return ampers;
}

std::vector<std::pair<std::string, double>> Source_Voltage_AC::getValues()
{
    return std::vector<std::pair<std::string, double>> { std::make_pair("volts", volts), std::make_pair("ampers", ampers) };
};

void Source_Voltage_AC::setValue(std::string name, double value)
{
    if (name == "volts") volts = value;
    if (name == "ampers") ampers = value;
}
