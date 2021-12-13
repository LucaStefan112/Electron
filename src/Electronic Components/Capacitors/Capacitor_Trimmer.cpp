#include "Electronic Components/Capacitors/Capacitor_Trimmer.h"

Capacitor_Trimmer::Capacitor_Trimmer(): ElectronicComponent(200, 50, "Trimmer Capacitor"){}

//Drawing the component:
void Capacitor_Trimmer::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    double diff = height / 2;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 4, center_y);
    line(center_x - height / 4, up_left_y, center_x - height / 4, down_right_y);
    line(center_x + height / 4, up_left_y, center_x + height / 4, down_right_y);
    line(center_x + height / 4, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);

    line(center_x - height / 10 - diff, up_left_y, center_x - height / 10 - height / 5 - diff, up_left_y + height / 5);
    line(center_x - height / 5 - diff, up_left_y + height / 10, center_x + height / 5 + diff, down_right_y);
}

