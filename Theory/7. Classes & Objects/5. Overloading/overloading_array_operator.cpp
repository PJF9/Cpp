#include <iostream>

/*
    ? How can we overload the [] operator
    Syntax: data_type &operator[](int i)
*/

class Simple {
    private:
        // All the class members we want
        int x;
        int y;
        int *array;
    
    public:
        // Creating the constructor
        Simple (int aX, int aY): x(aX), y(aY) {
            // Dynamic memory commitment
            array = new int [2];

            // Condition
            if (!array) {std::cout << "Error Allocating Memory" << std::endl;}
        };

        // Creating the destructor
        ~Simple() {
            delete [] array;
        }

        // Creating the accessors
        void set_x(int x) {
            this->x = x;
        } 
        void set_y(int y) {
            this->y = y;
        }
        int get_x() {
            return x;
        }
        int get_y() {
            return y;
        }

        // Overload the [] operator
        int &operator[](int i) {
            if (i == 0) {
                array[i] = this->x;
                return array[i];
            } else if (i == 1) {
                array[i] = this->y;
                return array[i];
            }
                std::cout << "Invalid Index Position..." << std::endl;
            }

            // Or we could only check and return the value of a given index position
};

int main() {
    // Creating the object
    Simple a(3, 9);

    // Printing results
    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
}