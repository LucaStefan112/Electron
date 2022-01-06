#include "Electronic Components/Measurements/Ammeter.h"

Helper Ammeter_Helper;

Ammeter::Ammeter() : ElectronicComponent(200, 50, "Ammeter", 2){}

//Drawing the component:
void Ammeter::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Ammeter_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Ammeter_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2, center_y, getPositionCenter(),
        rotateState);

    Ammeter_Helper.rotationalCircle(
        center_x, center_y, getPositionCenter(), height / 2,
        rotateState);

    Ammeter_Helper.rotationalLine(
        center_x - thisHeight / 4, center_y + height / 5, center_x, up_left_y + height / 5, getPositionCenter(),
        rotateState);

    Ammeter_Helper.rotationalLine(
        center_x + thisHeight / 4, center_y + height / 5, center_x, up_left_y + height / 5, getPositionCenter(),
        rotateState);

    Ammeter_Helper.rotationalLine(
        center_x - thisHeight / 7.2, center_y, center_x + thisHeight / 7.2, center_y, getPositionCenter(),
        rotateState);

    Ammeter_Helper.rotationalLine(
        center_x + thisHeight / 2, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Ammeter_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Ammeter::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x;
    double center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Ammeter_Helper.rotatePointToReference(
        Ammeter_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Ammeter_Helper.rotatePointToReference(
        Ammeter_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);
}

void Ammeter::setCurrent(double thisCurrent){
    current = thisCurrent;
}

double Ammeter::getCurrent(){
    return current;
}
