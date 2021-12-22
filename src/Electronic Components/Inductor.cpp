#include "Electronic Components/Inductor.h"

Inductor::Inductor() : ElectronicComponent(200, 50, "Inductor", 2){}

//Drawing the component:
void Inductor::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height, center_y);

    arc(center_x - 2 * height / 3, center_y, 180, 360, height / 3);
    arc(center_x, center_y, 180, 360, height / 3);
    arc(center_x + 2 * height / 3, center_y, 180, 360, height / 3);

    line(center_x + height, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
