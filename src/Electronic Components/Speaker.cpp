#include "Electronic Components/Speaker.h"

Speaker::Speaker() : ElectronicComponent(200, 100, "Speaker"){}

//Drawing the component:
void Speaker::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    line(center_x - height / 1.5, up_left_y, center_x + height / 1.5, up_left_y);
    line(center_x - height / 1.5, up_left_y, center_x - height / 4, center_y - height / 10);
    line(center_x + height / 1.5, up_left_y, center_x + height / 4, center_y - height / 10);
    line(center_x - height / 3, center_y - height / 10, center_x + height / 3, center_y - height / 10);
    line(center_x - height / 3, center_y + height / 10, center_x + height / 3, center_y + height / 10);
    line(center_x - height / 3, center_y - height / 10, center_x - height / 3, center_y + height / 10);
    line(center_x + height / 3, center_y - height / 10, center_x + height / 3, center_y + height / 10);
    circle(up_left_x + height / 20, center_y, height / 20);
    line(up_left_x + height / 10, center_y, center_x - height / 3, center_y);
    line(center_x + height / 3, center_y, down_right_x - height / 10, center_y);
    circle(down_right_x - height / 20, center_y, height / 20);
}
