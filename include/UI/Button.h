#ifndef BUTTON_H
#define BUTTON_H

#include "Helper.h"

class Button
{
protected:
        //Reference points:
        struct{
            Helper::Vector_2D up_left, center, down_right;
        }position;

        //Dimensions of the component:
        double width = 100, height = 100;
        std::string title;

    public:
        Button(double thisWidth = 100, double thisHeight = 100, std::string thisTitle = "Button");

        //Setters:
        void setPositionUpLeft(Helper::Vector_2D thisPosition);
        void setPositionCenter(Helper::Vector_2D thisPosition);
        void setPositionDownRight(Helper::Vector_2D thisPosition);
        void setWidth(double thisWidth);
        void setHeight(double thisHeight);
        void setTitle(std::string thisTitle);

        //Getters:
        Helper::Vector_2D getPositionUpLeft();
        Helper::Vector_2D getPositionCenter();
        Helper::Vector_2D getPositionDownRight();
        double getWidth();
        double getHeight();
        std::string getTitle();

        //Show the component:
        void Show();

        //Parsing the component's data to string:
};

#endif // BUTTON_H
