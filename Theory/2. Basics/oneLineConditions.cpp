#include <iostream>


int main() {
    int x;
    int y = 10;
    int z = 20;

    /*
     * If (z > y) is true then x will take the value of z
     *  else y.
    */

    x = (z > y) ? z : y;

    std::cout << x; 
}