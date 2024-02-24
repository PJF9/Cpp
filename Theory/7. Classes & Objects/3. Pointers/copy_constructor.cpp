#include <iostream>

/**
 * ? What is the copy constructor ?
 *  This constructor is a constructor that is called when we want
 *  to copy the object we are working with
 * 
 *  There are three defferent situations that we need the copy costructor:
 *      -> 1. When we want to pass our object as an argument in a fucntion. 
 *      -> 2. When we want to return our object at a function.
 *      -> 3. When we declare a new object and assign ( at the same time )
 *          the value of the object we are working with.
 * 
 *  Syntax:
 *      class_name(const class_name& working_object);
 *      
 *      The key concept about copy constructor is the refference.
 *      Because we are using refference with the copy constructor we create
 *      an alias for the object we are working with and we can modify the
 *      other object with the alias.
 * 
 *      We are using const because we don't want our working object to be
 *      modifyed. The copy constructor only allow us to take informations
 *      for the object we are working with.
 * 
 * 
 * ? When we want to pass our object as an argument in a function
 *  By calling a function that has as a parameter our class objects, the
 *  compiler copies our working object and creating a new one that has the
 *  same value as our working one. Therefore because the class constructor,
 *  is only called when we creating object and now we are copying an object,
 *  will not be called. Although the destructor is always dismissing the memory
 *  space of the object no matter what it came from. So the destructor will
 *  always going to be called when its time to be called. Concluding if we try
 *  to pass our working object in a funtion as an argument and we modyfy the
 *  parametered object ( the copy one ) it will cause an undifined behavior.
 * 
 * 
 * ? When we want to return out object at a function
 *  When we try to return our working object we might don't need a copy
 *  constructor. Its might according the compiler. MinGW doesn't need a
 *  copy constructor to return the object. Its returning the working
 *  object as a temporary object.
 * 
 * 
 * ? When we declare a new object and assign ( at the same time )
 * ?  the value of the object we are working with.
 *  This is the eaziest way to both activate the copy construtor and also
 *  to realize why is so important. Without a copy constructor we can't
 *  perform this task.
*/

class Simple {
    private:
        int x;

    public:
        Simple(int x = 3) {
            std::cout << "Constructing..." << std::endl;
            this->x = x;
        }

        ~Simple() {
            std::cout << "Destructing..." << std::endl;
        }

        Simple(const Simple& ob) {
            std::cout << "Copy Constructor..." << std::endl;
            this->x = ob.x;
        }

        int get_X() {
            return x;
        }
};


void f(Simple aOb) {
    std::cout << "Inside f..." << std::endl;
}

Simple Funct() {
    Simple ob;
    std::cout << "Inside Funct..." << std::endl;

    return ob;
}


int main() {
    /// This is the working object
    Simple working_ob(9);

    std::cout << std::endl;

    /// First situation
    std::cout << "Before calling f..." << std::endl;
    f(working_ob);
    std::cout << "After calling f..." << std::endl << std::endl;

    /// Second situation
    std::cout << "Before calling f..." << std::endl;
    Simple ob = Funct();
    std::cout << "After calling f..." << std::endl << std::endl;

    /// Third situation
    Simple copy_ob = working_ob;

    std::cout << std::endl;
}