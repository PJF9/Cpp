#include <iostream>
#include <string>

int main() {
    //! + overloaded operator
    std::string s1 = "This is ";
    std::string s2 = "a string";
    std::cout << s1 + s2 << std::endl; //* It will combine the 2 strings together

    //! = overloaded operator
    s1 = s2; //* Copies the second string to the first one

    //! += overloaded operator
    s1 += s2; //* s1 = "This is a string", because a+=b == a=a+b

    // All this dont only work with string object, work also with string text ( s1 + "string1" )

    //! [] overloaded operator
    s1[0] = 't'; //* Give access to each letter of the string

    //! < <= > >= == != overloaded operators
    // Returns true/false if the first string lets say is bigger ( alphabeticly ) than string two
    if (s1 > s2); //* The same works with all the other conditional operators

    // Lower case letters is winning against the capital ones
    // If the first letters are the same and one string is finished, then the longest string is winning
}