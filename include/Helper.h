#include <graphics.h>
#include <string>
#include <iostream>
#include <math.h>
#include "Electronic Components/ElectronicComponent.h"

#ifndef HELPER_H
#define HELPER_H

#define DEFAULT_CONNECTED_COMPONENT "-2"
#define DEFAULT_X 0
#define DEFAULT_Y 0
#define PI 3.14159265

class Helper{
public:
    struct Vector_2D{double x = DEFAULT_X, y = DEFAULT_Y;};

    Vector_2D makeVector_2D(double x, double y);
    int textSpace(std::string text);

    struct ConnectionPoint{
        std::string connectedComponentCode = DEFAULT_CONNECTED_COMPONENT;
        Vector_2D position;
    };

    double distanceBetween(Vector_2D a, Vector_2D b);

    Vector_2D rotatePointToReference(Vector_2D a, Vector_2D b, int degrees);

    void rotationalLine(double x1, double y1, double x2, double y2, Vector_2D thisReference, int degrees);
    void rotationalBar(double x1, double y1, double x2, double y2, Vector_2D thisReference, int degrees);
    void rotationalCircle(double x, double y, Vector_2D thisReference, double radius, int degrees);
    void rotationalEllipse(double x, double y, Vector_2D thisReference, double D1, double D2, double R1, double R2, int degrees, bool thisFlipped);
    void rotationalFillPoly(int nr, int* arr, Vector_2D thisReference, int degrees);
    void rotationalArc(double x, double y, Vector_2D thisReference, double D1, double D2, double R, int degrees, bool thisFlipped);
    void rotationalOuttextxy(double x, double y, Vector_2D thisReference, char* text, int degrees);

    void drawWire(Vector_2D v1, Vector_2D v2, colors COLOR);
};


#endif // HELPER_H
