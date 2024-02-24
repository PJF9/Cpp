#include <iostream>

/*
    Synstax:
        try {
            ...
            if (...) {
                throw x; -> Where x = any int number
            }

            We can have code after the throw exceprion
        }
        catch (int var_x) {
            ...
            var_x will be the same as x if an error occur
        }

        We can also replace the argument of the catch with ... , if we want a default error handler 
*/

int main() {
    try {
        int moms_age = 40;
        int sons_age = 41;

        if (moms_age < sons_age) {
            throw 99; // This can be whatever number we want ( it's the id of the error )
        }
    } 
    catch(int x) {
        std::cout << "Age error: Error number " << x << std::endl;
    }
}