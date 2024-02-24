#include <iostream>
#include <string>

// Creating the card class
class Card {
    private:
        // All the class members we will need fo this class
        std::string card_name;
        std::string card_color;
        std::string rarity;

    public:
        // Creating the constructor
        Card(std::string card_name, std::string card_color, std::string rarity) {
            // Assign value to the name
            this->card_name = card_name;

            // Assign value to the color
            if (card_color == "blue" || card_color == "green" || card_color == "red" || card_color == "white" || card_color == "black") {
                this->card_color = card_color;
            } else {
                std::cout << "Colors Available: blue, red, green, white, black" << std::endl;
                this->card_color = "None";
            }

            // Assign value to the rarity
            if (rarity == "common" || rarity == "uncommon" || rarity == "rare") {
                this->rarity = rarity;
            } else {
                std::cout << "Raraties Available: common, uncommon, rare" << std::endl;
                this->rarity = "None";
            }
        } 

        // Overloading the << operator
        friend std::ostream &operator<<(std::ostream &left, Card &ob) {
            left << "(" << "Name: " << ob.card_name << ", Color: " << ob.card_color << ", Rarity: " << ob.rarity << ")";

            return left;
        }

        // Creating all getters
        std::string get_name() {
            return this->card_name;
        }
        std::string get_color() {
            return this->card_color;
        }
        std::string get_rarity() {
            return this->rarity;
        }
};

// Create the creature class
class Creature: public Card {
    private:
        // All the class members we need 
        int attack;
        int defence;
        std::string kind;

    public:
        // Creating the constructor
        Creature(std::string aCard_name, std::string aCard_color, std::string aRarity, int attack, int defence, std::string kind):
        Card(aCard_name, aCard_color, aRarity) {
            this->attack = attack;
            this->defence = defence;
            this->kind = kind;
        }

        // Overloading the << operator
        friend std::ostream &operator<<(std::ostream &left, Creature &ob) {
            left << "(" << "Name: " << ob.get_name() << ", Color: " << ob.get_color() << ", Rarity: " << ob.get_rarity(); 
            left << ", Attack: " << ob.attack << ", Defence: " << ob.defence << ", Kind: " << ob.kind << ")";
            
            return left;
        }   
};

// Creating a land card
class Land: public Card {
    private:
        // All the class members we will need for the class land
        int mana;
        std::string desc;
        bool tap;

    public:
        // Creating the constructor
        Land(std::string aCard_name, std::string acCrd_color, std::string aRarity, int mana, std::string desc, bool tap):
        Card(aCard_name, acCrd_color, aRarity) {
            // Assign value to mana
            if (mana == 1 || mana == 2) {
                this->mana = mana;
            } else {
                std::cout << "Mana takes only the 1 or 2 ( values )" << std::endl;
                this->mana = 0;
            }
            
            // Assign value to desc
            this->desc = desc;

            // Assign value to tap
            this->tap = tap;
        }

        // Overloading the << opertaor
        friend std::ostream &operator<<(std::ostream &left, Land &ob) {
              left << "(" << "Name: " << ob.get_name() << ", Color: " << ob.get_color() << ", Rarity: " << ob.get_rarity();
              left << ", Mana: " << ob.mana << ", Descreption: " << ob.desc << ", tap: " << ob.tap; 

              return left;
        } 
};

int main() {
    // Creating two object
    Creature c1("Rune-Scarred Demon", "black", "rare", 6, 6, "Demon");
    Creature c2("Akroan Crusader", "red", "common", 1, 1, "Human Soldier");

    // Printing results
    std::cout << c1 << std::endl << c2 << "\n" << std::endl;

    // Creating the land objects
    Land l1("Plains", "white", "uncommon", 1, "Plains", false);
    Land l2("Swamp", "black", "rare", 1, "Swamp", true);

    // Printing results
    std::cout << l1 << std::endl << l2 << "\n" << std::endl;

    return 0;
}