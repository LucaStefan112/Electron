#include "Electronic Components/Switches/Switch_SPDT.h"

Switch_SPDT::Switch_SPDT(): ElectronicComponent(200, 50, "SPDT Switch"){}

//Drawing the component:
void Switch_SPDT::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2 - height / 10, center_y);
    circle(center_x - height / 2, center_y, height / 10);

    line(center_x - height / 2 + height / 13, center_y - height / 25, center_x + height / 2 - height / 13, up_left_y + height / 10 + height / 25);

    circle(center_x + height / 2, up_left_y + height / 10, height / 10);
    line(center_x + height / 2 + height / 10, up_left_y + height / 10, down_right_x - height / 5, up_left_y + height / 10);
    circle(down_right_x - height / 10, up_left_y + height / 10, height / 10);

    circle(center_x + height / 2, down_right_y - height / 10, height / 10);
    line(center_x + height / 2 + height / 10, down_right_y - height / 10, down_right_x - height / 5, down_right_y - height / 10);
    circle(down_right_x - height / 10, down_right_y - height / 10, height / 10);
}
