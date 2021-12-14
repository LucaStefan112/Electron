#include "Electronic Components/Switches/Switch_Thermal_Magnetic_Breaker.h"

Switch_Thermal_Magnetic_Breaker::Switch_Thermal_Magnetic_Breaker(): ElectronicComponent(200, 50, "Thermal Magnetic Breaker Switch"){}

//Drawing the component:
void Switch_Thermal_Magnetic_Breaker::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y + height / 10;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y + height / 10;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    const double sinAngle = 0.4472135955, cosAngle = 0.894427191, off = height / 5;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 2 - height / 10, center_y);
    circle(center_x - height / 2, center_y, height / 10);
    line(center_x - height / 2 + height / 10 * cosAngle, center_y - height / 10 * sinAngle, center_x + height / 2 - height / 9, up_left_y);
    circle(center_x + height / 2, center_y, height / 10);
    line(center_x + height / 2 + height / 10, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);

    int points[] = {
        int(center_x - height / 5), int(up_left_y - height / 10),
        int(center_x - height / 5 - height / 10), int(up_left_y + height / 10),
        int(center_x - height / 5 + height / 10), int(up_left_y + height / 10)
    };

    fillpoly(3, points);

    line(center_x - height / 5, center_y - height / 6, center_x - height / 5, up_left_y - height / 10);
}
