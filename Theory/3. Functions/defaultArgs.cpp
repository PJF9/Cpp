#include <iostream>
                
// Default arguments works the same as python

int pow(int base, int power=1) {
    int total = 1;

    for (int i=0; i<power; i++) {
        total *= base;
    }
    return total;
}

int main() {
    int total = pow(2,3);
    std::cout << total << std::endl;
}