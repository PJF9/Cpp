#include <iostream>
// Importing the math module for c++
#include <cmath>

using namespace std;

int main() {
    // The operation in this language is the same except:
    // -- For increment / decrement a number by 1 we can use number++ / number--
    // -- If the devision is between 2 intager the result will be int 

    // The power function:
    cout << pow(2,4) << endl;

    // The square root funtion:
    cout << sqrt(81) << endl;

    // The round function
    cout << round(8.2) << endl;

    // The round only upwords
    // If we pass 2.0 will round to 2
    cout << ceil(5.1) << endl;

    // The round only dackwords
    cout << floor(8.9) << endl;

    // The maximumn of 2 number 
    cout << fmax(10,3) << endl;

    // The minimum of 2 numbers 
    cout << fmin(10,3) << endl;

}

