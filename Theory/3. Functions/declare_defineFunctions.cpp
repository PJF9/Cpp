#include <iostream>

/**
 * Declare our function ( forword declaration )
 * We can also pass a name for the double and the int vairables or not
 * The this names called parameters
**/

double power(double, int);

int main() {
    // Declaire power variables variables
    double base;
    int exponent;

    // User input
    std::cout << "Give me base: ";
    std::cin >> base; // Initialize the base variables
    std::cout << "Give me the power: ";
    std::cin >> exponent; // Initialize the exponent variable

    // Call the power funtion
    // base and exponent are arguments
    std::cout << power(base, exponent) << std::endl;
}

// Define the power function
// base and exponent are parameters
double power(double base, int exponent) {
    // Decalre the reasult variable
    double resualt;
    // Initialize the variable
    resualt = 1;

    for(int i=0; i<exponent; i++) {
        resualt *= base;
    }
    // Return the output
    return resualt;
}