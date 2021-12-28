#ifndef CELL_H
#define CELL_H

#include <cstring>
#include "./Position.h"

class Cell
{
protected:
    Position *position;
    short value;
    Cell(Position *position, short value);

public:
    virtual ~Cell();
    Position *getPosition();
    short getValue();
    void setValue(short value);
    virtual void render();
};

#endif