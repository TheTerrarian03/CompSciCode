#include "util.hpp"

void clearConsole() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
        
}