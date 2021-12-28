#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <cstring>

const char UP = 'u';
const char RIGHT = 'r';
const char DOWN = 'd';
const char LEFT = 'l';
const char DEFAULT_MOVEMENT = '0';

const std::string STR_UP = "up";
const std::string STR_RIGHT = "right";
const std::string STR_DOWN = "down";
const std::string STR_LEFT = "left";

const int MODE_SIZE = 5;
const int MODE_1_SIZE = 3;
const int MODE_2_SIZE = 5;
const int MODE_3_SIZE = 13;
const int MODE_4_SIZE = 6;
const int MODE_5_SIZE = 6;

const std::string MODE_1[] = {"8r", "5d", "6l"};
const std::string MODE_2[] = {"8r", "5d", "2d", "1r", "4u"};
const std::string MODE_3[] = {"6d", "3d", "2r", "5u", "4r", "7u", "8l", "6l", "3d", "4r", "5d", "1r", "7u"};
const std::string MODE_4[] = {"8r", "7r", "4d", "1d", "2l", "5u"};
const std::string MODE_5[] = {"6d", "5r", "4r", "7u", "8l", "4d"};

#endif