#include <iostream>

class Footballer {

    private:
        std::string full_name;
        std::string position;        
        int age;

    public:
        Footballer() {};
        Footballer(std::string aFirst, std::string aLast, int aAge, std::string aPosition);
        ~Footballer() {
            std::cout << "Destroyed :)" << std::endl;
        }

        //* All the getter and setter are called accesors

        void set_fullname(std::string first, std::string last) {
            full_name = first + " " + last;
        }

        void set_position(std::string pos) {
            position = pos;
        }

        void set_age(int user_age) {
            age = user_age;
        }

        std::string get_fullname() {
            return full_name;
        }
        
        std::string get_position() {
            return position;
        }

        int get_age() {
            return age;
        }

        //* We can create methods also like this
        bool is_jung();
        
};

int main() {
    Footballer petros;
    Footballer jacob("Jacob", "Floratos", 18, "CM");

    petros.set_fullname("Petros-Iakovws", "Floratos");
    petros.set_age(17);
    petros.set_position("CDM");

    std::cout << "My name is " << petros.get_fullname() << std::endl;
    std::cout << "I am " << petros.get_age() << std::endl;
    std::cout << "And I play " << petros.get_position() << std::endl;

    std::cout << "My name is " << jacob.get_fullname() << std::endl;
    std::cout << "I am " << jacob.get_age() << std::endl;
    std::cout << "And I play " << jacob.get_position() << std::endl;
}

//*
bool Footballer::is_jung() {
    if (age < 22) {
        return true;
    } else {
        return false;
    }
}

//*
Footballer::Footballer(std::string aFirst, std::string aLast, int aAge, std::string aPosition) {
            full_name = aFirst + " " + aLast;
            position = aPosition;
            age = aAge;
        }