#include "Helper.h"

#define LETTER_SPACE 8

Helper::Vector_2D Helper::makeVector_2D(double x, double y){
    Vector_2D thisVector;   thisVector.x = x;   thisVector.y = y;
    return thisVector;
}

int Helper::textSpace(std::string title) {
    return title.size() * LETTER_SPACE;
}

double Helper::distanceBetween(Vector_2D a, Vector_2D b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Helper::Vector_2D Helper::rotatePointToReference(Vector_2D b, Vector_2D a, int degrees){

    double defaultAngle = asin(abs(a.y - b.y) / distanceBetween(a, b)) * 180 / PI;

    if(a.x < b.x && a.y > b.y)  defaultAngle = 180 - defaultAngle;
    else if(a.x <= b.x && a.y <= b.y)   defaultAngle += 180;
    else if(a.x > b.x && a.y < b.y) defaultAngle = 360 - defaultAngle;

    return makeVector_2D(a.x - distanceBetween(a, b) * cos(PI / 180 * (defaultAngle + degrees)),
                         a.y - distanceBetween(a, b) * sin(PI / 180 * (defaultAngle + degrees)));
}

void Helper::rotationalLine(double x1, double y1, double x2, double y2, Vector_2D thisReference, int degrees){

    Vector_2D linePosition1 = rotatePointToReference(
        makeVector_2D(x1, y1),
        thisReference,
        degrees);
    Vector_2D linePosition2 = rotatePointToReference(
        makeVector_2D(x2, y2),
        thisReference,
        degrees);

    line(linePosition1.x, linePosition1.y, linePosition2.x, linePosition2.y);
}

void Helper::rotationalCircle(double x1, double y1, Vector_2D thisReference, double radius, int degrees){

    Vector_2D circlePosition = rotatePointToReference(
        makeVector_2D(x1, y1),
        thisReference,
        degrees);

    circle(circlePosition.x, circlePosition.y, radius);
}
