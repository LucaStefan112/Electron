#include "Electronic Components/Resistors/Resistor_Mobile_Contact_Stop_Position.h"

Helper Resistor_Mobile_Contact_Stop_Position_Helper;

Resistor_Mobile_Contact_Stop_Position::Resistor_Mobile_Contact_Stop_Position(): ElectronicComponent(200, 50, "Mobile Contact and Stop Position Resistor", 2) {}

//Drawing the component:
void Resistor_Mobile_Contact_Stop_Position::Show()
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

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight, center_y, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalLine(
        center_x - thisHeight + 0 * thisHeight / 3, center_y, center_x - thisHeight + 1 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalLine(
        center_x - thisHeight + 1 * thisHeight / 3, up_left_y + height / 4, center_x - thisHeight + 2 * thisHeight / 3, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalLine(
        center_x - thisHeight + 2 * thisHeight / 3, down_right_y - height / 4, center_x - thisHeight + 3 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalLine(
        center_x - thisHeight + 3 * thisHeight / 3, up_left_y + height / 4, center_x - thisHeight + 4 * thisHeight / 3, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalLine(
        center_x - thisHeight + 4 * thisHeight / 3, down_right_y - height / 4, center_x - thisHeight + 5 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalLine(
        center_x - thisHeight + 5 * thisHeight / 3, up_left_y + height / 4, center_x + thisHeight, center_y, getPositionCenter(),
        rotateState);

    int points1[] =
    {
        int(center_x + thisHeight), int(center_y + height / 4),
        int(center_x + 11 *  thisHeight / 10), int(center_y + height / 4),
        int(center_x + 11 *  thisHeight / 10), int(center_y - height / 4),
        int(center_x + thisHeight), int(center_y - height / 4),
    };

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalFillPoly(
        4, points1, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalLine(
        center_x, up_left_y + height / 10, down_right_x - thisHeight / 5, up_left_y + height / 10, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, up_left_y + height / 10, getPositionCenter(), height / 10,
        rotateState);

    int poins[] =
    {
        int(center_x), int(up_left_y + height / 4 - height / 60),
        int(center_x - thisHeight / 15), int(up_left_y + height / 4 - height / 6.8),
        int(center_x + thisHeight / 15), int(up_left_y + height / 4 - height / 6.8)
    };

    Resistor_Mobile_Contact_Stop_Position_Helper.rotationalFillPoly(
        3, poins, getPositionCenter(), rotateState);

    showElements();
}

void Resistor_Mobile_Contact_Stop_Position::updateConnectionPointsPosition()
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

    connectionPoints[0].position = Resistor_Mobile_Contact_Stop_Position_Helper.rotatePointToReference(
                                       Resistor_Mobile_Contact_Stop_Position_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Resistor_Mobile_Contact_Stop_Position_Helper.rotatePointToReference(
                                       Resistor_Mobile_Contact_Stop_Position_Helper.makeVector_2D(down_right_x - thisHeight / 10, up_left_y + height / 10),
                                       getPositionCenter(),
                                       rotateState);
}

void Resistor_Mobile_Contact_Stop_Position::setResistance(double thisResistance)
{
    resistance = thisResistance;
}

double Resistor_Mobile_Contact_Stop_Position::getResistance()
{
    return resistance;
}

std::vector<std::pair<std::string, double>> Resistor_Mobile_Contact_Stop_Position::getValues()
{
    return std::vector<std::pair<std::string, double>> { std::make_pair("resistance", resistance) };
};

void Resistor_Mobile_Contact_Stop_Position::setValue(std::string name, double value)
{
    if (name == "resistance") resistance = value;
}
