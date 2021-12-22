#include "Electronic Components/Logic Gates/XorGate.h"

XorGate::XorGate(): ElectronicComponent(200, 50, "Xor Gate", 0){}

//Drawing the component:
void XorGate::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    circle(up_left_x + height / 10, center_y - height / 4, height / 10);
    line(up_left_x + height / 5, center_y - height / 4, center_x - height / 2, center_y - height / 4);
    circle(up_left_x + height / 10, center_y + height / 4, height / 10);
    line(up_left_x + height / 5, center_y + height / 4, center_x - height / 2, center_y + height / 4);
    ellipse(center_x - 1.5 * height, center_y, -65, 65,2 * height, height / 2);
    ellipse(center_x - height / 1.3, center_y, -65, 65,height / 3, height / 2);
    ellipse(center_x - height / 1, center_y, -65, 65,height / 3, height / 2);
    line(center_x + height / 2, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
