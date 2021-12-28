#ifndef VALUE_H
#define VALUE_H

const short MIN_SELECTED_VALUE = 0;
const short MAX_SELECTED_VALUE = 9;
const short DEFAULT_SELECTED_VALUE = -1;
const short ASCII_0 = 48;
const short BOARD_SIZE = 9;
const short BOARD_ROW_SIZE = 3;
const short UPPER = BOARD_ROW_SIZE - 1;
const short MIDDLER = BOARD_ROW_SIZE / 2;
const int RANDOM_MIN = 0;
const int RANDOM_MAX = 3;

enum CellType 
{
    CORNER,
    CENTER,
    REST
};

#endif