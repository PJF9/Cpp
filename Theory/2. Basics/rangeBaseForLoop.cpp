#include <iostream>

int main() {
    int array[] = {1,2,3,4,5,6,7};
    // This method work also for SLT arrays and vectors
    // First decaliring the datatype of the array
    // Then we declare a new variable that will store each element of the list
    // Final we have to refference from what collention will take each element
    for (int element:array) {
        std::cout << element << std::endl;
    }
    // But this method is useless for arrays in other functions
    // Because these arrays forget their size
}