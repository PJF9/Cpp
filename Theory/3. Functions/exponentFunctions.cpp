#include <iostream>

using namespace std;

// Creating the function to raise a number in whatever power
int power(int numToPower, int inThePower) {
    
    // Declairing the resault
    int resault = 1; 

    // For loop 
    for (int i=0; i<inThePower; i++) {
        resault *= numToPower;        
    }

    // Returning the value
    return resault;
}

// Main function
int main(){
    
    // Get the user input
    int num;
    int pow;
    cout << "Number: ";
    cin >> num;
    cout << "Pow: ";
    cin >>  pow;

    // Calling the power function
    cout << power(num, pow) << endl;
}