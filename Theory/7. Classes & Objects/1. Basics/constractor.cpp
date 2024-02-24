#include <iostream>


class User{
    private:
        std::string major;
    public:
        std::string first_name;
        std::string last_name;
        int age;

        // Creating a Constractor
        // Constractors force us to create our objetc differently
        // If we difine a constractor then we can only create an object only using one of all the all the constractor we defined 
        User(std::string aFirst_name, std::string aLast_name) {
            first_name = aFirst_name;
            last_name = aLast_name;
        } 
        User() {
            std::cout << "Default" << std::endl;
        }
        User(int aAge) {
            age = aAge;
            std::cout << "Age object" << std::endl;
        }
        User(std::string aMajor) {
            major = aMajor;
        }

        std::string get_major() {
            return major;
        }
        // Destractors
        // Applies when an object destroys
        ~User() {
            std::cout << "Object Destroyed" << std::endl;
        } 
};


int main() {
    User user1("Petros", "Floratos");
    std::cout << "First name: " + user1.first_name << std::endl;
    std::cout << "Last name: " + user1.last_name << std::endl;

    User user2;
    // Calling the constructor function
    user2.~User();

    User user3(18);

    User user4("Camp. Science");
    std::cout << user4.get_major() << std::endl;
}