#include <iostream>
#include <string>

int main() {
    // The value of an enmpty string is "" 
    // We can concatinate strings using +
    std::string first_name = "Petros";
    std::string last_name = "Floratos";
    std::cout <<"My name is " + first_name + " " + last_name << std::endl;

    // Length of the string
    std::cout << first_name.length() << std::endl;

    // C string are arrays and like all arrays in c++ their size is fixed
    char middle_name[] = "Jacob";
    std::cout << middle_name << std::endl;

    // String methods
    std::string major = "Comp. Science";
    
    // Size of a string
    std::cout << major.size() << std::endl; 
    
    // Append to a string
    major += "!";
    major.append("!!");
    std::cout << major << std::endl;

    // Insert to a sting
    std::cout << major.insert(5, "              ") << std::endl;

    // Remove ( 1 arg = index pos, 2 arg = num we want to remove )
    std::cout << major.erase(5, 14) << std::endl;
    // Remove the last letter --> major.pop_back()

    // Replace ( 1 arg = start index, 2 arg = how many, 3 arg = new value ) 
    std::cout << major.replace(5, 1, "_") << std::endl;
}