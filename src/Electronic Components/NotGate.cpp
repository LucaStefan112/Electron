#include "Electronic Components/NotGate.h"

Helper NotGate_helper;

NotGate::NotGate(): ElectronicComponent(200, 50, "NotGate"){}

//Drawing the component:
void NotGate::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2, center_y);
    line(center_x - height / 2, up_left_y, center_x - height / 2, down_right_y);
    line(center_x - height / 2, up_left_y, center_x + height / 2, center_y);
    line(center_x - height / 2, down_right_y, center_x + height / 2, center_y);
    circle(center_x + height / 2 + height / 5, center_y, height / 5);
    line(center_x + height / 2 + height / 2.5, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
