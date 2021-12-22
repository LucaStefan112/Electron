#include <vector>
#include <string>
#include <algorithm>

#include "ElectronicComponent.h"
#include "Data Structures/ElectronicComponentsVector.h"

void ElectronicComponentsVector::addComponent(ElectronicComponent component) {
    current.push_back(component);
}

void ElectronicComponentsVector::removeComponent(std::string component_code) {
    current.erase(std::remove_if(current.begin(),
                                 current.end(),
                                 [component_code](ElectronicComponent component){ return component_code == component.getComponentCode(); }));
}

std::vector<ElectronicComponent> ElectronicComponentsVector::getComponents() {
    return current;
}
