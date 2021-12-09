#include "Electronic Components/Rezistor.h"

Rezistor::Rezistor(): ElectronicComponent(200, 50, "Rezistor"){}

//Drawing the component:
void Rezistor::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height, center_y);
    line(center_x - height + 0 * height / 3, center_y, center_x - height + 1 * height / 3, up_left_y + height / 4);
    line(center_x - height + 1 * height / 3, up_left_y + height / 4, center_x - height + 2 * height / 3, down_right_y - height / 4);
    line(center_x - height + 2 * height / 3, down_right_y - height / 4, center_x - height + 3 * height / 3, up_left_y + height / 4);
    line(center_x - height + 3 * height / 3, up_left_y + height / 4, center_x - height + 4 * height / 3, down_right_y - height / 4);
    line(center_x - height + 4 * height / 3, down_right_y - height / 4, center_x - height + 5 * height / 3, up_left_y + height / 4);
    line(center_x - height + 5 * height / 3, up_left_y + height / 4, center_x + height, center_y);
    line(center_x + height, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
