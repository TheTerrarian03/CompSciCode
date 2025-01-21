#include "lab2.h"

int main() {
    Contact data = {.name = "Logan", .email = "urmom@myhouse.com", .phone="5095095095", .title="super awesome"};
    Contact data2 = {.name = "Zach", .email = "yahoo@mail.com", .phone="1231231234", .title="crazy kat"};
    Contact data3 = {.name = "Bob", .email = "yahoo@mail.com", .phone="1231231234", .title="crazy kat"};
    Node *node = makeNode(data);

    // insertContactInOrder(&node, data2);
    // insertContactInOrder(&node, data3);
    insertAtFront(&node, data2);
    insertAtFront(&node, data3);

    printList(node);

    printf("--------\n\n");

    deleteContact(&node, data2);

    printList(node);

}

// dont necessarily need to test edit and print