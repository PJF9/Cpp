#include <iostream>
#include <vector>
#include <string>



namespace _hid {
    class Substitutional_Decryption {
        public:
            std::string go(std::vector<int> encrypted_ascii_digits, int decoder);
    };
}





std::string _hid::Substitutional_Decryption::go(std::vector<int> encrypted_ascii_digits, int decoder) {
    std::string decrypted_string;
    int final_decoder;

    final_decoder = encrypted_ascii_digits.size() + decoder;

    for (int i=0; i<encrypted_ascii_digits.size(); i++) {
        decrypted_string += (char) (encrypted_ascii_digits[i] - final_decoder);
    }

    return decrypted_string;
}
