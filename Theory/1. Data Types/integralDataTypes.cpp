#include <iostream>
// We have to include a library to see the max/min of number any data type
#include <climits>


int main() {
    // Integral data types
    
    // Both positive and negative numbers ( short <= int <= long <= long long )
    short a; // At least 8 bits
    int b; // At least 16 bits
    long c; // At least 16-32 bits (according to the compiler)
    long long d; // At least 64 bits 

    // With unsinged keyword we use all the 32 bits for only negative or positive number 
    unsigned short aa;
    unsigned int bb;
    unsigned long cc;
    unsigned long long dd;

    // Showing the size of a data type in bytes
    std::cout << sizeof(b) << std::endl;
    // Showing the max number of each data types
    std::cout << SHRT_MAX << std::endl; // If we want with both negative USHRT_MAX
    std::cout << INT_MAX << std::endl; // UINT
    std::cout << LONG_MAX << std::endl; // ULONG
    std::cout << LLONG_MAX << std::endl; // ULLONG
    // We can also see the min number if we replace MAX with MIN
}