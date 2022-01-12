#include "Electronic Components/Resistors/Resistor_Mobile_Contact.h"

Helper Resistor_Mobile_Contact_Helper;

Resistor_Mobile_Contact::Resistor_Mobile_Contact(): ElectronicComponent(200, 50, "Mobile Contact Resistor", 2){}

//Drawing the component:
void Resistor_Mobile_Contact::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Resistor_Mobile_Contact_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight, center_y, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalLine(
        center_x - thisHeight + 0 * thisHeight / 3, center_y, center_x - thisHeight + 1 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalLine(
        center_x - thisHeight + 1 * thisHeight / 3, up_left_y + height / 4, center_x - thisHeight + 2 * thisHeight / 3, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalLine(
        center_x - thisHeight + 2 * thisHeight / 3, down_right_y - height / 4, center_x - thisHeight + 3 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalLine(
        center_x - thisHeight + 3 * thisHeight / 3, up_left_y + height / 4, center_x - thisHeight + 4 * thisHeight / 3, down_right_y - height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalLine(
        center_x - thisHeight + 4 * thisHeight / 3, down_right_y - height / 4, center_x - thisHeight + 5 * thisHeight / 3, up_left_y + height / 4, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalLine(
        center_x - thisHeight + 5 * thisHeight / 3, up_left_y + height / 4, center_x + thisHeight, center_y, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalLine(
        center_x, up_left_y + height / 10, down_right_x - thisHeight / 5, up_left_y + height / 10, getPositionCenter(),
        rotateState);

    Resistor_Mobile_Contact_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, up_left_y + height / 10, getPositionCenter(), height / 10,
        rotateState);

    int poins[] = {
        int(center_x), int(up_left_y + height / 4 - height / 60),
        int(center_x - thisHeight / 15), int(up_left_y + height / 4 - height / 6.8),
        int(center_x + thisHeight / 15), int(up_left_y + height / 4 - height / 6.8)};

    Resistor_Mobile_Contact_Helper.rotationalFillPoly(
        3, poins, getPositionCenter(), rotateState);

    showElements();
}

void Resistor_Mobile_Contact::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Resistor_Mobile_Contact_Helper.rotatePointToReference(
        Resistor_Mobile_Contact_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Resistor_Mobile_Contact_Helper.rotatePointToReference(
        Resistor_Mobile_Contact_Helper.makeVector_2D(down_right_x - thisHeight / 10, up_left_y + height / 10),
        getPositionCenter(),
        rotateState);
}

void Resistor_Mobile_Contact::setResistance(double thisResistance){
    resistance = thisResistance;
}

double Resistor_Mobile_Contact::getResistance(){
    return resistance;
}

std::vector<std::pair<std::string, double>> Resistor_Mobile_Contact::getValues() {
    return std::vector<std::pair<std::string, double>> { std::make_pair("resistance", resistance) };
};

void Resistor_Mobile_Contact::setValue(std::string name, double value) {
    if (name == "resistance") resistance = value;
}
