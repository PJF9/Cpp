#include <iostream>

using namespace std;

int main() {
    // The most used data types in C++

    // Storing in a variable a charachter of length 1
    // With char data type we use ' '
    char letter = 'A';

    // Storing in a variable a sequence of charecters
    // With string data type we use " "
    string name = "Petros";

    // Storing a intager number in a variable
    int grade = 18;

    // Storing a float number in a variable
    float number = 3.14;
    double float_number = 3.141592;
    // With double we can store * 2 more digits after the comma

    // Sort a boolean value in a variable
    bool isMale = true; 
    // Whatever we put  except 0 will output 1
    // 0 = false
    // 1 = true 
    // If we want to output true/false instead 0/1
    cout << boolalpha << isMale << endl;
}