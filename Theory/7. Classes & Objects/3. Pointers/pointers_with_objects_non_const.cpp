#include <iostream>

/// Because a class is a new data type we can commit its memory dynamicly

class Simple {
    public:
        int x;

        Simple(){};

        Simple(int aX) {
            x = aX;
            std::cout << "Constracting..." << std::endl;
        }

        ~Simple() {
            std::cout << "Destructing..." << std::endl;
        }
};

int main() {
    /**
     * Because we delare a Simple data type pointer, the pointer is going 
     *  to point to a Simple object.
     * 
     * In fact data type is not changing the 'job' of the pointer in our
     *  program. His job is to point to an object ( store its memory
     *  address ). 
    */
    Simple *p = nullptr; 
    
    /// Commit memory space at the heap ( memory of bytes that Simple needs )
    p = new Simple;

    /// The nessecary condition to determin if the last line of code worked
    if (!p) {
        std::cout << "Error Allocating Memory" << std::endl;
    }

    // Assigning value 9 to the Simple object class member x that the pointer is pointing
    p->x = 9;

    // Printing the results
    std::cout << "p->x = " << p->x << std::endl;

    /**
     * The same lines of code can be written as bellow
     * 
     * Note that *p is actual the object the object that the pointer is
     *  pointing
    */
    (*p).x = 9;
    
    // Printing the results
    std::cout << "(*p.x) = " << (*p).x << std::endl; 

    // Dismiss the memory location at thg heap
    delete p; 

    //? Staticly memory ( A pointer is going to head to an object inside the main memory location )

    Simple ob;
    /// The pointer ptr is going to point the object ob at that lies on the stack
    Simple *ptr = nullptr;

    /// Pointing the pointer to the ob object ( pass the ob's memory address )
    ptr = &ob;
    
    /// Assigning the x's value
    ptr->x = 9;

    /// Printing results
    std::cout << ob.x << " " << ptr->x << " " << (*ptr).x << std::endl; 

    //? Dynamik memory with constractors

    /**
     * The job we have to do is the same as before.
     * 
     * We can create a pointer that shows at a Simple object in one line:
     *  Simple *P = new Simple();
     * For better look.
    */
    Simple *P = nullptr;
    P = new Simple();

    P->x = 9;

    /// Printing result
    std::cout << P->x << std::endl; 

    if (!p) {
        std::cout << "Error Allocating Memory" << std::endl;
    }

    delete P;
}