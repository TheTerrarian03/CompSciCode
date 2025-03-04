#include "Queue.hpp"
#include "User.hpp"

void testString() {
    Queue q = Queue<string>();

    string words[4] = {"Hello, ", "world!", "I'm here for", " Miku!"};

    for (int i=0; i < 4; i++) {
        q.enqueue(words[i]);
    }

    q.print();
}

void testInt() {
    Queue q = Queue<int>();

    int nums[4] = {1, 2, 3, 4};

    for (int i=0; i < 4; i++) {
        q.enqueue(nums[i]);
    }

    q.print();
}

void testDouble() {
    Queue q = Queue<float>();

    float nums[4] = {1.1, 2.8, 3.3423, 6.9};

    for (int i=0; i < 4; i++) {
        q.enqueue(nums[i]);
    }

    q.print();
}

// void testUser() {
//     Queue q = Queue<User>();

//     User users[4];

//     users[0] = User("Logan", "1234", 1);
//     users[1] = User("Jayren", "8976", 2);
//     users[2] = User("Martin", "password1", 3);
//     users[3] = User("HelloKitty", "UnicornsR_Real", 4);

//     for (int i=0; i < 4; i++) {
//         q.enqueue(users[i]);
//     }

//     q.print();
// }