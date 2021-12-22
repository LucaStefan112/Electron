#include "Data Structures/ElectronicComponentsVector.h"

#include "Data Structures/Helpers/Node.h"

States::States() {
    head = NULL;
    tail = NULL;
    current = NULL;
}

Node States::getHead() {
    return head;
}

Node States::getCurrent() {
    return current;
}

Node States::getTail() {
    return tail;
}

void States::setCurrent(ElectronicComponentsVector state) {
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

void States::setCurrentToPrevious() {
    if (current->previous != NULL) {
        current = current->previous;
    }
}

void States::setCurrentToNext() {
    if (current->next != NULL) {
        current = current->next;
    }
}
