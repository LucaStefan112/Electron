#ifndef DIODESINFO_H
#define DIODESINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class DiodesInfo: public Screen
{
    public:
        DiodesInfo();
        
        Button exit;
        void Show(double w, double h);
        void WatchClick();
};

#endif // DIODESINFO_H
