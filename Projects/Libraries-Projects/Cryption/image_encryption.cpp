#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "common_functions.hpp"


namespace _hid {
    class Image_Encryption {
        private:
            std::string __rotate_2digit_number(std::string number);
            std::string __swift_to_place(std::string image_line, int encoder);
            std::vector<std::string> __swift_lines(std::string image_path, int encoder);

        public:
            std::vector<std::string> go(std::string image_path, int encoder);
    };
}




std::string _hid::Image_Encryption::__rotate_2digit_number(std::string number) {
    bool is_neg = false;
    if (number[0] == '-') {
        is_neg = true;
        number = number.substr(1, number.length() - 1);
    }

    if ((number.length() == 2) || (number.length() == 1)) {
        if (number.length() == 1) {
            number = '0' + number;
        }

        char temp;
        for (int i=0; i<number.length() / 2; i++) {
            temp = number[i];
            number[i] = number[number.length() - 1 - i];
            number[number.length() - 1 - i] = temp;
        }
    }

    return (is_neg) ? '-' + number : number;
}


std::string _hid::Image_Encryption::__swift_to_place(std::string image_line, int encoder) {
    std::string encrypted_line = image_line;

    for (int i=0; i<image_line.length(); i++) {
        encrypted_line[(i + encoder) % image_line.length()] = image_line[i];
    }

    return encrypted_line;
}


std::vector<std::string> _hid::Image_Encryption::__swift_lines(std::string image_path, int encoder) {
    std::ifstream read_file; 
    std::vector<std::string> temp_vector;
    std::vector<std::string> encrypted_lines;
    std::string line;

    read_file.open(image_path, std::ios::binary);
    if (!read_file.is_open()) return temp_vector;

    while (getline(read_file, line)) {
        temp_vector.push_back(line);
    }

    encrypted_lines = temp_vector;
    for (int i=0; i<temp_vector.size(); i++) {
        encrypted_lines[(i + encoder) % temp_vector.size()] = temp_vector[i];
    }

    return encrypted_lines;
}


std::vector<std::string> _hid::Image_Encryption::go(std::string image_path, int encoder) {
    std::vector<std::string> encrypted_lines;

    encrypted_lines = this->__swift_lines(image_path, encoder);

    for (int i=0; i<encrypted_lines.size(); i++) {
        encrypted_lines[i] = this->__swift_to_place(encrypted_lines[i], encoder);
    }

    for (int i=0; i<encrypted_lines.size(); i++) {
        for (int j=0; j<encrypted_lines[i].size(); j++) {
            encrypted_lines[i][j] = (char) Cryption_Functions().to_int(this->__rotate_2digit_number(Cryption_Functions().to_string((int) encrypted_lines[i][j])));
        }
    }

    return encrypted_lines;
}
