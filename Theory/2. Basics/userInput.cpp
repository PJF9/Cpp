#include <iostream>

using namespace std;

int main() {
    // Creating a variable to store the input that user give us
    // We can take every data type as input from the user except string

    // Getting the name of a user
    string name;
    cout << "Now, give me your name: ";
    getline(cin, name);


    double age;
    // Creating the input text
    cout << "Please give me your age: ";
    // Getting the input and storing it to the age variable
    cin >> age;

    
    // If worked:
    cout << "So, your name is " << name << " and you are " << age << " yaers old" << endl;

    return 0;

}