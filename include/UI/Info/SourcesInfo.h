#ifndef SOURCESINFO_H
#define SOURCESINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class SourcesInfo: public Screen
{
    public:
        SourcesInfo();
        
        Button exit;
        void Show(double w, double h);
        void WatchClick();
};
#endif // SOURCESINFO_H
