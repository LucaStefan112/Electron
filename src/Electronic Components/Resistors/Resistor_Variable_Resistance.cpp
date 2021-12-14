#include "Electronic Components/Resistors/Resistor_Variable_Resistance.h"

Resistor_Variable_Resistance::Resistor_Variable_Resistance(): ElectronicComponent(200, 50, "Variable Resistance Resistor"){}

//Drawing the component:
void Resistor_Variable_Resistance::Show(){
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

    line(center_x - height / 2, down_right_y, center_x + height / 2 - height / 15, up_left_y + height / 15);

    line(center_x + height / 2 - height / 10, up_left_y + height / 40, center_x + height / 2, up_left_y);
    line(center_x + height / 2 - height / 40, up_left_y + height / 10, center_x + height / 2, up_left_y);
    line(center_x + height / 2 - height / 10, up_left_y + height / 40, center_x + height / 2 - height / 40, up_left_y + height / 10);
}