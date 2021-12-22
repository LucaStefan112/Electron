#include "Electronic Components/Diodes/Diode_Laser.h"

Diode_Laser::Diode_Laser(): ElectronicComponent(200, 100, "Laser Diode", 2){}

//Drawing the component:
void Diode_Laser::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y + height / 4;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y + height / 8;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    double distance = height / 5;

    circle(up_left_x + height / 20, center_y, height / 20);
    line(up_left_x + height / 10, center_y, center_x - height / 4, center_y);
    line(center_x - height / 4, up_left_y + height / 10, center_x - height / 4, down_right_y - height / 10);
    line(center_x - height / 4, up_left_y + height / 10, center_x + height / 4, center_y);
    line(center_x - height / 4, down_right_y - height / 10, center_x + height / 4, center_y);

    line(center_x + height / 4, up_left_y + height / 10, center_x + height / 4, down_right_y - height / 10);
    line(center_x + height / 6, up_left_y + height / 10, center_x + height / 6, down_right_y - height / 10);

    line(center_x + height / 4, center_y, down_right_x - height / 10, center_y);
    circle(down_right_x - height / 20, center_y, height / 20);

    circle(center_x, center_y, height / 2 * 0.75);

    line(center_x + distance / 2, up_left_y - height / 4, center_x + distance / 2, up_left_y - height / 20);
    line(center_x + distance / 2, up_left_y - height / 4, center_x + distance / 2 - height / 20, up_left_y - height / 4 + height / 12);
    line(center_x + distance / 2, up_left_y - height / 4, center_x + distance / 2 + height / 20, up_left_y - height / 4 + height / 12);

    line(center_x - distance / 2, up_left_y - height / 4, center_x - distance / 2, up_left_y - height / 20);
    line(center_x - distance / 2, up_left_y - height / 4, center_x - distance / 2 - height / 20, up_left_y - height / 4 + height / 12);
    line(center_x - distance / 2, up_left_y - height / 4, center_x - distance / 2 + height / 20, up_left_y - height / 4 + height / 12);
}
