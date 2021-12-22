#include "Electronic Components/Resistors/Potentiometer_Mobile_Contact.h"

Potentiometer_Mobile_Contact::Potentiometer_Mobile_Contact(): ElectronicComponent(200, 50, "Mobile Contact Potentiometer", 3){}

//Drawing the component:
void Potentiometer_Mobile_Contact::Show(){
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

    line(center_x + height, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
