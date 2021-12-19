#include "Electronic Components/Capacitors/Capacitor_Ceramic.h"

Capacitor_Ceramic::Capacitor_Ceramic(): ElectronicComponent(200, 50, "Ceramic Capacitor", 2){}

//Drawing the component:
void Capacitor_Ceramic::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    circle(up_left_x + height / 10, center_y, height / 10);
    line(up_left_x + height / 5, center_y, center_x - height / 4, center_y);
    line(center_x - height / 4, up_left_y, center_x - height / 4, down_right_y);
    line(center_x + height / 4, up_left_y, center_x + height / 4, down_right_y);
    line(center_x + height / 4, center_y, down_right_x - height / 5, center_y);
    circle(down_right_x - height / 10, center_y, height / 10);
}

//Updating the positions of the connection points:
void Capacitor_Ceramic::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    connectionPoints[0].position.x = up_left_x + height / 10;
    connectionPoints[0].position.y = center_y;

    connectionPoints[1].position.x = down_right_x - height / 10;
    connectionPoints[1].position.y = center_y;
}
