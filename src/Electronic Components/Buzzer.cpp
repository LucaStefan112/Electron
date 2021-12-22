#include "Electronic Components/Buzzer.h"

Buzzer::Buzzer() : ElectronicComponent(100, 100, "Buzzer", 0){}

//Drawing the component:
void Buzzer::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    line(up_left_x, up_left_y, down_right_x, up_left_y);
    arc(center_x, up_left_y, 180, 360, height / 2);
    line(center_x - height / 4, up_left_y + height / 2.3, center_x - height / 4, down_right_y - height / 10);
    line(center_x + height / 4, up_left_y + height / 2.3, center_x + height / 4, down_right_y - height / 10);
    circle(center_x - height / 4, down_right_y - height / 20, height / 20);
    circle(center_x + height / 4, down_right_y - height / 20, height / 20);
}
