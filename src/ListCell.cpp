#include <iostream>
#include "../include/value.h"
#include "../include/movement.h"
#include "../include/Cell.h"
#include "../include/ListCell.h"

ListCell::ListCell()
{
    this->size = BOARD_SIZE;
    this->cells = new Cell *[this->size];

    for (short i = 0; i < BOARD_SIZE; i++)
    {
        this->cells[i] = nullptr;
    }
}

ListCell::~ListCell()
{
    for (short i = 0; i < BOARD_SIZE; i++)
    {
        delete this->cells[i];
        this->cells[i] = nullptr;
    }

    delete[] this->cells;
    this->cells = nullptr;
}

short ListCell::getSize()
{
    return this->size;
}

Cell *ListCell::getCell(Position *position)
{
    return this->cells[this->parsePosition(position)];
}

Cell *ListCell::getCell(short value)
{
    Cell *cell = nullptr;

    for (short i = 0; i < BOARD_SIZE; i++)
    {
        cell = this->cells[i];
        if (cell->getValue() == value)
        {
            return cell;
        }
    }

    return nullptr;
}

void ListCell::setCell(Position *position, Cell *cell)
{
    this->cells[this->parsePosition(position)] = cell;
}

void ListCell::swapCell(Cell *selectedCell, Position *nextPosition)
{
    Cell *nextCell = this->getCell(nextPosition);
    short tempValue = selectedCell->getValue();
    selectedCell->setValue(nextCell->getValue());
    nextCell->setValue(tempValue);
}

short ListCell::parsePosition(Position *position)
{
    return position->getPosY() * BOARD_ROW_SIZE + position->getPosX();
}

bool ListCell::isNextMove(Position *nextPosition, std::string strMove, short selectedValue)
{
    if (nextPosition != nullptr)
    {
        if (this->getCell(nextPosition)->getValue() == 0)
        {
            return true;
        }
    }

    std::cout << "Cell " << selectedValue << " cannot move " << strMove << "\n";
    return false;
}

void ListCell::processMove(Cell *selectedCell, short x, short y, std::string strMove)
{
    Position *nextPosition = Position::getInstance(selectedCell->getPosition()->getPosX() + x, selectedCell->getPosition()->getPosY() + y);

    if (this->isNextMove(nextPosition, strMove, selectedCell->getValue()))
    {
        this->swapCell(selectedCell, nextPosition);
    }

    delete nextPosition;
    nextPosition = nullptr;
}

void ListCell::move(Cell *selectedCell, char nextMove)
{
    switch (nextMove)
    {
    case UP:
        this->processMove(selectedCell, 0, -1, STR_UP);
        break;
    case RIGHT:
        this->processMove(selectedCell, 1, 0, STR_RIGHT);
        break;
    case DOWN:
        this->processMove(selectedCell, 0, 1, STR_DOWN);
        break;
    case LEFT:
        this->processMove(selectedCell, -1, 0, STR_LEFT);
        break;
    }
}

void ListCell::updateList(short selectedValue, char nextMove)
{
    this->move(this->getCell(selectedValue), nextMove);
}

void ListCell::randomList(const std::string *mode, const int modeSize)
{
    for (int i = 0; i < modeSize; i++)
    {
        this->updateList(mode[i][0] - ASCII_0, mode[i][1]);
    }
}

bool ListCell::isWin()
{
    short value = 1;
    Position *position = nullptr;

    for (short i = 0; i < BOARD_ROW_SIZE; i++)
    {
        for (short j = 0; j < BOARD_ROW_SIZE; j++)
        {
            if (i == BOARD_ROW_SIZE - 1 && j == BOARD_ROW_SIZE - 1)
            {
                break;
            }
            position = Position::getInstance(j, i);
            if (this->getCell(position)->getValue() != value++)
            {
                delete position;
                position = nullptr;
                return false;
            }
        }
    }

    delete position;
    position = nullptr;
    
    return true;
}