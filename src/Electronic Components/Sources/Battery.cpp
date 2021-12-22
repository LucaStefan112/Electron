#include "Electronic Components/Sources/Battery.h"

Battery::Battery(): ElectronicComponent(200, 50, "Battery", 0){}

//Drawing the component:
void Battery::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    double plusOff  = height / 8;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2, center_y);
    line(center_x - height / 2, up_left_y, center_x - height / 2, down_right_y);
    line(center_x - height / 2 + height / 3, center_y - height / 4, center_x - height / 2 + height / 3, center_y + height / 4);
    line(center_x - height / 2 + 2 * height / 3, up_left_y, center_x - height / 2 + 2 * height / 3, down_right_y);
    line(center_x + height / 2, center_y - height / 4, center_x + height / 2, center_y + height / 4);
    line(center_x + height / 2, center_y, down_right_x - height / 5, center_y);
    line(center_x - height / 1.5 - height / 4 - plusOff, center_y - height / 5 - plusOff, center_x - height / 1.5 - plusOff, center_y - height / 5 - plusOff);
    line(center_x - height / 1.5 - height / 8 - plusOff, center_y - height / 5 - height / 8 - plusOff, center_x - height / 1.5 - height / 8 - plusOff, center_y - height / 5 + height / 8 - plusOff);
    line(center_x + height / 1.1 - height / 4 + plusOff, center_y - height / 5 - plusOff, center_x + height / 1.1 + plusOff, center_y - height / 5 - plusOff);
    circle(down_right_x - height / 10, center_y, height / 10);
}
