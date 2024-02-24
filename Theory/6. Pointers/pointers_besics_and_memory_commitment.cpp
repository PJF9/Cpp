#include <iostream>

/**
 * ? What are pointers ?
 *  Pointer is variable that takes as value the memory location
 *  of another variable. Pointer do this and only this, storing
 *  memory addresses, whatever data type we declare them. The data
 *  type that we are telling the compiler to create a pointer is 
 *  just the type that the variable that will point the pointer.
 *  No the type of the pointer. A pointer is going to be always
 *  int data type.
 * 
 *  Because the pointer is a variable we can declare them and pass
 *  either the 0 or NULL or nullptr value, meanning that the pointer
 *  won't take any value ( any memory address ).
*/

/**
 * We can store some data with two defferent ways inside the
 *  RAM. First we can store the data staticly and second
 *  dynamicly.
 * 
 * ? What is static memory commitment ?
 *  The static memory commitment is the process of storing some
 *  data inside the function's or class memory space ( in RAM ).
 *  This place is called stack.
 * 
 * ? What is dynamic memory commitment ?
 *  The dynamic memory commitment is the process of storing some
 *  data outside of the function's or class memory space ( in RAM ).
 *  This place is called heap.
 * 
 * ? When we should use static memory commitment ?
 *  We use this method when we know how much space will the
 *  data need. This way we commit the memory space before 
 *  compiling.
 * 
 * ? When we should use the dynamic memory commitment ?
 *  We use this method when we doen't know how much memory will
 *  a variable is going to need. We commit the memory space at 
 *  compiling time.
 * 
 * ? How we can store something staticly ?
 *  We can store something statickly by declaring an object
 *  and not assigne it with the new keyword. All the object
 *  that is created without the new keyword are stored inside
 *  stack.
 * 
 * ? How we can store something dynamicly ?
 *  To store some data at the heap we need to create the object
 *  using the new keyword. After the work is done for the data
 *  that we declare dynamicly we need to dismiss the memory space
 *  we have commited using the delete keyword.
 * 
 *  data_type* pointer's_name = new data_type;
 *  ...
 *  delete pointer's_name;
 * 
 * ? How we know that the data stored succesfully in the heap ?
 *  The answer is that we don't. Although we can check after we 
 *  create it:
 *      if (!pointer's_name) {...}
 *  or
 *      if (pointer's_name == nullptr) {...}, or 0 or NULL
 * 
 * 
*/


/// Creating a basic class to store objects dynamicly
class Simple {
    private:
        int x;
    
    public:
        Simple(int x=0) {
            this->x = x;
        }
};

int main() {
    /// Creating a pointer
    int* ptr = nullptr;
    int number = 9;

    /**
     * Pointing the pointer on the number's memory location.
     * 
     * When we prefix a variable with the & we tell the compiler
     *  that we want to take the memory location of the variable.
     * 
     * To get the value of number we use derefference ( *ptr ).
     * 
    */
    ptr = &number;

    /// Printing results
    std::cout << "ptr = " << ptr << ", &number = " << &number << std::endl;
    std::cout << "*ptr = " << *ptr << ", number = " << number << std::endl << std::endl;

    
    //! Static memory commitment

    int varaible = 99;
    bool another = true;
    Simple(99);

    /// All the above objects are stored inside the stack.


    int x = 3;

    //! Dynamic memory commitment
    
    int *pter = new int;
    
    if (pter == nullptr) {
        std::cout << "Error Allocating Memory" << std::endl;
    }

    *pter = x;

    std::cout << "pter = " << pter << ", &x = " << &x << std::endl;
    std::cout << "*pter = " << *pter << ", x = " << x << std::endl;    

    delete pter;

}