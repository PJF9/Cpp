#include <iostream>

/*
    ? What is an inline function?
    An inline function is a function ( very basic, sort ) that does only one think
    These are not functions because they don't commit exrta memmory space at the stack
    By using inline functions we are gaining memory space and speed

    The inline definitions a request to the compiler
    Thats way the combiler can deny our request
  
    ? When the compiler will deny the request?
    When there are inside the function loops, conditions and recursions.
    The compiler also denies the request when the function we want to be inline is more
    than a line.

    So in a nutshell an inline function must only contains one line of code.

    Inline function can be the accessors functions inside a class
*/

inline int sqr(int x) {
    return x*x;
}

int main() {
    std::cout << sqr(3) << std::endl;
}