#include <iostream>

// Passing by refference
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;

    std::cout << "x = " << x << ", y = " << y << std::endl;
}

int main() {
    // if we dont pass the variables by referrende then the variables in the main funtion will not be affected
    int x = 10;
    int y = 20;

    swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
}