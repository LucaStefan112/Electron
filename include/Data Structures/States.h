#include "Data Structures/ElectronicComponentsVector.h"

#include "Data Structures/Helpers/Node.h"

class States {
private:
    Node *head, *current, *tail;
public:
    States();

    Node getTail();
    Node getCurrent();
    Node getHead();

    void setCurrent(ElectronicComponentsVector state);
};
