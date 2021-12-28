#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
    short posX;
    short posY;
    Position(short posX, short posY);

public:
    static Position *getInstance(short posX, short posY);
    void setPosX(short posX);
    short getPosX();
    void setPosY(short posY);
    short getPosY();
};

#endif
