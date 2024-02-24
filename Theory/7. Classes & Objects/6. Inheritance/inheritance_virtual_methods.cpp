#include <iostream>

/*
    ? What is a virtual method ?
    A virtual method is a class method that we can solve the last problem 
    at "inheritance_method_overwriting.cpp"

    To achive a virtual method we put a virtual in front of the method we want 
    The best for us to pass the vitual key at the front both the base and the derived class method

    If we have a pointer of the base class and shows at an object of the derived class
    if the method we want to run is virtual then it will run the derived class method, else
    it will run the base one

    The virtual method only appliew in situations with pointers or references ( at all other cases the result will be the base class method )

*/

class Animal {
    public:
        virtual void make_sound() {
            std::cout << "Animal sound" << std::endl;
        }
};

class Dog: public Animal {
    public:
        void make_sound() {
            std::cout << "Dog sound" << std::endl;
        }
};

class Cat: public Animal {
    public:
        void make_sound() {
            std::cout << "Cat sound" << std::endl;
        }
};

// Reference example
void f(Animal &ob) {
    ob.make_sound();
}


int main() {
    // Create the pointer array
    Animal *arr[3];

    // Pass the values of the array
    arr[0] = new Animal();
    arr[1] = new Cat();
    arr[2] = new Dog();

    // Printing the methods
    for (int i=0; i<3; i++) {
        arr[i]->make_sound();
        delete arr[i];
    }

    // Another example
    Animal array[3] = {
        Animal(),
        Dog(),
        Cat()
    };

    for (int i=0; i<3; i++) {
        array[i].make_sound();
    }

    // Reference example
    Dog d;
    f(d);

    return 0;
}