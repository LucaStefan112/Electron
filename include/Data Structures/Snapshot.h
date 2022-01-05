#ifndef SNAPSHOT
#define SNAPSHOT

#include <vector>
#include <string>

#include "Electronic Components/ElectronicComponent.h"

class Snapshot {
private:
    std::vector<ElectronicComponent> current;
public:
    void addComponent(ElectronicComponent componenet);
    void removeComponent(std::string component_code);
    std::vector<ElectronicComponent> getComponents();
};

#endif
