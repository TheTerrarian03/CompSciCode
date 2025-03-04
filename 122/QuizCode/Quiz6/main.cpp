#include "Queue.hpp"

int main() {
    Queue q = Queue();

    string word = "banana";

    std::cout << q.enqueue(word) << std::endl;
    std::cout << q.enqueue(word) << std::endl;
    std::cout << q.enqueue(word) << std::endl;
    std::cout << q.enqueue(word) << std::endl;
    std::cout << q.enqueue(word) << std::endl;
    std::cout << q.enqueue(word) << std::endl;
    std::cout << q.enqueue(word) << std::endl;
    std::cout << q.enqueue(word) << std::endl;

    return 0;
}