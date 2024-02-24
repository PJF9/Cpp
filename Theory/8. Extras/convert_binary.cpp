#include <iostream>
#include <string>


int char_to_int(const char &letter) {
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


int pow(const int base, const int exponent) {
    int num = 1;
    for (int i=0; i<exponent; i++) {
        num *= base;
    }

    return num;
}


std::string to_binary(int num, const int bitset=8) {
    std::string bin_num;
    char temp;
    int bin_nums_original_size;

    while (num > 1) {
        bin_num += std::to_string(num % 2);
        num /= 2;
    }
    bin_num += std::to_string(num % 2);

    if (bitset > bin_num.size()) {
        bin_nums_original_size = bin_num.size();
        for (int i=0; i<bitset-bin_nums_original_size; i++) {
            bin_num += '0';
        }
    }

    for (int i=0; i<bin_num.size()/2; i++) {
        temp = bin_num[i];
        bin_num[i] = bin_num[bin_num.size() - i - 1];
        bin_num[bin_num.size() - i - 1] = temp;
    }

    return bin_num;
}


int from_binary(std::string bin_num) {
    int num = 0;

    for (int i=0; i<bin_num.size(); i++) {
        num += (pow(2, i) * char_to_int(bin_num[bin_num.size() - 1 - i]));
    }

    return num;
}



int main() {
    std::cout << to_binary(126);
}