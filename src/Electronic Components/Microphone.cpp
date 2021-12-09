#include "Electronic Components/Microphone.h"

Microphone::Microphone() : ElectronicComponent(100, 50, "Microphone"){}

//Drawing the component:
void Microphone::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    bar(up_left_x, up_left_y, up_left_x + height / 7, down_right_y);
    circle(up_left_x + height / 7 + height / 2, center_y, height / 2);
    line(up_left_x + height / 7 + height - height / 10, center_y - height / 4, down_right_x - height / 5, center_y - height / 4);
    line(up_left_x + height / 7 + height - height / 10, center_y + height / 4, down_right_x - height / 5, center_y + height / 4);
    circle(down_right_x - height / 10, center_y - height / 4, height / 10);
    circle(down_right_x - height / 10, center_y + height / 4, height / 10);
}
