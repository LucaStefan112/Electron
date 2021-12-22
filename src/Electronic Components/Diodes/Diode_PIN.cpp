#include "Electronic Components/Diodes/Diode_PIN.h"

Diode_PIN::Diode_PIN(): ElectronicComponent(200, 50, "PIN Diode", 2){}

//Drawing the component:
void Diode_PIN::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2, center_y);
    line(center_x - height / 2, up_left_y, center_x - height / 2, down_right_y);
    line(center_x - height / 2, up_left_y, center_x + height / 2, center_y);
    line(center_x - height / 2, down_right_y, center_x + height / 2, center_y);

    int points[] = {
        int(center_x + height), int(center_y),
        int(center_x + height - height / 4), int(center_y - height / 3),
        int(center_x + height - height / 4 - height / 3), int(center_y - height / 3),
        int(center_x + height - height / 3), int(center_y)};

    fillpoly(4, points);

    line(center_x + height + height / 10, up_left_y, center_x + height + height / 10, down_right_y);
    line(center_x + height / 2, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
