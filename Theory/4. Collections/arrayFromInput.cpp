#include <iostream>
// Include package
#include <limits>

void arrayPrint(int array[], int size) {
    // Printing array
    for (int i=0; i<size; i++) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

int main() {
    const int SIZE = 100;
    int array_numbers[SIZE];

    int count = 0;

    for (int i=0; i<SIZE; i++) {
        // This way we can break if we inputed not int
        if (std::cin >> array_numbers[i]) {count++;} else {break;}
    }

    // Calling function
    arrayPrint(array_numbers, count);

    // Some nessesary thinks
    std::cin.clear();

    // By default the last element is still wating to be picked up
    // to solve this 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // or something like
    // std::cin.ignore(10000, '\n')

    // To be sure
    int test;
    std::cin >> test; 

    std::cout << test; 
}
