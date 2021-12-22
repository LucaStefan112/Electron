#include <vector>
#include <string>

#include "ElectronicComponent.h"
#include "Data Structures/ElectronicComponentsVector.h"

void ElectronicComponentsVector::addComponent(ElectronicComponent component) {
    current.push_back(component);
}

void ElectronicComponentsVector::removeComponent(string component_code) {
    current.erase(std::remove_if(current.begin(),
                                 current.end(),
                                 [](ElectronicComponent component){ return component_code == componet.getComponentCode() }));
}

vector<ElectronicComponent> ElectronicComponentsVector::getComponents() {
    return current;
}
