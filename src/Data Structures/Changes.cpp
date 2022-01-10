#include "Data Structures/Changes.h"
#include <iostream>

void Changes::addChange(Change change) {
    undo.push_back(change);
}

Change Changes::getUndo() {
    Change returnable = undo[undo.size() - 1];
    undo.pop_back();
    redo.push_back(returnable);

    return returnable;
}

Change Changes::getRedo() {
    Change returnable = redo[redo.size() - 1];
    redo.pop_back();
    undo.push_back(returnable);

    return returnable;
}

void Changes::clearRedo() {
    redo.clear();
}

bool Changes::undoEmpty() {
    return undo.empty();
}

bool Changes::redoEmpty() {
    return redo.empty();
}
