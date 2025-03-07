#include <iostream>
#include "QueueNode.hpp"

int main() {
    Data *d = new Data(1, 2, 3);
    Data *e = new Data(*d);

    e->setTotalTime(10);
    
    // std::cout << *d << std::endl;
    // std::cout << *e << std::endl;

    QueueNode *qn = new QueueNode();
    QueueNode *qn2 = new QueueNode();
    qn->setData(*d);
    qn->setNext(qn2);
    qn2->setData(*e);

    std::cout << *qn << std::endl;
    std::cout << *qn2 << std::endl;

    // queue 1: express lane
    // queue 2: normal lane
    
    // gen random num for express and normal lane
        // express: 1-5 for arrival time
        // normal: 3-8 for arrival time
        
    
    // program main loop:

        // randomly generate arrival times and service times of customers into each lane


        // express lane gen: 1-5min
        // normal lane gen: 3-8min

        // express lane time: 1-5min
        // normal lane time: 3-8min

        // print as customers are enqueued into the line
            // arrival time
            // customer number
        
        // print as customers are checked out and dequeue line
            // which line
            // customer number
            // totalTime in the line
        
        // loop runs for n minutes, inputted by user

}