#ifndef SNAPSHOT
#define SNAPSHOT

#include <string>
#include <map>

#include "Enums.h"
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
    void reset();

    int getComponentsNumber();
    ElectronicComponent* *getComponents();
    ElectronicComponent* getComponent(std::string componentCode);
    std::string getClicked(int mouse_x, int mouse_y);
    ElectronicComponent* getSelectedComponent();

    static int nameToCtype(std::string name);
    static std::string removeSubString(std::string str, std::string subStr);

    void saveToStream(std::ostream &stream, int i);
    void saveToFile(std::string filepath);
    void importFromStream(std::istream &stream);
    void importFromFile(std::string filepath);
};

#endif
