#include <iostream>
#include <string>

int main() {
    // The methods length and size are the same one
    // Their work is to count the size of the string
    std::string s = "1234";
    s.length(); //* = 4
    s.size(); //* = 4

    /*  
        The space that an object has commited its not the the same as the length of the string
        By commited dynamicly a string we are commited more space, so to predict if we want the string
        to be with more letters letter
    */

    //! The capasity method
    // returns the exact bytes that the object has commited at the heap
    s.capacity();

    //! The shrink_to_fit method
    // reduce the space that the string has commited dynamicly so it can be the same as the length of this string
    s.shrink_to_fit();

    //! The resize method
    // change the space ( increase or decrease ) the bytes of commitment
    // With reseize the capasity doesn't change, only shrink_to_fit change the capasity
    s.resize(20); //* 20 is the size of bytes
}
