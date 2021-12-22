#include "Electronic Components/Switches/Switch_Open.h"

Switch_Open::Switch_Open(): ElectronicComponent(200, 50, "Open Switch", 2){}

//Drawing the component:
void Switch_Open::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    const double sinAngle = 0.4472135955, cosAngle = 0.894427191;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2 - height / 10, center_y);
    circle(center_x - height / 2, center_y, height / 10);
    line(center_x - height / 2 + height / 10 * cosAngle, center_y - height / 10 * sinAngle, center_x + height / 2 - height / 9, up_left_y);
    circle(center_x + height / 2, center_y, height / 10);
    line(center_x + height / 2 + height / 10, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
