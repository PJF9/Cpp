#include <iostream>

using namespace std;

int main() {
    // Creating the if statements
    // The AND operator is &&
    // The OR operator is ||
    // The NOT operator is !
    // elif statement is else if

    // The main form of the if statement is:
    // if (condition) {expression} else {expresion}

    // If we put return -1 at the end of our code then the programm is going to end

    // Declairing the main variables
    bool isMale = true;
    bool isTall = true;

    if (isMale && isTall) {
        cout << "You are both male and tall";
    } else if (isMale && !isTall) {
        cout << "You are male but not tall";
    } else if (!isMale && isTall) {
        cout << "You are tall but not male";
    } else {
        cout << "You are neither tall nor male";
    }
}