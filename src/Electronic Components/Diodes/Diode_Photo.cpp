#include "Electronic Components/Diodes/Diode_Photo.h"

Diode_Photo::Diode_Photo(): ElectronicComponent(200, 100, "Photo Diode", 2){}

//Drawing the component:
void Diode_Photo::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y + height / 4;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y + height / 8;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    double distance = height / 10;

    circle(up_left_x + height / 20, center_y, height / 20);
    line(up_left_x + height / 10, center_y, center_x - height / 4, center_y);
    line(center_x - height / 4, up_left_y, center_x - height / 4, down_right_y);
    line(center_x - height / 4, up_left_y, center_x + height / 4, center_y);
    line(center_x - height / 4, down_right_y, center_x + height / 4, center_y);
    line(center_x + height / 4, up_left_y, center_x + height / 4, down_right_y);
    line(center_x + height / 4, center_y, down_right_x - height / 10, center_y);
    circle(down_right_x - height / 20, center_y, height / 20);

    line(center_x, up_left_y, center_x + height / 4, up_left_y - height / 4);
    line(center_x, up_left_y, center_x + height / 12, up_left_y);
    line(center_x, up_left_y, center_x, up_left_y - height / 12);

    line(center_x + distance, up_left_y + distance, center_x + height / 4 + distance, up_left_y - height / 4 + distance);
    line(center_x + distance, up_left_y + distance, center_x + distance + height / 12, up_left_y + distance);
    line(center_x + distance, up_left_y + distance, center_x + distance, up_left_y + distance - height / 12);
}
