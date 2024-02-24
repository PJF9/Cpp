#include <iostream>

/*
    ? What to model about?
    Modeling a class is the concept that creating the best object posible for that class

    This concept is very common when we are working with real life problems and we are trying to create classes to solve them
    
    * etc:
      Lets say that an appartment building has 3 floors. Every floor has 5 appartments. Every appartment has peoples...  
*/

//! Let's model an appartment building

class Appartment {
    private:
        int people = 0;
    public:
        // Creating the constructor
        Appartment(int aPeople=0): people(aPeople) {
            std::cout << "Contructing flat..." << std::endl;
        };

        // Creating the destructor
        ~Appartment() {
            std::cout << "Destruction flat..." << std::endl;
        }

        // Creating the accessors
        void set_people(int people) {
            this->people = people;
        }
        int get_people() {
            return people;
        }
};

class Floor {
    private:
        Appartment appartments[5]; //* Let's say that every floor has 5 appartments
    public:
        // Creating the constructor
        Floor() {
            std::cout << "Constructing Floor..." << std::endl;
        }
        
        // Creating the destructor
        ~Floor() {
            std::cout << "Destructing Floor..." << std::endl;
        }

        // Creating the accessors
        void set_people_per_appartment(int appartment_index, int people_in_that_appartment) {
            // Calling the function from the Appartment class to insert the people in the appartment
            appartments[appartment_index].set_people(people_in_that_appartment);
        }
        int get_people_per_appartment() {
            // Declare a variable to help us work with lots of appartments
            int total_people_per_appartment = 0;

            for (int i=0; i<5; i++) {
                // Calling the function from the Appartment class to get the people per appartmen
                total_people_per_appartment += appartments[i].get_people();
            }

            return total_people_per_appartment;
        }
};

class Appartment_building {
    private:    
        Floor floors[3]; //* Let's say that the appartmentbuilding has 3 floors
    public:
        // Creating the constructor  
        Appartment_building() {
            std::cout << "Constructing appartment building..." << std::endl;
        }
    
        // Creating the destructor
        ~Appartment_building() {
            std::cout << "Destructing appartment building..." << std::endl;
        }

        // Creating the accessors
        void set_people_per_floor(int floor_index, int appartment_index, int people_in_that_appartment) {
            floors[floor_index].set_people_per_appartment(appartment_index, people_in_that_appartment);
        }
        int get_people_per_floor() {
            // Declare a variable to help us work with a lot of floors
            int total_people_per_floor = 0;

            for (int i=0; i<3; i++) {
                total_people_per_floor += floors[i].get_people_per_appartment();
            }

            return total_people_per_floor;
        }
};

/*
    First the program will construct from the inside to the outside ( from the appartment to the floor )
    and will destruct from the outside to the inside ( from the floor to the appaertment )
*/

int main() {
    Appartment_building b;

    /*
        If we want the program to be more releible we could:
            * Replace the floor and the appartment index with getters from each class
            * Create a function to ask the user to insert the total ammount of people in the appartment
    */       
    
    for (int floor_index=0; floor_index<3; floor_index++) {
        for (int appartment_index=0; appartment_index<5; appartment_index++) {
            b.set_people_per_floor(floor_index, appartment_index, 4);
        }
    }

    std::cout << "----People in that appartment building: " << b.get_people_per_floor() << std::endl;

    return 0;
}