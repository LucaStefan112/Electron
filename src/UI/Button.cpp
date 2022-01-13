#include "UI/Button.h"

#include <string>
#include <sstream>

Helper Button_helper;

Button::Button(double thisWidth, double thisHeight, std::string thisTitle)
{

    if (thisWidth <= 0 || thisHeight <= 0)
    {
        std::cout << "Width and height must be greater than 0!";
        return;
    }
    else
    {
        width = thisWidth;
        height = thisHeight;
        title = thisTitle;
    }
}

//Setter of the up_left point:
void Button::setPositionUpLeft(Helper::Vector_2D thisPosition)
{
    positionType = up_left;
    //Updating the other reference points:
    position.up_left.x = thisPosition.x;
    position.center.x = position.up_left.x + width / 2;
    position.down_right.x = position.up_left.x + width;

    position.up_left.y = thisPosition.y;
    position.center.y = position.up_left.y + height / 2;
    position.down_right.y = position.up_left.y + height;
}

//Setter of the center point:
void Button::setPositionCenter(Helper::Vector_2D thisPosition)
{
    positionType = center;

    //Updating the other reference points:
    position.center.x = thisPosition.x;
    position.up_left.x = thisPosition.x - width / 2;
    position.down_right.x = thisPosition.x + width / 2;

    position.center.y = thisPosition.y;
    position.up_left.y = thisPosition.y - height / 2;
    position.down_right.y = thisPosition.y + height / 2;
}

//Setter of the down_right point:
void Button::setPositionDownRight(Helper::Vector_2D thisPosition)
{
    positionType = down_right;

    //Updating the other reference points:
    position.down_right.x = thisPosition.x;
    position.up_left.x = position.down_right.x - width;
    position.center.x = position.down_right.x - width / 2;

    position.down_right.y = thisPosition.y;
    position.up_left.y = position.down_right.y - height;
    position.center.y = position.down_right.y - height / 2;
}

//Setter of the title:
void Button::setTitle(std::string thisTitle)
{
    title = thisTitle;
}

//Setter of the width:
void Button::setWidth(double thisWidth)
{
    width = thisWidth;
    switch (positionType)
    {
    case up_left:
        position.center.x = position.up_left.x + width / 2;
        position.down_right.x = position.up_left.x + width;
        break;
    case center:
        position.up_left.x = position.center.x - width / 2;
        position.down_right.x = position.center.x + width / 2;
        break;
    case down_right:
        position.up_left.x = position.down_right.x - width;
        position.center.x = position.down_right.x - width / 2;
        break;
    }
}

//Setter of the height:
void Button::setHeight(double thisHeight)
{
    height = thisHeight;
    switch (positionType)
    {
    case up_left:
        position.center.y = position.up_left.y + height / 2;
        position.down_right.y = position.up_left.y + height;
        break;
    case center:
        position.up_left.y = position.center.y - height / 2;
        position.down_right.y = position.center.y + height / 2;
        break;
    case down_right:
        position.up_left.y = position.down_right.y - height;
        position.center.y = position.down_right.y - height / 2;
        break;
    }
}

//Getter of the up_left point:
Helper::Vector_2D Button::getPositionUpLeft()
{
    return Button_helper.makeVector_2D(position.up_left.x, position.up_left.y);
}

//Getter of the center point:
Helper::Vector_2D Button::getPositionCenter()
{
    return Button_helper.makeVector_2D(position.center.x, position.center.y);
}

//Getter of the down_right point:
Helper::Vector_2D Button::getPositionDownRight()
{
    return Button_helper.makeVector_2D(position.down_right.x, position.down_right.y);
}

//Getter of the width:
double Button::getWidth()
{
    return width;
}

//Getter of the height:
double Button::getHeight()
{
    return height;
}

bool Button::isCursorPointInButton()
{
    POINT cursorPoint;
    GetCursorPos(&cursorPoint);

    return cursorPoint.x >= position.up_left.x && cursorPoint.x <= position.down_right.x && cursorPoint.y >= position.up_left.y && cursorPoint.y <= position.down_right.y;
}

std::string Button::getTitle()
{
    return title;
}

void Button::Show()
{
    setlinestyle(0, 0, 3);
    rectangle(position.up_left.x, position.up_left.y, position.down_right.x, position.down_right.y);
    settextstyle(3, 0, 1);
    outtextxy(position.center.x - Button_helper.textSpace(title) / 2, position.up_left.y + 4, strdup(title.c_str()));
}

void Button::ShowCircleMode()
{
    double dimension = (this->width > this->height) ? this->width : this->height;
    setlinestyle(0, 0, 3);
    circle(position.center.x, position.center.y, dimension / 2);
    settextstyle(3, 0, 1);
    outtextxy(position.center.x, position.center.y, strdup(title.c_str()));
}

//Show left box with component info
void Button::ShowBox()
{
    setlinestyle(0, 0, 3);
    rectangle(position.up_left.x, position.up_left.y, position.down_right.x, position.down_right.y);
    settextstyle(3, 0, 2);

    std::stringstream titleStream(title);
    std::string temporary;

    int k = 0;
    while (std::getline(titleStream, temporary, '\n'))
    {
        outtextxy(position.center.x - Button_helper.textSpace(temporary) / 2, position.up_left.y + 4 + k * 20, strdup(temporary.c_str()));
        k++;
        settextstyle(3, 0, 1);
    }

    settextstyle(3, 0, 1);
}


//Hide the left box right buttons (measures)
void Button::Hide()
{
    setcolor(BLACK);
    for(int i = position.up_left.y; i <= position.down_right.y; i++)
    {
        line(position.up_left.x, i, position.down_right.x, i);
    }
    setcolor(WHITE);
}
