#ifndef COMPOPNENTSLIST_H
#define COMPOPNENTSLIST_H

#include "ElectronicComponent.h"

class CompopnentsList{
    private:
        int numberOfComponents = 0;

        ElectronicComponent* componentsList[50];

    public:
        CompopnentsList();

        int getNumberOfComponents();
        void addComponent(std::string typeOfComponent);
        void removeComponent(std::string thisComponentCode);
        ElectronicComponent* getSelectedComponent();
};

#endif // COMPOPNENTSLIST_H
