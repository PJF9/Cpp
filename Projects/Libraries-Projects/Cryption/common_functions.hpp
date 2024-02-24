#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sys/stat.h>
#include <dirent.h>


class Cryption_Functions {
    public:
        int pow(int base, int exponent);
        int abs(int n);

        int char_to_natural(const char &letter);
        char natural_to_char(int num);
        int to_int(std::string str);
        std::string to_string(int n);
        std::string to_binary(int num, int bitset=8);
        int from_binary(std::string bin_num);

        char check_path(std::string path);
        std::vector<std::string> get_directory_data(const char* path, bool dipslay_hidden=false);

};





int Cryption_Functions::pow(int base, int exponent) {
    if (exponent < 0) return 0;

    int result = 1;
    for (int i=0; i<exponent; i++) {
        result *= base;
    }

    return result;
}


int Cryption_Functions::abs(int n) {
    return (n < 0) ? (-1)*n : n;
}


int Cryption_Functions::char_to_natural(const char &letter) {
    switch (letter) {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}


char Cryption_Functions::natural_to_char(int num) {
    if (num == 1) return '1';
    else if (num == 2) return '2';
    else if (num == 3) return '3';
    else if (num == 4) return '4';
    else if (num == 5) return '5';
    else if (num == 6) return '6';
    else if (num == 7) return '7';
    else if (num == 8) return '8';
    else if (num == 9) return '9';
    else return '0';
}


int Cryption_Functions::to_int(std::string str) {
    bool is_neg = false;

    if (str[0] == '-') {
        is_neg = true;
        str = str.substr(1, str.length() - 1);
    }

    int num = 0;
    int zero_collector;

    for (int i=0; i<str.size(); i++) {
        zero_collector = 1;
        for (int j=0; j<str.size()-1-i; j++) {
            zero_collector *= 10;
        }
        num += this->char_to_natural(str[i]) * zero_collector;
    }

    return (is_neg) ? (-1) * num : num;
}


std::string Cryption_Functions::to_string(int n) {
    bool is_neg = false;

    if (n < 0) {
        is_neg = true;
        n *= (-1);
    }

    std::string s;

    while (n != 0) {
        s += this->natural_to_char(n % 10);
        n /= 10;
    }

    for (int i=0; i<s.length() / 2; i++) {
        char temp = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1 - i] = temp;
    }

    return (is_neg) ? "-" + s : s;
}


std::string Cryption_Functions::to_binary(int num, int bitset) {
    std::string bin_num;
    int original_size;
    char temp_reverser;

    while (num > 1) {
        bin_num += this->natural_to_char(num % 2);
        num /= 2;
    }
    bin_num += this->natural_to_char(num % 2);

    original_size = bin_num.size();
    for (int i=0; i<bitset-original_size; i++) {
        bin_num += '0';
    }

    for (int i=0; i<bin_num.size()/2; i++) {
        temp_reverser = bin_num[i];
        bin_num[i] = bin_num[bin_num.size() - i - 1];
        bin_num[bin_num.size() - i - 1] = temp_reverser;
    }

    return bin_num;
}


int Cryption_Functions::from_binary(std::string bin_num) {
    int num = 0;
    for (int i=0; i<bin_num.size(); i++) {
        num += (pow(2, i) * this->char_to_natural(bin_num[bin_num.size() - 1 - i]));
    }

    return num;
}


char Cryption_Functions::check_path(std::string path) {
    struct stat buffer;

    if (stat(path.c_str(), &buffer) == 0) {
        if (buffer.st_mode & S_IFDIR) {
            return 'D';
        }
        else if (buffer.st_mode & S_IFREG) {
            return 'F';
        }
        return 'E';
    }
    return 'X';
}


std::vector<std::string> Cryption_Functions::get_directory_data(const char* path, bool dipslay_hidden) {
    DIR *directory;                // The pointer that will open the the given directory.
    struct dirent *dir_reader;     // The pointer that will get all the data from the directory.
    std::vector<std::string> data;

    if (check_path(path) != 'X') {
        directory = opendir(path);
        dir_reader = readdir(directory);

        if (directory != nullptr && dir_reader != nullptr) {
            do {
                // Hidden files and folders condition.
                if ((!dipslay_hidden && dir_reader->d_name[0] != '.') || (dipslay_hidden)) {
                    data.push_back(dir_reader->d_name);
                }
                // Getting the next object of the directory.
                dir_reader = readdir(directory);

            } while (dir_reader != nullptr);

            closedir(directory);
        }
    }

    return data;
}

#endif
