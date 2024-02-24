#include <iostream>

/**
 * ? What is the this pointer?
 *  The this pointer is a pointer that shows the memory address of the object.
 *  This pointer in fact is like a normal private class members that goes there automatically
 * 
 * With the this pointer we can construct a little bit different our program
*/

class point {
    private:
        int x;
        int y;

    public:
        point(int aX, int aY): x(aX), y(aY) {};
        point(int x) {
            this->x = x; //* With this pointer we are reffering to the class member x not the argument
        }

        point *return_this() {
            return this;
        }

        void print_ob() {
            std::cout << "x = " << x << ", y = " << y << std::endl;
            std::cout << std::endl;
        }
};

int main() {
    point p(3, 9);
    p.print_ob();

    std::cout << "Address: " << &p << std::endl;
    std::cout << "Address: " << p.return_this() << std::endl;
}