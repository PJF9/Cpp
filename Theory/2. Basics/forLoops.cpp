#include <iostream>

using namespace std;

int main() {
    // Creating the for loop    
    // First argument is the declaration and the starting value of the index
    // Second is the condition that allows the for loop to continue looping  
    // Third is the step 
    // Each argument is seperated with ;

    int nums[] = {3,6,9};

    for(int i=0; i<3; i++) {
        cout << nums[i] << endl;
    }

    // We have also the choice to use a for loop like Python
    for (int num: nums) {
        std::cout << num << " ";
    }
}
