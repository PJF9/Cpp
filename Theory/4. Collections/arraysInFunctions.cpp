#include <iostream>

// First parameter is the array and secont is the size of the array we using

void arrayPrint(int array[], int size) {
    // Try to see the size off aray
    std::cout << sizeof(array) << std::endl;
    std::cout << size << std::endl;

    // Printing array
    for (int i=0; i<size; i++) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

int main() {
    int array_of_numbers[] = {1,2,3,4,5,6,7,8,9};
    std::cout << sizeof(array_of_numbers) << std::endl; 

    // Size of array
    int size = sizeof(array_of_numbers) / sizeof(int);

    // Calling the function
    arrayPrint(array_of_numbers, size);
}