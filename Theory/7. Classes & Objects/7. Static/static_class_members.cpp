#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    ? What is a static class member ?
    Stattic class member is a class member that all the objects has access to
    ( normal class members are only accessable by the same object )
    A static class member is common for all th object of the class

    We can declare a static variable outside the class:
    Syntax: data_type class_name::var_name = var_value;

    Inside the class:
    Syntax: static data_type var_name = var_value;

    We can have access to this variable ( outside the class ):
    Suntax: class_name::var_name

    With static variables we are dispalying information about the class
*/

// Craete an orc class
class Orc {
    public:
        // Create the static class member
        static int alive_orcs;

        // Creating the constructor
        Orc() {
            alive_orcs ++;
        }
        // Creating the destructor
        ~Orc() {
            alive_orcs --;
        }
};

// Assinging the starting alive orcs
int Orc::alive_orcs = 0;


int main() {

    srand(time(0));

    // Creating a pointer array to face orc objects
    Orc *arr[5]; //* Max 5 Orcs

    // Asign the value NULL to all the pointers
    for (int i=0; i<5; i++) {
        arr[i] = NULL;
    }

    for (int i=0; i<=100; i++) { //* 50 is the total moves we want
        int pos = rand() % 5;

        if (arr[pos] == NULL) {
            // Dynamic memory commitment
            arr[pos] = new Orc;
            // Commitment condition
            if (!arr[pos]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
        } 
        else {
            // Delete the memory space
            delete arr[pos];
            // Null value
            arr[pos] = NULL;
        }

        // Print the total alive orcs every 10 loops
        if (i%10 == 0) {
            std::cout << "Step " << i << ": Alive Orcs = " << Orc::alive_orcs << std::endl;
        }
    }
    return 0;
}