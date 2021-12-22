#include "Electronic Components/Switches/Switch_DPST.h"

Switch_DPST::Switch_DPST(): ElectronicComponent(200, 100, "DPST Switch", 0){}

//Drawing the component:
void Switch_DPST::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y - height / 12;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y - height / 12;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y - height / 12;

    circle(up_left_x + height / 20, center_y - height / 20, height / 20);
    line(up_left_x + height / 10, center_y - height / 20, center_x - height / 4 - height / 20, center_y - height / 20);
    circle(center_x - height / 4, center_y - height / 20, height / 20);

    line(center_x - height / 4 + height / 30, center_y - height / 30 - height / 20, center_x + height / 4 - height / 10, up_left_y + height / 6);

    circle(center_x + height / 4, center_y - height / 20, height / 20);
    line(center_x + height / 4 + height / 20, center_y - height / 20, down_right_x - height / 10, center_y - height / 20);
    circle(down_right_x - height / 20, center_y - height / 20, height / 20);

    circle(up_left_x + height / 20, down_right_y - height / 20, height / 20);
    line(up_left_x + height / 10, down_right_y - height / 20, center_x - height / 4 - height / 20, down_right_y - height / 20);
    circle(center_x - height / 4, down_right_y - height / 20, height / 20);

    line(center_x - height / 4 + height / 30, down_right_y - height / 20 - height / 30, center_x + height / 4 - height / 10, center_y + height / 6);

    circle(center_x + height / 4, down_right_y - height / 20, height / 20);
    line(center_x + height / 4 + height / 20, down_right_y - height / 20, down_right_x - height / 10, down_right_y - height / 20);
    circle(down_right_x - height / 20, down_right_y - height / 20, height / 20);
}
