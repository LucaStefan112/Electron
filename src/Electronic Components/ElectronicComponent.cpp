#include "Electronic Components/ElectronicComponent.h"

Helper ElectronicComponent_helper;

ElectronicComponent::ElectronicComponent(double thisWidth, double thisHeight, std::string thisName, int thisNumberOfConnectionPoints)
{
    //Tamas Luca-Stefan
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
    //Tamas Luca-Stefan
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
    //Tamas Luca-Stefan
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
    //Tamas Luca-Stefan
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
    //Tamas Luca-Stefan
    if(this->name == "Connection Point")    return;

    if(thisWidth < 30 || thisWidth > 500)  return;
    Erase();

    width = thisWidth;
    height = width / width_height_ratio;

    switch (positionType)
    {
    case up_left:
        position.center.x = position.up_left.x + width / 2;
        position.center.y = position.up_left.y + height / 2;
        position.down_right.x = position.up_left.x + width;
        position.down_right.y = position.up_left.x + height;
        break;

    case center:
        position.up_left.x = position.center.x - width / 2;
        position.up_left.y = position.center.y - height / 2;
        position.down_right.x = position.center.x + width / 2;
        position.down_right.y = position.center.y + height / 2;
        break;

    case down_right:
        position.up_left.x = position.down_right.x - width;
        position.up_left.y = position.down_right.y - height;
        position.center.x = position.down_right.x - width / 2;
        position.center.y = position.down_right.y - height / 2;
        break;
    }

    this->updateConnectionPointsPosition();
    this->Show();
}

//Setter of the height:
void ElectronicComponent::setHeight(double thisHeight)
{
    //Tamas Luca-Stefan
    if(this->name == "Connection Point")    return;

    if(thisHeight < 30 || thisHeight > 500)  return;

    Erase();

    height = thisHeight;
    width = height * width_height_ratio;

    switch (positionType)
    {
    case up_left:
        position.center.y = position.up_left.y + height / 2;
        position.center.x = position.up_left.x + width / 2;
        position.down_right.y = position.up_left.y + height;
        position.down_right.x = position.up_left.x + width;
        break;

    case center:
        position.up_left.y = position.center.y - height / 2;
        position.up_left.x = position.center.x - width / 2;
        position.down_right.y = position.center.y + height / 2;
        position.down_right.x = position.center.x + width / 2;
        break;

    case down_right:
        position.up_left.y = position.down_right.y - height;
        position.up_left.x = position.down_right.x - width;
        position.center.y = position.down_right.y - height / 2;
        position.center.x = position.down_right.x - width / 2;
        break;
    }

    this->updateConnectionPointsPosition();
    this->Show();
}

//Setter of the component code:
void ElectronicComponent::setComponentCode(std::string thisComponentCode)
{
    //Tamas Luca-Stefan
    componentCode = thisComponentCode;
}

//Setter of the code of the connected component at a given index:
void ElectronicComponent::setConnectedComponentCodeAtPoint(int thisPoint, std::string thisComponentCode)
{
    //Tamas Luca-Stefan
    if(0 <= thisPoint && thisPoint < numberOfConnectionPoints)
        connectionPoints[thisPoint].connectedComponentCode = thisComponentCode;
}

// Set red box to the component
void ElectronicComponent::setOutterBox(bool thisState)
{
    //Tamas Luca-Stefan
    Erase();

    showOutterBox = thisState;

    this->Show();
}

void ElectronicComponent::setConnectionPoints(bool thisState)
{
    //Tamas Luca-Stefan
    Erase();

    showConnectionPoints = thisState;

    this->Show();
}

//Flipping the component:
void ElectronicComponent::flipComponent()
{
    //Tamas Luca-Stefan
    if(this->name == "Connection Point")    return;

    this->Erase();

    flipped = !flipped;
    rotateState *= -1;

    this->updateConnectionPointsPosition();
    this->Show();
}

//Rotating the component:
void ElectronicComponent::rotateComponent(int thisDegree)
{
    //Tamas Luca-Stefan
    if(this->name == "Connection Point")    return;

    Erase();

    rotateState = thisDegree % 360;

    this->updateConnectionPointsPosition();
    this->Show();
}

//Getter of the up_left point:
Helper::Vector_2D ElectronicComponent::getPositionUpLeft()
{
    //Tamas Luca-Stefan
    return ElectronicComponent_helper.makeVector_2D(position.up_left.x, position.up_left.y);
}

//Getter of the center point:
Helper::Vector_2D ElectronicComponent::getPositionCenter()
{
    //Tamas Luca-Stefan
    return ElectronicComponent_helper.makeVector_2D(position.center.x, position.center.y);
}

//Getter of the down_right point:
Helper::Vector_2D ElectronicComponent::getPositionDownRight()
{
    //Tamas Luca-Stefan
    return ElectronicComponent_helper.makeVector_2D(position.down_right.x, position.down_right.y);
}

//Getter of the width:
double ElectronicComponent::getWidth()
{
    //Tamas Luca-Stefan
    return width;
}

//Getter of the height:
double ElectronicComponent::getHeight()
{
    //Tamas Luca-Stefan
    return height;
}

//Getter of the component code:
std::string ElectronicComponent::getComponentCode()
{
    //Tamas Luca-Stefan
    return componentCode;
}

//Getter of the number of connecting points:
int ElectronicComponent::getNumberOfConnectionPoints()
{
    //Tamas Luca-Stefan
    return numberOfConnectionPoints;
}

//Getter of the connected component code
std::string ElectronicComponent::getCodeOfConnectedComponentAtPoint(int thisPoint)
{
    //Tamas Luca-Stefan
    return connectionPoints[thisPoint].connectedComponentCode;
}

//Getter of the connection points
Helper::ConnectionPoint* ElectronicComponent::getConnectionPoints()
{
    //Tamas Luca-Stefan
    return connectionPoints;
}

//Updating the position of the connection points:
void ElectronicComponent::updateConnectionPointsPosition()
{
    //Tamas Luca-Stefan
    if(numberOfConnectionPoints == 0)   return;
}

//Drawing the component:
void ElectronicComponent::Show()
{
    //Tamas Luca-Stefan
}

void ElectronicComponent::showElements(bool modeErase)
{
    //Tamas Luca-Stefan
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(this->name == "Connection Point")
    {
        setcolor(RED);
        if(modeErase)   setcolor(BLACK);
        fillellipse(getPositionCenter().x, getPositionCenter().y, 7, 7);
        setcolor(WHITE);
        return;
    }

    if(showOutterBox)
    {

        setcolor(RED);

        if(this->name == "Connection Node")
        {
            if(modeErase)
                setcolor(BLACK);

            fillellipse(getPositionCenter().x, getPositionCenter().y, 10, 10);

            setcolor(WHITE);

            return;
        }


        if(modeErase)
        {
            setcolor(BLACK);

            for (int i = 0; i < 4; i++)
            {
                ElectronicComponent_helper.rotationalLine(
                    up_left_x - i, up_left_y - i, down_right_x + i, up_left_y - i, getPositionCenter(),
                    rotateState);
            }

            for (int i = 0; i < 4; i++)
            {
                ElectronicComponent_helper.rotationalLine(
                    down_right_x + i, up_left_y - i, down_right_x + i, down_right_y + i, getPositionCenter(),
                    rotateState);
            }

            for (int i = 0; i < 4; i++)
            {
                ElectronicComponent_helper.rotationalLine(
                    down_right_x + i, down_right_y + i, up_left_x - i, down_right_y + i, getPositionCenter(),
                    rotateState);
            }

            for (int i = 0; i < 4; i++)
            {
                ElectronicComponent_helper.rotationalLine(
                    up_left_x - i, down_right_y + i, up_left_x - i, up_left_y - i, getPositionCenter(),
                    rotateState);
            }
        }
        else
        {
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

    if(showConnectionPoints)
    {

        setfillstyle(INTERLEAVE_FILL, RED);

        if(modeErase)
        {
            setfillstyle(INTERLEAVE_FILL, BLACK);
            setcolor(BLACK);
        }

        for(int i = 0; i < numberOfConnectionPoints; i++)
        {
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
    //Tamas Luca-Stefan
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);

    int outline = 5;

    int points[] =
    {
        int(getPositionUpLeft().x - outline), int(getPositionUpLeft().y - outline),
        int(getPositionDownRight().x + outline), int(getPositionUpLeft().y - outline),
        int(getPositionDownRight().x + outline), int(getPositionDownRight().y + outline),
        int(getPositionUpLeft().x - outline), int(getPositionDownRight().y + outline),
    };

    ElectronicComponent_helper.rotationalFillPoly(4, points, getPositionCenter(), rotateState);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
}

//Checks if the cursor is on the component
bool ElectronicComponent::isCursorPointInButton()
{
    //Melinte Daria
    POINT cursorPoint;
    GetCursorPos(&cursorPoint);

    if(this->name == "Connection Node")
        return ElectronicComponent_helper.distanceBetween(ElectronicComponent_helper.makeVector_2D(cursorPoint.x, cursorPoint.y), getPositionCenter()) < 20;

    return cursorPoint.x >= position.up_left.x && cursorPoint.x <= position.down_right.x && cursorPoint.y >= position.up_left.y && cursorPoint.y <= position.down_right.y;
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
    //Tamas Luca-Stefan
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
                            connectionPoints[i].connectedComponentCode +
                            std::string(" | Coordinates: ") +
                            std::string("x: ") + std::to_string(connectionPoints[i].position.x) + std::string(" \ ") +
                            std::string("y: ") + std::to_string(connectionPoints[i].position.y) + std::string(";\n"));

    text += std::string("\n====================================================\n\n");

    return text;
}

// [[string, double], [string, double]]
std::vector<std::pair<std::string, double>> ElectronicComponent::getValues()
{
    //Hirbu Andrei
    return std::vector<std::pair<std::string, double>> { std::make_pair("unsupported", 0) };
}

void ElectronicComponent::setValue(std::string name, double value)
{
    //Hirbu Andrei
    return;
}
