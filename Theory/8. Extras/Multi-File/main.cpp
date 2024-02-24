#include <iostream>
#include "oop_example.hpp"



int main() {

    //https://stackoverflow.com/questions/18535621/separating-c-class-code-into-multiple-files-what-are-the-rules

    ex::Point<int> p(3, 6);

    p.set_x(9);

    std::cout << p[0];
}
