#include <iostream>
#include "../include/movement.h"
#include "../include/Cell.h"

Cell::Cell(Position *position, short value)
{
    this->position = position;
    this->value = value;
}

Cell::~Cell()
{
    delete this->position;
    this->position = nullptr;
}

Position *Cell::getPosition()
{
    return this->position;
}

short Cell::getValue()
{
    return this->value;
}

void Cell::setValue(short value)
{
    this->value = value;
}

void Cell::render()
{
    if (this->value != 0)
    {
        std::cout << this->value;
        return;
    }
    std::cout << " ";
}