#include <iostream>


int main() {
    // We are using chars to store small numbers or character(letters) 
    // Character is 4 bits data type

    char x = 'b';
    // We can intepret the x as an int
    // std::cout << (int) x << std::endl;
    // The character to int is based of the asci table

    // We can store int to chars
    char y = 65;
    std::cout << (int) y << std::endl;

    // The maximum number is char
    char c = 127;
    std::cout << (int) c << std::endl; 

    // If we will input any number after 127 the the console will output:
    // It will start from the -127 and 129 --> -126 
    char b = 129;
    std::cout << (int) b << std::endl;
    // Output to the console the asci equivelant of 129
    std::cout << (char) b << std::endl;

    // But we can store until 255 
    // If we will input any number after 255 then the output will be 255
    unsigned char v = 255;
    std::cout << (int) v << std::endl;

}   