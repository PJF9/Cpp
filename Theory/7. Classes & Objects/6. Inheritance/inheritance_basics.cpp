#include <iostream>

/*
    ? What is class inheritance ? 
    It's the last big concept of OOP
    Inheritance is taking a class an add it to another one ( both members and methods )

    etc of inheritance in life
    A horse is an animal
    A dog is also an animal, but a bulldog is also a dog...

    Syntax:
        class A: public B {
            ...
        };

        In this case all the public members and method of the B class are accessivle by the class A
        But the private ones are not accessable in the class A

        We can also instead of public ( public inheritance ) use private ( private inheritance ) 
*/

// Creating the animal class
class Animal {
    private:
        // All the class members we will need in that class
        int weight;
        int height;
    
    public:
        // Creating the accessord
        void set_weight(int weigth) {
            this->weight = weight;
        }
        void set_height(int height) {
            this->height = height;
        }

        int get_weight() {
            return this->weight;
        }
        int get_height() {
            return this->height;
        }
    
};

// Creating the dog class ( this class will be inherited the class animal )
class Dog: public Animal {
    private:
        // All the class members we are going to use
        std::string house_address;

    public:
        // Creating the accessors
        void set_house_address(std::string house_address) {
            this->house_address = house_address;
        }
        std::string get_house_address() {
            return this->house_address;
        }

        // Creating the bark method
        void bark() {
            std::cout << "baaarrk" << std::endl;
        }

        // Overload the << operator
        friend std::ostream &operator<<(std::ostream &left, Dog &ob) {
            left << ob.get_height() << std::endl;
            left << ob.get_weight() << std::endl;
            left << ob.get_house_address() << std::endl;
        
            return left;
        }
};

int main() {
    // Check our classes
    Dog piko;
    piko.set_height(2);
    piko.set_weight(60);
    piko.set_house_address("1234");
    piko.bark();

    std::cout << piko;

    return 0;
}