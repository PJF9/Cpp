#include <iostream>
#include <string> // To use all the string methods

int main() {
    // Create a string object ( seeing all the costructor )
    
    //! First ( default constructor )
    // The constructor: string(); 
    std::string s; //* Declaring a string with length 0

    //! Second ( with an actual constructor )
    // The constructor: string(const char *s);
    std::string s("Hallo");
    // We can also do
    std::string s = "There";

    //! Third ( a declare ( reapet ) constructor )
    // The constructor: string(int n, char c);
    std::string s(20, 'x');

    //! Copy Constructor
    // The copy constructor: string(const string &s);
    std::string s2 = s; // Or
    std::string s2(s);

    
    // Overloaded >> operator
    std::cin >> s; //* sin is stoping when we push the charachter ' ', so can only read one word
    // If we don't want that we need to use the friendly function getline
    getline(std::cin, s);
    
    // Overloading getline function
    getline(std::cin, s, '\n'); //* \n is the delimeter ( it will stop at this letter )

    
    // Overloaded << operator
    std::cout << s << std::endl;

    return 0;    
}