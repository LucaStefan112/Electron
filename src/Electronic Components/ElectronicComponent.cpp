#include <ctime>
#include <sstream>

#include <stdio.h>
#include "Electronic Components/ElectronicComponent.h"

Helper ElectronicComponent_helper;

ElectronicComponent::ElectronicComponent(double thisWidth, double thisHeight, std::string thisName, int thisNumberOfConnectionPoints)
{
    width = thisWidth;
    height = thisHeight;
    width_height_ratio = thisWidth / thisHeight;
    name = thisName;
    numberOfConnectionPoints = thisNumberOfConnectionPoints;
    setPositionUpLeft(ElectronicComponent_helper.makeVector_2D(-1000, -1000));

    if(thisWidth <= 0 || thisHeight <= 0)
    {
        std::cout << "Width and height must be greater than 0!";
        return;
    }
    else
    {
        width = thisWidth;
        height = thisHeight;
        width_height_ratio = thisWidth / thisHeight;
        name = thisName;
        numberOfConnectionPoints = thisNumberOfConnectionPoints;

        updateConnectionPointsPosition();
    }

    // set componentCode
    std::stringstream strm;
    strm << std::time(nullptr);
    componentCode = strm.str();

    this->updateConnectionPointsPosition();
    this->Show();
}

//Setter of the up_left point:
void ElectronicComponent::setPositionUpLeft(Helper::Vector_2D thisPosition)
{
    Erase();

    positionType = up_left;
    //Updating the other reference points:
    position.up_left.x = thisPosition.x;
    position.center.x = position.up_left.x + width / 2;
    position.down_right.x = position.up_left.x + width;

    position.up_left.y = thisPosition.y;
    position.center.y = position.up_left.y + height / 2;
    position.down_right.y = position.up_left.y + height;

    this->updateConnectionPointsPosition();
    this->Show();
}

//Setter of the center point:
void ElectronicComponent::setPositionCenter(Helper::Vector_2D thisPosition)
{
    Erase();

    positionType = center;
    //Updating the other reference points:
    position.center.x = thisPosition.x;
    position.up_left.x = position.center.x - width / 2;
    position.down_right.x = position.center.x + width / 2;

    position.center.y = thisPosition.y;
    position.up_left.y = position.center.y - height / 2;
    position.down_right.y = position.center.y + height / 2;

    this->updateConnectionPointsPosition();
    this->Show();
}

//Setter of the down_right point:
void ElectronicComponent::setPositionDownRight(Helper::Vector_2D thisPosition)
{
    Erase();

    positionType = down_right;
    //Updating the other reference points:
    position.down_right.x = thisPosition.x;
    position.up_left.x = position.down_right.x - width;
    position.center.x = position.down_right.x - width / 2;

    position.down_right.y = thisPosition.y;
    position.up_left.y = position.down_right.y - height;
    position.center.y = position.down_right.y - height / 2;

    this->updateConnectionPointsPosition();
    this->Show();
}

//Setter of the width:
void ElectronicComponent::setWidth(double thisWidth)
{
    Erase();

    width = thisWidth;
    height = width / width_height_ratio;

    switch (positionType)
    {
        case up_left:
            position.center.x = position.up_left.x + width / 2; position.center.y = position.up_left.y + height / 2;
            position.down_right.x = position.up_left.x + width; position.down_right.y = position.up_left.x + height;
        break;

        case center:
            position.up_left.x = position.center.x - width / 2; position.up_left.y = position.center.y - height / 2;
            position.down_right.x = position.center.x + width / 2; position.down_right.y = position.center.y + height / 2;
        break;

        case down_right:
            position.up_left.x = position.down_right.x - width; position.up_left.y = position.down_right.y - height;
            position.center.x = position.down_right.x - width / 2; position.center.y = position.down_right.y - height / 2;
        break;
    }

    this->updateConnectionPointsPosition();
    this->Show();
}

//Setter of the height:
void ElectronicComponent::setHeight(double thisHeight)
{
    Erase();

    height = thisHeight;
    width = height * width_height_ratio;

    switch (positionType)
    {
        case up_left:
            position.center.y = position.up_left.y + height / 2; position.center.x = position.up_left.x + width / 2;
            position.down_right.y = position.up_left.y + height; position.down_right.x = position.up_left.x + width;
        break;

        case center:
            position.up_left.y = position.center.y - height / 2; position.up_left.x = position.center.x - width / 2;
            position.down_right.y = position.center.y + height / 2; position.down_right.x = position.center.x + width / 2;
        break;

        case down_right:
            position.up_left.y = position.down_right.y - height; position.up_left.x = position.down_right.x - width;
            position.center.y = position.down_right.y - height / 2; position.center.x = position.down_right.x - width / 2;
        break;
    }

    this->updateConnectionPointsPosition();
    this->Show();
}

//Setter of the component code:
void ElectronicComponent::setComponentCode(std::string thisComponentCode){
    componentCode = thisComponentCode;
}

//Setter of the code of the connected component at a given index:
void ElectronicComponent::setConnectedComponentCodeAtPoint(int thisPoint, int thisComponentCode){

    if(0 <= thisPoint && thisPoint < numberOfConnectionPoints && thisComponentCode >= 0)
        connectionPoints[thisPoint].connectedComponentCode = thisComponentCode;
}

void ElectronicComponent::setOutterBox(bool thisState){
    Erase();

    showOutterBox = thisState;

    this->Show();
}

void ElectronicComponent::setConnectionPoints(bool thisState){
    Erase();

    showConnectionPoints = thisState;

    this->Show();
}

//Flipping the component:
void ElectronicComponent::flipComponent(){
    this->Erase();

    flipped = !flipped;
    rotateState *= -1;

    this->updateConnectionPointsPosition();
    this->Show();
}

//Rotating the component:
void ElectronicComponent::rotateComponent(int thisDegree){
    Erase();

    rotateState = thisDegree % 360;

    this->updateConnectionPointsPosition();
    this->Show();
}

//Getter of the up_left point:
Helper::Vector_2D ElectronicComponent::getPositionUpLeft()
{
    return ElectronicComponent_helper.makeVector_2D(position.up_left.x, position.up_left.y);
}

//Getter of the center point:
Helper::Vector_2D ElectronicComponent::getPositionCenter()
{
    return ElectronicComponent_helper.makeVector_2D(position.center.x, position.center.y);
}

//Getter of the down_right point:
Helper::Vector_2D ElectronicComponent::getPositionDownRight()
{
    return ElectronicComponent_helper.makeVector_2D(position.down_right.x, position.down_right.y);
}

//Getter of the width:
double ElectronicComponent::getWidth()
{
    return width;
}

//Getter of the height:
double ElectronicComponent::getHeight()
{
    return height;
}

//Getter of the component code:
std::string ElectronicComponent::getComponentCode(){

    return componentCode;
}

//Getter of the number of connecting points:
int ElectronicComponent::getNumberOfConnectionPoints(){

    return numberOfConnectionPoints;
}

int ElectronicComponent::getCodeOfConnectedComponentAtPoint(int thisPoint){

    return connectionPoints[thisPoint].connectedComponentCode;
}

Helper::ConnectionPoint* ElectronicComponent::getConnectionPoints(){
    return connectionPoints;
}

//Updating the position of the connection points:
void ElectronicComponent::updateConnectionPointsPosition(){
    if(numberOfConnectionPoints == 0)   return;
}

//Drawing the component:
void ElectronicComponent::Show()
{
    return;
}

void ElectronicComponent::showElements(bool modeErase){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(showOutterBox){

        setcolor(RED);

        if(modeErase) {
            setcolor(BLACK);

            for (int i = 0; i < 4; i++) {
                ElectronicComponent_helper.rotationalLine(
                up_left_x - i, up_left_y - i, down_right_x + i, up_left_y - i, getPositionCenter(),
                rotateState);
            }

            for (int i = 0; i < 4; i++) {
                ElectronicComponent_helper.rotationalLine(
                down_right_x + i, up_left_y - i, down_right_x + i, down_right_y + i, getPositionCenter(),
                rotateState);
            }

            for (int i = 0; i < 4; i++) {
                ElectronicComponent_helper.rotationalLine(
                down_right_x + i, down_right_y + i, up_left_x - i, down_right_y + i, getPositionCenter(),
                rotateState);
            }

            for (int i = 0; i < 4; i++) {
                ElectronicComponent_helper.rotationalLine(
                up_left_x - i, down_right_y + i, up_left_x - i, up_left_y - i, getPositionCenter(),
                rotateState);
            }
        }
        else {
            ElectronicComponent_helper.rotationalLine(
            up_left_x, up_left_y, down_right_x, up_left_y, getPositionCenter(),
            rotateState);

            ElectronicComponent_helper.rotationalLine(
            down_right_x, up_left_y, down_right_x, down_right_y, getPositionCenter(),
            rotateState);

            ElectronicComponent_helper.rotationalLine(
            down_right_x, down_right_y, up_left_x, down_right_y, getPositionCenter(),
            rotateState);

            ElectronicComponent_helper.rotationalLine(
            up_left_x, down_right_y, up_left_x, up_left_y, getPositionCenter(),
            rotateState);
        }

        setcolor(WHITE);
    }

    if(showConnectionPoints){

        setfillstyle(INTERLEAVE_FILL, RED);

        if(modeErase)    {setfillstyle(INTERLEAVE_FILL, BLACK); setcolor(BLACK);}

        for(int i = 0; i < numberOfConnectionPoints; i++){
            if(width_height_ratio == 4)
                fillellipse(connectionPoints[i].position.x, connectionPoints[i].position.y, height / 10, height / 10);

            else if(width_height_ratio == 2)
                fillellipse(connectionPoints[i].position.x, connectionPoints[i].position.y, height / 20, height / 20);

            else if(width_height_ratio == 1)
                fillellipse(connectionPoints[i].position.x, connectionPoints[i].position.y, height / 20, height / 20);

            else if(width_height_ratio == 0.75)
                fillellipse(connectionPoints[i].position.x, connectionPoints[i].position.y, height / 30, height / 30);
            else if(width_height_ratio == 0.75)
                fillellipse(connectionPoints[i].position.x, connectionPoints[i].position.y, height / 30, height / 30);
        }

        setfillstyle(SOLID_FILL, WHITE);
        setcolor(WHITE);
    }
}

//Erasing the component:
void ElectronicComponent::Erase()
{
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);

    this->Show();
    showElements(true);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
}

bool ElectronicComponent::isCursorPointInButton()
{
    POINT cursorPoint;
    GetCursorPos(&cursorPoint);

    if (cursorPoint.x < position.up_left.x)
    {
        return false;
    }

    if (cursorPoint.x > position.down_right.x)
    {
        return false;
    }

    if (cursorPoint.y < position.up_left.y)
    {
        return false;
    }
    if (cursorPoint.y > position.down_right.y)
    {
        return false;
    }
    return true;
}

bool ElectronicComponent::isSelected()
{
    return showOutterBox;
}

int ElectronicComponent::getRotationState()
{
    return rotateState;
}

//Passing trough a string all the data about the component:
std::string ElectronicComponent::toString()
{
    std::string text =  std::string(std::string("Type: ") + name + std::string(" | ")+
                                    std::string("Code: ") + componentCode + std::string(";\n\n") +
                                    std::string("Width: ") + std::to_string(width) + std::string(" | ") +
                                    std::string("Height: ") + std::to_string(height) + std::string(";\n") +
                                    std::string("Width / Height ratio: ") + std::to_string(width_height_ratio) + std::string(";\n\n") +
                                    std::string("Up_Left Coordinates: ") +
                                    std::string("x: ") + std::to_string(position.up_left.x) + std::string(" | ") +
                                    std::string("y: ") + std::to_string(position.up_left.y) + std::string(";\n") +
                                    std::string("Center Coordinates: ") +
                                    std::string("x: ") + std::to_string(position.center.x) + std::string(" | ") +
                                    std::string("y: ") + std::to_string(position.center.y) + std::string(";\n") +
                                    std::string("Down_Right Coordinates: ") +
                                    std::string("x: ") + std::to_string(position.down_right.x) + std::string(" | ") +
                                    std::string("y: ") + std::to_string(position.down_right.y) + std::string(";\n\n") +
                                    std::string("Flipped: ") + std::to_string(flipped) + std::string(" | ") +
                                    std::string("Angle of rotation: ") + std::to_string(rotateState) + std::string(";\n\n") +
                                    std::string("Number of Connection Points: ") + std::to_string(numberOfConnectionPoints) + std::string(";\n\n") +
                                    std::string("Connected Components:\n"));

    for(int i = 0; i < numberOfConnectionPoints; i++)
        text += std::string(std::string("Point ") +
                std::to_string(i) + std::string(": ") +
                std::to_string(connectionPoints[i].connectedComponentCode) +
                std::string(" | Coordinates: ") +
                std::string("x: ") + std::to_string(connectionPoints[i].position.x) + std::string(" \ ") +
                std::string("y: ") + std::to_string(connectionPoints[i].position.y) + std::string(";\n"));

    text += std::string("\n====================================================\n\n");

    return text;
}
