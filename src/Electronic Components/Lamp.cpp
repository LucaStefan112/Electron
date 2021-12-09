#include "Electronic Components/Lamp.h"

Lamp::Lamp() : ElectronicComponent(200, 50, "Lamp"){}

//Drawing the component:
void Lamp::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2, center_y);
    circle(center_x, center_y, height / 2);
    line(center_x + height / 2, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);

    line(center_x - height / 3, center_y - height / 3, center_x + height / 3, center_y + height / 3);
    line(center_x - height / 3, center_y + height / 3, center_x + height / 3, center_y - height / 3);
}
