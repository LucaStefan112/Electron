#ifndef HELPER_H
#define HELPER_H

class Helper{
public:
    struct Vector_2D{double x = 0, y = 0;};

    Helper();
    Vector_2D makeVector_2D(double x, double y);
};

#endif // HELPER_H