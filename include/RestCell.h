#ifndef REST_CELL_H
#define REST_CELL_H

#include "./Cell.h"

class RestCell : public Cell
{
public:
    RestCell(Position *position, short value);
    void render();
};

#endif