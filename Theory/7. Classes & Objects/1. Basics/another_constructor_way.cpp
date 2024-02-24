#include <iostream>

class Simple {
    private:
        int x;
        int y;
    public:
        /*
            ? There is another way to create a constructor
            x(aX) == (x = aX)
            y(aY) == (y = aY )
        */
        Simple (int aX, int aY): x(aX), y(aY) {}; //* All the code we want for the creation of the object goes inside the {} 
};

int main() {
    Simple s(10, 5);
}
