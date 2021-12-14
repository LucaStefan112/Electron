#include "Electronic Components/Resistors/Resistor_Mobile_Contact_Stop_Position.h"

Resistor_Mobile_Contact_Stop_Position::Resistor_Mobile_Contact_Stop_Position(): ElectronicComponent(200, 50, "Mobile Contact and Stop Position Resistor"){}

//Drawing the component:
void Resistor_Mobile_Contact_Stop_Position::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height, center_y);
    line(center_x - height + 0 * height / 3, center_y, center_x - height + 1 * height / 3, up_left_y + height / 4);
    line(center_x - height + 1 * height / 3, up_left_y + height / 4, center_x - height + 2 * height / 3, down_right_y - height / 4);
    line(center_x - height + 2 * height / 3, down_right_y - height / 4, center_x - height + 3 * height / 3, up_left_y + height / 4);
    line(center_x - height + 3 * height / 3, up_left_y + height / 4, center_x - height + 4 * height / 3, down_right_y - height / 4);
    line(center_x - height + 4 * height / 3, down_right_y - height / 4, center_x - height + 5 * height / 3, up_left_y + height / 4);
    line(center_x - height + 5 * height / 3, up_left_y + height / 4, center_x + height, center_y);

    line(center_x, up_left_y + height / 10, down_right_x - height / 5, up_left_y + height / 10);
    circle(down_right_x - height / 10, up_left_y + height / 10, height / 10);

    int poins[] = {
        int(center_x), int(up_left_y + height / 4 - height / 60),
        int(center_x - height / 15), int(up_left_y + height / 4 - height / 6.8),
        int(center_x + height / 15), int(up_left_y + height / 4 - height / 6.8)};

    fillpoly(3, poins);

    bar(center_x + height, center_y + height / 4, center_x + height + height / 10, center_y - height / 4);
}
