#include <iostream>

// Structs are the same are classes 
// They be used in low scale programms
// By default all the things inside the struct is public
// Structs commonly used only to store data, NOT methods

struct User{
    std::string first_name;
    std::string last_name;
    int age;
};

int main() {
    // Creating the struct object
    User user; 
    // Assinging value to the stuct variables
    user.first_name = "Petros";
    user.last_name = "Floratos";
    user.age = 17;

    // Printing the struct
    std::cout << "First name: " << user.first_name << std::endl;
    std::cout << "Last name: " << user.last_name << std::endl;
    std::cout << "Age: " << user.age << std::endl;
}