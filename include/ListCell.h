#ifndef LIST_CELL_H
#define LIST_CELL_H

#include "./Cell.h"

class ListCell
{
private:
    short size;
    Cell **cells;
    short parsePosition(Position *position);
    void swapCell(Cell *selectedCell, Position *nextPosition);
    bool isNextMove(Position *nextPosition, std::string strMove, short selectedValue);
    void processMove(Cell *selectedCell, short x, short y, std::string strMove);
    virtual void move(Cell *selectedCell, char nextMove);
    Cell *getCell(short value);

public:
    ListCell();
    virtual ~ListCell();
    short getSize();
    Cell *getCell(Position *position);
    void setCell(Position *position, Cell *cell);
    void updateList(short selectedValue, char nextMove);
    void randomList(const std::string *mode, const int modeSize);
    bool isWin();
};

#endif