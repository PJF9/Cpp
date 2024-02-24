#include <iostream>
#include <vector>

int main() {
    // Greating the 2d array
    int array[3][3] = {
        {1,2,3},
        {3,5,6},
        {7,8,9}
    };

    // Printing the array
    // The variable i runs for every row 
    // The variable j runs for every element in a row
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }  

    // New line
    std::cout << std::endl;

    // We can works also with vectors
    // Creating the 2d vector
    std::vector <std::vector <int>> vector = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    // Printing the vector
    for (int p=0; p<vector.size(); p++) {
        for (int k=0; k<vector.size(); k++) {
            std::cout << vector[p][k] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}