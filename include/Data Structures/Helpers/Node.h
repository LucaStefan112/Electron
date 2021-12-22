#include <string>

#include "ElectronicComponent.h"

class Node {
    public:
    ElectronicComponent component;
    Node* next; // Pointer to next node in DLL
    Node* prev; // Pointer to previous node in DLL
};
