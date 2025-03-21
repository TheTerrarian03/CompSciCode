#include <iostream>

// without using a map
int charToID(char input) {
    if (input > 'a') {
        std::cout << "Converting from " << input;
        input -= 32;
        std::cout << " to " << input << std::endl;
    }
    
    if (input >= 'A' && input <= 'Z') {
        return input - 'A';  // range of alphabet to 0-25
    }

    if (input >= '0' && input <= '9') {
        return input - '0' + 26; // range of numbers to 26-35
    }

    if (input == '.') return 36;
    if (input == ',') return 37;
    if (input == '?') return 38;

    else return 420; // bad number
}

// also without using a map
char intIDToChar(int input) {
    if (input >= 0 && input <= 25) {
        return (char)input + 'A';
    }

    if (input >= 26 && input <= 35) {
        return (char)(input-26) + '0';
    }

    if (input == 36) return '.';
    if (input == 37) return ',';
    if (input == 38) return '?';

    if (input == 420) return ' ';  // bad number
}