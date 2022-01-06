#ifndef COMPOPNENTSLIST_H
#define COMPOPNENTSLIST_H

#include "ELectronic Components/ElectronicComponent.h"

class CompopnentsList{
    private:
        int numberOfComponents = 0;

        ElectronicComponent* componentsList[50];

    public:
        CompopnentsList();

        int getNumberOfComponents();
        void addComponent(int componentCode);
        void removeComponent(std::string thisComponentCode);
        ElectronicComponent* getSelectedComponent();
};

#endif // COMPOPNENTSLIST_H
