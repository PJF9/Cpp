#include <iostream>
#include <string>
#include <vector>



namespace _hid {
    class Rotate_Encryption {
        private:
            std::vector<std::vector<char>> __to_vector(std::string message);
            std::vector<std::vector<char>> __to_2d_matrix(std::vector<std::vector<char>> vectored_string);
            std::vector<std::vector<char>> __rotate_vector(std::vector<std::vector<char>> vectored_string);
            std::string __to_string(std::vector<std::vector<char>> rotated_vector);

        public:
            std::string go(std::string message);
    };
}





std::vector<std::vector<char>> _hid::Rotate_Encryption::__to_vector(std::string message) {
    std::vector<std::vector<char>> vectored_string;
    std::vector<std::vector<char>> v;
    std::vector<char> temp_adder;

    for (int i=0; i<message.size(); i++) {
        temp_adder.push_back(message[i]);
        if (message[i] == ' ') {
            temp_adder.pop_back();
            vectored_string.push_back(temp_adder);
            temp_adder.clear();
        }
    }
    if (temp_adder.size() != 0) vectored_string.push_back(temp_adder);

    vectored_string = this->__to_2d_matrix(vectored_string);

    return vectored_string;
}



std::vector<std::vector<char>> _hid::Rotate_Encryption::__to_2d_matrix(std::vector<std::vector<char>> vectored_string) {
    int max_column;
    int matrix_size;
    int prior_row_size;

    max_column = 0;
    for (int i=0; i<vectored_string.size(); i++) {
        if (vectored_string[i].size() > max_column) {
            max_column = vectored_string[i].size();
        }
    }

    matrix_size = (vectored_string.size() > max_column) ? vectored_string.size() : max_column;

    prior_row_size = vectored_string.size();
    for (int i=0; i<(matrix_size - prior_row_size); i++) {
        vectored_string.push_back(std::vector<char> ());
    }
    prior_row_size = vectored_string.size();
    for (int i=0; i<prior_row_size; i++) {
        for (int j=vectored_string[i].size(); j<matrix_size; j++) {
            vectored_string[i].push_back(' ');
        }
    }

    return vectored_string;
}



std::vector<std::vector<char>> _hid::Rotate_Encryption::__rotate_vector(std::vector<std::vector<char>> vectored_string) {
    std::vector<std::vector<char>> rotated_vector(vectored_string.size(), std::vector<char> (vectored_string.size(), ' '));

    for (int i=0; i<vectored_string.size(); i++) {
        for (int j=0; j<vectored_string.size(); j++) {
            rotated_vector[i][j] = vectored_string[vectored_string.size() - j - 1][i];
        }
    }

    return rotated_vector;
}



std::string _hid::Rotate_Encryption::__to_string(std::vector<std::vector<char>> rotated_vector) {
    std::string encrypted_message;

    for (int i=0; i<rotated_vector.size(); i++) {
        for (int j=0; j<rotated_vector.size(); j++) {
                encrypted_message += rotated_vector[i][j];
        }
    }

    return encrypted_message;
}



std::string _hid::Rotate_Encryption::go(std::string message) {
    return this->__to_string(this->__rotate_vector(this->__to_vector(message)));
}
