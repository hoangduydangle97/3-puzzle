#ifndef BOARD_H
#define BOARD_H

#include "./value.h"
#include "./ListCell.h"

class Board
{
private:
    ListCell *listCell;
    void genMode();

public:
    Board();
    ~Board();
    ListCell *getListCell();
    void render();
    void init();
    void createNewCell(short x, short y, short value, CellType type);
    void update(short selectedValue, char nextMove);
    bool isWin();
};

#endif