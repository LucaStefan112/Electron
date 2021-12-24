#include "Electronic Components/Transistors/Transistor_Bipolar_NPN.h"

Helper Transistor_Bipolar_NPN_Helper;

Transistor_Bipolar_NPN::Transistor_Bipolar_NPN() : ElectronicComponent(150, 200, "Bipolar NPN Transistor", 3){}

//Drawing the component:
void Transistor_Bipolar_NPN::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    for(int i = 0; i <= height / 65; i++)
        Transistor_Bipolar_NPN_Helper.rotationalCircle(
            center_x + thisHeight / 9, center_y, getPositionCenter(),  2 * height / 9 - i,
            rotateState);

    Transistor_Bipolar_NPN_Helper.rotationalLine(
        down_right_x - thisHeight / 6, up_left_y + height / 15, down_right_x - thisHeight / 6, center_y - height / 4.5, getPositionCenter(),
        rotateState);

    Transistor_Bipolar_NPN_Helper.rotationalLine(
        down_right_x - thisHeight / 6, down_right_y - height / 15, down_right_x - thisHeight / 6, center_y + height / 4.5, getPositionCenter(),
        rotateState);

    Transistor_Bipolar_NPN_Helper.rotationalLine(
        down_right_x - thisHeight / 6, center_y - height / 4.5, center_x + thisHeight / 30, center_y - height / 30, getPositionCenter(),
        rotateState);

    Transistor_Bipolar_NPN_Helper.rotationalLine(
        down_right_x - thisHeight / 6, center_y + height / 4.5, center_x + thisHeight / 30, center_y + height / 30, getPositionCenter(),
        rotateState);

    int points[] = {
             int(down_right_x - thisHeight / 5.5), int(center_y + height / 5),
             int(down_right_x - thisHeight / 6 - thisHeight / 10), int(center_y + height / 4.5 - height / 20),
             int(down_right_x - thisHeight / 6 - thisHeight / 30), int(center_y + height / 4.5 - height / 10)};

    Transistor_Bipolar_NPN_Helper.rotationalFillPoly(
        3, points, getPositionCenter(),
        rotateState);

    settextstyle(8, HORIZ_DIR, 3);
    if(height / 50 > 2){
        Transistor_Bipolar_NPN_Helper.rotationalOuttextxy(
            down_right_x - thisHeight / 6 - thisHeight / 5 - 5, up_left_y + height / 40, getPositionCenter(), "C",
            rotateState);

        Transistor_Bipolar_NPN_Helper.rotationalOuttextxy(
            up_left_x + thisHeight / 7, center_y - height / 5 - 5, getPositionCenter(), "B",
            rotateState);

        Transistor_Bipolar_NPN_Helper.rotationalOuttextxy(
            down_right_x - thisHeight / 6 - thisHeight / 5 - 5, down_right_y - height / 40 - height / 6, getPositionCenter(), "E",
            rotateState);
    }

    Transistor_Bipolar_NPN_Helper.rotationalLine(
        up_left_x + thisHeight / 15, center_y, center_x, center_y, getPositionCenter(),
        rotateState);

    int points1[] = {
        int(center_x), int(center_y - height / 8),
        int(center_x + thisHeight / 40), int(center_y - height / 8),
        int(center_x + thisHeight / 40), int(center_y + height / 8),
        int(center_x), int(center_y + height / 8),
    };

    Transistor_Bipolar_NPN_Helper.rotationalFillPoly(
        4, points1, getPositionCenter(),
        rotateState);

    Transistor_Bipolar_NPN_Helper.rotationalCircle(
            up_left_x + thisHeight / 30, center_y, getPositionCenter(),  height / 30,
            rotateState);

    Transistor_Bipolar_NPN_Helper.rotationalCircle(
            down_right_x - thisHeight / 6, up_left_y + height / 30, getPositionCenter(),  height / 30,
            rotateState);

    Transistor_Bipolar_NPN_Helper.rotationalCircle(
            down_right_x - thisHeight / 6, down_right_y - height / 30, getPositionCenter(),  height / 30,
            rotateState);

    showElements();
}

void Transistor_Bipolar_NPN::updateConnectionPointsPosition(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Transistor_Bipolar_NPN_Helper.rotatePointToReference(
        Transistor_Bipolar_NPN_Helper.makeVector_2D(up_left_x + thisHeight / 30, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Transistor_Bipolar_NPN_Helper.rotatePointToReference(
        Transistor_Bipolar_NPN_Helper.makeVector_2D(down_right_x - thisHeight / 6, up_left_y + height / 30),
        getPositionCenter(),
        rotateState);

    connectionPoints[2].position = Transistor_Bipolar_NPN_Helper.rotatePointToReference(
        Transistor_Bipolar_NPN_Helper.makeVector_2D(down_right_x - thisHeight / 6, down_right_y - height / 30),
        getPositionCenter(),
        rotateState);
}
