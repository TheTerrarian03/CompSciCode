#include "Queue.hpp"
#include "test.hpp"
#include <string>

int main() {

    Queue q_int = Queue<int>();
    Queue q_str = Queue<string>();

    for (int i=0; i < 10; i++) {
        q_int.enqueue(i);
        string word = "Hello #" + std::to_string(i);
        q_str.enqueue(word);
    }

    q_int.print();
    q_str.print();

    while (!q_int.isEmpty()) {
        std::cout << "Dequeued: " << q_int.dequeue() << std::endl;
        std::cout << "Dequeued: " << q_str.dequeue() << std::endl;
    }

    std::cout << "----- Testing below -----" << std::endl << std::endl;

    testString();
    testInt();
    // testDouble();
    // testUser();

    return 0;
}