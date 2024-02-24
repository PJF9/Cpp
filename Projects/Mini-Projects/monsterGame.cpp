#include <iostream>
#include <cstdlib>
#include <ctime>


// Creating the class for the player and monster
class Atributes {
    public:
        std::string name;
        int health;
        int randDamage;
        int heal;

    Atributes(std::string aName, int aHealth, int aRandDamage, int aHeal) {
        name = aName;
        health = aHealth;
        randDamage = aRandDamage;
        heal = aHeal;
    }
};


// Get the choice from the user
int menu() {

    int choice;
    // Creating the Menu
    std::cout << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Heal" << std::endl;
    std::cout << "3. Defence" << std::endl;
    std::cout << "4. Exit\n" << std::endl;
    std::cout << "Enter Choice: ";
    std::cin >> choice;

    // Return the user input
    return choice;
}


// Creating the menu function
int userChoice(int choice) {
    // Declare the player choice variable
    int player_choice;

    switch (choice) {
        case 1:
            player_choice = 1;
            break;
        case 2:
            player_choice = 2;
            break;
        case 3:
            player_choice = 3;
            break;
        case 4:
            player_choice = 4;
            break;
    }
}


// Get the player name
std::string getUserName() {
    // Get user input
    std::string name;
    std::cout << std::endl;
    std::cout << "Give me your name champion: ";
    std::cin >> name;

    // Return value
    return name;
}

// Healht limitations
int resaetPlayersHelth(int player_health) {
    if (player_health <= 0) {
        player_health = 0;
    } else {
        player_health = player_health;
    }
    return player_health;
}

int resaetMonstersHelth(int monster_health) {
    if (monster_health <= 0) {
        monster_health = 0;
    } else {
        monster_health = monster_health;
    }
    return monster_health;
}


// Main funtion
int main() {

    // Create the player and the monster
    Atributes player(getUserName(), 175, 0, 30);
    Atributes monster("Zombie", 200, 0, 0);

    int number_of_moves = 0;

    while (true) {;
        // Track the total moves
        number_of_moves ++;

        // Generating a random seed
        srand(time(NULL));

        // Random damages
        player.randDamage = rand() % 41;
        if (player.randDamage < 10) {
            player.randDamage = 10;
        }

        monster.randDamage = rand() % 43;
        if (monster.randDamage < 15) {
            monster.randDamage = 15;
        }

        int menu_choice;
        do {
            // Calling the functions
            int show_menu = menu();
            menu_choice = userChoice(show_menu);
            std::cout << "____________________________" << std::endl;

        } while (menu_choice > 4 || menu_choice < 1);

        // Conditions
        if (menu_choice == 1) {
            monster.health -= player.randDamage;
            player.health -= monster.randDamage;

            // Health limitation
            player.health = resaetPlayersHelth(player.health);
            monster.health = resaetMonstersHelth(monster.health);

            // Make the app prettier
            std::cout << player.name << " attacked " << monster.name << " with " << player.randDamage << " damage." << std::endl;
            std::cout << monster.name << " attacked " << player.name << " with " << monster.randDamage << " damage." << std::endl;
            std::cout << std::endl;
            std::cout << player.name << " has " << player.health << " health." << std::endl;
            std::cout << monster.name << " has " << monster.health << " health." << std::endl;
            std::cout << "____________________________" << std::endl;

        } else if (menu_choice == 2) {
            player.health += player.heal;
            player.health -= monster.randDamage;

            // Health limitation
            player.health = resaetPlayersHelth(player.health);
            monster.health = resaetMonstersHelth(monster.health);

            // Make the app prettier
            std::cout << player.name << " healed with " << player.heal << " heal points." << std::endl;
            std::cout << monster.name << " attacked " << player.name << " with " << monster.randDamage << " damage." << std::endl;
            std::cout << std::endl;
            std::cout << player.name << " has " << player.health << " health." << std::endl;
            std::cout << monster.name << " has " << monster.health << " health." << std::endl;
            std::cout << "____________________________" << std::endl;

        } else if (menu_choice == 3) {
            player.health -= (monster.randDamage - (monster.randDamage * 0.75));

            // Health limitation
            player.health = resaetPlayersHelth(player.health);
            monster.health = resaetMonstersHelth(monster.health);

            // Make the app prettier
            std::cout << player.name << " defenced a hit but he took a little damage " << std::endl;
            std::cout << monster.name << " attacked " << player.name << " with " << monster.randDamage - (monster.randDamage * 0.75) << " damage." << std::endl;
            std::cout << std::endl;
            std::cout << player.name << " has " << player.health << " health." << std::endl;
            std::cout << monster.name << " has " << monster.health << " health." << std::endl;
            std::cout << "____________________________" << std::endl;

        } else {
            std::cout << "You Exited the game" << std::endl;
            std::cout << "____________________________" << std::endl;
            break;
        }

        // See if end game
        int won;
        if (player.health <= 0 && monster.health > 0) {
            won = 0;
        } else if (player.health > 0 && monster.health <= 0) {
            won = 1;
        } else {
            won = 2;
        }

        // Print results
        if (won == 0) {
            std::cout << "Unfortunately " << player.name << " you lost by " << monster.name + "." <<  std::endl;
            std::cout << "The game lasted " << number_of_moves << " moves." << std::endl;
            std::cout << std::endl;
            break;
        } else if (won == 1) {
            std::cout << "Corgatulations " << player.name << " you beat " << monster.name + "." << std::endl;
            std::cout << "The game lasted " << number_of_moves << " moves." << std::endl;
            std::cout << std::endl;
            break;
        } else if (player.health <= 0 && monster.health <= 0) {
            std::cout << "You had an equal game." << std::endl;
            std::cout << "The game lasted " << number_of_moves << " moves." << std::endl;
            std::cout << std::endl;
            break;
        }
    }
}
