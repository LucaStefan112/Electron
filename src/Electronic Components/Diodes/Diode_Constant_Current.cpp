#include "Electronic Components/Diodes/Diode_Constant_Current.h"

Diode_Constant_Current::Diode_Constant_Current(): ElectronicComponent(200, 50, "Constant Current Diode"){}

//Drawing the component:
void Diode_Constant_Current::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2, center_y);
    line(center_x - height / 2, up_left_y, center_x - height / 2, down_right_y);
    line(center_x - height / 2, up_left_y, center_x + height / 2, center_y);
    line(center_x - height / 2, down_right_y, center_x + height / 2, center_y);
    line(center_x + height / 2, up_left_y, center_x + height / 2, down_right_y);
    line(center_x + height / 2, up_left_y, center_x + height / 2 + height / 3, up_left_y);
    line(center_x + height / 2, up_left_y, center_x + height / 2 - height / 3, up_left_y);
    line(center_x + height / 2, down_right_y, center_x + height / 2 - height / 3, down_right_y);
    line(center_x + height / 2, down_right_y, center_x + height / 2 + height / 3, down_right_y);
    line(center_x + height / 2, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);

}