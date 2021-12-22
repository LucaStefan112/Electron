#include "Data Structures/ElectronicComponentsVector.h"

#include "Data Structures/Helpers/Node.h"

States::States() {
    current->prev = NULL;
    current->next = NULL;
}

Node States::getHead() {
    return head;
}

Node States::getTail() {
    return tail;
}

States::addState(ElectronicComponentsVector state) {
    Node *temporary = new Node();
    temporary->state = state;
    temporary->next = NULL;

    if (head == NULL) {
        head = temporary;
        tail = temporary;
    } else {
        tail->next = temporary;
        tail = temporary;
    }
}
