#include <iostream>

/*
    To overload the = operator first we need to understant it

    ? What does the = operator ?
    This operator is copy the result of the right side to the left ( a = b ) 

    The result of a = b is going to be a
    This helps us with multiple = ( a = b = c )

    ? How can we overload the = operator ?
    Syntax: class_name &operator=(const class_name &right)

    We use reference to prevent the compiler to copy the object
*/

class Simple {
    private:
        // All the class members we need
        int x;

    public:
        // Creating the constructor
        Simple(int aX=0): x(aX) {};

        // Creating the accessors
        void set_x(int x) {
            this->x = x;
        }
        int get_x() {
            return x;
        }

        // Create the = opereator overloading method
        Simple &operator=(const Simple &right) {
            // First we need to check if the 2 objects are equal
            if (this == &right) { //* this is the memory location of the current object and the &right is the memory location of the argument object
                return *this; //* *this is the current object
            }
            this->x = right.x; //* Its the same as x = right.x

            return *this;
        }
};

int main() {
    // Creating the objects
    Simple a(9);
    Simple b(6);
    Simple c;

    // Enable the = operator overloading
    b = a;
    c = b;
    b = c = b;

    // Printing results
    std::cout << "a = " << a.get_x() << std::endl;
    std::cout << "b = " << b.get_x() << std::endl;
    std::cout << "c = " << c.get_x() << std::endl;
}