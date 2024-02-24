#include <iostream>

/*
    A method of a different function can also be a friendly function to another class
    With this method only the friendly class has access to the private class member, not the entire class

    class A {
        private:
            ...
        
        public:
            data typesome_method(...);
            ...
    };

    class B {
        private:
            ...
        
        public:
            friend data type A::some_method();
    };

    * In fact we declaring that a method will have acceess to the pricate members off another class
*/

// Forward declaration, to make this method count ( friendly method inside a class )
class Man;

// Create the state class
class State {
    public:
        // This only works if we pre declare also the friendly method
        void withdraw(Man &ob);
};

// Create the Man class
class Man {
    private:
        // All the class members we need
        int money;
    
    public:
        // Creating the constructor
        Man(int aMoney): money(aMoney) {};

        // GCreating the accessors
        void set_money(int money) {
            // Set the new money
            this->money = money;
        }        
        int get_money() const {
            // Get the man's money
            return this->money;
        }

        // Declare a frindly method
        friend void State::withdraw(Man &ob);
};


int main() {
    // Create all the objects
    Man Sakis(100000);
    State Greece;

    // Printing results
    std::cout << "Sakis had " << Sakis.get_money() << " money" << std::endl;
    Greece.withdraw(Sakis);
    std::cout << "Sakis now has " << Sakis.get_money() << " money" << std::endl;

    return 0;
}

// Annoying Stuff
void State::withdraw(Man &ob) {
    ob.money = 0;
}