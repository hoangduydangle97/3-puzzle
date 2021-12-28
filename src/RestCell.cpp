#include <iostream>
#include "../include/value.h"
#include "../include/RestCell.h"

RestCell::RestCell(Position *position, short value) : Cell(position, value) {}

void RestCell::render()
{
    short posX = this->position->getPosX();
    short posY = this->position->getPosY();

    if (posY == 0 || posY == UPPER)
    {
        std::cout << "| ";
        Cell::render(); 
        std::cout << " |";
    }
    else if (posY == MIDDLER && posX == 0)
    {
        std::cout << "| ";
        Cell::render();
        std::cout << " ";
    }
    else if (posY == MIDDLER && posX == UPPER)
    {
        std::cout << " ";
        Cell::render();
        std::cout << " |" << std::endl;
    }
}