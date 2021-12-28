#ifndef USER_H
#define USER_H

#include <cstring>
#include "./Board.h"

class User
{
private:
    int stepCount;
    short selectedValue;
    char nextMove;
    Board *board;
    bool isInput();
    bool isExit();
    void parseInput(std::string);

public:
    User();
    ~User();
    int getStepCount();
    short getSelectedValue();
    void setSelectedValue(short selectedValue);
    char getNextMove();
    void setNextMove(char nextMove);
    void getInput();
    void process();
    void infoResult(bool isWin);
};

#endif