#include "Electronic Components/Capacitors/Capacitor_Electrolytic.h"

Capacitor_Electrolytic::Capacitor_Electrolytic(): ElectronicComponent(200, 50, "Electrolytic Capacitor"){}

//Drawing the component:
void Capacitor_Electrolytic::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 4 + height / 5, center_y);

    line(center_x - height / 4 + height / 5, up_left_y, center_x - height / 4 + height / 5, down_right_y);
    ellipse(center_x + height / 4 + height / 5, center_y, 90, 270, height / 4, height / 2.1);

    line(center_x - height / 4 - height / 5, center_y - height / 5, center_x - height / 4 - height / 5, center_y - height / 2);
    line(center_x - height / 4 - height / 2.8, center_y - height / 3.1, center_x - height / 4 - height / 20, center_y - height / 3.1);

    line(center_x + height / 4, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}

