#include <iostream>

/*
    ? What is operators overloading?
    In c++ as in python ( with dunder methods ) we can overload the classic math operators
    to give a little more functionality to our class  

    ? How can we achieve the overloading in c++
        * + operator
        The + operator is consist by two part, the left one and the rigth one ( left + right )
        The + operator is called by the left part of the operation
        The right part is the argument in the function ( left.operator+(rigtht) )
        
        Syntax: class_name operator+(const class_name &right)

        ! The right object is being passt as a const to prevent its modification ( when we could use const only better will be to our program ) 
        ! Also we are passing the right object as a reference to prevent the compiler to create an copy of that object

        We can overload the + operator to add a const value with the object
        
        Syntax: class_name operator+(int right)

        * - operator
        The method is the same wil the + operator overloading

        Syntax: class_name operator-(const class_name &right)
    

    By this way we can overload every operator we wont, only if its consist 2 parts ( one left and one rigth )
    ! The left one must be always an object of that class
    ! But the right one can be whatever we want
*/  

class Point {
    private:
        // All the class members we need
        int x;
        int y;
    
    public:
        // Creating the constructor
        Point(int aX=0, int aY=0): x(aX), y(aY) {};

        // Creating the accessors
        void set_x(int x=0) {
            this->x = x;
        }
        void set_y(int y=0) {
            this->y = y;
        }

        int get_x() {
            return x;
        }
        int get_y() {
            return y;
        }

        // Create a function to overload the + operator
        Point operator+(const Point &right) { //* If we are passing an object of the same class as an argument we have access to its private class membgers
            Point result;
            result.x = x + right.x; //* x is the x value of the left object
            result.y = y + right.y; //* Also with y

            return result; //* return the adding object
        }

        // Another overlodaing to the + operator
        Point operator+(int rigth) {
            Point result;
            result.y = y + rigth;
            result.x = x + rigth;

            return result;
        }

        // Create an overload to the - operator
        Point operator-(const Point &right) {
            Point result;
            result.x = x - right.x;
            result.y = y - right.y;

            return result;
        }

        // Another way to create an overloading method
        Point operator-(int right) {
            return Point(x - right, y - right);
        }
};

int main() {
    // Creating our points
    Point a(3,6);
    Point b(6,3);
    Point c;

    // Adding the 2 points to a third one
    c.set_x(a.get_x() + b.get_x());
    c.set_y(a.get_y() + b.get_y());

    // Printing result
    std::cout << "c(" << c.get_x() << "," << c.get_y() << ")" << std::endl;

    // Using the + overloading method
    c = a + b;

    // Printing result
    std::cout << "c(" << c.get_x() << "," << c.get_y() << ")" << std::endl;

    // Using another + overloading method
    c = a + 3;
    
    // Printing result
    std::cout << "c(" << c.get_x() << "," << c.get_y() << ")" << std::endl;

    // Using the - operator overloading
    c = a - b;

    // Printing result
    std::cout << "c(" << c.get_x() << "," << c.get_y() << ")" << std::endl;

    // Using the alternative way
    c = a - 3;
    std::cout << "c(" << c.get_x() << "," << c.get_y() << ")" << std::endl;

    return 0;
}