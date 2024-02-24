#include <iostream>
#include <cstdlib> //* To get a random number
#include <ctime> //* Change the seed


// Create the first monster
class Demigorgon {
    private:
        // All the class members we need
        int height;
        int weight;
        int health;

    public:
        // Creating the constructor
        Demigorgon(int health=10000) {
            this->health = health;
            height = 5;
            weight = 500;
        }

        // Creating the attack method
        int attack() { //* Return the attack damage
            srand(time(0));

            return 300 + rand() % 201; //* Because we need the range ( end - start + 1 )
        }
};

// Create the second monster
class Demidogs {
    private:
        // All the class members we want
        int health;

    public:
        // Creating the constructor
        Demidogs(int aHealth=100): health(aHealth) {};

        // Creating the attack method
        int attack() {
            // srand(time(0));

            return 10 + rand() % 21;
        }
};

// Create the hive of all monsters
class Hive {
    private:
        // All the class members we need
        Demigorgon *demigorgon;
        Demidogs *demidogs;
        int demigorgon_number;
        int demidogs_number;
        int attack_points = 0;
    
    public:
        // Creating the constructor
        Hive(int demigorgon_number=0) {
            this->demigorgon_number = demigorgon_number;
            
            if (demigorgon_number > 0) {
                // Dymanic memory commitment
                this->demigorgon = new Demigorgon [demigorgon_number];
                // Commitment condition
                if (!this->demigorgon) {std::cout << "Error Allocating Memory" << std::endl;}

            } else {
                // Assingn a value if not exist
                demigorgon = NULL;
            }

            // Get the random number of demidogs
            srand(time(0));
            this->demidogs_number = 10 + rand() % 41;

            // Dynamic mempory commitment
            this->demidogs = new Demidogs [demidogs_number];
            // Commitment condition
            if (!this->demidogs) {std::cout << "Error Allocating Memory" << std::endl;}
        }

        // Creating the attack function
        int attack() {
            // The total attacks count
            int attack_count = 1;
            
            // If exist
            if (demigorgon) {
                // Get the total damage
                for (int i=0; i<demigorgon_number; i++) {
                    attack_points += demigorgon[i].attack();
                    std::cout << "Attack number " << attack_count << " ( damage: " << demigorgon[i].attack() << " )" << std::endl;
                    attack_count ++;
                }
            }
            // Get all the demidogs attack points
            for (int i=0; i<demidogs_number; i++) {
                attack_points += demidogs[i].attack();
                std::cout << "Attack number " << attack_count << " ( damage: " << demidogs[i].attack() << " )" << std::endl;    
                attack_count ++;
            }

            // Return the total amount of attack points
            return attack_points;
        }
};

int main() {
    // Creating the hive object
    Hive h(1);

    // Active the attack method
    std::cout << "\nHive total attack points: " << h.attack() << std::endl;
}
