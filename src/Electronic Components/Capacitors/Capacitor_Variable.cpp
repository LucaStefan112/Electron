#include "Electronic Components/Capacitors/Capacitor_Variable.h"

Helper Capacitor_Variable_Helper;

Capacitor_Variable::Capacitor_Variable(): ElectronicComponent(200, 50, "Variable Capacitor", 2) {}

//Drawing the component:
void Capacitor_Variable::Show()
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

    double diff = thisHeight / 2, sup = thisHeight / 7;

    Capacitor_Variable_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Capacitor_Variable_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 4, center_y, getPositionCenter(),
        rotateState);

    Capacitor_Variable_Helper.rotationalLine(
        center_x - thisHeight / 4, up_left_y, center_x - thisHeight / 4, down_right_y, getPositionCenter(),
        rotateState);

    Capacitor_Variable_Helper.rotationalLine(
        center_x + thisHeight / 4, up_left_y, center_x + thisHeight / 4, down_right_y, getPositionCenter(),
        rotateState);

    int points[] =
    {
        int(center_x - thisHeight / 5 - diff), int(up_left_y + height / 10),
        int(center_x - thisHeight / 10 - diff + sup), int(up_left_y + height / 7),
        int(center_x - thisHeight / 10 - thisHeight / 5 - diff + sup * 1.5), int(up_left_y + height / 5 + height / 7 / 1.5)
    };

    Capacitor_Variable_Helper.rotationalFillPoly(3, points, getPositionCenter(), rotateState);

    Capacitor_Variable_Helper.rotationalLine(
        center_x - thisHeight / 5 - diff, up_left_y + height / 10, center_x + thisHeight / 5 + diff, down_right_y, getPositionCenter(),
        rotateState);

    Capacitor_Variable_Helper.rotationalLine(
        center_x + thisHeight / 4, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Capacitor_Variable_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

//Updating the positions of the connection points:
void Capacitor_Variable::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Capacitor_Variable_Helper.rotatePointToReference(
                                       Capacitor_Variable_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Capacitor_Variable_Helper.rotatePointToReference(
                                       Capacitor_Variable_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}

void Capacitor_Variable::setCapacitance(double thisCapacitance)
{
    capacitance = thisCapacitance;
}

double Capacitor_Variable::getCapacitance()
{
    return capacitance;
}

std::vector<std::pair<std::string, double>> Capacitor_Variable::getValues()
{
    return std::vector<std::pair<std::string, double>> { std::make_pair("capacitance", capacitance) };
};

void Capacitor_Variable::setValue(std::string name, double value)
{
    if (name == "capacitance") capacitance = value;
}
