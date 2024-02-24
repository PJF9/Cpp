#include <iostream>
#include <cmath>

int main() {
    // Number types 
    std::cout << sqrt(25) << std::endl; // Returns a regular number
    std::cout << sqrt(-25) << std::endl; // Returns not a number
    std::cout << pow(9, 999) << std::endl; // Returns infinity
    std::cout << pow(-9, 999) << std::endl; // Returns -infinity

    // Remainder operation
    // % dont work with doubles but remainder does
    std::cout << remainder(10, 3.25) << std::endl; // Or 10 % 3 or fmod(10, 3.25)
}