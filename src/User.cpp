#include <iostream>
#include <cstring>
#include "../include/movement.h"
#include "../include/value.h"
#include "../include/User.h"

User::User()
{
    this->stepCount = 0;
    this->selectedValue = DEFAULT_SELECTED_VALUE;
    this->nextMove = DEFAULT_MOVEMENT;
    this->board = new Board();
}

User::~User()
{
    delete this->board;
    this->board = nullptr;
}

int User::getStepCount()
{
    return this->stepCount;
}

short User::getSelectedValue()
{
    return this->selectedValue;
}

void User::setSelectedValue(short selectedValue)
{
    this->selectedValue = selectedValue;
}

char User::getNextMove()
{
    return this->nextMove;
}

void User::setNextMove(char nextMove)
{
    this->nextMove = nextMove;
}

void User::getInput()
{
    std::string input = "";
    do
    {
        std::cout << "Enter your next movement (00 to give up): ";
        getline(std::cin, input);
        this->parseInput(input);
    } while (!this->isInput());
}

void User::parseInput(std::string input)
{
    try
    {
        this->setSelectedValue(input.at(0) - ASCII_0);
        this->setNextMove(input.at(1));
    }
    catch (const std::exception &e)
    {
        this->setSelectedValue(DEFAULT_SELECTED_VALUE);
        this->setNextMove(DEFAULT_MOVEMENT);
        return;
    }
}

bool User::isInput()
{
    bool isSelectedValue = this->selectedValue >= MIN_SELECTED_VALUE && this->selectedValue < MAX_SELECTED_VALUE;
    bool isNextMove = this->nextMove == UP || this->nextMove == RIGHT || this->nextMove == DOWN || this->nextMove == LEFT || this->nextMove == DEFAULT_MOVEMENT;
    bool isValid = isSelectedValue && isNextMove;
    
    if (!isValid)
    {
        std::cout << "Please enter valid movement\n";
        std::cout << "Example: 1r, 8d, 5u, 2l\n";
    }

    return isValid;
}

bool User::isExit()
{
    return this->selectedValue == 0;
}

void User::infoResult(bool isWin)
{
    if (isWin)
    {
        std::cout << "You win!";
    }
    else
    {
        std::cout << "You lose!";
    }
    std::cout << std::endl;
}

void User::process()
{
    std::cout << "3-PUZZLE\n\n";
    std::cout << "Cell: 1 to 8\n";
    std::cout << "Movement: u, r, d, l\n\n";
    std::cout << "Example:\n";
    std::cout << "\tEnter 1u if you want to move cell 1 upwards\n";
    std::cout << "\tEnter 8l if you want to move cell 8 to the left\n\n";

    this->board->init();

    do
    {
        this->getInput();
        if (this->isExit())
        {
            this->infoResult(false);
            return;
        }
        this->board->update(this->selectedValue, this->nextMove);
        if (this->board->getListCell()->isWin())
        {
            this->infoResult(true);
            return;
        }
    } while (true);
}