#include <iostream>
#include <ctime>
#include <cstdlib>

// Creating the class
class BankSystem {
    // Declairing all the class members as private
    private:
        std::string account_name;
        std::string account_type;
        int account_number = 0;
        double account_money = 0;

    public:
        // Set account name function
        void set_account_name();
        // Set account type function
        void set_account_type();
        // Set accound number function
        int set_account_number();
        // Withdraw money from the account
        void withdraw(double amount);
        // Deposit money from the account
        void deposit();
        // Modify the account name
        void modify_account_name();
        // Modify the account type
        void modify_account_type();
        // Getting the money
        double get_money();
        // Showing the account
        void show_account();
};

// Creating a method to set the account name
void BankSystem::set_account_name() {
    std::string aAccount_name;
    std::cout << "Enter Account Name: ";
    std::cin >> aAccount_name;

    if (aAccount_name.size() < 15) {
        account_name = aAccount_name;
    } else {
        account_name = "Invalid Account Name";
    }
}

// Creating a method to set the account type 
void BankSystem::set_account_type() {
    std::string aAccount_type;
    std::cout << "Enter Account Type ( P, B ): ";
    std::cin >> aAccount_type;

    if (aAccount_type == "P" || aAccount_type == "B") {
        account_type = aAccount_type;
    } else {
        account_type = "Invalid Account Type";
    }
}

// Creating a method to set the account number
int BankSystem::set_account_number() {
    srand(time(NULL));
    account_number = 1000 + rand() % 1001;
}

// Creating a method to give the withdraw functionality
void BankSystem::withdraw(double amount) {
    account_money -= amount;

    std::cout << "Your account balance is: " << account_money << "$" << std::endl;
}

// Create a method to give the deposit functionality
void BankSystem::deposit() {
    double amount;
    std::cout << "Amount ( $ ) you want to deposit: ";
    std::cin >> amount;

    account_money += amount;

    std::cout << "Your account balance is: " << account_money << "$" << std::endl;
}

// Create a method to modify the account name
void BankSystem::modify_account_name() {
    std::string aAccount_name;
    std::cout << "Enter new account name: ";
    std::cin >> aAccount_name;

    account_name = aAccount_name;

    std::cout << "Your new account name is: " << aAccount_name << std::endl;
}

// Create a method to modify the account type
void BankSystem::modify_account_type() {
    char aAccount_type;
    std::cout << "Enter the new account type ( P, B ): ";
    std::cin >> aAccount_type; 

    if (aAccount_type == 'B' || aAccount_type == 'P') {
        account_type = aAccount_type;
    } else {
        account_type = 'N';
    }
}

// Get the money to use them later
double BankSystem::get_money() {
    return account_money;
}

// Printing the account
void BankSystem::show_account() {
    std::cout << "Account name: " << account_name << std::endl;
    std::cout << "Account type: " << account_type << std::endl;
    std::cout << "Account number: " << account_number << std::endl;
    std::cout << "Account balance: " << account_money << "$" << std::endl;
}

// Heart of the program
void menu(BankSystem account) {
    int choice;
    int has_name = 0;
    int has_type = 0;
    while (choice != 6){
        do {
            system("cls");
            std::cout << "1. Create Account" << std::endl;
            std::cout << "2. Modify Account" << std::endl;
            std::cout << "3. Show Account" << std::endl;
            std::cout << "4. Deposit" << std::endl;
            std::cout << "5. Withdraw" << std::endl;
            std::cout << "6. Exit Program" << std::endl;
            std::cout << "Enter Choice: ";
            std::cin >> choice;

        } while (choice > 6 || choice < 1);

        if (choice == 1) {
            int choice2;
            while (choice2 != 4) {
                do {
                    system("cls");
                    std::cout << "1. Set Account Name" << std::endl;
                    std::cout << "2. Set Account Type" << std::endl;
                    std::cout << "3. Set Account Number" << std::endl;
                    std::cout << "4. Back" << std::endl;
                    std::cout << "Enter Choice: ";
                    std::cin >> choice2;
            
                } while (choice2 > 4 || choice2 < 1);

                if (choice2 == 1) {
                    account.set_account_name();
                    has_name = 1;
                } else if (choice2 == 2) {
                    account.set_account_type();
                    has_type = 1;
                } else if (choice2 == 3) {
                    account.set_account_number();
                }   
            }

        } else if (choice == 2) {
            while (true) {
                int choice3;
                do {
                    system("cls");
                    std::cout << "1. Modify Account Name" << std::endl;
                    std::cout << "2. Modify Account Type" << std::endl;
                    std::cout << "3. Back" << std::endl;
                    std::cout << "Enter Choice: ";
                    std::cin >> choice3;
                } while (choice3 > 3 || choice < 1);

                if (choice3 == 1) {
                    account.modify_account_name();
                } else if (choice3 == 2) {
                    account.modify_account_type();
                } else {
                    break;
                }
            }

        } else if (choice == 3) {
            system("cls");
            account.show_account();
            int choice4;
            do {
                std::cout << "Want to continue? ( 0=no/1=yes ) : ";
                std::cin >> choice4;
            } while (choice4 != 1);
            
        } else if (choice == 4) {
            account.deposit();

        } else if (choice == 5) {
            system("cls");
            int choice5;
            double with_money;
            do {
                std::cout << "Insert Amount to Withdraw: ";
                std::cin >> with_money;

                if (with_money > account.get_money()) {
                    std::cout << "No such balance" << std::endl;
                    std::cout << "What to continue? ( 0=no/1=yes ) : ";
                    std::cin >> choice5;
                } else {
                    account.withdraw(with_money);
                    break;
                }
            } while (choice5 != 1);

        } else {
            return;
        }
    }
}

int main() {
    BankSystem p;
    menu(p);
}