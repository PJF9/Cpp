#include <iostream>

class User {
    private:
        std::string _status;
        // Creating a static class member
        // These members can also take place in public
        // We can't asigne the static menmbers there
        // So we can asign outside the class
        static int _userCount;
    public:
        std::string first_name;
        std::string last_name;

        // Creating a function to get the user count
        // In static methods we an only use static class members
        static int get_userCount() {
            return _userCount;
        }

        User(std::string aFirst_name, std::string aLast_name) {
            first_name = aFirst_name;
            last_name = aLast_name;
            // Increase the user count
            // Every object when it's created goes througth the constractor
            _userCount++;
        }
        // Decrease the user count when an object is destroed
        ~User() {
            _userCount--;
        }
};

// The name must be the same as the static inside the class
int User::_userCount = 0;


int main() {
    User user("Petros", "Floratos");
    User user1("Jacob", "Floratos");
    User user2("Antonis", "Floratos");
    
    // Calling the destructor function
    user.~User();

    // With this way we cann call static members functions
    std::cout << User::get_userCount() << std::endl;
}