#include <iostream>

/**
 * We have three defferent categories ( except for the regular pointer to object ) 
 *  of objects to work with pointers. 
 *  Those are:
 *      ! Pointer to const object
 *      ! Const pointer to obejct
 *      ! Const pointer to const object
 * 
 * ? Pointer to const object ( const class_name *pointer's_name )
 *  In such case the object can't modified. It is usefull when we are 
 *  passing an object as an argument inside a function and we don't 
 *  want the object to be affected. Although the pointer can change value, 
 *  meaning the memory address that is showing ( it can show on another const 
 *  object later ). Of course because the object is const we can only use
 *  const function with our pointer.
 * 
 * ? Const pointer to object ( class_name* const pointer's_name ) 
 *  In such case the pointer is always going to show the same object 
 *  ( it can't changed value ). Although the object can change it's value.
 * 
 * ? Const pointer to const object ( const class_name* const pointer's_name )
 *  Neither the object nor the pointer can change values
*/

class Simple {
    private:
        int x;

    public:
        Simple(int aX): x(aX) {};
        Simple (const Simple &ob) {};

        void set_x(int x) {
            this->x = x;
        }
        int get_x() const {
            return x;
        }
};

void f(const Simple *p) {
    std::cout << p->get_x() << std::endl;
    //! p->set_x(3): Error ( because the object that the pointer is facing is const )
}

int main() {
    Simple s(9);
    f(&s);

    return 0;
}