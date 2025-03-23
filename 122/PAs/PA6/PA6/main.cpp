/*
- Name: Logan Meyers
- Date: 03/20/2025
- Assignment: PA6
- TA: Martin Hundrup

- Description: Convert english to morse code!

- Note: I usually would have liked to stick with the .hpp files only, but I was getting what seemed like
          7.3 gajillion linker errors for duplicate symbols, so after much tortue I gave up and
          put all the definitions in the c.cpp files. :(
*/

#include "MorseEnglishTranslater.hpp"

int main() {
    MorseEnglishTranslater translater;

    translater.run();
}
