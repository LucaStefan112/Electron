#include "Electronic Components/Transistors/Transistor_Bipolar_PNP.h"

Transistor_Bipolar_PNP::Transistor_Bipolar_PNP() : ElectronicComponent(150, 200, "Bipolar PNP Transistor", 0){}

//Drawing the component:
void Transistor_Bipolar_PNP::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    for(int i = 0; i <= height / 65; i++)
        circle(center_x + width / 6, center_y, width / 3 - i);

    line(down_right_x - height / 6, up_left_y + height / 20, down_right_x - height / 6, center_y - height / 4.5);
    line(down_right_x - height / 6, down_right_y - height / 20, down_right_x - height / 6, center_y + height / 4.5);

    line(down_right_x - height / 6, center_y - height / 4.5, center_x + height / 40, center_y - height / 30);
    line(down_right_x - height / 6, center_y + height / 4.5, center_x + height / 40, center_y + height / 30);

    int poits[] = {
             int(center_x + height / 40), int(center_y + height / 30),
             int(down_right_x - height / 3.5), int(center_y + height / 6),
             int(center_x + height / 7), int(center_y + height / 9)};

    fillpoly(3, poits);

    settextstyle(8, HORIZ_DIR, height / 50);
    if(height / 50 > 1.7){
        outtextxy(up_left_x + height / 20, center_y - height / 5 - 5, "B");
        outtextxy(down_right_x - height / 6 - height / 5 - 5, up_left_y + height / 40, "C");
        outtextxy(down_right_x - height / 6 - height / 5 - 5, down_right_y - height / 40 - height / 6, "E");
    }

    line(up_left_x + height / 20, center_y, center_x, center_y);
    bar(center_x, center_y - height / 8, center_x + height / 40, center_y + height / 8);

    circle(up_left_x + height / 40, center_y, height / 40);
    circle(down_right_x - height / 6, up_left_y + height / 40, height / 40);
    circle(down_right_x - height / 6, down_right_y - height / 40, height / 40);
}
