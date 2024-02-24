#include <iostream>

class B1 {
    private:
        int x;

    public:
        B1(int aX): x(aX) {std::cout << "Constructing B1..." << std::endl;};
        ~B1() {std::cout << "Destructing B1..." << std::endl;}
};


class B2 {
    private:
        int y;

    public:
        B2(int aY): y(aY) {std::cout << "Constucting B2..." << std::endl;};
        ~B2() {std::cout << "Destructing B2..." << std::endl;}
};

// First will be executed the constructor of B1 and then the B2 ( from the right to left )
// About the destructors applies the oposite mindset
class D: public B1, public B2 {
    private:
        int z;

    public: // First we are passing the first class we inherate from then the other and at the end the arguments from this class
        D(int x, int y, int z): B1(x), B2(y) {
            this->z = z;
            std::cout << "Constucting D..." << std::endl;
        }
        ~D() {std::cout << "Destructing D..." << std::endl;}
};


int main() {
    D d(1,2,3); 
}