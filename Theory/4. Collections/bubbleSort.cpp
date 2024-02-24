#include <iostream>

int main() {
    // Create the array
    int array[] = {1,9,2,8,3,7,4,6,5};

    // Size of the array
    int size = sizeof(array) / sizeof(int);

    //Sorting the array
    for (int i=size; i>0; i--) {
        for (int j=size-1; j>0; j--) {

            if (array[j] < array[j-1]) {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
    // Printing the array
    for (int k=0; k<size; k++) {
        std::cout << array[k] << std::endl;
    }
    return 0;
}