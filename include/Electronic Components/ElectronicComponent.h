#ifndef ELECTRONICCOMPONENT_H_INCLUDED
#define ELECTRONICCOMPONENT_H_INCLUDED

#include <string>
#include <sstream>
#include "Helper.h"
#include "Enums.h"

#define MAX_NUMBER_OF_CONNECTION_POINTS 5
#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 100
#define DEFAULT_WIDTH_HEIGHT_RATIO 1
#define DEFAULT_NAME "Electronic Component"
#define DEFAULT_NUMBER_OF_CONNECTION_POINTS 0
#define DEFAULT_COMPONENT_CODE "0"
#define DEFAULT_FLIP_STATE false
#define DEFAULT_ROTATE_STATE 0
#define DEFAULT_OUTTERBOX_VALUE false;
#define DEFAULT_CONNECTIONPOINTS_VALUE false;

class ElectronicComponent{
protected:
    //Reference points:
    struct{
        Helper::Vector_2D up_left, center, down_right;
    }position;

    //Dimensions of the component:
    double width = DEFAULT_WIDTH, height = DEFAULT_HEIGHT, width_height_ratio = DEFAULT_WIDTH_HEIGHT_RATIO;

    int numberOfConnectionPoints = DEFAULT_NUMBER_OF_CONNECTION_POINTS;
    Helper::ConnectionPoint connectionPoints[MAX_NUMBER_OF_CONNECTION_POINTS];

    /* TODO getters and setters
    bool flipped = DEFAULT_FLIP_STATE;
    int rotateState = DEFAULT_ROTATE_STATE;

    bool showOutterBox = DEFAULT_OUTTERBOX_VALUE;
    bool showConnectionPoints = DEFAULT_CONNECTIONPOINTS_VALUE;
    ENDTODO */

public:
    ElectronicComponent(double thisWidth = DEFAULT_WIDTH, double thisHeight = DEFAULT_HEIGHT, std::string thisName = DEFAULT_NAME, int thisNumberOfConnectionPoints = DEFAULT_NUMBER_OF_CONNECTION_POINTS);

    /* TODO getters and setters */
    bool flipped = DEFAULT_FLIP_STATE;
    int rotateState = DEFAULT_ROTATE_STATE;

    bool showOutterBox = DEFAULT_OUTTERBOX_VALUE;
    bool showConnectionPoints = DEFAULT_CONNECTIONPOINTS_VALUE;
    /* ENDTODO  */

    //Name of the component:
    std::string name = DEFAULT_NAME;
    PositionType positionType = up_left;
    std::string componentCode = DEFAULT_COMPONENT_CODE;

    //Setters:
    void setPositionUpLeft(Helper::Vector_2D thisPosition);
    void setPositionCenter(Helper::Vector_2D thisPosition);
    void setPositionDownRight(Helper::Vector_2D thisPosition);
    void setWidth(double thisWidth);
    void setHeight(double thisHeight);
    void setComponentCode(std::string thisComponentCode);
    void setConnectedComponentCodeAtPoint(int thisPoint, std::string thisComponentCode);
    void flipComponent();
    void rotateComponent(int thisDegree);
    void setOutterBox(bool thisState);
    void setConnectionPoints(bool thisState);
    void showElements(bool modeErase = false);

    //Getters:
    Helper::Vector_2D getPositionUpLeft();
    Helper::Vector_2D getPositionCenter();
    Helper::Vector_2D getPositionDownRight();
    double getWidth();
    double getHeight();
    std::string getComponentCode();
    int getNumberOfConnectionPoints();
    std::string getCodeOfConnectedComponentAtPoint(int thisPoint);
    Helper::ConnectionPoint* getConnectionPoints();
    int getRotationState();

    bool isCursorPointInButton();
    bool isSelected();
    //Updating the position of each connection point:
    virtual void updateConnectionPointsPosition();

    //Drawing the component:
    virtual void Show();

    //Erasing the component:
    void Erase();

    //Draw lines to connected components:
    void drawConnectionLines();

    //Parsing the component's data to string:
    std::string toString();

    void saveToFile(char *filename);
};


#endif // ELECTRONICCOMPONENT_H_INCLUDED
