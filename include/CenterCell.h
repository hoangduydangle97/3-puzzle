#ifndef CENTER_CELL_H
#define CENTER_CELL_H

#include "./Cell.h"

class CenterCell : public Cell
{
public:
    CenterCell(Position *position, short value);
    void render();
    void generateAvailableNextMoves();
};

#endif