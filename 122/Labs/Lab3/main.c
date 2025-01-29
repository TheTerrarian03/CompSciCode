#include "lab3.h"

int main() {
    Contact data = {.name = "Logan", .email = "urmom@myhouse.com", .phone="5095095095", .title="super awesome"};
    Contact data2 = {.name = "Zach", .email = "yahoo@mail.com", .phone="1231231234", .title="crazy kat"};
    Contact data3 = {.name = "Bob", .email = "yahoo@mail.com", .phone="1231231234", .title="crazy kat"};
    Contact data4 = {.name = "Martin", .email = "MartinFactorial@lab.com", .phone="5099056364", .title="best ta"};
    Contact data5 = {.name = "Fred", .email = "MartinFactorial@lab.com", .phone="5099056364", .title="best ta"};
    // Node *node = makeNode(data);
    Node *node = NULL;

    // insertAtFront(&node, data2);
    // insertAtFront(&node, data3);
    // insertAtFront(&node, data4);

    // insertAtBack(&node, data);
    // insertAtBack(&node, data2);
    // insertAtBack(&node, data3);
    // insertAtBack(&node, data4);

    insertContactInOrder(&node, data2);  // zach at empty
    insertContactInOrder(&node, data3);  // bob at front
    insertContactInOrder(&node, data);   // logan in middle
    insertContactInOrder(&node, data4);  // martin after logan in middle
    insertContactInOrder(&node, data5);  // fred before logan in middle

    printList(node);
}

// dont necessarily need to test edit and print