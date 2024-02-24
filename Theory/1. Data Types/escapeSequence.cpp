#include <iostream>


int main() {
    
    // \t add a tab to the string
    std::cout << "Hallo\tThere" << std::endl;

    // \b delete a character
    std::cout << "Hallo\bThere" << std::endl;

    // \n means next line
    std::cout << "Hallo\nThere" << std::endl;

    // \v uses \n and \t
    std::cout << "Hallo\vThere" << std::endl;

    // /" allow us to use "" also the same with \\ 
    std::cout << "Hallo\"There\"" << std::endl;

    std::cout << "Hallo\rThere" << std::endl;
}