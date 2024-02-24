#include <iostream>

class User {
    private:
        std::string _status;
    public:
        std::string first_name;
        std::string last_name;

        // Setter function
        void set_status(std::string aStatus) {
            if (aStatus == "Gold" || aStatus == "Silver" || aStatus == "Bronse") {
                _status = aStatus;
            } else {
                _status = "Invalid Status";
            }
        }
        // Getter function
        std::string get_status() {
            return _status;
        }
        
        User(std::string aFirst_name, std::string aLast_name) {
            first_name = aFirst_name;
            last_name = aLast_name;
        }
};


int main() {
    User user("Petros", "Floratos");
    
    user.set_status("Gold");
    std::cout << user.get_status() << std::endl;
    
    user.set_status("Status");
    std::cout << user.get_status() << std::endl;
}