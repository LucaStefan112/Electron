#include "Data Structures/Snapshot.h"

#include "Data Structures/Helpers/Node.h"

class States {
private:
    Node *head, *current, *tail;
public:
    States();

    Node* getTail();
    Node* getCurrent();
    Node* getHead();

    void setCurrent(Snapshot state);
    void setCurrentToPrevious();
    void setCurrentToNext();
};
