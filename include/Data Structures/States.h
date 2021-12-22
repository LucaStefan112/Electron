#include "Data Structures/ElectronicComponentsVector.h"

#include "Data Structures/Helpers/Node.h"

class States {
private:
    Node *head, *tail;
public:
    States();

    Node getTail();
    Node getHead();
    void addState(ElectronicComponentsVector state);
};
