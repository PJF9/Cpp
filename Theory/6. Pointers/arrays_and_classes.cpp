#include <iostream>

//! Arrays as class members
class C1 {
    private:
        int array[3];
    public:
        // Initialize the array
        C1 () {
            for (int i=0; i<3; i++) {
                array[i] = 0;
            }
        }

        // Creating the accessors
        void set_i(int pos, int val) {
            if (pos >= 0 && pos < 3) {
                array[pos] = val;
            } else {
                std::cout << "Out of bounds" << std::endl;
            }
        }
        int get_i(int pos) {
            if (pos >= 0 && pos < 3) {
                return array[pos];
            } else {
                std::cout << "Out of bounds" << std::endl;
            }
        }
};

//! Arrays that contains objects
class C2 {
    private:
        int x;
    
    public:
        // Constructor
        C2 (int aX=0): x(aX) {};

        // Accessors
        int get_x() {
            return x;
        }
        void set_x(int x) {
            this->x = x;
        }
};

int main() {
    //? First
    C1 c1;
    c1.set_i(0, 0);
    c1.set_i(1, 1);
    c1.set_i(2, 2);

    for (int i=0; i<3; i++) {
        std::cout << c1.get_i(i) << std::endl;
    }

    //? Second
    C2 array[3] = {C2(), C2(1), C2(2)}; 

    for (int i=0; i<3; i++) {
        std::cout << array[i].get_x() << std::endl;
    }

    // Or

    C2 array2[3];

    for (int i=0; i<3; i++) {
        array2[i].set_x(i);
    }

    for (int i=0; i<3; i++) {
        std::cout << array2[i].get_x() << std::endl;
    }

    //! The same with dynamic memory commitment
    C2 *array3;
    int n = 3;

    array3 = new C2 [n];

    if (!array3) {std::cout << "Error Allocating MEmory" << std::endl;}

    for (int i=0; i<n; i++) {
        array3[i].set_x(i);
        std::cout << array3[i].get_x() << std::endl;
    }

    delete [] array3;

    //! Array that contains pointers that shows to objects
    C2 *array4[3];

    for (int i=0; i<3; i++) {
        array4[i] = new C2;
        if (!array4[i]) {std::cout << "Error Allocating Memory" << std::endl;}
    }

    for (int i=0; i<3; i++) {
        array4[i]->set_x(i);
        std::cout << array4[i]->get_x() << std::endl;
    }

    for (int i=0; i<3; i++) {
        delete array4[i];
    }

    // The difference between the last two is that the first pointer is showing to an array that contains object
    // The second pointer is showing to an array that cointains pointers that will show to objects  

}
