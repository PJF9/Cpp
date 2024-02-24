#include <iostream>

class User {
    public:
        std::string first_name;
        std::string last_name;

        User(std::string aFirst_name, std::string aLast_name) {
            first_name = aFirst_name;
            last_name = aLast_name;
        }
        User() {
        }
};

// These operator changers have no accesse to the private class member
std::ostream &operator << (std::ostream& output, User user) {
    output << "First Name: " << user.first_name << "\tLast Name: " << user.last_name;
    return output;
}

std::istream &operator >> (std::istream& input, User& user) {
    input >> user.first_name >> user.last_name;
    return input;
}

int  main() {
    User user("Petros", "Floratos");

    std::cout << user << std::endl;

    User user1;
    std::cin >> user1;
    std::cout << user1 << std::endl;
}