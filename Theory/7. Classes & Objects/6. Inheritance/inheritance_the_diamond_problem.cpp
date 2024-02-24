#include <iostream>

/*
    ? What is the diamond problem ?
    The diamond problem is the main problem with inheritance
    It's about some members
    Lets say we want to add the name of the philosopher king
    So we build a new class that will inherate by the philosopher king

    The problem is that the compiler don't know where the name is comming from
    ( The king class or the philosopher one? )

    First solutuon is to use the :: operator (King::name or Philosopher::name)
    This is not the best choice

    The best choice is to use virtual inheritance

    We have to create a default constructor because, each time the King constructor or the philosopher consructor
    is being run, before they run the person constructor must exetuted first, but with no given values
*/

// Creating the person class
class Person {
    protected:
        std::string name;
    
    public:
        Person() {};
        Person(std::string name) {
            this->name = name;
        }
};

// Creating the first class
class King: virtual public Person {
    protected:
        std::string realm;

    public:
        King(std::string realm) {
            this->realm = realm;
        }

        void set_realm(std::string realm) {
            this->realm = realm;
        }

        void rule() {
            std::cout << "Now i rule" << std::endl;
        }
};

// Creating the second class
class Philosopher: virtual public Person {
    protected:
        std::string philosophy;

    public:
        Philosopher(std::string philosophy) {
            this->philosophy = philosophy;
        }

        void set_philosophy(std::string philosophy) {
            this->philosophy = philosophy;
        }

        void think() {
            std::cout << "Now i think" << std::endl;
        }
};

// Creating the class that will inherate those two classes
class Philosepher_Kind: public King, public Philosopher {
    public:
        Philosepher_Kind(std::string aName, std::string aRealm, std::string aPhilosophofy):
        Person(aName), King(aRealm), Philosopher(aPhilosophofy) {}

        void routine() {
            think();
            rule();
            think();
        }

        // Help us with the printings
        friend std::ostream &operator<<(std::ostream &left, Philosepher_Kind &ob) {
            left << "Name: " << ob.name << std::endl;
            left << "Ruling: " << ob.realm << std::endl;
            left << "Using: " << ob.philosophy << " philosophy";
        }
};


int main() {
    Philosepher_Kind a("Marcus Aurelius", "Roman Empire", "stoic");
    std::cout << a << std::endl;
}