#include <graphics.h>
#include <string>

#include "Electronic Components/Rezistors.h"
#include "Helper.h"

Helper Rezistor_helper;

Rezistors::Rezistors()
{
    //ctor
}


//Setter of the up_left point:
void Rezistors::setPositionUpLeft(Helper::Vector_2D thisPosition)
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
void Rezistors::setPositionCenter(Helper::Vector_2D thisPosition)
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
void Rezistors::setPositionDownRight(Helper::Vector_2D thisPosition)
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
void Rezistors::setWidth(double thisWidth)
{
    width = thisWidth;
    position.up_left.x = position.center.x - width / 2;
    position.down_right.x = position.center.x + width / 2;
}

//Setter of the height:
void Rezistors::setHeight(double thisHeight)
{
    height = thisHeight;
    position.up_left.y = position.center.y - height / 2;
    position.down_right.y = position.center.y + height / 2;
}

//Getter of the up_left point:
Helper::Vector_2D Rezistors::getPositionUpLeft()
{
    return Rezistor_helper.makeVector_2D(position.up_left.x, position.up_left.y);
}

//Getter of the center point:
Helper::Vector_2D Rezistors::getPositionCenter()
{
    return Rezistor_helper.makeVector_2D(position.center.x, position.center.y);
}

//Getter of the down_right point:
Helper::Vector_2D Rezistors::getPositionDownRight()
{
    return Rezistor_helper.makeVector_2D(position.down_right.x, position.down_right.y);
}

//Getter of the width:
double Rezistors::getWidth()
{
    return width;
}

//Getter of the height:
double Rezistors::getHeight()
{
    return height;
}

//Drawing the component:
void Rezistors::Show()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double x = height + up_left_x;
    double y = up_left_y;

    double middleOfComponentHeight = x / 2;

    //circle
    circle(x, middleOfComponentHeight, 4);
    x += 4;

    //wire
    line(x, middleOfComponentHeight, x + 50, middleOfComponentHeight);
    x += 50;

    //resistor lines
    line(x, middleOfComponentHeight, x + 5, middleOfComponentHeight - 10);
    x += 5;

    for (int i = 1; i < 3; i++)
    {
        line(x, middleOfComponentHeight - 10, x + 10, middleOfComponentHeight + 10);
        x += 10;

        line(x, middleOfComponentHeight + 10, x + 10, middleOfComponentHeight - 10);
        x += 10;
    }

    line(x, middleOfComponentHeight - 10, x + 10, middleOfComponentHeight + 10);
    x += 10;

    line(x, middleOfComponentHeight + 10, x + 5, middleOfComponentHeight);
    x += 5;

    //wire
    line(x, middleOfComponentHeight, x + 50, middleOfComponentHeight);
    x += 50;

    //circle
    x += 4;
    circle(x, middleOfComponentHeight, 4);
    x += 4;

    width = x - height - up_left_x;
}

//Passing trough a string all the data about the component:
std::string Rezistors::toString()
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
