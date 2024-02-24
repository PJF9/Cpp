#include <iostream>


/**
 * ? What is a refference ?
 *  A refference is an alias for an existing valiable. Note that
 *  refference is not a variable, meanning that it doesn't commit
 *  its own memory space and we have to assigne it with a value
 *  at the time we declare it. It's an alias because with a refference
 *  we can work with the variable that the refference is 'pointing'
 *  without naming the variable's name. Refferences are actually
 *  pointers with the defference that they are not variables.
 *  If we want to change the value that the refferenc is 'pointing'
 *  we have no way to do that. The reffernce can only 'point'
 *  to one variable and only one.
*/

int main() { 
    int x = 9;
    
    /// Creating a reference of the variable x named refx
    int &refx = x;

    /// Prints results
    std::cout << "x = " << x << std::endl;
    std::cout << "refx = " << refx << std::endl;

    /// This line will also affect the variable a
    refx = 6;

    std::cout << "x = " << x << std::endl;
    std::cout << "refx = " << refx << std::endl << std::endl;
}