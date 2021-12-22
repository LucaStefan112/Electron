#include "Electronic Components/Switches/Switch_Closed.h"

Switch_Closed::Switch_Closed(): ElectronicComponent(200, 50, "Closed Switch", 2){}

//Drawing the component:
void Switch_Closed::Show(){
    double up_left_x = getPositionUpLeft().x;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2 - height / 10, center_y);
    circle(center_x - height / 2, center_y, height / 10);
    line(center_x - height / 2 + height / 10, center_y, center_x + height / 2 - height / 10, center_y);
    circle(center_x + height / 2, center_y, height / 10);
    line(center_x + height / 2 + height / 10, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
