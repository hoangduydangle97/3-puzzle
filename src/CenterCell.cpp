#include <iostream>
#include "../include/Cell.h"
#include "../include/CenterCell.h"

CenterCell::CenterCell(Position *position, short value) : Cell(position, value) {}

void CenterCell::render()
{
    std::cout << "| ";
    Cell::render();
    std::cout << " |";
}