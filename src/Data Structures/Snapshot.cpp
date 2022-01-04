#include <vector>
#include <string>
#include <algorithm>

#include "Electronic Components/ElectronicComponent.h"
#include "Data Structures/Snapshot.h"

void Snapshot::addComponent(ElectronicComponent component) {
    current.push_back(component);
}

void Snapshot::removeComponent(std::string component_code) {
    current.erase(std::remove_if(current.begin(),
                                 current.end(),
                                 [component_code](ElectronicComponent component){ return component_code == component.getComponentCode(); }));
}

std::vector<ElectronicComponent> Snapshot::getComponents() {
    return current;
}
