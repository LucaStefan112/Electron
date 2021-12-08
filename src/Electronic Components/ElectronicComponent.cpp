#include <graphics.h>
#include <string>

#include "Electronic Components/ElectronicComponent.h"
#include "Helper.h"

Helper ElectronicComponent_helper;

ElectronicComponent::ElectronicComponent(){

}

//Setter of the up_left point:
void ElectronicComponent::setPositionUpLeft(Helper::Vector_2D thisPosition){
    //Updating the other reference points:
    position.up_left.x = thisPosition.x;
    position.center.x = position.up_left.x + width / 2; position.down_right.x = position.up_left.x + width;

    position.up_left.y = thisPosition.y;
    position.center.y = position.up_left.y + height / 2; position.down_right.y = position.up_left.y + height;
}

//Setter of the center point:
void ElectronicComponent::setPositionCenter(Helper::Vector_2D thisPosition){
    //Updating the other reference points:
    position.center.x = thisPosition.x;
    position.up_left.x = position.center.x - width / 2; position.down_right.x = position.center.x + width / 2;

    position.center.y = thisPosition.y;
    position.up_left.y = position.center.y - height / 2; position.down_right.y = position.center.y + height / 2;
}

//Setter of the down_right point:
void ElectronicComponent::setPositionDownRight(Helper::Vector_2D thisPosition){
    //Updating the other reference points:
    position.down_right.x = thisPosition.x;
    position.up_left.x = position.down_right.x - width; position.center.x = position.down_right.x - width / 2;

    position.down_right.y = thisPosition.y;
    position.up_left.y = position.down_right.x - height; position.center.y = position.down_right.y - height / 2;
}

//Setter of the width:
void ElectronicComponent::setWidth(double thisWidth){
    width = thisWidth;  height = width / width_height_ratio;
    position.up_left.x = position.center.x - width / 2;
    position.down_right.x = position.center.x + width / 2;
}

//Setter of the height:
void ElectronicComponent::setHeight(double thisHeight){
    height = thisHeight;    width = height * width_height_ratio;
    position.up_left.y = position.center.y - height / 2;
    position.down_right.y = position.center.y + height / 2;
}

//Setter of the with / height ratio:
void ElectronicComponent::setWidth_Height_Ratio(double thisWidth_Height_Ratio){
    if(thisWidth_Height_Ratio > 0) width_height_ratio = thisWidth_Height_Ratio;
}

//Getter of the up_left point:
Helper::Vector_2D ElectronicComponent::getPositionUpLeft(){
    return ElectronicComponent_helper.makeVector_2D(position.up_left.x, position.up_left.y);
}

//Getter of the center point:
Helper::Vector_2D ElectronicComponent::getPositionCenter(){
    return ElectronicComponent_helper.makeVector_2D(position.center.x, position.center.y);
}

//Getter of the down_right point:
Helper::Vector_2D ElectronicComponent::getPositionDownRight(){
    return ElectronicComponent_helper.makeVector_2D(position.down_right.x, position.down_right.y);
}

//Getter of the width:
double ElectronicComponent::getWidth(){
    return width;
}

//Getter of the height:
double ElectronicComponent::getHeight(){
    return height;
}

//Getter of the width / height ratio:
double ElectronicComponent::getWidth_Height_Ratio(){
    return width_height_ratio;
}

//Drawing the component:
void ElectronicComponent::Show(){
    bar(position.up_left.x, position.up_left.y, position.down_right.x, position.down_right.y);
}

//Passing trough a string all the data about the component:
std::string ElectronicComponent::toString(){
    return std::string(std::string("Type: ElectronicComponent;\n") +
           std::string("Width: ") + std::to_string(width) + std::string(";\n") +
           std::string("Height: ") + std::to_string(height) + std::string(";\n") +
           std::string("Width / Height ratio: ") + std::to_string(width_height_ratio) + std::string(";\n") +
           std::string("Up_Left Coordinates: ") +
           std::string("x: ") + std::to_string(position.up_left.x) + std::string(" \ ") +
           std::string("y: ") + std::to_string(position.up_left.y) + std::string(";\n") +
           std::string("Center Coordinates: ") +
           std::string("x: ") + std::to_string(position.center.x) + std::string(" \ ") +
           std::string("y: ") + std::to_string(position.center.y) + std::string(";\n") +
           std::string("Down_Right Coordinates: ") +
           std::string("x: ") + std::to_string(position.down_right.x) + std::string(" \ ") +
           std::string("y: ") + std::to_string(position.down_right.y) + std::string(";\n"));
}