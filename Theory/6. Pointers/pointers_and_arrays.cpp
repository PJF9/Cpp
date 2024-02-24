#include <iostream>

/**
 * We can also, except from ordenary variable, commit dynamic
 *  memory space for arrays
 * 
 * ? What is an array ?
 *  In a nutshell an array is a collection of data, data of the
 *  same data type. Its a sequencialy data structure, meanning
 *  that each element of the array is stored next to each other
 *  inside RAM.
 * 
 * ? How we can commit memory space dynamicly for arrays ?
 *  Fist we need to create the array pointer, a pointer that is
 *  going to point on the first element of the array.
 *
 *       data_type* pointer's_name = new data_type [size_of_array];
 * 
 *  'data_type' is the data type that we want the elements of the
 *  array to be and 'size_of_array' is the size that we want the
 *  array to have. 
 *  
 *  Because we create a pointer that is pointing on an array, after
 *  the work is done with the array we need to dismiss the memory
 *  that we have commited.
 * 
 *      delete [] pointer's_name; 
*/

/**
 * ? Can we implement a two dimention array using dynamic memory ?
 *  The answer is yes. First of all we need to understand what a
 *  2d array is. A 2d array is an array that each element is 
 *  actually an array. So in order to store a 2d array in heap
 *  we need to create a pointer that will show to the 2d array and
 *  then we have to create a new pointer array for each element of
 *  the array. After we have created succesfully our array and we
 *  end with the work we needed it for, its time to 'delete' the
 *  memory space of the array. First we need to delete each element
 *  array and finally the 2d pointer array.
 *  
 *      data_type** 2d_pointer's_name = new data_type* [rows];
 *      
 *      for (int i=0; i<rows; i++) {
 *             2d_pointer's_name[i] = new data_type [columns];
 *      }
 *      
 *      ...
 * 
 *      for (int i=0; i<rows; i++) {
 *          delete [] 2d_pointer's_name[i]; 
 *      }
 *      
 *      delete [] 2d_pointer's_name;
*/

int main() {

    //! Examples

    //* 1d array using dynamic memory commitment
    int* array = new int [9];

    if (array == nullptr) {std::cout << "Error Allocating Memory" << std::endl;}

    for (int i=0; i<9; i++) {
        array[i] = i*i;
    }

    /// Printing results
    for (int i=0; i<9; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;

    delete [] array;


    //* 2d array using dynamic memory commitment
    int rows = 5;
    int columns = 6;

    int** tow_d_array = new int* [rows];
    
    if (tow_d_array == nullptr) {std::cout << "Error Allocating Memory" << std::endl;}

    for (int i=0; i<rows; i++) {
        tow_d_array[i] = new int [columns];

        if (tow_d_array[i] == nullptr) {std::cout << "Error Allocating Memory" << std::endl;}
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            tow_d_array[i][j] = i+j;
        }
    }

    /// Printing results
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            std::cout << tow_d_array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i=0; i<rows; i++) {
        delete [] tow_d_array[i];
    }
    delete [] tow_d_array;
}   