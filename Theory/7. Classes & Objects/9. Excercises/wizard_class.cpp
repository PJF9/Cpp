#include <iostream>
#include <cstdlib>
#include <ctime>

// Creating the wizard class
class Wizard {
    private:
        // All the class members we will need
        int age;
        int health;
        int magic_points;
        std::string beard;

    public:
        // Creating the constructor
        Wizard(int aAge, std::string aBeard, int aMagic_points=100, int aHealth=100): age(aAge), beard(aBeard), magic_points(aMagic_points), health(aHealth) {};

        // Overloading the += operator
        Wizard &operator+=(int value) {
            if (this->health + value <= 100) {
                this->health += value;
                return *this;
            }
            std::cout << "Max health only can be 100, not above" << std::endl;
            std::cout << std::endl;
        }

        // Overloading the -= operator
        Wizard &operator-=(int value) {
            this->health -= value;
            if (this->health <= 0) {
                this->health = 0;
            }
            
            return *this;
        }

        // Creating the accessors
        void set_magic_points(int magic_points) {
            // Setting the magic points
            if (magic_points > 0) {
                this->magic_points = magic_points;
            } else {
                std::cout << "Invalid given magic points" << std::endl;
                std::cout << std::endl;
            }
        }
        int get_magic_points () {
            // Get the magic points
            return magic_points;
        }
        int get_health() {
            // Get the wizard's health
            return this->health;
        }


        // Fireball Spell
        int fireball_spell() {
            if (this->magic_points >= 30) {
                this->magic_points -= 30;
                
                int damage = 10 + rand() % 11;  

                std::cout << "The wizard has activate the fireball spell (" << damage << ")" << std::endl;
                std::cout << "Current magic points: " << this->magic_points << std::endl; 
                std::cout << std::endl;

                return damage;                

            } else {
                std::cout << "Not enougth magic points for this ability" << std::endl;
                std::cout << std::endl;
            }
        }

        // Lightning Spell
        int lightning_spell() {
            if (this->magic_points >= 90) {
                this->magic_points -= 90;

                int damage = 50 + rand() % 21;

                std::cout << "The wizard has activate the lightning spell (" << damage << ")" << std::endl;
                std::cout << "Current magic points: " << this->magic_points << std::endl;
                std::cout << std::endl;

                return damage;

            } else {
                std::cout << "Not enought magic points for this ability" << std::endl;
                std::cout << std::endl;
            }
        }

        // Waiting method
        void wait() {
            this->magic_points += 10;
            std::cout << "The wizard is resting now" << std::endl;
            std::cout << "Current magic points: " << this->magic_points << std::endl;
            std::cout << std::endl;
        }
        
        // Check if the wizard is dead
        bool check_dead() {
            if (this->health == 0) {
                return true;
            }
            return false;
        }
};

// Creating the humanoid class
class Humanoid {
    private:
        // All the class members we need
        int health;
    
    public:
        // Creating the constructor
        Humanoid(int aHealth=100): health(aHealth) {};

        // Overloading the -= operator
        Humanoid &operator-=(int value) {
            this->health -= value;

            if (this->health <= 0) {
                this->health = 0;
            }

            return *this;
        }

        // Create the accessors
        void set_health(int health) {
            // Set the new humanoid's health
            this->health = health;
        }
        int get_health() {
            // Get the humanoid's health
            return this->health;
        }

        // Create the attack method
        int attack() {
            int damage = 1 + rand() & 30;

            std::cout << "Humanoid has done a little bit of damage (" << damage << ")" << std::endl;
            std::cout << std::endl;
            
            return damage;
        }

        // Check if the humanoid is dead
        bool check_dead() {
            if (this->health == 0) {
                return true;
            }
            return false;
        }
    
};


int main() {
    // Creating the Gandalf object
    Wizard Gandalf(2019, "Gray", 120, 90);
    // Create the Robot object
    Humanoid Robot(120); 

    // Generate a new seed, each time the peogram is being run
    srand(time(0));

    // Test the code
    while (true) {
        int rand_choice = rand() % 2; //* Get a random number between 0 and 1

        // Condition for the wizards move
        if (rand_choice == 0) {
            // Wait condition
            if (Gandalf.get_magic_points() <= 30) {
                Gandalf.wait();
            } else {
                Robot -= Gandalf.fireball_spell();
            }

        } else {
            // Wait conditon
            if (Gandalf.get_magic_points() <= 90) {
                Gandalf.wait();
            } else {
                Robot -= Gandalf.lightning_spell();
            }
        }

        // Check if robot is dead
        if (Robot.check_dead()) {
            std::cout << "The Robot is dead!" << std::endl;
            break;
        }

        // Robot move
        Gandalf -= Robot.attack();

        // Check if Gandalf is dead
        if (Gandalf.check_dead()) {
            std::cout << "Gandalf is dead!" << std::endl;
            break;
        }

        // Print the players health
        std::cout << "Robot's Health: " << Robot.get_health() << "\nGandlaf's health: " << Gandalf.get_health() << "\n" << std::endl;
    }

    return 0;
}