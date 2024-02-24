#include <iostream>

/*
    Inheritance doesn't prevent us to overwrite the method of the base class
    Our main goal now is to create an array of defferent object that will have each own methods
*/

class Animal {
    public:
        void make_sound() {
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


int main() {
    Animal an;
    Dog d;
    Cat c;

    an.make_sound();
    d.make_sound();
    c.make_sound();
    
    // In c++ we can do that, no the oposite ( only with the base class )
    Animal *anp = new Animal();
    Animal *cap = new Cat();
    Animal *dop = new Dog();

    anp->make_sound();
    cap->make_sound();
    dop->make_sound();

    delete anp;
    delete cap;
    delete dop;

    // Creating an array of pointers, that will show objects
    // The make sound is the base class ( Animal ) method
    Animal *arr[3];

    arr[0] = new Animal();
    arr[1] = new Cat();
    arr[2] = new Dog();

    for (int i=0; i<3; i++) {
        arr[i]->make_sound();
        delete arr[i];
    }
}   