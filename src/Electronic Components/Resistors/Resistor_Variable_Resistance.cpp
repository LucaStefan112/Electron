#include "Electronic Components/Resistors/Resistor_Variable_Resistance.h"

Helper Resistor_Variable_Resistance_Helper;

Resistor_Variable_Resistance::Resistor_Variable_Resistance(): ElectronicComponent(200, 50, "Variable Resistance Resistor", 2){}

//Drawing the component:
void Resistor_Variable_Resistance::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Resistor_Variable_Resistance_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight, center_y, getPositionCenter(),
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        center_x - thisHeight + 0 * thisHeight / 3, center_y, center_x - thisHeight + 1 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        center_x - thisHeight + 1 * thisHeight / 3, up_left_y + height / 4, center_x - thisHeight + 2 * thisHeight / 3, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        center_x - thisHeight + 2 * thisHeight / 3, down_right_y - height / 4, center_x - thisHeight + 3 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        center_x - thisHeight + 3 * thisHeight / 3, up_left_y + height / 4, center_x - thisHeight + 4 * thisHeight / 3, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        center_x - thisHeight + 4 * thisHeight / 3, down_right_y - height / 4, center_x - thisHeight + 5 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        center_x - thisHeight + 5 * thisHeight / 3, up_left_y + height / 4, center_x + thisHeight, center_y, getPositionCenter(),
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        center_x - thisHeight / 2, down_right_y, center_x + thisHeight / 2 - thisHeight / 15, up_left_y + height / 15, getPositionCenter(),
        rotateState);

    int points[] = {
        int(center_x + thisHeight / 3.5), int(up_left_y + height / 15),
        int(center_x + thisHeight / 2), int(up_left_y),
        int(center_x + thisHeight / 2.1), int(up_left_y + height / 5)
    };

    Resistor_Variable_Resistance_Helper.rotationalFillPoly(
        3, points, getPositionCenter(), rotateState);

    Resistor_Variable_Resistance_Helper.rotationalLine(
        center_x + thisHeight, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Resistor_Variable_Resistance_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Resistor_Variable_Resistance::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Resistor_Variable_Resistance_Helper.rotatePointToReference(
        Resistor_Variable_Resistance_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Resistor_Variable_Resistance_Helper.rotatePointToReference(
        Resistor_Variable_Resistance_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);
}

void Resistor_Variable_Resistance::setResistance(double thisResistance){
    resistance = thisResistance;
}

double Resistor_Variable_Resistance::getResistance(){
    return resistance;
}
