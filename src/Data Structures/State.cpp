#include <vector>
#include <string>
#include <algorithm>

#include "ElectronicComponent.h"
#include "Data Structures/State.h"

void State::addComponent(ElectronicComponent component) {
    current.push_back(component);
}

void State::removeComponent(std::string component_code) {
    current.erase(std::remove_if(current.begin(),
                                 current.end(),
                                 [component_code](ElectronicComponent component){ return component_code == component.getComponentCode(); }));
}

std::vector<ElectronicComponent> State::getComponents() {
    return current;
}
