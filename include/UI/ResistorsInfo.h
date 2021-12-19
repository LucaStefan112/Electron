#ifndef RESISTORSINFO_H
#define RESISTORSINFO_H

#include "UI/InfoScreen.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class ResistorsInfo: public InfoScreen
{
    public:
        ResistorsInfo();
        void Show(double w, double h);
};

#endif // RESISTORSINFO_H
