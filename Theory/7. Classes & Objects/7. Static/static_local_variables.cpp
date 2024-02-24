#include <iostream>

/*
    ? Why we need the static local variables ?
    We need them to maintain the value of a variable after the function finished
*/

void funct() {
    int y = 0;
    static int x = 0; //* This is the value of the variable only the first time

    x += 1;
    y += 1;

    std::cout << "x = " << x << ", y = " << y << std::endl;
}

int main() {
    for (int i=0; i<5; i++) {
        funct();
    }

    return 0;
}
