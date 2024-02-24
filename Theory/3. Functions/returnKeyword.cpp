#include <iostream>

using namespace std;

// Creating a function
// First we need to declaire what data type will be the return value
int cube(double number) {
    // We can also return number * number * number 
    double result = number * number * number;
    return result;
    // Every code that is under the return keyword is considered unreachable code
}

int main() {
    // With return keyword we can store the value that returned in a varible
    double cubeResault = cube(9.4);
    cout << cubeResault << endl;
    return 0;
}

// Like return is continue but the different between those is that continue doesn't stop the loop
// it just go to the other iteration