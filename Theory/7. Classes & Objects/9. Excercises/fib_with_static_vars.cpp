#include <iostream>

// Create the fibonacci function
int fib(int n) {
    static int steps = 0;
    
    steps ++;
    std::cout << "Steps: " << steps <<std::endl;

    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return fib(n-1)+fib(n-2);
    }
}

int main() {
    std::cout << fib(15) << std::endl;
}