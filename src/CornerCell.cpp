#include <iostream>
#include "../include/value.h"
#include "../include/CornerCell.h"

CornerCell::CornerCell(Position *position, short value) : Cell(position, value) {}

void CornerCell::render()
{
    short posX = this->position->getPosX();
    short posY = this->position->getPosY();
    
    if ((posX == 0 && posY == 0) || (posX == 0 && posY == UPPER))
    {
        std::cout << "| ";
        Cell::render();
        std::cout << " ";
    }
    else if ((posX == UPPER && posY == 0) || (posX == UPPER && posY == UPPER))
    {
        std::cout << " ";
        Cell::render();
        std::cout << " |" << std::endl;
    }
}