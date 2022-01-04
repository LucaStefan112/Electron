#ifndef NAMEFILE_H
#define NAMEFILE_H

#include "UI/Button.h"
#include "Helper.h"

class NameFile
{
    public:
        NameFile();

        Button save, cancel;
        std::string filename;
        int window_code;

        void Show();
        int ListenEvents();
};

#endif // NAMEFILE_H
