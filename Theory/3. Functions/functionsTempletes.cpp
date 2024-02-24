#include <iostream>
#include <string>

// Function Templetes works like function overloading
// Its a more generic function definition

// T is the generaric name of the data type
// If the parameters are int then T will be int
template <typename T>

void swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 10;
    int y = 20;

    std::string a = "10";
    std::string b = "20";

    // Calling the templetized functions
    swap(x, y);
    swap(a, b);

    // Printing the resault
    std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
    std::cout << "a = " << a << "\t" << "b = " << b << std::endl;
}
