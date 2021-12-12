#include "UI/Button.h"
#include <string>

#define LETTER_SPACE 10

Helper Button_helper;

Button::Button(double thisWidth, double thisHeight, std::string thisTitle){

    if(thisWidth <= 0 || thisHeight <= 0){
        std::cout << "Width and height must be greater than 0!";
        return;
    }
    else{
        width = thisWidth;  height = thisHeight;
        title = thisTitle;
    }
}

//Setter of the up_left point:
void Button::setPositionUpLeft(Helper::Vector_2D thisPosition){
    //Updating the other reference points:
    position.up_left.x = thisPosition.x;
    position.center.x = position.up_left.x + width / 2;
    position.down_right.x = position.up_left.x + width;

    position.up_left.y = thisPosition.y;
    position.center.y = position.up_left.y + height / 2;
    position.down_right.y = position.up_left.y + height;
}

//Setter of the center point:
void Button::setPositionCenter(Helper::Vector_2D thisPosition){
    //Updating the other reference points:
    position.center.x = thisPosition.x;
    position.up_left.x = position.center.x - width / 2;
    position.down_right.x = position.center.x + width / 2;

    position.center.y = thisPosition.y;
    position.up_left.y = position.center.y - height / 2;
    position.down_right.y = position.center.y + height / 2;
}

//Setter of the down_right point:
void Button::setPositionDownRight(Helper::Vector_2D thisPosition){
    //Updating the other reference points:
    position.down_right.x = thisPosition.x;
    position.up_left.x = position.down_right.x - width;
    position.center.x = position.down_right.x - width / 2;

    position.down_right.y = thisPosition.y;
    position.up_left.y = position.down_right.y - height;
    position.center.y = position.down_right.y - height / 2;
}

//Setter of the title:
void Button::setTitle(std::string thisTitle) {
    title = thisTitle;
}

//Setter of the width:
void Button::setWidth(double thisWidth){
    width = thisWidth;
    position.up_left.x = position.center.x - width / 2;
    position.down_right.x = position.center.x + width / 2;
}

//Setter of the height:
void Button::setHeight(double thisHeight){
    height = thisHeight;
    position.up_left.y = position.center.y - height / 2;
    position.down_right.y = position.center.y + height / 2;
}

//Getter of the up_left point:
Helper::Vector_2D Button::getPositionUpLeft(){
    return Button_helper.makeVector_2D(position.up_left.x, position.up_left.y);
}

//Getter of the center point:
Helper::Vector_2D Button::getPositionCenter(){
    return Button_helper.makeVector_2D(position.center.x, position.center.y);
}

//Getter of the down_right point:
Helper::Vector_2D Button::getPositionDownRight(){
    return Button_helper.makeVector_2D(position.down_right.x, position.down_right.y);
}

//Getter of the width:
double Button::getWidth(){
    return width;
}

//Getter of the height:
double Button::getHeight(){
    return height;
}

std::string Button::getTitle(){
    return title;
}

void Button::Show() {
    int textSpace = title.size() * LETTER_SPACE;
    std::cout << position.up_left.x << " " << position.up_left.y << " " << position.down_right.x << " " << position.down_right.y;
    std::cout << std::endl;
    std::cout << title << " " << title.size();
    //bar(position.up_left.x, position.up_left.y, position.down_right.x, position.down_right.y);

    char char_array[title.size() + 1];
    strcpy(char_array, title.c_str());

    setlinestyle(0, 0, 3);
    rectangle(position.up_left.x, position.up_left.y, position.down_right.x, position.down_right.y);
    settextstyle(9, 0, 2);
    outtextxy(position.up_left.x + 20, position.up_left.y + 20, char_array);
}
