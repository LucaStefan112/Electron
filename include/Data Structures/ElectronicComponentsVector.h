#include <vector>
#include <string>

#include "ElectronicComponent.h"

class ElectronicComponentsVector {
private:
    std::vector<ElectronicComponent> current;
public:
    void addComponent(ElectronicComponent componenet);
    void destroyComponent(std::string component_code);
    std::vector<ElectronicComponent> getComponents();
};
