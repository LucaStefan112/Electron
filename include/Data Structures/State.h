#include <vector>
#include <string>

#include "ElectronicComponent.h"

class State {
private:
    std::vector<ElectronicComponent> current;
public:
    void addComponent(ElectronicComponent componenet);
    void removeComponent(std::string component_code);
    std::vector<ElectronicComponent> getComponents();
};
