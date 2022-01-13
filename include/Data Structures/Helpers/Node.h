#ifndef NODE
#define NODE

#include <vector>

#include "Data Structures/Snapshot.h"

class Node
{
public:
    Snapshot state;
    Node* next;
    Node* previous;
};

#endif
