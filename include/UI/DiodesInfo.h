#ifndef DIODESINFO_H
#define DIODESINFO_H


#include "UI/InfoScreen.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class DiodesInfo: public InfoScreen
{
    public:
        DiodesInfo();
        void Show(double w, double h);
};

#endif // DIODESINFO_H
