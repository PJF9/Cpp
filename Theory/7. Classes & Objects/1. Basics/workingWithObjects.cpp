#include <iostream>
#include <vector>

class User{
    private:
        int grade = 19;
    public:
        std::string first_name;
        std::string last_name;
        int age;

    int get_grade() {
        return grade;
    }
};

// Another way to add objects into a vector
int add_if_no_exist(std::vector <User> &users, User user) {
    for (int i=0; i<users.size(); i++) {
        if (user.first_name == users[i].first_name && user.last_name == users[i].last_name && user.age == users[i].age) {
            return i;
        }
    }
    users.push_back(user);
    return users.size() - 1;
}

int main() {
    // Create class objects
    User user1, user2;

    // Assigning the class variables
    user1.first_name = "Petros";
    user1.last_name = "Floratos";
    user1.age = 17;
    user2.first_name = "Jacob";
    user2.last_name = "Floratos";
    user2.age = 17;

    // Adding the class objetc into a vector
    std::vector <User> users;
    users.push_back(user1);
    users.push_back(user2);

    // Printing users2 last name 
    std::cout << users[1].last_name << std::endl;

    // Creating new Users
    User user3, user4, user5;
    
    user3.first_name = "John";
    user3.last_name = "Smith";
    user3.age = 16;
    user4.first_name = "Anna";
    user4.last_name = "Last";
    user4.age = 17;
    user5.first_name = "Anna";
    user5.last_name = "Last";
    user5.age = 17;

    // This function return the index of each object inside the vector
    std::cout << add_if_no_exist(users, user3) << std::endl;
    std::cout << add_if_no_exist(users, user4) << std::endl;
    std::cout << add_if_no_exist(users, user5) << std::endl;
}