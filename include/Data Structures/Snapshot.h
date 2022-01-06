#ifndef SNAPSHOT
#define SNAPSHOT

#include <string>

#include "Electronic Components/ElectronicComponent.h"

class Snapshot {
private:
public:
    ElectronicComponent *current[100];
    int sizeOfCurrent = 0;
    void addComponent(ElectronicComponent &componenet);
    void removeComponent(std::string component_code);
    ElectronicComponent* *getComponents();
    ElectronicComponent* getComponent(std::string componentCode);
    std::string getClicked(int mouse_x, int mouse_y);

    void saveToFile(std::string filepath);
    void importFromFile(std::string filepath);
};

#endif
