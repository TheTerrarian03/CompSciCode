#pragma once

#include "Queue.hpp"
#include <cstdlib>  // for rand and time
#include <chrono>  // for more time stuff
#include <thread>  // for thread sleep
//#include <ctime>  // needed for some reason on windows (??)

class Simulation {

public:
    Simulation(): Simulation(true, false) {};  // call overloaded operator and set debug to a default 0
    Simulation(bool verbose, bool realtime) : nextExpress(0),
                                              nextNormal(0),
                                              nextCustomerID(1),
                                              servedCustomers(0),
                                              totalCustomers(0),
                                              maxExpressCustomers(0),
                                              maxNormalCustomers(0),
                                              enableVerbose(verbose),
                                              realtime(realtime) {
        express = Queue();
        normal = Queue();

        srand(time(0));
    };
    
    void runSimulation(int minutes);

private:
    Queue express,
          normal;
    int nextExpress,
        nextNormal,
        nextCustomerID,
        servedCustomers,
        totalCustomers,
        maxExpressCustomers,
        maxNormalCustomers;
    
    bool enableVerbose;
    bool realtime;
    
    void step_minute(int n);

    int randNextExpress() { return (rand() % 5) + 1; }
    int randNextNormal()  { return (rand() % 6) + 3; }
    int randExpressST()   { return (rand() % 5) + 1; }
    int randNormalST()    { return (rand() % 6) + 3; }

    void waitForNextSecond();
    void waitForNextMinute();
};

void Simulation::runSimulation(int minutes) {
    // gen first arrival times (step 1)
    nextExpress = randNextExpress();
    nextNormal = randNextNormal();
    
    // wait until next round minute if in realtime
    if (realtime) {
        std::cout << std::endl << "~ The store is waiting until the next minute to open..." << std::endl;
        waitForNextMinute();
    }

    for (int n=0; n < minutes; n++) {
        // cool clock or sumth'n
        int min = n % 60;
        std::cout << std::endl << "----- [ " << n / 60 << ":";
        if (min < 10) std::cout << "0";
        std::cout << min << " ] -----" << std::endl;

        step_minute(n);

        // wait if running in realtime
        if (realtime) waitForNextMinute();
    }

    std::cout << std::endl << "!! ----- SIMULATION FINISHED ----- !!" << std::endl;
    std::cout << std::endl << "> Served " << servedCustomers << " customers" << std::endl;
    std::cout << std::endl << "> Ran for " << minutes << " minutes" << std::endl;
    std::cout << std::endl << "> Finished with " << express.getLength() << " customer(s) left in express lane" << std::endl;
    std::cout << "  ......... and " << normal.getLength() << " customer(s) left in normal lane" << std::endl;
    std::cout << std::endl << "> Max line length (express): " << maxExpressCustomers << std::endl;
    std::cout << "  ............... (normal):  " << maxNormalCustomers << std::endl;

    if (maxExpressCustomers > 20 && maxNormalCustomers > 20) std::cout << std::endl << "* Don't go in EITHER lane! Wowza!" << std::endl;
    else {
        if ((maxExpressCustomers - maxNormalCustomers) > 10) std::cout << std::endl << "* Don't go in the express lane..... Yikes!" << std::endl;
        if ((maxNormalCustomers - maxExpressCustomers) > 10) std::cout << std::endl << "* Don't go in the normal lane..... Yikes!" << std::endl;
    }
}

void Simulation::step_minute(int n) {
    // reset next customer ID every 24h
    if ((n % (24*60) == 0) && n >= 0) nextCustomerID = 1;
    
    if (enableVerbose) {
        std::cout << "1. Next Express: " << nextExpress << "min" << std::endl;
        std::cout << "   Next Normal:  " << nextNormal << "min" << std::endl;
    }

    // decrement service times for people at the front of the lines
    express.decrementCurrentST();
    normal.decrementCurrentST();

    // dequeue and display message if the current reached zero service time
    if (express.isCurrentDone()) {
        Data cust = express.dequeue();
        
        if (enableVerbose) {
            std::cout << "3. Customer in express lane checked out:" << std::endl;
            std::cout << "   ID: " << cust.getCustomerNumber() << std::endl;
            std::cout << "   Total Time: " << cust.getTotalTime() << std::endl;
        } else {
            std::cout << "> Customer checked out from express lane! They waited "
                << cust.getTotalTime() << " minutes"
                << std::endl;
        }

        servedCustomers++;
    }
    if (normal.isCurrentDone()) {
        Data cust = normal.dequeue();
        
        if (enableVerbose) {
            std::cout << "3. Customer in normal lane checked out:" << std::endl;
            std::cout << "   ID: " << cust.getCustomerNumber() << std::endl;
            std::cout << "   Total Time: " << cust.getTotalTime() << std::endl;
        } else {
            std::cout << "> Customer checked out from normal lane! They waited "
                << cust.getTotalTime() << " minutes"
                << std::endl;
        }

        servedCustomers++;
    }

    // decrement next times for lines
    nextExpress--;
    nextNormal--;

    // increment total times for all current customers
    express.incrementAllTT();
    normal.incrementAllTT();

    // add next express and/or normal customers if time's up for that line
    if (nextExpress <= 0) {
        Data cust = Data(nextCustomerID++, randExpressST(), 0);
        
        if (enableVerbose) {
            std::cout << "2. [Express] Added customer with ID " << cust.getCustomerNumber()
                << ", and service time of " << cust.getServiceTime()
                << "min" << std::endl;
        } else {
            std::cout << "> Customer entered express lane!" << std::endl;
        }
        
        express.enqueue(cust);
        nextExpress = randNextExpress();
    }
    if (nextNormal <= 0) {
        Data cust = Data(nextCustomerID++, randNormalST(), 0);
        
        if (enableVerbose) {
            std::cout << "2. [Normal] Added customer with ID " << cust.getCustomerNumber()
                << ", and service time of " << cust.getServiceTime()
                << "min" << std::endl;
        } else {
            std::cout << "> Customer entered normal lane!" << std::endl;
        }

        normal.enqueue(cust);
        nextNormal = randNextNormal();
    }

    // show people in the lanes every 10 minutes,
    // or every minute if verbose is enable
    if (((n % 10 == 0) && n > 0) || enableVerbose) {
        std::cout << "Express Line: " << express << std::endl;
        std::cout << "Normal Line:  " << normal << std::endl;
    }

    // track max line len
    int expressLen = express.getLength();
    if (expressLen > maxExpressCustomers) maxExpressCustomers = expressLen;

    int normalLen = normal.getLength();
    if (normalLen > maxNormalCustomers) maxNormalCustomers = normalLen;
}

// had a little help with ChatGPT with this one.
// I haven't used time or chrono that much,
// with either c, c++, OR rust.
// You could say I'm a little... Rusty! haha.
void Simulation::waitForNextSecond() {
    // Get the current time
    auto now = std::chrono::system_clock::now();

    // Calculate the next second
    auto next_second = std::chrono::time_point_cast<std::chrono::seconds>(now) + std::chrono::seconds(1);

    // Sleep until the next second
    std::this_thread::sleep_until(next_second);
}

// I initially had the exact type definitions out,
// but to fix a whole bunch of issues Chat and I
// changed them to autos. It works!
// Windows is wacky.
void Simulation::waitForNextMinute() {
    // Get the current time
    auto now = std::chrono::system_clock::now();

    // Get the current time in seconds since epoch
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    tm* current_time = std::localtime(&now_time_t);

    // Calculate the time until the next minute
    int seconds_to_wait = 60 - current_time->tm_sec;

    // Sleep for the calculated time
    std::this_thread::sleep_for(std::chrono::seconds(seconds_to_wait));
}
