#include "Electronic Components/Ground.h"

Ground::Ground(): ElectronicComponent(50, 50, "Ground", 1){}

//Drawing the component:
void Ground::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x, center_y);
    line(center_x, up_left_y, center_x, down_right_y);
    line(center_x + width / 4, center_y - height / 4, center_x + width / 4, center_y + height / 4);
    line(down_right_x, center_y - height / 8, down_right_x, center_y + height / 8);
}
