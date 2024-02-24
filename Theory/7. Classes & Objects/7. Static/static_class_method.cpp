#include <iostream>

/*
    ? What is a static class method ? 
    A static class method is a method that is common for all the object of the class

    Syntax: static data_type funct_name(...);

    The body is usually declared outside the class

    We can call this method outside the class:
    Syntax: class_name::funct_name(...);

    The static methods have only access to the static class members, not the normal one
    Also this method has no access to the this pointer
*/

// Create the orc class
class Orc {
    public:
        // Creating the static variables
        static int alive_orcs;
        static bool frenzy_mode;
        
        // Creating the static method
        static void toggle_frenzy_mode() {
            if (frenzy_mode) {
                frenzy_mode == false;
            } else {
                frenzy_mode = true;
            }
        };

        // Creating the constructor
        Orc() {
            alive_orcs ++;
        }        
        // Creating the destructor
        ~Orc() {
            alive_orcs --;
        }

        // Overloading th << operator
        friend std::ostream &operator<<(std::ostream &left, Orc &ob) {
            if (Orc::frenzy_mode) { //* We need the Ord:: becasue this is a frienfly function
                std::cout << "AAAAHHGAAHGA" << std::endl;
            } else {
                std::cout << "ougba" << std::endl;
            }
        }
};

// Assinging the starting values of the static class members
int Orc::alive_orcs = 0;
bool Orc::frenzy_mode = false;

int main() {
    // Creating 2 orcs
    Orc orc1, orc2;

    std::cout << "Normal Mode" << std::endl;
    std::cout << "\nOrc1: " << orc1;
    std::cout << "Orc2: " << orc2;

    Orc::toggle_frenzy_mode();

    std::cout << "\nFreanzy Mode" <<std::endl;
    std::cout << "\nOrc1: " << orc1;
    std::cout << "Orc2: " << orc2;

    return 0;    
}