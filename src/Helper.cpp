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

    if(a.x == b.x && a.y == b.y)  return a;

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

void Helper::rotationalBar(double x1, double y1, double x2, double y2, Vector_2D thisReference, int degrees){

    Vector_2D barPosition1 = rotatePointToReference(
        makeVector_2D(x1, y1),
        thisReference,
        degrees);
    Vector_2D barPosition2 = rotatePointToReference(
        makeVector_2D(x2, y2),
        thisReference,
        degrees);

    bar(barPosition1.x, barPosition1.y, barPosition2.x, barPosition2.y);
}

void Helper::rotationalCircle(double x, double y, Vector_2D thisReference, double radius, int degrees){

    Vector_2D circlePosition = rotatePointToReference(
        makeVector_2D(x, y),
        thisReference,
        degrees);

    circle(circlePosition.x, circlePosition.y, radius);
}

void Helper::rotationalEllipse(double x, double y, Vector_2D thisReference, double D1, double D2, double R1, double R2, int degrees, bool thisFlipped){

    Vector_2D ellipsePosition = rotatePointToReference(
        makeVector_2D(x, y),
        thisReference,
        degrees);

    if(R1 != R2){
        R1 = abs(R1);   R2 = abs(R2);
        R1 = abs(R1 + (R2 - R1) * abs(sin(degrees * PI / 180)));
        R2 = abs(R2 + (R1 - R2) * abs(sin(degrees * PI / 180)));
    }

    if(thisFlipped){
        D1 += degrees;
        D2 += degrees;
    }
    else{
        D1 -= degrees;
        D2 -= degrees;
    }

    while(D1 < 0)   D1 += 360;
    while(D1 > 360)   D1 -= 360;

    while(D2 < 0)   D2 += 360;
    while(D2 > 360)   D2 -= 360;

    if(thisFlipped){
        if(0 <= D1 && D1 <= 180) D1 = 180 - D1;
        else if(180 <= D1 && D1 <= 360) D1 = 540 - D1;

        if(0 <= D2 && D2 <= 180) D2 = 180 - D2;
        else if(180 <= D2 && D2 <= 360) D2 = 540 - D2;

        std::swap(D1, D2);
    }

    ellipse(ellipsePosition.x, ellipsePosition.y, D1, D2, R1, R2);
}

void Helper::rotationalFillPoly(int nr, int* arr, Vector_2D thisReference, int degrees){

    int thisArr[2 * nr];

    for(int i = 0; i < nr; i++){
        Vector_2D pointPosition = rotatePointToReference(
            makeVector_2D(arr[2 * i], arr[2 * i + 1]),
            thisReference,
            degrees);

        thisArr[2 * i] = pointPosition.x;
        thisArr[2 * i + 1] = pointPosition.y;;
    }

    fillpoly(nr, thisArr);
}

void Helper::rotationalArc(double x, double y, Vector_2D thisReference, double D1, double D2, double R, int degrees, bool thisFlipped){

    Vector_2D arcPosition = rotatePointToReference(
        makeVector_2D(x, y),
        thisReference,
        degrees);

    if(thisFlipped){
        D1 += degrees;
        D2 += degrees;
    }
    else{
        D1 -= degrees;
        D2 -= degrees;
    }

    while(D1 < 0)   D1 += 360;
    while(D1 > 360)   D1 -= 360;

    while(D2 < 0)   D2 += 360;
    while(D2 > 360)   D2 -= 360;

    if(thisFlipped){
        if(0 <= D1 && D1 <= 180) D1 = 180 - D1;
        else if(180 <= D1 && D1 <= 360) D1 = 540 - D1;

        if(0 <= D2 && D2 <= 180) D2 = 180 - D2;
        else if(180 <= D2 && D2 <= 360) D2 = 540 - D2;

        std::swap(D1, D2);
    }

    arc(arcPosition.x, arcPosition.y, D1, D2, R);
}

void Helper::rotationalOuttextxy(double x, double y, Vector_2D thisReference, char* text, int degrees){

    Vector_2D textPosition = rotatePointToReference(
        makeVector_2D(x, y),
        thisReference,
        degrees);

    outtextxy(textPosition.x, textPosition.y, text);
}
