#include "Electronic Components/Transistors/Transistor_Dual_Gate_MOSFET_Nchannel.h"

Transistor_Dual_Gate_MOSFET_Nchannel::Transistor_Dual_Gate_MOSFET_Nchannel() : ElectronicComponent(150, 200, "Dual Gate MOSFET N-channel Transistor"){}

//Drawing the component:
void Transistor_Dual_Gate_MOSFET_Nchannel::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    for(int i = 0; i <= height / 65; i++)
        circle(center_x + width / 6, center_y, width / 3 - i);

    line(down_right_x - height / 6, up_left_y + height / 20, down_right_x - height / 6, center_y - height / 15);
    line(down_right_x - height / 6, down_right_y - height / 20, down_right_x - height / 6, center_y);
    line(center_x + height / 10, center_y, down_right_x - height / 6, center_y);

    line(down_right_x - height / 6, center_y - height / 15, center_x + height / 10, center_y - height / 15);
    line(down_right_x - height / 6, center_y + height / 15, center_x + height / 10, center_y + height / 15);

    int poits[] = {
             int(center_x + height / 10), int(center_y),
             int(center_x + height / 5.5), int(center_y + height / 30),
             int(center_x + height / 5.5), int(center_y - height / 30)};

    fillpoly(3, poits);

    settextstyle(8, HORIZ_DIR, height / 50);
    if(height / 50 > 1.7){
        outtextxy(down_right_x - height / 6 - height / 5 - 5, up_left_y + height / 40, "D");
        outtextxy(up_left_x + height / 20, center_y - height / 4.5 - 5, "G2");
        outtextxy(up_left_x + height / 20, center_y + height / 8 + height / 20, "G1");
        outtextxy(down_right_x - height / 6 - height / 5 - 5, down_right_y - height / 40 - height / 6, "S");
    }

    line(up_left_x + height / 20, center_y + height / 8, center_x, center_y + height / 8);
    line(center_x, center_y + height / 8, center_x, center_y + height / 20);

    line(up_left_x + height / 20, center_y - height / 20, center_x, center_y - height / 20);
    line(center_x, center_y - height / 20, center_x, center_y - height / 8);

    bar(center_x + height / 20, center_y - height / 8, center_x + height / 10, center_y + height / 8);

    circle(up_left_x + height / 40, center_y + height / 8, height / 40);
    circle(up_left_x + height / 40, center_y - height / 20, height / 40);

    circle(down_right_x - height / 6, up_left_y + height / 40, height / 40);
    circle(down_right_x - height / 6, down_right_y - height / 40, height / 40);
}
