#include "../include/value.h"
#include "../include/Position.h"

Position::Position(short posX, short posY)
{
    this->posX = posX;
    this->posY = posY;
}

Position *Position::getInstance(short posX, short posY)
{
    if (posX < 0 || posX > (BOARD_ROW_SIZE - 1) || posY < 0 || posY > (BOARD_ROW_SIZE - 1))
    {
        return nullptr;
    }
    return new Position(posX, posY);
}

void Position::setPosX(short posX)
{
    this->posX = posX;
}

short Position::getPosX()
{
    return this->posX;
}

void Position::setPosY(short posY)
{
    this->posY = posY;
}

short Position::getPosY()
{
    return this->posY;
}