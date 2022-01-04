#ifndef OTHERINFO_H
#define OTHERINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class OtherInfo
{
    public:
        OtherInfo();
        
        Button exit;
        Buzzer buzzer;
        Ground ground;
        Inductor inductor;
        Lamp lamp;
        Microphone microphone;
        Motor motor;
        Speaker speaker;

        int window_code;
        void Show(double w, double h);
        int WatchClick();
        int WatchExit();
};

#endif // OTHERINFO_H
