#include "Data Structures/Snapshot.h"

#include <string>

#include "Data Structures/Helpers/Node.h"

class ColectionOfSnapshots {
private:
    Node *head, *current, *tail;
public:
    ColectionOfSnapshots();

    void reset();

    Node* getTail();
    Node* getCurrent();
    Node* getHead();

    void setCurrent(Snapshot state);
    void setCurrentToPrevious();
    void setCurrentToNext();

    void saveToFile(std::string filepath);
    void importFromFile(std::string filepath);
};
