#include <iostream>

using namespace std;

// Creating a new function
// First we need to write void if the function doesn't return anything
// To see the output we need to call the function into the main funct.
// We can also pass as many arguments we want, but first declairing each data type

void sayHi() {
    cout << "Hi User" << endl;
}

void sayHallo(string name, int age) {
    cout << "Hallo " << name << " , you are " << age << " years old" << endl;
}

// If we want to place the function down the main, we need ti declaire it first
void Hallo();

int main() {
    // Calling the sayHi function
    sayHi();
    // Calling the sayHallo function
    sayHallo("Petros", 17);

    // We can do something more complex
    // Get the name of the user
    string userName;
    cout << "Please, give me your name: ";
    getline(cin, userName);

    // Get the age of the user
    int userAge;
    cout << "Now, give me your age: ";
    cin >> userAge;

    // Call the sayHallo function
    sayHallo(userName, userAge);

    // Call Hallo function
    Hallo(); 

    return 0;
}

// Give value to the Hallo function
void Hallo() {
    cout << "Hallo" << endl;
}