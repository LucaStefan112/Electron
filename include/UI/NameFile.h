#ifndef NAMEFILE_H
#define NAMEFILE_H

#include "Helper.h"

class NameFile
{
    public:
        NameFile();

        std::string filename;
        int window_code;

        void Show();
        int ListenEvents();
};

#endif // NAMEFILE_H
