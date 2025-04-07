#include "Cipher.hpp"

class Caesar : public Cipher {
    string encode(string &msg) override;
    string decode(string &msg) override;
};