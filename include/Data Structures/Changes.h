#include <vector>
#include <string>

#include "Data Structures/Helpers/Change.h"

class Changes {
private:
    std::vector <Change> undo;
    std::vector <Change> redo;
public:
    void addChange(Change change);
    Change getUndo();
    Change getRedo();
    void clearRedo();
    bool undoEmpty();
    bool redoEmpty();
};
