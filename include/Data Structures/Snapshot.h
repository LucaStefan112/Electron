#ifndef SNAPSHOT
#define SNAPSHOT

#include <string>
#include <map>

#include "Electronic Components/ElectronicComponent.h"
#include "Electronic Components/Electronics.h"

class Snapshot {
private:
    ElectronicComponent* current[100];
    int sizeOfCurrent = 0;
public:
    Snapshot();
    void addComponent(int cType);
    void removeComponent(std::string component_code);
    ElectronicComponent* *getComponents();
    ElectronicComponent* getComponent(std::string componentCode);
    std::string getClicked(int mouse_x, int mouse_y);
    ElectronicComponent* getSelectedComponent();

    void saveToFile(std::string filepath);
    void importFromFile(std::string filepath);
};

#endif
