#include "Electronic Components/Diodes/Diode_Transient_Voltage_Suppression.h"

Diode_Transient_Voltage_Suppression::Diode_Transient_Voltage_Suppression(): ElectronicComponent(200, 50, "Transient Voltage Suppression Diode"){}

//Drawing the component:
void Diode_Transient_Voltage_Suppression::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height, center_y);

    line(center_x - height, up_left_y, center_x - height, down_right_y);
    line(center_x - height, up_left_y, center_x, center_y);
    line(center_x - height, down_right_y, center_x, center_y);

    line(center_x, up_left_y, center_x, down_right_y);

    line(center_x + height, up_left_y, center_x + height, down_right_y);
    line(center_x + height, up_left_y, center_x, center_y);
    line(center_x + height, down_right_y, center_x, center_y);

    line(center_x + height, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}
