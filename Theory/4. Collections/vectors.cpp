#include <iostream>
// To use vectors we need to include a package
#include <vector>

int main() {
    // Declaring a vector
    std::vector <int> numbers;
    // Adding elements to the vector
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);

    // Print an element
    std::cout << numbers[0] << std::endl;
    // Show the size of the vector
    std::cout << numbers.size() << std::endl;
    // Print the last element of the vector
    std::cout << numbers[numbers.size() - 1] << std::endl;

    // Remove the last element of the vector
    numbers.pop_back();
    std::cout << numbers.size() << std::endl;

    // Getting the first element
    std::cout << numbers.front() << std::endl;
    // Getting the last elemetn
    std::cout << numbers.back() << std::endl;
    
}