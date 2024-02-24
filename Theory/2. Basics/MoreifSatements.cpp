#include <iostream>

using namespace std;

// The comparison operators are the same as python
// The different is that we can also compare charachters 

// Creating the function for finding the max number
double findingMax(double num1, double num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}


// Creating a more complex function
double moreComplex(double num1, double num2, double num3) {
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    } else if (num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    }
}


int main() {
    // Get the number from the user
    double num1;
    cout << "First number: ";
    cin >> num1;

    double num2;
    cout << "Second number: ";
    cin >> num2;

    // Calling the fanction
    double resault = findingMax(num1, num2);
    cout << resault << endl;

    // Geting again the input from the user
    double num01;
    double num02;
    double num03;

    cout << "First: ";
    cin >> num01;
    cout << "Second: ";
    cin >> num02;
    cout << "Third: ";
    cin >> num03;

    double resault2 = moreComplex(num01, num02, num03);
    cout << resault2;

   return 0;
}