#include <iostream>
#include <vector>
#include <string>
#include "common_functions.hpp"


namespace _hid {
    class Binary_Encryption {
        private:
            std::vector<std::string> alphabet = {
                "1111",
                "0111",
                "1011",
                "0011",
                "1101",
                "0101",
                "1001",
                "0001",
                "1110",
                "0110",
                "0000"
            };

        public:
            std::string go(std::vector<int> encrypted_ascii_digits);
    };
}





std::string _hid::Binary_Encryption::go(std::vector<int> encrypted_ascii_digits) {
    std::string encrypted_string;
    std::string digit_string;
    std::string temp;
    
    for (int i=0; i<encrypted_ascii_digits.size(); i++) {

        digit_string = Cryption_Functions().to_string(encrypted_ascii_digits[i]);
        for (int j=0; j<digit_string.length(); j++) {
            temp += this->alphabet[Cryption_Functions().char_to_natural(digit_string[j])];
        }
        if (i != encrypted_ascii_digits.size() - 1) {
            temp += this->alphabet[this->alphabet.size() - 1];
        }

        encrypted_string += temp;
        temp.clear();
    }

    return encrypted_string;
}
