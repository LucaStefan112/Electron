#include "Electronic Components/Motor.h"

Motor::Motor(): ElectronicComponent(200, 50, "Motor"){}

//Drawing the component:
void Motor::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2, center_y);
    circle(center_x, center_y, height / 2);

    line(center_x - height / 5, center_y - height / 5, center_x - height / 5, center_y + height / 5);
    line(center_x - height / 5, center_y - height / 5, center_x, center_y);
    line(center_x + height / 5, center_y - height / 5, center_x, center_y);
    line(center_x + height / 5, center_y - height / 5, center_x + height / 5, center_y + height / 5);

    line(center_x + height / 2, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
