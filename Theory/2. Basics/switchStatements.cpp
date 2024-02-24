#include <iostream>

using namespace std;

string dayOfWeek(int number) {

    // Declairing the finall variable
    string nameDay;

    // Create the switch statement
    // It is like an if statement but more cleaner
    // number takes the place of case every time 
    // And break is used to break out the switch statement
    // If we forgot the break then the programm will go throught all cases
    // Instead of break we can use return 0
    // default is like the else keyword 
    // Switch statements use only integral data types
    

    switch (number) {
        case 0:
            nameDay = "Sunday";
            break;
        case 1:
            nameDay = "Monday";
            break;
        case 2:
            nameDay = "Tuesday";
            break;
        case 3:
            nameDay = "Wednesday";
            break;
        case 4:
            nameDay = "Thurday";
            break;
        case 5:
            nameDay = "Friday";
            break;
        case 6:
            nameDay = "Suturday";
            break;
        default:
            nameDay = "Invalid day index";

    return nameDay;
    }
}

int main() {
    // Get the user input
    int userNumber;
    cout << "Day index (0-6): ";
    cin >> userNumber;

    // Calling the function
    string dayName = dayOfWeek(userNumber);

    // Printing the resaults
    cout << userNumber << " index day is " << dayName << endl; 

}