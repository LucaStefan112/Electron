#include <graphics.h>
#include <string>
#include <iostream>

#ifndef HELPER_H
#define HELPER_H

class Helper{
public:
    struct Vector_2D{double x = 0, y = 0;};

    Vector_2D makeVector_2D(double x, double y);
    int textSpace(std::string text);
};

#endif // HELPER_H
