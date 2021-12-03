#include "Diode.h"
#include <graphics.h>
#include <iostream>

Diode::Diode(){

}

void Diode::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    //line(up_left_x, center_y, center_x - height / 2, center_y);
    line(center_x - height / 2, up_left_y, center_x - height / 2, down_right_y);
    line(center_x - height / 2, up_left_y, center_x + height / 2, center_y);
    line(center_x - height / 2, down_right_y, center_x + height / 2, center_y);
    line(center_x + height / 2, up_left_y, center_x + height / 2, down_right_y);
    //line(center_x + height / 2, center_y, down_right_x, center_y);
}

//Passing trough a string all the data about the component:
std::string Diode::toString(){
    return std::string("Type: Diode;\n") +
           std::string("Width: ") + std::to_string(width) + std::string(";\n") +
           std::string("Height: ") + std::to_string(height) + std::string(";\n") +
           std::string("Up_Left Coordinates: ") +
           std::string("x: ") + std::to_string(position.up_left.x) + std::string(" \ ") +
           std::string("y: ") + std::to_string(position.down_right.y) + std::string(";\n") +
           std::string("Center Coordinates: ") +
           std::string("x: ") + std::to_string(position.center.x) + std::string(" \ ") +
           std::string("y: ") + std::to_string(position.center.y) + std::string(";\n") +
           std::string("Down_Right Coordinates: ") +
           std::string("x: ") + std::to_string(position.down_right.x) + std::string(" \ ") +
           std::string("y: ") + std::to_string(position.down_right.y) + std::string(";\n");
}

