#include "Electronic Components/Measurements/Ammeter.h"

Ammeter::Ammeter() : ElectronicComponent(200, 50, "Ammeter", 0){}

//Drawing the component:
void Ammeter::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    double sin30 = 0.5, cos30 = 0.86602540378;
    double offSet = height / 5;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2, center_y);
    circle(center_x, center_y, height / 2);
    line(center_x - height / 2 * sin30, center_y + height / 2 * cos30 - offSet, center_x, up_left_y + offSet);
    line(center_x + height / 2 * sin30, center_y + height / 2 * cos30 - offSet, center_x, up_left_y + offSet);
    line(center_x - height / 7.2, center_y, center_x + height / 7.2, center_y);
    line(center_x + height / 2, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
