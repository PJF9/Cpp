#include <iostream>

/*
    ? Which constructor and destructor will applied first ? 
    First run the constructor of the base class and then the constructor of the derived(= παραγωμενη) one
    ( from inside to the outside )

    About the destructors
    First will destruct the derived object and then the base one
    ( from the outside to the inside )
*/

class A {
    private:
        // All the class members we will need
        int x;
        int y;
    public:
        // Creating the constructor
        A(int aX, int aY): x(aX), y(aY) {
            std::cout << "Constructing A..." << std::endl;
        }
        // Creating the destuctor
        ~A() {
            std::cout << "Destructing A..." << std::endl;
        }
};

class B: public A {
    private:
        // All the B class members
        int z;
    public:
        // Creating the constructor
        B(int aX, int aY, int aZ): A(aX, aY) { //* first we are passing the mambers of the prime class
            this->z = aZ;
            std::cout << "Costructing B..." << std::endl;
        }
        // Creating the destructor
        ~B() {
            std::cout << "Destructong B..." << std::endl;
        }
};

int main() {
    B b(1,2,3);
}