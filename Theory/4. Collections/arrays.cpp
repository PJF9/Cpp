#include <iostream>

int main() {
    // Creating the array
    // First we need to tell cpp what data type we want the array to store
    // By creating the array we need to place a [] at the end of the name
    // Now we can declaire the size of the array inside the []
    // If we dont declaire the size the array will have only the primary elements that we put inside at the start
    // Tp see the array we can't print it in the screen, we can only print each element
    // Indexes are the same as python

    int array1[] = {1,2,3,4};
    std::cout << array1[1] << std::endl;

    // Or 
    
    int array2[10];
    array2[0] = 100;
    std::cout << array2[0] << std::endl;


    int numbers[15] = {1,2,3,4,5,6,7,8,9,10};

    // To solve that
    int num_of_elements = 10;

    // Get the total size in bytes of the array
    int size_in_bytes = sizeof(numbers);

    // To calculate the size of array
    int size_of_array = sizeof(numbers) / sizeof(int);
    
    // Get each element of the array with zeroes
    for (int i = 0; i < size_of_array; i++) {
        std::cout << numbers[i] << std::endl; 
    }
     
    // Get each element of the array without zeroes
    for (int j = 0; j < num_of_elements; j++) {
        std::cout << numbers[j] << std::endl; 
    }
}
