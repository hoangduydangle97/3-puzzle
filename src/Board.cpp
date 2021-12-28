#include <iostream>
#include "../include/movement.h"
#include "../include/Board.h"
#include "../include/CornerCell.h"
#include "../include/CenterCell.h"
#include "../include/RestCell.h"

Board::Board()
{
    this->listCell = new ListCell();
}

Board::~Board()
{
    delete this->listCell;
    this->listCell = nullptr;
}

ListCell *Board::getListCell()
{
    return this->listCell;
}

void Board::render()
{
    Position *position = nullptr;

    for (short i = 0; i < BOARD_ROW_SIZE; i++)
    {
        std::cout << "+---+---+---+\n";
        for (short j = 0; j < BOARD_ROW_SIZE; j++)
        {
            position = Position::getInstance(j, i);
            this->listCell->getCell(position)->render();
            delete position;
            position = nullptr;
        }
    }
    
    std::cout << "+---+---+---+\n";
}

void Board::update(short selectedValue, char nextMove)
{
    this->listCell->updateList(selectedValue, nextMove);
    std::cout << "\n";
    this->render();
}

void Board::createNewCell(short x, short y, short value, CellType type)
{
    Position *position = Position::getInstance(x, y);
    Cell *cell = nullptr;

    switch (type)
    {
    case CORNER:
        cell = new CornerCell(position, value);
        break;
    case CENTER:
        cell = new CenterCell(position, value);
        break;
    case REST:
        cell = new RestCell(position, value);
        break;
    }
    
    this->listCell->setCell(position, cell);
}

void Board::genMode()
{
    int min = 1;
    int max = MODE_SIZE;

    switch (min + rand() % (max + 1 - min))
    {
    case 1:
        this->listCell->randomList(MODE_1, MODE_1_SIZE);
        break;
    case 2:
        this->listCell->randomList(MODE_2, MODE_2_SIZE);
        break;
    case 3:
        this->listCell->randomList(MODE_3, MODE_3_SIZE);
        break;
    case 4:
        this->listCell->randomList(MODE_4, MODE_4_SIZE);
        break;
    case 5:
        this->listCell->randomList(MODE_5, MODE_5_SIZE);
        break;
    }
}

void Board::init()
{
    this->createNewCell(0, 0, 1, CORNER);
    this->createNewCell(1, 0, 2, REST);
    this->createNewCell(2, 0, 3, CORNER);
    this->createNewCell(0, 1, 4, REST);
    this->createNewCell(1, 1, 5, CENTER);
    this->createNewCell(2, 1, 6, REST);
    this->createNewCell(0, 2, 7, CORNER);
    this->createNewCell(1, 2, 8, REST);
    this->createNewCell(2, 2, 0, CORNER);
    this->genMode();
    this->render();
}