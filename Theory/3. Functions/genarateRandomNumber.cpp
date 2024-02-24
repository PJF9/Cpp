#include <iostream>
// Include pakcages 
#include <cstdlib>
#include <ctime>

// This method will give us a number from 0 to whatever we need

int main() {
    // This method in going to give us the same resaults
    int randomNum1 = rand() % 251;

    // To fix that
    srand(time(NULL));
    int randomNum2 = rand() % 11;

    std::cout <<  randomNum1 << " " << randomNum2 << std::endl; 
}