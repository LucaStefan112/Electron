#ifndef LOGICGATESINFO_H
#define LOGICGATESINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class LogicGatesInfo
{
    public:
        LogicGatesInfo();
        
        Button exit;
        AndGate andGate;
        NandGate nandGate;
        NorGate norGate;
        NotGate notGate;
        OrGate orGate;
        XorGate xorGate;

        int window_code;

        void Show(double w, double h);
        int WatchClick();
        void WatchExit();
};

#endif // LOGICGATESINFO_H
