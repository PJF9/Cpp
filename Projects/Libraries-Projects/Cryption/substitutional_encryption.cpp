#include <iostream>
#include <vector>
#include <string>



namespace _hid {
    class Substitutional_Encryption {
        public:
            std::vector<int> go(std::string message, int encoder);
    };
}





std::vector<int> _hid::Substitutional_Encryption::go(std::string message, int encoder) {
    std::vector<int> ascii_digits_of_encrypted_string;
    int final_encoder;

    final_encoder = encoder + message.size();

    for (int i=0; i<message.size(); i++) {
        ascii_digits_of_encrypted_string.push_back((int) (message[i] + final_encoder));
    }

    return ascii_digits_of_encrypted_string;
}
