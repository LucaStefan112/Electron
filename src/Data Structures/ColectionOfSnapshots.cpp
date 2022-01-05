#include "Data Structures/ColectionOfSnapshots.h"
#include "Data Structures/Snapshot.h"
#include "Data Structures/Helpers/Node.h"

ColectionOfSnapshots::ColectionOfSnapshots() {
    head = NULL;
    tail = NULL;
    current = NULL;
}

void ColectionOfSnapshots::reset() {
    head = NULL;
    tail = NULL;
    current = NULL;
}

Node* ColectionOfSnapshots::getHead() {
    return head;
}

Node* ColectionOfSnapshots::getCurrent() {
    return current;
}

Node* ColectionOfSnapshots::getTail() {
    return tail;
}

void ColectionOfSnapshots::setCurrent(Snapshot state) {
    Node *temporary = new Node();
    temporary->state = state;
    temporary->next = NULL;

    if (head == NULL) {
        head = temporary;
        current = temporary;
        tail = temporary;
    } else {
        tail->next = temporary;
        tail = temporary;
    }
}

void ColectionOfSnapshots::setCurrentToPrevious() {
    if (current->previous != NULL) {
        current = current->previous;
    }
}

void ColectionOfSnapshots::setCurrentToNext() {
    if (current->next != NULL) {
        current = current->next;
    }
}

void ColectionOfSnapshots::saveToFile(std::string filepath) {
    std::ofstream outputFile;
    outputFile.open(filepath, std::fstream::trunc);
    outputFile.write((char*)&current->state, sizeof(current->state));
    outputFile.close();
}

void ColectionOfSnapshots::importFromFile(std::string filepath) {
    reset();
    Snapshot temporary;

    std::ifstream inputFile;
    inputFile.open(filepath, std::fstream::in);
    inputFile.seekg(0);
    inputFile.read((char*)&temporary, sizeof(temporary));
    inputFile.close();

    setCurrent(temporary);
}

void ColectionOfSnapshots::toString() {

}
