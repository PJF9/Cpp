#include <iostream>

/*
    ? What is a frienly class
    At c++ we can create a class A that is a friendly class on another
    class B
    With this method the object of the A class have access to the private
    class members at the B class 

    class A {
        ...
    };

    class B {
        private:
            ...
        public:
            friend class A;
            ...
    }

    * In fact we are declaring in a class, other classes that can have access to it's private class members 

    We can't overuse the friecdly class in our progeamms
    If we do that is like all the class members are public

    Also the "friendship" has a directon
    In that example the class A is a friendly class to the B class
    Not the oposite 
    
*/

// Create the Bad man class
class Bad_man {
    private:
        // All the class members we need
        int bullshits;
    
    public:
        // Creating the constructor
        Bad_man(int aBullshits): bullshits(aBullshits) {};

        // Create the accessors
        void set_bullshits(int bullshits) {
            // Set the new bullshits count
            this->bullshits = bullshits;
        }
        int get_boolshits() {
            // Get the bullshits count
            return bullshits;
        }

        // Declare a class that will be a friendly to this one
        friend class Good_man;
};

// Create the Good man class
class Good_man {
    public:
        // A function to clear all the bullshits
        void forgive(Bad_man &ob) { //* We need a reference of an object in the class that this one is a friend
            ob.bullshits = 0;
        }
};

int main() {
    // Create the bad man object
    Bad_man NoSakis(90000);
    // Create the good man object
    Good_man Sakis;

    std::cout << "NoSakis had " << NoSakis.get_boolshits() << " bullshits" << std::endl;
    Sakis.forgive(NoSakis);
    std::cout << "Now thanks to Sakis, NoSakis has " << NoSakis.get_boolshits() << " bullshits" << std::endl;

    return 0;
}