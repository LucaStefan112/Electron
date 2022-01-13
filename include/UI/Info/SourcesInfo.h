#ifndef SOURCESINFO_H
#define SOURCESINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class SourcesInfo
{
public:
    SourcesInfo();

    Button exit;
    Source_Voltage_AC sourceAC;
    Source_Voltage_DC sourceDC;
    Battery battery;

    int window_code;
    void Show(double w, double h);
    int WatchClick();
    int WatchExit();
};
#endif // SOURCESINFO_H
