#include <iostream>
// This file tell us how many digits we should trust
#include <float.h>

int main() {
    // Float numbers
    float a = 3.14f; // To decalre a float number we need to pass the f at the end of the number
    double b = 77E4; // = 7.7 x 10^4
    long double c;

    // Floats are 4 bytes large and doubles are 8 bytes large

    std::cout << FLT_DIG << std::endl;
    std::cout << DBL_DIG << std::endl; 
    std::cout << LDBL_DIG << std::endl;
}