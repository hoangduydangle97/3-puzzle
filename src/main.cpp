#include <iostream>
#include <time.h>
#include "../include/User.h"

int main() {
    // using for random
    srand((int)time(0));

    User *user = new User();
    user->process();
    delete user;
    user = nullptr;

    // consider the OS is Windows, pause the screen
    #ifdef _WIN32
        std::cout << "Press any keys to exit...";
        std::cin.get();
    #endif
    
    return 0;
}