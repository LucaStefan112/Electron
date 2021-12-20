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
