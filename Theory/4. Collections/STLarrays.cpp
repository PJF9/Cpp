// Standar Library Templetize arrays
// Its the same as vectors with the defference that STL arrays are statick size
#include <iostream>
// The same as vectors, first we need to inlcude a package
#include <array>

// If we dont want to see the zeroes we put another parameter size and replace the array.size() with that
void print_array(std::array <int, 5> data) {
    for (int i=0; i<data.size(); i++) {
        std::cout << data[i] << "\t";
    }
}

int main() {
    // Creating the stl array
    // The second parameter is the size of the array
    std::array <int, 5> ages = {1,2,3,4};

    // We have access to the size of the array
    std::cout << ages.size() << std::endl;
    
    // Calling the array print function
    print_array(ages);
}
