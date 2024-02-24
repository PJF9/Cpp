#include <iostream>

/*
    ? What is a template and why we use them ?
    Lets say we have a class that only works with ints
    But we want also that class to work with other data types

    In that case we can use a template
    Syntax:
        template <typename T>
        class class_name {
            public:
                T var_name;

                data_type method(...);
        };

        T -> is the general data type ( we can name T whatever we want )

    We can imagine that we are building a class that is taking as an argument a data type
    We can also change the 'template' to 'class' keyword
    
    ? How to declare a method outside the class
    Declare a mehtod outside the class:

    template <typename T>
    data_type class_name<T>::method(...) {
        ...
    }

    ? Can we have a template with multiple data types ?
    Yes, a template can have a lot of different data types
    Synatx:
        template <typename T1, typename T2, ..>

    ? How we difine object of templatized classes ?
    Syntax:
        class_name <T> ob_name;
        Where T is the data type ( int, char, float, ... )
    
    ? Can we pass an argument other that the data type at classes
    Yes we can
    Syntax:
        template <typename T, arg1, arg2, ...>

        But we have to update also the object
        class_name <T, arg1, arg2, ...> ob_name

    ? What about the static class members ?
    They are diefferent for each diefferent data type

    * To demonstrate this knowleage we will built a stack

    
    ? Can we make templatized functions ?
    Yes we can
    Syntax:
        template <typename T>
        ... funct(args) {
            ...
        }

        Calling the function
        funct<T>(args) -> Where T a data type

    * To demonstrate that we will create a swap function 


    ? What about friendly function ?
    We can also templatize a friendly function inside a class
    Synctax:
        template <typename T>
        class class_name {
            public:
                ...
               template <typename U> friend std::ostream &operator<<(std::ostream &left, classname<U> &right);
                ...
        };

        Difine this function outside the class
        template <typename T>
        std::ostream &operator<<(std::ostream &left, classname<T> &right) {
            ...
            return left;
        }

     
    
*/

// Create the swap function
template <typename T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// Creating the stack class
template <typename T, int stack_size>
class Stack {
    private:
        // All the class members we want
        T array[stack_size]; //* Where 100 is the max stack elements
        int top=0;

    public:
        // Creating the constructor
        Stack() {
            top -= 1;
        }

        // Some nesecary methods

        bool empty() {
            return top == -1;
        }

        bool full() {
            return top == stack_size - 1;
        }

        bool push(T elem) {
            if (full()) {
                return false;
            }
            top++;
            array[top] = elem;
            return true;
        }

        bool pop(T *elem) {
            if (empty()) {
                return false;
            }

            *elem = array[top];
            top --;
            return true;
        }

        template <typename U, int size> friend std::ostream &operator<<(std::ostream &left, Stack<U, size> &right);
};

template <typename T, int stack_size> 
std::ostream &operator<<(std::ostream &left, Stack<T, stack_size> &right) {
    for (int i=0; i<right.top+1; i++) {
        left << right.array[i] << std::endl;
    }

    return left;
}

int main() {
    int a=0, b=1;
    char A='a', B='b';
    
    swap<int>(a, b);
    swap<char>(A, B);

    // std::cout << a << " " << b << std::endl;
    // std::cout << A << " " << B << "\n\n" << std::endl;

    Stack <int, 100> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    std::cout << s1 << std::endl;

    int temp1;

    s1.pop(&temp1);
    // std::cout << temp1 << " ";
    s1.pop(&temp1);
    // std::cout << temp1 << std::endl;
    s1.pop(&temp1);

    std::cout << s1 << std::endl;

    Stack <std::string, 100> s2;

    s2.push("Lo");
    s2.push("Lol");

    std::string temp2;

    s2.pop(&temp2);
    // std::cout << temp2 << " ";
    s2.pop(&temp2);
    // std::cout << temp2 << std::endl;
}