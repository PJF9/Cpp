#include <iostream>

// Declare our functions
double power(double, int);
void print_pow(double, int);

int main() {
    double base;
    int exponent;

    std::cout << "Give me base: ";
    std::cin >> base; 
    std::cout << "Give me the power: ";
    std::cin >> exponent;

    print_pow(base, exponent);
}


// Define our functions
double power(double base, int exponent) {
    double resualt;
    resualt = 1;

    for(int i=0; i<exponent; i++) {
        resualt *= base;
    }
    return resualt;
}


void print_pow(double base, int exponent) {
    std::cout << "The number " << base << " to the power of " << exponent << " is " << power(base, exponent) << "." << std::endl; 
}