#include <iostream>

/*
    To understand how we can overload this type off operator we need to incpect them
    lets take for example the ++ operator

    ? What is the ++ operator ?
    The ++ operator is the operator that increment by one the left variable ( x++ == x = x + 1 )
    First the x is going to be x and then the x is going to incremented by one

    ? What happens to this situation (a = x++) ?
    lets incpect it: a = x = x + 1
    So a will be equal to x and x is going to be equal x amd then the x is going to be equal to x + 1 

    Now we now how this operators work

    ? How can we overload the ++ operator ?
    Syntax: class_name operator++(int right)

    In this situation we dont care at all for the argument, we only want it to be int data type 

    ? What is going to do the a = ++x ?
    a = x + 1 = x
    So the a = x + 1 and the x = x + 1

    Suntax: class_name operator++()
*/

class Simple {
    private:
        // All the class member we need
        int x;
    
    public:
        // Create the constructor
        Simple(int aX=0): x(aX) {};

        // Create the accessors
        void set_x(int x) {
            this->x = x;
        }
        int get_x() {
            return x;
        }

        // Overload the ++ operator
        Simple operator++(int right) {
            // With * we are taking the object ( this: is a pointer facing to the memory location of the original object )
            Simple result = *this; //* We use *this because we want the new object to be the same as the old one (x = x ...)
            this-> x++; //* We can also write only x++

            return result;
        }

        // Another operator overloading ( ++ )
        Simple operator++() {
            this-> x++; //* The same is x++
            return *this; //* Return the original object with diferent value
        }
};

int main() {
    // Creating the objects
    Simple a;
    Simple x(1);

    // Enable the operator overloading
    a = x++;

    // Printing results
    std::cout << a.get_x() << " " << x.get_x() << std::endl;

    // Enable the ++var overloading
    a = ++x;

    // Printing results
    std::cout << a.get_x() << " " << x.get_x() << std::endl;
    
}