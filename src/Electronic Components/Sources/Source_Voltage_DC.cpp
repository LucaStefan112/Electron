#include "Electronic Components/Sources/Source_Voltage_DC.h"
//Tamas Luca-Stefan
Helper Source_Voltage_DC_Helper;

Source_Voltage_DC::Source_Voltage_DC() : ElectronicComponent(200, 50, "DC Voltage Source", 2) {}

//Drawing the component:
void Source_Voltage_DC::Show()
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

    Source_Voltage_DC_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Source_Voltage_DC_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Source_Voltage_DC_Helper.rotationalCircle(
        center_x, center_y, getPositionCenter(), height / 2,
        rotateState);

    Source_Voltage_DC_Helper.rotationalLine(
        center_x - 2 * thisHeight / 5 + thisHeight / 15, center_y, center_x - 2 * thisHeight / 5 + thisHeight / 5 + thisHeight / 15, center_y, getPositionCenter(),
        rotateState);

    Source_Voltage_DC_Helper.rotationalLine(
        center_x - 3 * thisHeight / 10 + thisHeight / 15, center_y - height / 10, center_x - 3 * thisHeight / 10 + thisHeight / 15, center_y + height / 10, getPositionCenter(),
        rotateState);

    Source_Voltage_DC_Helper.rotationalLine(
        center_x + 2 * thisHeight / 5 - thisHeight / 15, center_y, center_x + 2 * thisHeight / 5 - thisHeight / 5 - thisHeight / 15, center_y, getPositionCenter(),
        rotateState);

    Source_Voltage_DC_Helper.rotationalLine(
        center_x + thisHeight / 2, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Source_Voltage_DC_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Source_Voltage_DC::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Source_Voltage_DC_Helper.rotatePointToReference(
                                       Source_Voltage_DC_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Source_Voltage_DC_Helper.rotatePointToReference(
                                       Source_Voltage_DC_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}

void Source_Voltage_DC::setVolts(double thisVolts)
{
    volts = thisVolts;
}

void Source_Voltage_DC::setAmpers(double thisAmpers)
{
    ampers = thisAmpers;
}

double Source_Voltage_DC::getVolts()
{
    return volts;
}

double Source_Voltage_DC::getAmpers()
{
    return ampers;
}

std::vector<std::pair<std::string, double>> Source_Voltage_DC::getValues()
{
    return std::vector<std::pair<std::string, double>> { std::make_pair("volts", volts), std::make_pair("ampers", ampers) };
}

void Source_Voltage_DC::setValue(std::string name, double value)
{
    if (name == "volts") volts = value;
    if (name == "ampers") ampers = value;
}
