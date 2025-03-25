#include "TestStack.hpp"
#include <sstream>
#include <cctype>
#include <math.h>  // for infinity

class Postfix {

private:
    static int malformMsg(string reason);
    static bool isOperator(char c);
    static bool isParen(char c);

public:
    Postfix() = delete;  // static class

    static int solve(string expression);

    static string convert(string expression);
};

int Postfix::malformMsg(string reason) {
    std::cerr << "Malformed expression! Reason: " << reason << endl;
    return -INFINITY;
}

bool Postfix::isOperator(char c) {
    return (c == '-' ||
        c == '+' ||
        c == '*' ||
        c == '/');
}
bool Postfix::isParen(char c) {
    return (c == '(' ||
            c == ')');
}

int Postfix::solve(string postfixExpression) {
    // 0. convert expression to string stream to read from
    std::stringstream expr(postfixExpression);
    
    // 1. create int stack
    Stack<int> s;

    // 2. no character to read, malformed
    if (expr.peek() == -1) return malformMsg("Empty expression.");
    
    // step 2 loop
    while (expr.peek() != -1) {
        // 3.
        char c;
        expr >> c;

        // 4. '='
        if (c == '=') {
            if (s.isEmpty()) return malformMsg("Calling = assignment on empty expression");

            if (s.size() > 1) return malformMsg("Too many items to call = assignment on.");

            // condition implied by previous
            if (s.size() == 1) {
                int e;
                s.pop(e);
                return e;
            }
        }

        // 5. digit
        if (isdigit(c)) {
            int newNum = c - '0';
            s.push(newNum);
        }

        // 6. binary operator
        if (isOperator(c)) {

            if (s.size() < 2) return malformMsg("Not enough elements to perform operation.");

            int s2, s1;

            s.pop(s2);
            s.pop(s1);

            switch (c) {
                case '-': {
                    int v = s1 - s2;
                    s.push(v);
                    break;
                }
                case '+': {
                    int v = s1 + s2;
                    s.push(v);
                    break;
                }
                case '*': {
                    int v = s1 * s2;
                    s.push(v);
                    break;
                }
                case '/': {
                    int v = s1 / s2;
                    s.push(v);
                    break;
                }
            }
        }

        // cout << "Stack is now: ";
        // s.print();
        // cout << endl;
    }

    // default, no equals found to return value
    return malformMsg("You forgot your equal sign!");
}

string Postfix::convert(string infixExpression) {
    // convert given expression to string stream
    std::stringstream expr(infixExpression);

    // 0. make char stack and output postfix string
    Stack<char> s;
    std::stringstream postfixString;

    // 1. scan loop
    while (expr.peek() != -1) {
        // 2. operand, push to postfix string immediately
        if (isdigit(expr.peek())) {
            // postfixString << expr;
        }

        // 3. operator, 
    }
}