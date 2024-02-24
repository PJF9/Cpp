#include <iostream>

// Creating an example to undersatnd the multiple inheritance

// Creating the first class
class King {
    private:
        std::string realm;

    public:
        void set_realm(std::string realm) {
            this->realm = realm;
        }

        void rule() {
            std::cout << "Now i rule" << std::endl;
        }
};

// Creating the second class
class Philosopher {
    private:
        std::string philosophy;

    public:
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
        void routine() {
            think();
            rule();
            think();
        }
};


int main() {
    Philosepher_Kind marcus_aurelius;

    marcus_aurelius.set_realm("Roman Empire");
    marcus_aurelius.set_philosophy("Stoic");

    marcus_aurelius.routine();
}
