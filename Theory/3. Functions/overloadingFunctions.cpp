#include <iostream>
#include <string>

// Overloading is a concept that function can have the same names only if they have defferent arguments

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap(std::string &a, std::string &b) {
    std::string temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    std::string a = "10";
    std::string b = "20";

    swap(x, y);
    swap(a, b);

    std::cout << x << "\t" << y << std::endl;
    std::cout << a << "\t" << b << std::endl;
}