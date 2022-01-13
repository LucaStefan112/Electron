#include "Electronic Components/Transistors/Transistor_Dual_Gate_MOSFET_Nchannel.h"

Helper Transistor_Dual_Gate_MOSFET_Nchannel_Helper;

Transistor_Dual_Gate_MOSFET_Nchannel::Transistor_Dual_Gate_MOSFET_Nchannel() : ElectronicComponent(150, 200, "Dual Gate MOSFET N-channel Transistor", 4) {}

//Drawing the component:
void Transistor_Dual_Gate_MOSFET_Nchannel::Show()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    for(int i = 0; i <= height / 65; i++)
        Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalCircle(
            center_x + thisHeight / 9, center_y, getPositionCenter(),  2 * height / 9 - i,
            rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        down_right_x - thisHeight / 6, up_left_y + height / 15, down_right_x - thisHeight / 6, center_y - height / 15, getPositionCenter(),
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        down_right_x - thisHeight / 6, down_right_y - height / 15, down_right_x - thisHeight / 6, center_y, getPositionCenter(),
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        center_x + thisHeight / 10, center_y, down_right_x - thisHeight / 6, center_y, getPositionCenter(),
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        down_right_x - thisHeight / 6, center_y - height / 15, center_x + thisHeight / 10, center_y - height / 15, getPositionCenter(),
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        down_right_x - thisHeight / 6, center_y + height / 15, center_x + thisHeight / 10, center_y + height / 15, getPositionCenter(),
        rotateState);

    int points[] =
    {
        int(center_x + thisHeight / 10), int(center_y),
        int(center_x + thisHeight / 5.5), int(center_y + height / 30),
        int(center_x + thisHeight / 5.5), int(center_y - height / 30)
    };

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalFillPoly(
        3, points, getPositionCenter(),
        rotateState);

    settextstyle(8, HORIZ_DIR, 3);
    if(height / 50 > 2)
    {
        Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalOuttextxy(
            down_right_x - thisHeight / 6 - thisHeight / 5 - 5, up_left_y + height / 40, getPositionCenter(), "D",
            rotateState);

        if(flipped)
        {
            Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalOuttextxy(
                up_left_x + thisHeight / 4, center_y - height / 4 - 15, getPositionCenter(), "G2",
                rotateState);

            Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalOuttextxy(
                up_left_x + thisHeight / 4, center_y + height / 8 + height / 10, getPositionCenter(), "G1",
                rotateState);
        }
        else
        {
            Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalOuttextxy(
                up_left_x + thisHeight / 20, center_y - height / 4.5 - 5, getPositionCenter(), "G2",
                rotateState);

            Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalOuttextxy(
                up_left_x + thisHeight / 20, center_y + height / 8 + height / 20, getPositionCenter(), "G1",
                rotateState);
        }

        Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalOuttextxy(
            down_right_x - thisHeight / 6 - thisHeight / 5 - 5, down_right_y - height / 40 - height / 6, getPositionCenter(), "S",
            rotateState);
    }

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        up_left_x + thisHeight / 15, center_y + height / 8, center_x, center_y + height / 8, getPositionCenter(),
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        center_x, center_y + height / 8, center_x, center_y + height / 20, getPositionCenter(),
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        up_left_x + thisHeight / 15, center_y - height / 20, center_x, center_y - height / 20, getPositionCenter(),
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalLine(
        center_x, center_y - height / 20, center_x, center_y - height / 8, getPositionCenter(),
        rotateState);

    int points1[] =
    {
        int(center_x + thisHeight / 20), int(center_y - height / 8),
        int(center_x + thisHeight / 20), int(center_y + height / 8),
        int(center_x + thisHeight / 10), int(center_y + height / 8),
        int(center_x + thisHeight / 10), int(center_y - height / 8)
    };

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalFillPoly(
        4, points1, getPositionCenter(),
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalCircle(
        up_left_x + thisHeight / 30, center_y + height / 8, getPositionCenter(),  height / 30,
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalCircle(
        up_left_x + thisHeight / 30, center_y - height / 20, getPositionCenter(),  height / 30,
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalCircle(
        down_right_x - thisHeight / 6, up_left_y + height / 30, getPositionCenter(),  height / 30,
        rotateState);

    Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotationalCircle(
        down_right_x - thisHeight / 6, down_right_y - height / 30, getPositionCenter(),  height / 30,
        rotateState);

    showElements();
}

void Transistor_Dual_Gate_MOSFET_Nchannel::updateConnectionPointsPosition()
{

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotatePointToReference(
                                       Transistor_Dual_Gate_MOSFET_Nchannel_Helper.makeVector_2D(up_left_x + thisHeight / 30, center_y + height / 8),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotatePointToReference(
                                       Transistor_Dual_Gate_MOSFET_Nchannel_Helper.makeVector_2D(up_left_x + thisHeight / 30, center_y - height / 20),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[2].position = Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotatePointToReference(
                                       Transistor_Dual_Gate_MOSFET_Nchannel_Helper.makeVector_2D(down_right_x - thisHeight / 6, up_left_y + height / 30),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[3].position = Transistor_Dual_Gate_MOSFET_Nchannel_Helper.rotatePointToReference(
                                       Transistor_Dual_Gate_MOSFET_Nchannel_Helper.makeVector_2D(down_right_x - thisHeight / 6, down_right_y - height / 30),
                                       getPositionCenter(),
                                       rotateState);
}
