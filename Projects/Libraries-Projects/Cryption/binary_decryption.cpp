#include <iostream>
#include <vector>
#include <string>
#include "common_functions.hpp"


namespace _hid {
    class Binary_Decryption {
        private:
            char reverse_alphabet(std::string encrypted_digit);
        public:
            std::vector<int> go(std::string encrypted_string);
    };
}





char _hid::Binary_Decryption::reverse_alphabet(std::string encrypted_digit) {
    if (encrypted_digit == "1111") return '0';
    else if (encrypted_digit == "0111") return '1';
    else if (encrypted_digit == "1011") return '2';
    else if (encrypted_digit == "0011") return '3';
    else if (encrypted_digit == "1101") return '4';
    else if (encrypted_digit == "0101") return '5';
    else if (encrypted_digit == "1001") return '6';
    else if (encrypted_digit == "0001") return '7';
    else if (encrypted_digit == "1110") return '8';
    else if (encrypted_digit == "0110") return '9';
    else if (encrypted_digit == "0000") return ' ';
    else return '_';
}



std::vector<int> _hid::Binary_Decryption::go(std::string encrypted_string) {
    std::vector<int> encrypted_ascii_digits;
    std::string temp;
    std::string temp2;

    for (int i=0; i<encrypted_string.size(); i++) {
        if (temp == "0000") {
            encrypted_ascii_digits.push_back(Cryption_Functions().to_int(temp2));
            temp2.clear();
            temp.clear();
        }
        else if ((i % 4 == 0) && (i != 0)) {
            temp2 += this->reverse_alphabet(temp);
            temp.clear();
        }
        temp += encrypted_string[i];
    }
    temp2 += this->reverse_alphabet(temp);
    encrypted_ascii_digits.push_back(Cryption_Functions().to_int(temp2));

    return encrypted_ascii_digits;
}
