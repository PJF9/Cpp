#include <iostream>
#include <string>

int main() {
    // Creating the string object
    std::string s = "Hallo There";

    //! Find method
    // Syntax: string::find(const string &str, start_index_pos);
    // This method is searching in the string to find the argumented string, always starting at the second argument index pos
    // If we dint pass the second argument that will be equal to 0
    s.find(std::string("Th"), 2);

    //! Overloaded method
    // C strings
    s.find("Th", 2);
    // Only char
    s.find('T', 2);

    // This find method only returns the first index pos of the given argument
    // If the argumented string is not exist at the string then it will return the size of the string

    //! Some other find methods ( works also with c strings and chars, and object )
    // rfind method ( the same as find but starts default by the end of the string and going to the start )
    s.rfind("H", 8);

    // find_first_of method ( search to find whatever of the charachter in the argumented string, starts at 0 )
    s.find_first_of("hhhhH", 0);

    // find_last_of mehtods ( The same as the previous but starting at the end of the string )
    s.find_last_of("hhhhH", 8);

}
