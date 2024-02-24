#include <iostream>
#include <string>
#include <vector>
#include <cmath>



namespace _hid {
    class Rotate_Decryption {
        private:
            std::vector<std::vector<char>> __to_2d_matrix(std::string encrypted_string);
            std::vector<std::vector<char>> __rotate_vector(std::vector<std::vector<char>> encrypted_vector);
            std::string __to_decrypted_string(std::vector<std::vector<char>> rotated_vector);

        public:
            std::string go(const std::string encrypted_string);
    };
}





std::vector<std::vector<char>> _hid::Rotate_Decryption::__to_2d_matrix(std::string encrypted_string) {
    std::vector<std::vector<char>> encrypted_vector;
    std::vector<char> temp_v;
    int matrix_size;

    matrix_size = sqrt(encrypted_string.size());
    for (int i=0; i<encrypted_string.size(); i++) {
        if ((i % matrix_size == 0) && (i != 0)) {
            encrypted_vector.push_back(temp_v);
            temp_v.clear();
        }
        temp_v.push_back(encrypted_string[i]);
    }

    if (temp_v.size() != 0) {
        encrypted_vector.push_back(temp_v);
    }

    return encrypted_vector;
}



std::vector<std::vector<char>> _hid::Rotate_Decryption::__rotate_vector(std::vector<std::vector<char>> encrypted_vector) {
    std::vector<std::vector<char>> rotated_vector;

    rotated_vector = encrypted_vector;
    for (int i=0; i<rotated_vector.size(); i++) {
        for (int j=0; j<rotated_vector.size(); j++) {
            rotated_vector[encrypted_vector.size() - j - 1][i] = encrypted_vector[i][j];
        }
    }

    return rotated_vector;
}



std::string _hid::Rotate_Decryption::__to_decrypted_string(std::vector<std::vector<char>> rotated_vector) {
    std::string decrypted_string;

    for (int i=0; i<rotated_vector.size(); i++) {
        for (int j=0; j<rotated_vector.size(); j++) {
            if (rotated_vector[i][j] != ' ') {
                decrypted_string += rotated_vector[i][j];
            }
        }
        decrypted_string += ' ';
    }

    while (decrypted_string[decrypted_string.size() - 1] == ' ') {
        decrypted_string.pop_back();
    }

    return decrypted_string;
}



std::string _hid::Rotate_Decryption::go(const std::string encrypted_string) {
    return this->__to_decrypted_string(this->__rotate_vector(this->__to_2d_matrix(encrypted_string)));
}
