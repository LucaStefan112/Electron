#include <graphics.h>
#include <string>

#include "Electronic Components/NotGate.h"
#include "Helper.h"

Helper NotGate_helper;

NotGate::NotGate()
{
    //ctor
}


//Setter of the up_left point:
void NotGate::setPositionUpLeft(Helper::Vector_2D thisPosition)
{
    //Updating the other reference points:
    position.up_left.x = thisPosition.x;
    position.center.x = position.up_left.x + width / 2;
    position.down_right.x = position.up_left.x + width;

    position.up_left.y = thisPosition.y;
    position.center.y = position.up_left.y + height / 2;
    position.down_right.y = position.up_left.y + height;
}

//Setter of the center point:
void NotGate::setPositionCenter(Helper::Vector_2D thisPosition)
{
    //Updating the other reference points:
    position.center.x = thisPosition.x;
    position.up_left.x = position.center.x - width / 2;
    position.down_right.x = position.center.x + width / 2;

    position.center.y = thisPosition.y;
    position.up_left.y = position.center.y - height / 2;
    position.down_right.y = position.center.y + height / 2;
}

//Setter of the down_right point:
void NotGate::setPositionDownRight(Helper::Vector_2D thisPosition)
{
    //Updating the other reference points:
    position.down_right.x = thisPosition.x;
    position.up_left.x = position.down_right.x - width;
    position.center.x = position.down_right.x - width / 2;

    position.down_right.y = thisPosition.y;
    position.up_left.y = position.down_right.x - height;
    position.center.y = position.down_right.y - height / 2;
}

//Setter of the width:
void NotGate::setWidth(double thisWidth)
{
    width = thisWidth;
    position.up_left.x = position.center.x - width / 2;
    position.down_right.x = position.center.x + width / 2;
}

//Setter of the height:
void NotGate::setHeight(double thisHeight)
{
    height = thisHeight;
    position.up_left.y = position.center.y - height / 2;
    position.down_right.y = position.center.y + height / 2;
}

//Getter of the up_left point:
Helper::Vector_2D NotGate::getPositionUpLeft()
{
    return NotGate_helper.makeVector_2D(position.up_left.x, position.up_left.y);
}

//Getter of the center point:
Helper::Vector_2D NotGate::getPositionCenter()
{
    return NotGate_helper.makeVector_2D(position.center.x, position.center.y);
}

//Getter of the down_right point:
Helper::Vector_2D NotGate::getPositionDownRight()
{
    return NotGate_helper.makeVector_2D(position.down_right.x, position.down_right.y);
}

//Getter of the width:
double NotGate::getWidth()
{
    return width;
}

//Getter of the height:
double NotGate::getHeight()
{
    return height;
}

//Drawing the component:
void NotGate::Show()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    //circle
    circle(up_left_x + height / 10, center_y, height / 10);

    //wire
    line(up_left_x + height / 5, center_y, center_x - height / 2, center_y);

    // not symbol
    line(center_x - height / 2, up_left_y, center_x - height / 2, down_right_y);
    line(center_x - height / 2, up_left_y, center_x + height / 2, center_y);
    line(center_x - height / 2, down_right_y, center_x + height / 2, center_y);
    circle(center_x + height / 2 + height / 5, center_y, height / 5);

    //wire
    line(center_x + height / 2 + height / 2.5, center_y, down_right_x - height / 5, center_y);

    //circle
    circle(down_right_x - height / 10, center_y, height / 10);
}

//Passing trough a string all the data about the component:
std::string NotGate::toString()
{
    return std::string(std::string("Type: Rezistor;\n") +
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
