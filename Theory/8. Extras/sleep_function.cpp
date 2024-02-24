#include <Windows.h> // for Sleep(...);
#include <iostream>


void sleep(const int secs) {
    std::cout.flush();
    Sleep(secs * 1000);
}


int main() {
    std::cout << "Hello ";
    sleep(4);
    std::cout << "World";

  return 0;
}
