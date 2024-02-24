#include <iostream>

/*
    ? What is a const object?
    A const object is an object that is beeing created by the constructor and can't change throughout the program

    This object need nessecerely a constructor
*/

class Simple {
    private:
        int x;
    
    public:
        // Creating the constructor
        Simple (int aX=0): x(aX) {};

        // Creating the accesors
        int get_x() {
            return x;
        }
        void set_x(int x) {
            this->x = x;
        }
};

int main() {
    const Simple s(9);

    //! s.set_x(6); --> Error (the compiler doesn't allow us to change its value)
}