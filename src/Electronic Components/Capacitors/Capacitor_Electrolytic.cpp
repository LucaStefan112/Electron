#include "Electronic Components/Capacitors/Capacitor_Electrolytic.h"

Helper Capacitor_Electrolytic_Helper;

Capacitor_Electrolytic::Capacitor_Electrolytic(): ElectronicComponent(200, 50, "Electrolytic Capacitor", 2){}

//Drawing the component:
void Capacitor_Electrolytic::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Capacitor_Electrolytic_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Capacitor_Electrolytic_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 4, center_y, getPositionCenter(),
        rotateState);

    Capacitor_Electrolytic_Helper.rotationalLine(
        center_x - thisHeight / 4, up_left_y, center_x - thisHeight / 4, down_right_y, getPositionCenter(),
        rotateState);

    Capacitor_Electrolytic_Helper.rotationalArc(
        center_x + thisHeight / 5 + thisHeight / 1.5, center_y, getPositionCenter(), 130, 230, height / 1.5,
        rotateState, flipped);

    Capacitor_Electrolytic_Helper.rotationalLine(
        center_x - thisHeight / 4 - thisHeight / 5, center_y - height / 5, center_x - thisHeight / 4 - thisHeight / 5, center_y - height / 2, getPositionCenter(),
        rotateState);

    Capacitor_Electrolytic_Helper.rotationalLine(
        center_x - thisHeight / 4 - thisHeight / 2.8, center_y - height / 3.1, center_x - thisHeight / 4 - thisHeight / 20, center_y - height / 3.1, getPositionCenter(),
        rotateState);

    Capacitor_Electrolytic_Helper.rotationalLine(
        center_x + thisHeight / 4.8, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Capacitor_Electrolytic_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

//Updating the positions of the connection points:
void Capacitor_Electrolytic::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x;
    double center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Capacitor_Electrolytic_Helper.rotatePointToReference(
        Capacitor_Electrolytic_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Capacitor_Electrolytic_Helper.rotatePointToReference(
        Capacitor_Electrolytic_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);
}

void Capacitor_Electrolytic::setCapacitance(double thisCapacitance){
    capacitance = thisCapacitance;
}

double Capacitor_Electrolytic::getCapacitance(){
    return capacitance;
}
