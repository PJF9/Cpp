#include <iostream>
#include <string>

int main() {
    // Creating the string object
    std::string s = "Hallo";

    //! Adding elements to the string
    // append method ( add the argument at the last of the string )
    s.append(" There");
    // insert method ( add the argument at a specific position )
    // This method is not deleting the element at this position, it only moves it right
    s.insert(11, "!"); //* The position is counted with the letters
    // push_back method ( add a character at the end )
    s.push_back('.');

    //! Delete elements from the string
    // clear method ( Delete the string, the string length becomes 0 )
    s.clear();
    // erase method ( delete specific charachters )
    // This method has default arguments ( if we don't pass the end pos then the compiler will delete all all the letters starting wiith the given start )
    s.erase(1, 3); //* We are telling the compiler to start from the 1 index position and delete 3 letters including the 1 one
    // pop_back method ( delete the last character of the string )
    s.pop_back();

    //! Get/Replace elements from/at the list
    /*
        replace method ( strart at the first argument and continue with second argument, 
        including the start one, replace this substring with the given third argument but 
        only a part of the string, starting with the fourth arguments and continue with the 
        fifth argument)

        Syntax: string::replace(start_pos, size_len, const std::string &str, str_start_pos, str_size_len)
    */
    s.replace(1, 3, std::string("12345"), 2, 3);
    // The substr method ( return part of the string )
    s.substr(1, 2); //* Start at index position 1 and continue 2 letters ( including 1 )
}
