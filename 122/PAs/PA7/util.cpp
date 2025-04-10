#include "util.hpp"

void clearConsole() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
        
}

std::string getDate() {
    // get today's date
    time_t t = time(0);  // time now
    struct tm * now = localtime( &t );
    std::ostringstream oss = std::ostringstream();

    oss << (now->tm_mon + 1) << "-" << (now->tm_mday) << "-" << (now->tm_year + 1900);
    std::string date = oss.str();

    return date;
}