#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>


#define memory_condition std::cout << "Error Allocating Memory" << std::endl; exit(0);

class Test {
    private:
        std::string *str_ptr = nullptr;

    public:
        Test() {
            this->str_ptr = new std::string;

            if (!this->str_ptr) {memory_condition}
        }
        Test(std::string value) {
            this->str_ptr = new std::string;

            if (!this->str_ptr) {memory_condition}

            *this->str_ptr = value;
        }
        ~Test() {
            delete this->str_ptr;
        }

        inline void set_val(std::string val) {
            *this->str_ptr = val;
        }
        inline std::string get_val() {
            return *this->str_ptr;
        }

};


int main() {
    Test a("Sir");
    a.set_val("Hello");
    std::cout << a.get_val() << std::endl;
}
