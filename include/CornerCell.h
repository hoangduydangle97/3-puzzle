#ifndef CORNER_CELL_H
#define CORNER_CELL_H

#include "./Cell.h"

class CornerCell : public Cell
{
public:
    CornerCell(Position *position, short value);
    void render();
};

#endif