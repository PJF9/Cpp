#include <iostream>

using namespace std;

int main() {
    // Creating the array
    int numsArray[3][2] = {
        {1,2},
        {4,5},
        {7,8}
    };

    // Begin the nested loop to print the array
    for(int rowIndex=0; rowIndex<3; rowIndex++) {
        for(int columnIndex=0; columnIndex<2; columnIndex++) {
            // Prints the one down the other
            //cout << numsArray[rowIndex][columnIndex] << endl;
            // Or
            cout << numsArray[rowIndex][columnIndex] << " ";
        }
        cout << endl;
    }   
    return 0;
}