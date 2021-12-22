#include "Electronic Components/Transistors/Transistor_Single_Connection_Pchannel.h"

Transistor_Single_Connection_Pchannel::Transistor_Single_Connection_Pchannel() : ElectronicComponent(150, 200, "Single Connection P-channel Transistor", 3){}

//Drawing the component:
void Transistor_Single_Connection_Pchannel::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    for(int i = 0; i <= height / 65; i++)
        circle(center_x + width / 6, center_y, width / 3 - i);

    line(down_right_x - height / 6, up_left_y + height / 20, down_right_x - height / 6, center_y - height / 15);
    line(down_right_x - height / 6, down_right_y - height / 20, down_right_x - height / 6, center_y + height / 15);

    line(down_right_x - height / 6, center_y - height / 15, center_x + height / 10, center_y - height / 15);
    line(down_right_x - height / 6, center_y + height / 15, center_x + height / 10, center_y + height / 15);

    int poits[] = {
             int(center_x - height / 13), int(center_y + height / 15),
             int(center_x - height / 40), int(center_y + height / 80),
             int(center_x), int(center_y + height / 17)};

    fillpoly(3, poits);

    settextstyle(8, HORIZ_DIR, height / 50);
    if(height / 50 > 1.7){
        outtextxy(down_right_x - height / 6 - height / 5 - 10, up_left_y + height / 40, "B1");
        outtextxy(up_left_x + height / 20, center_y + height / 15 + height / 20, "E");
        outtextxy(down_right_x - height / 6 - height / 5 - 10, down_right_y - height / 40 - height / 6, "B2");
    }

    line(up_left_x + height / 20, center_y + height / 15, center_x - height / 13, center_y + height / 15);
    line(center_x - height / 13, center_y + height / 15, center_x + height / 20, center_y);
    bar(center_x + height / 20, center_y - height / 8, center_x + height / 10, center_y + height / 8);

    circle(up_left_x + height / 40, center_y + height / 15, height / 40);
    circle(down_right_x - height / 6, up_left_y + height / 40, height / 40);
    circle(down_right_x - height / 6, down_right_y - height / 40, height / 40);
}

