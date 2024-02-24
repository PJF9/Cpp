#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "common_functions.hpp"


namespace _hid {
    class Image_Decryption {
        private:
            std::vector<std::string> __image_to_vector(std::string image_path);
            std::string __rotate_2digit_number(std::string number);
            std::string __swift_to_place(std::string image_lines, int decoder);
            std::vector<std::string> __swift_lines(std::vector<std::string> image_data, int decoder);

        public:
            std::vector<std::string> go(std::string image_path, int decoder);
    };
}





std::vector<std::string> _hid::Image_Decryption::__image_to_vector(std::string image_path) {
    std::ifstream read_file;
    std::string line;
    std::vector<std::string> v;

    read_file.open(image_path, std::ios::binary);
    if (!read_file.is_open()) return v;

    while (getline(read_file, line)) {
        v.push_back(line);
    }

    return v;
}


std::string _hid::Image_Decryption::__rotate_2digit_number(std::string number) {
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


std::string _hid::Image_Decryption::__swift_to_place(std::string image_line, int decoder) {
    std::string encrypted_line = image_line;

    for (int i=0; i<image_line.length(); i++) {
        encrypted_line[i] = image_line[(i + decoder) % image_line.length()];
    }

    return encrypted_line;
}


std::vector<std::string> _hid::Image_Decryption::__swift_lines(std::vector<std::string> image_data, int decoder) {
    std::vector<std::string> decrypted_vector = image_data;

    for (int i=0; i<image_data.size(); i++) {
        decrypted_vector[i] = image_data[(i + decoder) % image_data.size()];
    }

    return decrypted_vector;
}


std::vector<std::string> _hid::Image_Decryption::go(std::string image_path, int decoder) {
    std::vector<std::string> image_data;
    std::vector<std::string> decrypted_vector;
    
    image_data = this->__image_to_vector(image_path);

    for (int i=0; i<image_data.size(); i++) {
        for (int j=0; j<image_data[i].size(); j++) {
            image_data[i][j] = (char) Cryption_Functions().to_int(this->__rotate_2digit_number(Cryption_Functions().to_string((int) image_data[i][j])));
        }
    }

    for (int i=0; i<image_data.size(); i++) {
        image_data[i] = this->__swift_to_place(image_data[i], decoder);
    }

    decrypted_vector = this->__swift_lines(image_data, decoder);

    return decrypted_vector;
}
