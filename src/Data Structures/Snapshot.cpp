#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "Electronic Components/ElectronicComponent.h"
#include "Data Structures/Snapshot.h"

void Snapshot::addComponent(ElectronicComponent &component) {
    current[sizeOfCurrent] = &component;
    std::cout << sizeOfCurrent << ' ' << current[sizeOfCurrent]->componentCode << '\n';
    sizeOfCurrent++;
}

ElectronicComponent* *Snapshot::getComponents() {
    return current;
}

ElectronicComponent* Snapshot::getComponent(std::string componentCode) {
    for (int i = 0; i < sizeOfCurrent; i++) {
        if (current[i]->componentCode == componentCode) {
            return current[i];
        }
    }
}

void Snapshot::removeComponent(std::string component_code) {
    for (int i = 0; i < sizeOfCurrent; i++) {
        if (current[i]->componentCode == component_code) {
            delete current[i];
            current[i] = NULL;
            sizeOfCurrent--;
            break;
        }
    }

    for (int i = 0; i < sizeOfCurrent; i++) {
        std::cout << current[i]->componentCode;
    }
}

