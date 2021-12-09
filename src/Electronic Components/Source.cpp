#include "Electronic Components/Source.h"

Source::Source(): ElectronicComponent(200, 50, "Source"){}

//Drawing the component:
void Source::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;
    double offPlus = height / 5;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 4, center_y);
    line(center_x - height / 4, up_left_y, center_x - height / 4, down_right_y);
    line(center_x + height / 4, center_y + height / 4, center_x + height / 4, center_y - height / 4);
    line(center_x + height / 4, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
    line(center_x - height / 4 - offPlus, center_y - offPlus - height / 8, center_x - height / 4 - offPlus - height / 4, center_y - offPlus - height / 8);
    line(center_x - height / 4 - offPlus - height / 8, center_y - offPlus, center_x - height / 4 - offPlus - height / 8, center_y - offPlus - height / 4);
    line(center_x + height / 4 + offPlus, center_y - offPlus - height / 8, center_x + height / 4 + offPlus + height / 4, center_y - offPlus - height / 8);
}
