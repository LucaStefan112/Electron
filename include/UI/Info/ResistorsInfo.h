#ifndef RESISTORSINFO_H
#define RESISTORSINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class ResistorsInfo: public Screen
{
    public:
        ResistorsInfo();
        
        Button exit;
        void Show(double w, double h);
        void WatchClick();
};

#endif // RESISTORSINFO_H
