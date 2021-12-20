#ifndef ELECTRONICCOMPONENT_H_INCLUDED
#define ELECTRONICCOMPONENT_H_INCLUDED

#include "Helper.h"
#include "Enums.h"
#define MAX_NUMBER_OF_CONNECTION_POINTS 5
#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 100
#define DEFAULT_WIDTH_HEIGHT_RATIO 1
#define DEFAULT_NAME "Electronic Component"
#define DEFAULT_NUMBER_OF_CONNECTION_POINTS 0
#define DEFAULT_COMPONENT_CODE -1
#define DEFAULT_FLIP_STATE false
#define DEFAULT_ROTATE_STATE 0

class ElectronicComponent{
protected:
    //Reference points:
    struct{
        Helper::Vector_2D up_left, center, down_right;
    }position;

    //Dimensions of the component:
    double width = DEFAULT_WIDTH, height = DEFAULT_HEIGHT, width_height_ratio = DEFAULT_WIDTH_HEIGHT_RATIO;

    std::string name = DEFAULT_NAME;

    PositionType positionType = up_left;

    int componentCode = DEFAULT_COMPONENT_CODE;

    int numberOfConnectionPoints = DEFAULT_NUMBER_OF_CONNECTION_POINTS;
    Helper::ConnectionPoint connectionPoints[MAX_NUMBER_OF_CONNECTION_POINTS];

    bool flipped = DEFAULT_FLIP_STATE;
    int rotateState = DEFAULT_ROTATE_STATE;

public:
    ElectronicComponent(double thisWidth = DEFAULT_WIDTH, double thisHeight = DEFAULT_HEIGHT, std::string thisName = DEFAULT_NAME, int thisNumberOfConnectionPoints = DEFAULT_NUMBER_OF_CONNECTION_POINTS);

    //Setters:
    void setPositionUpLeft(Helper::Vector_2D thisPosition);
    void setPositionCenter(Helper::Vector_2D thisPosition);
    void setPositionDownRight(Helper::Vector_2D thisPosition);
    void setWidth(double thisWidth);
    void setHeight(double thisHeight);
    void setComponentCode(int thisComponentCode);
    void setConnectedComponentCodeAtPoint(int thisPoint, int thisComponentCode);
    void flipComponent();
    void rotateComponent(int thisDegree);

    //Getters:
    Helper::Vector_2D getPositionUpLeft();
    Helper::Vector_2D getPositionCenter();
    Helper::Vector_2D getPositionDownRight();
    double getWidth();
    double getHeight();
    int getComponentCode();
    int getNumberOfConnectionPoints();
    int getCodeOfConnectedComponentAtPoint(int thisPoint);
    Helper::ConnectionPoint* getConnectionPoints();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();

    //Parsing the component's data to string:
    std::string toString();

    void saveToFile();
};


#endif // ELECTRONICCOMPONENT_H_INCLUDED
