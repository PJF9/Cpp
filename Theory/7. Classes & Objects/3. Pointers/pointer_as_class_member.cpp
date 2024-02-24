#include <iostream>

/**
 * Because class member can be whatever type we want, we can also
 *  have pointer class members
*/

class Simple {
    private:
    /// Declaring a pointer class member 
        int *p = nullptr;
    public:
        Simple() {
            /// Assigne the pointer a memory space at the heap ( outside the class memory space )
            p = new int;
            
            /// The not so usefull condition
            if (!p) {
                std::cout << "Error Allocating Memory" << std::endl;
            }
            std::cout << "Constructing..." << std::endl;
        }

        ~Simple() {
            /// Dismiss the memory space that the pointer was commiting
            delete p;
            std::cout << "Destucting..." << std::endl;
        }

        void set_val(int val) {
            *p = val;
        }
        int get_val() {
            return *p;
        }

        /// This method is going to return the memory location of the p pointer
        void print_memory() {
            std::cout << p << std::endl;
        }
};

int main() {
    /// First example
    Simple ob;
    ob.set_val(9);
    std::cout << "ob.get_val = " << ob.get_val() << std::endl;

    /**
     * ! The main problem of working with pointers and objects ( memory leak )
     * 
     * ? What this problem is about?
     *  The problem is occuring when we are using dynamic memory commitment and we are 
     *  trying to delete copied objects
     * 
     * ? Why copying object challenge an error?
     *  It's because when we creating the first object, the constructor provide him a 
     *  memory location at the heap and then with the accessors we assigne a value at this 
     *  memory location. 
     * 
     *  By declaring the second object, the constructor is commiting a new memory space at the heap
     *  for the second object. With the line "ob2 = ob1", we are pointing the ob2 to memory location 
     *  off ob1 ( and his value will be also the same as ob1 ).
     * 
     * After all the code is done and its time to run the destuctors, the first time the compiler 
     * deletes the ob2 ( dismiss its memory location ), but when it tries to run the 
     * destructor for the ob1 the program will crash because there will be not a memory space left 
     * to delete
    */
   
    Simple ob1;
    ob1.set_val(9);

    Simple ob2;

    ob2 = ob1;

    std::cout << "ob1.get_val() = " << ob1.get_val() << std::endl;
    ob1.print_memory();
    std::cout << "ob2.get_val() = " << ob2.get_val() << std::endl;
    ob2.print_memory();
}

