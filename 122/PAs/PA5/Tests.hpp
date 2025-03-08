#pragma once

#include "Data.hpp"
#include "QueueNode.hpp"
#include "Queue.hpp"
#include "Simulation.hpp"

bool testEmptyGet() {
    Queue q = Queue();

    Data res = q.getHeadData();
    Data def = Data();


    if (res == def) {
        std::cout << "TEST EMPTY GET     - SUCCESS - Queue returned default Data" << std::endl;
        return true;
    }

    std::cout << "TEST EMPTY GET     - FAIL    - Queue didn't return default Data" << std::endl;
    return false;
}

bool testOneGet() {
    Queue q = Queue();

    Data d = Data(1, 3, 5);

    q.enqueue(d);

    Data res = q.getHeadData();
    Data def = Data();

    if (res == d) {
        std::cout << "TEST ONE GET     - SUCCESS - Queue returned the right Data" << std::endl;
        return true;
    } else if (res == def) {
        std::cout << "TEST ONE GET     - FAIL    - Queue returned the default Data" << std::endl;
    } else {
        std::cout << "TEST ONE GET     - FAIL    - Queue somehow returned neither the right data nor the default Data" << std::endl;
    }

    return false;
}

// enqueue on empty
bool testEnqueueEmpty() {
    Queue q = Queue();

    Data d = Data(1, 2, 3);

    q.enqueue(d);

    if (q.isEmpty()) {
        std::cout << "TEST ENQUEUE EMPTY - FAIL    - Queue is empty after enqueue call" << std::endl;
        return false;
    }

    Data res = q.getHeadData();

    if (res == d) {
            std::cout << "TEST ENQUEUE EMPTY - SUCCESS - Data was inserted correctly" << std::endl;
            return true;
    } else {
        std::cout << "TEST ENQUEUE EMPTY - FAIL    - Data was not inserted correctly; attributes off" << std::endl;
    }

    return false;
}

// enqueue with one node
bool testEnqueueOne() {
    Queue q = Queue();

    Data d = Data(1, 2, 3);
    Data d2 = Data(4, 5, 6);

    q.enqueue(d);

    if (q.isEmpty()) {
        std::cout << "TEST ENQUEUE ONE   - FAIL    - Queue is empty after first enqueue call" << std::endl;
        return false;
    }

    q.enqueue(d2);

    if (q.isEmpty()) {
        std::cout << "TEST ENQUEUE ONE   - FAIL    - Queue is somehow empty after second enqueue call" << std::endl;
        return false;
    }

    Data res = q.dequeue();
    Data res2 = q.getHeadData();

    Data def = Data();

    if (res == def || res2 == def) {
        std::cout << "TEST ENQUEUE ONE   - FAIL    - One or more Datas weren't inserted correctly" << std::endl;
        return false;
    }

    if (res == d && res2 == d2) {
            std::cout << "TEST ENQUEUE ONE   - SUCCESS - Both Datas were inserted correctly" << std::endl;
            return true;
    } else {
        std::cout << "TEST ENQUEUE ONE   - FAIL - Data was not inserted correctly; attributes off" << std::endl;
    }

    return false;
}

// dequeue on one node queue
bool testDequeueEmpty() {
    Queue q = Queue();

    Data d = Data(1, 2, 3);

    q.enqueue(d);

    if (q.isEmpty()) {
        std::cout << "TEST DEQUEUE EMPTY - FAIL    - Queue is empty after enqueue call" << std::endl;
        return false;
    }

    Data res = q.dequeue();

    if (res == d) {
            std::cout << "TEST DEQUEUE EMPTY - SUCCESS - Data was inserted correctly" << std::endl;
            return true;
    } else {
        std::cout << "TEST DEQUEUE EMPTY - FAIL    - Data was not inserted correctly; attributes off" << std::endl;
    }

    return false;
}

// dequeue on two node queue
bool testDequeueOne() {
    Queue q = Queue();

    Data d = Data(1, 2, 3);
    Data d2 = Data(4, 2, 0);

    q.enqueue(d);

    if (q.isEmpty()) {
        std::cout << "TEST DEQUEUE EMPTY - FAIL    - Queue is empty after enqueue call" << std::endl;
        return false;
    }

    q.enqueue(d2);

    if (q.isEmpty()) {
        std::cout << "TEST DEQUEUE ONE   - FAIL    - Queue is somehow empty after second enqueue call" << std::endl;
        return false;
    }

    Data res = q.dequeue();
    Data res2 = q.dequeue();
    Data def = Data();

    if (res == d && res2 == d2) {
        std::cout << "TEST DEQUEUE ONE   - SUCCESS - Queue returned both Datas correctly" << std::endl;
        return true;
    } else if ((res == d && res2 == def) || (res == def && res2 == d2)) {
        std::cout << "TEST DEQUEUE ONE   - FAIL     - Queue returned one Data correctly but not the other" << std::endl;
    } else {
        std::cout << "TEST DEQUEUE ONE   - FAIL    - Queue returned not Datas correctly" << std::endl;
    }

    return false;
}

// test sim for 24h (1440min)
void testSim24H() {
    Simulation sim = Simulation(false, true);

    sim.runSimulation(24*60);
}

void testMost() {
    testEmptyGet();
    testEnqueueEmpty();
    testDequeueEmpty();
    testEnqueueOne();
    testDequeueOne();
}
