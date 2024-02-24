#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <conio.h> //* for the wait function

// Create the hangman class
class Hangman {
    private:
        // All the class membres we are going to use
        std::vector <std::string> words = {"petros", "game", "giraffe", "play", "spiderman", "batman"};
        std::string secret_word;
        std::string game;
        std::string bad_guesses = " ";
        std::string right_guesses = " ";
        int max_wrongs = 5;
        int wrongs = 0;

    public:
        // Creating the constructor
        Hangman() {
            // Take a random word out of the vector
            secret_word = words[rand() % 6];

            // Give the start value of the words
            for (int i=0; i<secret_word.length(); i++) {
                game.push_back('-');
            }
        }

        void printings() {
            system("cls");
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << "\tWelcome to the Hangman Game" << std::endl;
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << "  ( only lower case letters are allowed )\n" << std::endl; 
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << "Good Luck\n" << std::endl;
            std::cout << "Secret word: " << game << std::endl;
        }

        void wait() {
            std::cout << "Press Anything To Continue...";
            getch();
        }

        // Creating the game method
        void hang_game() {
            while (wrongs != 5) {
            printings();

                bool found = false;
                char user_choice;
                
                while (true) {

                    bool is_in = true;
                    
                    std::cout << "-> Give me a letter( worng answers: " << wrongs << "): "; 
                    std::cin >> user_choice;

                    for (int i=0; i<bad_guesses.length(); i++) {
                        if (user_choice == bad_guesses[i]) {
                            std::cout << "***Give another letter, you have choose " << user_choice << " before\n" << std::endl;    
                            is_in = false;
                            wait();
                            printings();
                        }
                    }
                    
                    for (int i=0; i<right_guesses.length(); i++) {
                        if (user_choice == right_guesses[i]) {
                            std::cout << "***Give another letter, you have choose " << user_choice << " before\n" << std::endl; 
                            is_in = false;
                            wait();
                            printings();
                        }
                    }

                    if (is_in) {
                        break;
                    }

                }

                for (int i=0; i<secret_word.length(); i++) {
                    if (user_choice == secret_word[i]) {
                        right_guesses.push_back(user_choice);
                        game[i] = user_choice;
                        found = true;
                    }
                }
                
                if (!found) {
                    bad_guesses.push_back(user_choice);
                    std::cout << "***" << user_choice << " is not at the secret word\n" << std::endl;
                    wait();
                    wrongs += 1;
                } 

                if (game == secret_word) {
                    printings();
                    std::cout << "\nCongarst You Won, The secret word was indead " << game << std::endl;
                    return;
                }
            }
            printings();
            std::cout << "\nI Am Sorry, You Lost, The Secret Word Was: " << secret_word << std::endl;
        }
};

int main() {
    srand(time(0));

    Hangman h;
    h.hang_game();
    

    return 0;
}