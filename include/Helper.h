#include <graphics.h>
#include <string>
#include <iostream>
#include <math.h>
#include "Electronic Components/ElectronicComponent.h"

#ifndef HELPER_H
#define HELPER_H

#define DEFAULT_CONNECTED_COMPONENT -2
#define DEFAULT_X 0
#define DEFAULT_Y 0
#define PI 3.14159265

class Helper{
public:
    struct Vector_2D{double x = DEFAULT_X, y = DEFAULT_Y;};

    Vector_2D makeVector_2D(double x, double y);
    int textSpace(std::string text);

    struct ConnectionPoint{
        int connectedComponentCode = DEFAULT_CONNECTED_COMPONENT;
        Vector_2D position;
    };

    double distanceBetween(Vector_2D a, Vector_2D b);
};

#endif // HELPER_H
