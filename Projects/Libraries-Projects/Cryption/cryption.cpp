#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "common_functions.hpp"
#include "encoder_decode_key.cpp"
#include "rotate_encryption.cpp"
#include "rotate_decryption.cpp"
#include "substitutional_encryption.cpp"
#include "substitutional_decryption.cpp"
#include "binary_encryption.cpp"
#include "binary_decryption.cpp"
#include "image_encryption.cpp"
#include "image_decryption.cpp"




void print_image(std::string image_path, int total=0) {
    std::ifstream read_image(image_path, std::ios::binary);
    std::string line;

    if (total == 0) {
        while (getline(read_image, line)) {
            for (char c: line) {
                printf("%d ", (int) c);
            }
            printf("\n");
        }
    }
    else {
        int i = 0;
        while (getline(read_image, line)) {
            if (i == total) return;
            for (char c: line) {
                printf("%d ", (int) c);
            }
            printf("\n");
            i ++;
        }
    }
}


class Encrypt {
    private:
        int encoder;
        std::string decode_key;

    public:
        Encrypt();
        Encrypt(std::string user_key);

        int get_encoder() const;

        std::string encrypt_message(std::string message);
        bool enrypt_file(std::string file_path);
        bool encrypt_folder(std::string folder_name, bool encrypt_hidden=false);
        bool encrypt_directory(std::string dir_path, bool encrypt_hidden=false);
        
        bool encrypt_image(std::string image_path, int enocder);
};


class Decrypt {
    private:
        int decoder;

        int __update_decoder(std::string encrypted_message);

    public:
        Decrypt();

        int get_decoder() const;

        std::string decrypt_message(std::string encrypted_message);
        bool decrypt_file(std::string file_path);
        bool decrypt_folder(std::string folder_path, bool decrypt_hidden=false);
        bool decrypt_directory(std::string dir_path, bool decrypt_hidden=false);

        bool decrypt_image(std::string image_path, int decoder);
};





int main() {
    Encrypt e;
    Decrypt d;

    std::cout << e.encrypt_image("C:\\Users\\user\\Documents\\PJ\\Cryption\\t22.jpg", 45) << std::endl;
    std::cout << d.decrypt_image("C:\\Users\\user\\Documents\\PJ\\Cryption\\t22.jpg", 45) << std::endl;
    print_image("C:\\Users\\user\\Documents\\PJ\\Cryption\\t22.jpg");
}





Encrypt::Encrypt() {
    this->encoder = 45;
    this->decode_key = Cryption_Functions().to_binary(this->encoder);
}


Encrypt::Encrypt(std::string user_key) {
    _hid::__Encoder_Decode_Key edk;

    this->encoder = edk.create_encoder(user_key);
    this->decode_key = edk.create_decode_key();
}


int Encrypt::get_encoder() const {
    return this->encoder;
}


std::string Encrypt::encrypt_message(std::string message) {
    return Cryption_Functions().to_binary(this->decode_key.size(), 9) + this->decode_key + _hid::Binary_Encryption().go(_hid::Substitutional_Encryption().go(_hid::Rotate_Encryption().go(message), this->encoder));
}


bool Encrypt::enrypt_file(std::string file_path) {
    std::vector<std::string> encrypted_vector;
    std::ifstream given_file_r;
    std::ofstream given_file_w;
    std::string line;

    given_file_r.open(file_path);
    if (!given_file_r.is_open()) return false;

    while (getline(given_file_r, line)) {
        if (line != "") encrypted_vector.push_back(this->encrypt_message(line));
        else            encrypted_vector.push_back("");
    }

    given_file_r.close();
    system(std::string("del " + file_path).c_str());

    given_file_w.open(file_path, std::ios::app);
    if (!given_file_w.is_open()) return false;

    for (std::string encrypted_line : encrypted_vector) {
        given_file_w << encrypted_line << std::endl;
    }

    return true;
}


bool Encrypt::encrypt_folder(std::string folder_name, bool encrypt_hidden) {
    if (Cryption_Functions().check_path(folder_name) == 'X') return false;

    folder_name = (folder_name[folder_name.length() - 1] == '\\') ? folder_name : folder_name + "\\";

    std::vector<std::string> folder_data = Cryption_Functions().get_directory_data(folder_name.substr(0, folder_name.length() - 1).c_str(), encrypt_hidden);

    for (int i=0; i<folder_data.size(); i++) {
        if (Cryption_Functions().check_path(folder_name + folder_data[i]) == 'F') {
            this->enrypt_file(folder_name + folder_data[i]);
        }
    }

    return true;
}


bool Encrypt::encrypt_directory(std::string dir_path, bool encrypt_hidden) {
    if (Cryption_Functions().check_path(dir_path) == 'X') return false;

    dir_path = (dir_path[dir_path.length() - 1] == '\\') ? dir_path : dir_path + "\\";

    std::vector<std::string> dir_data = Cryption_Functions().get_directory_data(dir_path.substr(0, dir_path.length() - 1).c_str(), encrypt_hidden);

    for (int i=0; i<dir_data.size(); i++) {
        if (Cryption_Functions().check_path(dir_path + dir_data[i]) == 'F') {
            this->enrypt_file(dir_path + dir_data[i]);
        }
        else if (Cryption_Functions().check_path(dir_path + dir_data[i]) == 'D') {
            this->encrypt_directory(dir_path + dir_data[i]);
        }
    }

    return true;
}


bool Encrypt::encrypt_image(std::string image_path, int enocder) {
    if (Cryption_Functions().check_path(image_path) == 'X') return false;

    std::ofstream write_file;
    std::vector<std::string> encrypted_lines;

    encrypted_lines = _hid::Image_Encryption().go(image_path, encoder);
    if (encrypted_lines.size() == 0) return false;

    system(std::string("del " + image_path).c_str());

    write_file.open(image_path, std::ios::binary);
    if (!write_file.is_open()) return false;

    for (int i=0; i<encrypted_lines.size(); i++) {
        if (i != encrypted_lines.size() - 1) write_file << encrypted_lines[i] << std::endl;
        else                                 write_file << encrypted_lines[i];
    }

    return true;
}





Decrypt::Decrypt() {

}


int Decrypt::__update_decoder(std::string encrypted_message) {
    int decode_key_length = Cryption_Functions().from_binary(encrypted_message.substr(0, 9));
    this->decoder = Cryption_Functions().from_binary(encrypted_message.substr(9, decode_key_length));

    return decode_key_length;
}


int Decrypt::get_decoder() const {
    return this->decoder;
}


std::string Decrypt::decrypt_message(std::string encrypted_message) {
    int decode_key_length = this->__update_decoder(encrypted_message);

    encrypted_message = encrypted_message.substr(9 + decode_key_length, encrypted_message.size() - 9 - decode_key_length);

    return _hid::Rotate_Decryption().go(_hid::Substitutional_Decryption().go(_hid::Binary_Decryption().go(encrypted_message), this->decoder));
}


bool Decrypt::decrypt_file(std::string file_path) {
    std::vector<std::string> decrypted_vector;
    std::ifstream given_file_r;
    std::ofstream given_file_w;
    std::string line;

    given_file_r.open(file_path);
    if (!given_file_r.is_open()) return false;

    while (getline(given_file_r, line)) {
        if (line != "") decrypted_vector.push_back(this->decrypt_message(line));
        else            decrypted_vector.push_back("");
    }

    given_file_r.close();
    system(std::string("del " + file_path).c_str());

    given_file_w.open(file_path, std::ios::app);
    if (!given_file_w.is_open()) return false;

    for (std::string decrypted_line : decrypted_vector) {
        given_file_w << decrypted_line << std::endl;
    }

    return true;
}


bool Decrypt::decrypt_folder(std::string folder_name, bool decrypt_hidden) {
    if (Cryption_Functions().check_path(folder_name) == 'X') return false;

    folder_name = (folder_name[folder_name.length() - 1] == '\\') ? folder_name : folder_name + "\\";

    std::vector<std::string> folder_data = Cryption_Functions().get_directory_data(folder_name.substr(0, folder_name.length() - 1).c_str(), decrypt_hidden);

    for (int i=0; i<folder_data.size(); i++) {
        if (Cryption_Functions().check_path(folder_name + folder_data[i]) == 'F') {
            this->decrypt_file(folder_name + folder_data[i]);
        }
    }

    return true;
}


bool Decrypt::decrypt_directory(std::string dir_path, bool decrypt_hidden) {
    if (Cryption_Functions().check_path(dir_path) == 'X') return false;

    dir_path = (dir_path[dir_path.length() - 1] == '\\') ? dir_path : dir_path + "\\";

    std::vector<std::string> dir_data = Cryption_Functions().get_directory_data(dir_path.substr(0, dir_path.length() - 1).c_str(), decrypt_hidden);

    for (int i=0; i<dir_data.size(); i++) {
        if (Cryption_Functions().check_path(dir_path + dir_data[i]) == 'F') {
            this->decrypt_file(dir_path + dir_data[i]);
        }
        else if (Cryption_Functions().check_path(dir_path + dir_data[i]) == 'D') {
            this->decrypt_directory(dir_path + dir_data[i]);
        }
    }

    return true;
}


bool Decrypt::decrypt_image(std::string image_path, int decoder) {
    if (Cryption_Functions().check_path(image_path) == 'X') return false;

    std::ofstream write_file;
    std::vector<std::string> decrypted_lines;

    decrypted_lines = _hid::Image_Decryption().go(image_path, decoder);
    if (decrypted_lines.size() == 0) return false;

    system(std::string("del " + image_path).c_str());

    write_file.open(image_path, std::ios::binary);
    if (!write_file.is_open()) return false;

    for (int i=0; i<decrypted_lines.size(); i++) {
        if (i != decrypted_lines.size() - 1) write_file << decrypted_lines[i] << std::endl;
        else                                 write_file << decrypted_lines[i];
    }

    return true;
}
