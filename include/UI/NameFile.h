#ifndef NAMEFILE_H
#define NAMEFILE_H

#include "Helper.h"

//daria
class NameFile
{
public:
    NameFile();

    bool mode = 0; // 0 -> save, 1 -> open
    std::string filename;
    int window_code;

    void Show();
    int ListenEvents();
    void setMode(int m);
};

#endif // NAMEFILE_H
