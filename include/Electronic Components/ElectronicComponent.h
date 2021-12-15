#ifndef ELECTRONICCOMPONENT_H_INCLUDED
#define ELECTRONICCOMPONENT_H_INCLUDED

#include "Helper.h"
#include "Enums.h"

class ElectronicComponent{
protected:
    //Reference points:
    struct{
        Helper::Vector_2D up_left, center, down_right;
    }position;

    //Dimensions of the component:
    double width = 100, height = 100, width_height_ratio = 1;
    std::string name;
    PositionType positionType = up_left;

public:
    ElectronicComponent(double thisWidth = 100, double thisHeight = 100, std::string thisName = "Electronic Component");

    //Setters:
    void setPositionUpLeft(Helper::Vector_2D thisPosition);
    void setPositionCenter(Helper::Vector_2D thisPosition);
    void setPositionDownRight(Helper::Vector_2D thisPosition);
    void setWidth(double thisWidth);
    void setHeight(double thisHeight);

    //Getters:
    Helper::Vector_2D getPositionUpLeft();
    Helper::Vector_2D getPositionCenter();
    Helper::Vector_2D getPositionDownRight();
    double getWidth();
    double getHeight();

    //Drawing the component:
    void Show();

    //Parsing the component's data to string:
    std::string toString();
};


#endif // ELECTRONICCOMPONENT_H_INCLUDED
