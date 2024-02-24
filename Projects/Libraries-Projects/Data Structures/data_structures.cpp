#include <iostream> //* For input and output
#include <vector> //* To pass multiple args
#include <cstdlib> //* To use the exit method and the EXIT_SUCSS one
#include <string> //* To use the string data type


//? All the data structurs on this project
template <typename A> class array;
template <typename L2> class S_L_List;
template <typename L> class D_L_List;
template <typename AS> class stack_array;
template <typename LS> class stack_list;
template <typename AQ> class queue_array;
template <typename LQ> class queue_list;
template <typename A2D> class array_2d;


//Todo: Create many algorithms
//Todo: One chaeck up to all the class methods

//! ############################################################################################################################################ !\\

//!                                                                Array                                                                         !\\

//! ############################################################################################################################################ !\\



// Making this class more functional ( now is working with all the data types availible )
template <typename A>
// Creating the array class
class Array {
    private:
        // All the class members we need
        A *arr;
        int array_size;

    public:
    // Creating the constructors
        Array();
        Array(std::vector <A> args);
        Array(const D_L_List<A> &ob);
        Array(S_L_List<A> &ob);
        Array(std::initializer_list<A> ai);
        Array(int size, A value);
        Array(const Array<A> &ob);

    // Creating the destructor
        ~Array();

    // Creating the accessors
        int get_array_size() const;
        void set_array_size(int size, A value);
        A get_elem(int index);

    /*
        All the methods return an array object so we can
        copy the result on another array object

        We are using reference in some methods, because
        with this way we can automaticly print the new
        object that is created

        We can't do that if we skip the refference
    */

    // Creating all the array methods
        //* Add element methods
        Array<A> &push_back(A value);
        Array<A> &push_front(A value);
        Array<A> &insert(int index, A value);
        Array<A> extend(const Array<A> aArray);
        Array<A> extend(const std::vector<A> aVector);
        Array<A> extend(const D_L_List<A> aList);
        Array<A> extend(const S_L_List<A> aList);

        //* Remove element methods
        Array<A> &pop_back();
        Array<A> &pop_front();
        Array<A> &clear();
        Array<A> &remove_by_index(int index, int total_pos);
        Array<A> &remove_by_value(A value, bool dupl, bool err);
        Array<A> &ndpl();
        Array<A> &set_with_sort();

        //* Sorting method
        Array<A> &sort();
        Array<A> &reverse_sort();

        //* Reverse method
        Array<A> &reverse();

        //* Copy mehtod
        Array<A> copy(const Array<A> &ob);
        Array<A> copy(const std::vector<A> &ob);
        Array<A> copy(const D_L_List<A> &ob);
        Array<A> copy(const S_L_List<A> &ob);

        //* Count and index methods
        int count(A value);
        int index(A value);
        Array<int> index(A value, bool nes);

        //* Methods to get eazily the first or the last element
        A first();
        A last();

    // Creating the overloading methods  
        Array<A> &operator=(const Array<A> &left);
        Array<A> &operator=(const std::vector<A> &ob);
        Array<A> &operator=(const D_L_List<A> &ob);
        Array<A> &operator=(const S_L_List<A> &ob);

        bool operator==(const Array<A> &left);
        bool operator==(const std::vector<A> &left);
        bool operator==(const D_L_List<A> &left);
        bool operator==(const S_L_List<A> &left);

        bool operator!=(const Array<A> &left);
        bool operator!=(const std::vector<A> &left);
        bool operator!=(const D_L_List<A> &left);
        bool operator!=(const S_L_List<A> &left);

        bool operator>(const Array<A> &right);
        bool operator>(const std::vector<A> &right);
        bool operator>(const D_L_List<A> &right);
        bool operator>(const S_L_List<A> &right);

        bool operator>=(const Array<A> &right);
        bool operator>=(const std::vector<A> &right);
        bool operator>=(const D_L_List<A> &right);
        bool operator>=(const S_L_List<A> &right);

        bool operator<(const Array<A> &right);
        bool operator<(const std::vector<A> &right);
        bool operator<(const D_L_List<A> &right);
        bool operator<(const S_L_List<A> &right);

        bool operator<=(const Array<A> &right);
        bool operator<=(const std::vector<A> &right);
        bool operator<=(const D_L_List<A> &right);
        bool operator<=(const S_L_List<A> &right);
        
        A &operator[](int index);
        
        Array<A> &operator+=(int value);
        Array<A> &operator+=(const Array<A> &right);
        Array<A> &operator+=(const std::vector<A> &right);
        Array<A> &operator+=(const D_L_List<A> &right);
        Array<A> &operator+=(const S_L_List<A> &right);
        
        Array<A> &operator-=(int value);
        Array<A> &operator-=(const Array<A> &right);
        Array<A> &operator-=(const std::vector<A> &right);
        Array<A> &operator-=(const D_L_List<A> &right);
        Array<A> &operator-=(const S_L_List<A> &right);
        
        Array<A> &operator*=(int value);

        template <typename U> friend std::ostream &operator<<(std::ostream &left, Array<U> &ob);
        template <typename U> friend std::istream &operator>>(std::istream &left, Array<U> &ob);
};




















//! ############################################################################################################################################ !\\

//!                                                            Linkded List                                                                      !\\

//! ############################################################################################################################################ !\\



// Creating a Node class
template <typename N>
class Node {
    private:
        // Those are all the nessecary class members
        N data; //* --> This will be the value of the node
        Node <N>*next; //* --> This will be the pointer that will show the next node

    public: 
        // Make this class friendly with the actual list, so in the list class we have access to the Node's private members
        template <typename L> friend class S_L_List ;        

};

// Creating the list class
template <typename L>
class S_L_List {
    private:
        // All the class members we need
        Node<L> *head; //* --> This pointer will point at the first element of the list

    public:
    // Creating the constructors
        S_L_List();
        S_L_List(std::vector <L> v);
        S_L_List(const array<L> &ob);
        S_L_List(const D_L_List<L> &ob);
        S_L_List(std::initializer_list <L> li);
        S_L_List(int size, L value);  
        S_L_List(const S_L_List<L> &ob);

    // Creating the accessors
        int get_size() const;
        L get_elem(int index) const;

    // Creating all the linked list methods
        //* All the adding elements methods
        S_L_List<L> &push_front(L user_data);
        S_L_List<L> &push_back(L user_data);
        S_L_List<L> &insert(int index, L value);
        S_L_List<L> &extend(const S_L_List<L> &list);

        //* Printig method
        void print();

        //* All the removing elements methods
        S_L_List<L> &pop_back();
        S_L_List<L> &pop_front();
        S_L_List<L> &remove_by_index(int index, int total_pos);
        S_L_List<L> &remove_by_value(L value, bool dupl);
        S_L_List<L> &clear();

        //* Sorting method
        S_L_List<L> &sort();
        S_L_List<L> &reverse_sort();
        S_L_List<L> &set_with_sort();

        //* Reverse method
        S_L_List<L> &reverse();

        //* Copy method
        S_L_List<L> &copy(const S_L_List<L> &ob);

        //* Count and index methods
        int count(L value);
        int index(L value);
        S_L_List<int> index(L value, bool nes);

        //* Getting eazily the first and the last element of the list methods
        L first();
        L last();

    // Creating the overloading methods
        S_L_List<L> &operator=(const S_L_List<L> &right);

        bool operator==(const S_L_List<L> &right);
        bool operator!=(const S_L_List<L> &right);
        bool operator>(const S_L_List<L> &right);
        bool operator>=(const S_L_List<L> &right);
        bool operator<(const S_L_List<L> &right);
        bool operator<=(const S_L_List<L> &right);

        L &operator[](int index);

        S_L_List<L> &operator+=(L value);
        S_L_List<L> &operator+=(S_L_List<L> &right);

        S_L_List<L> &operator-=(int total_indexes);
        S_L_List<L> &operator-=(S_L_List<L> &ob);

        S_L_List<L> &operator*=(int total_copies);

        template <typename M> friend std::ostream &operator<<(std::ostream &left, S_L_List<M> &right);
        template <typename M> friend std::istream &operator>>(std::istream &left, S_L_List<M> &right);
};




















//! ############################################################################################################################################ !\\

//!                                                               Stack                                                                          !\\

//! ############################################################################################################################################ !\\



// This stack is going to be created using our array data structur
template <typename AS>
class stack_array {
    private:
        // All the class members we need 
        array<AS> stack; //* This is the actual array
        int top; //* This is the index of the top element of the stack

    public:
    // Creating the constructors
        stack_array();
        stack_array(std::vector<AS> v);
        stack_array(std::initializer_list<AS> asi);
        stack_array(int size, AS value);
        stack_array(const stack_array<AS> &ob);

    // Creating all the stack's methods
        //* Adding elements method
        stack_array<AS> &push(AS value);

        //* Remove elements method
        AS pop();

        //* Seeing the last element of the stack method
        AS peek();

    // Creating the operator overloading methods
        stack_array<AS> &operator=(stack_array<AS> &right);

        template <typename SA> friend std::ostream &operator<<(std::ostream &left, stack_array<SA> &ob);
        template <typename SA> friend std::istream &operator>>(std::istream &left, stack_array<SA> &ob); 
};


// This stack is going to be created using our linked list data structur
template <typename LS>
class stack_list {
    private:
        // Those are all the class members we will need
        S_L_List<LS> stack;
        int top;

    public:
    // Creating the constructors
        stack_list();
        stack_list(std::vector<LS> v);
        stack_list(std::initializer_list<LS> sli);
        stack_list(int size, LS value);
        stack_list(const stack_list<LS> &ob);

    // Creating all the stack's methods
        //* Adding elements method
        stack_list<LS> &push(LS value);

        //* Remove elements method
        LS pop();

        //* Seeing the last element of the stack method
        LS peek();

    // Creating the operator overloading methods
        stack_list<LS> &operator=(stack_list<LS> &right);

        template <typename SL> friend std::ostream &operator<<(std::ostream &left, stack_list<SL> &ob);
        template <typename SL> friend std::istream &operator>>(std::istream &left, stack_list<SL> &ob); 
};



















//! ############################################################################################################################################ !\\

//!                                                               Queue                                                                          !\\

//! ############################################################################################################################################ !\\



// Creating a queue class using the array data structure
template <typename AQ>
class queue_array {
    private:
        // Those are all the class members we will need
        int back;
        array<AQ> queue;

    public:
    // Creating the constructors
        queue_array();
        queue_array(const std::vector<AQ> &v);
        queue_array(std::initializer_list<AQ> qai);
        queue_array(int size, AQ value);
        queue_array(const queue_array<AQ> &ob);

    // Creating all the queue's methods
        //* Adding elements method
        queue_array<AQ> &enqueue(AQ value);

        //* Remove elements method
        AQ dequeue();

        //* Seeing the last element of the stack method
        AQ peek();

    // Creating the operator overloading methods
        queue_array<AQ> &operator=(queue_array<AQ> &right);

        template <typename QA> friend std::ostream &operator<<(std::ostream &left, queue_array<QA> &ob);
        template <typename QA> friend std::istream &operator>>(std::istream &left, queue_array<QA> &ob); 
};


// Creating a queue using the linked list data structure
template <typename LQ>
class queue_list {
    private:
        // Those are all the class members we will need
        int back;
        S_L_List<LQ> queue;

    public:
    // Creating the constructors
        queue_list();
        queue_list(const std::vector<LQ> &v);
        queue_list(std::initializer_list<LQ> qli);
        queue_list(int size, LQ value);
        queue_list(const queue_list<LQ> &ob);

    // Creating all the queue's methods
        //* Adding elements method
        queue_list<LQ> &enqueue(LQ value);

        //* Remove elements method
        LQ dequeue();

        //* Seeing the last element of the stack method
        LQ peek();

    // Creating the operator overloading methods
        queue_list<LQ> &operator=(queue_list<LQ> &right);

        template <typename QL> friend std::ostream &operator<<(std::ostream &left, queue_list<QL> &ob);
        template <typename QL> friend std::istream &operator>>(std::istream &left, queue_list<QL> &ob);
};



















//! ############################################################################################################################################ !\\

//!                                                             2D Array                                                                         !\\

//! ############################################################################################################################################ !\\



// Creating the 2d array class
// We can also create a 2d array from our array data structur
// Syntax: array <array <data_type>> array_name(...);

template <typename A2D>
class array_2d {
    private:
        // All the class methods we will need
        A2D **array_of_pointers;
        int rows;
        int columns;

        // Creating a copy method to help us with the dynamic memory
        void expand_array(int rows, int columns);

    public:
    // Creating the constructors
        array_2d();
        array_2d(std::vector<std::vector<A2D>> &v); //* This is a vectror that instead of ints has another vectrors
        array_2d(std::initializer_list<std::initializer_list<A2D>> a2di);
        array_2d(int rows, int columns, A2D value);
        array_2d(const array_2d<A2D> &ob);

    // Creating the destructor
        ~array_2d();

    // Creating the accessors
        int get_row_size() const;
        int get_column_size() const;
        A2D get_element(int row, int column) const;
        void set_array_size(int rows, int columns);

    // Create all the methods
        //* Adding elements to the array
        array_2d<A2D> &insert_row(int row_index, const std::vector<A2D> &v);
        array_2d<A2D> &insert_row(int row_index, A2D value);
        array_2d<A2D> &insert_column(int column_index, const std::vector<A2D> &v);
        array_2d<A2D> &insert_column(int column_index, A2D value);
        array_2d<A2D> &insert_element(int row_index, int column_index, A2D element);

        //* Removing elements from the array
        array_2d<A2D> &delete_column(int column_index);
        array_2d<A2D> &delete_row(int row_index);
        array_2d<A2D> &delete_element_by_index(int row_index, int column_index);
        array_2d<A2D> &delete_element_by_value(A2D value, bool dupl);
        array_2d<A2D> &clear();
        array_2d<A2D> &fill(A2D value);

        //* Sorting methods
        array_2d<A2D> &sort();
        array_2d<A2D> &reverse_sort();
        array_2d<A2D> &sort_rows();
        array_2d<A2D> &reverse_sort_rows();
        array_2d<A2D> &sort_columns();
        array_2d<A2D> &reverse_sort_columns();

        //* Copy method
        array_2d<A2D> &copy(const array_2d<A2D> &ob);

        //* Count and index methods
        int count(A2D vlaue);
        Array<int> index(A2D value, bool all);

    // Creating the overloading methods
        array_2d<A2D> &operator=(const array_2d<A2D> &right);

        bool operator==(const array_2d<A2D> &right);
        bool operator!=(const array_2d<A2D> &right);

        array<A2D> &operator[](int row_index);

        template <typename D2A> friend std::ostream &operator<<(std::ostream &left, array_2d<D2A> &right);
};




















//! ############################################################################################################################################ !\\

//!                                                          Double Linked List                                                                  !\\

//! ############################################################################################################################################ !\\



// Creating the Node class
template <typename N_D_T>
class node {
    private:
        // Those are all the class members we need to describe a node
        N_D_T data;
        node<N_D_T> *next;
        node<N_D_T> *previous;

    public:
        // Create a friendly class called double_linked_list so it can have access to the node's private class members
        template <typename L2> friend class D_L_List;
};

// Create the accoual double link list class
template <typename L2>
class D_L_List {
    private:
        // All the class members we need to construct our list
        node<L2> *head;
        node<L2> *teil;

    public:
    // Create the constructors
        D_L_List();
        D_L_List(const std::vector<L2> &v);
        D_L_List(const array<L2> &ob);
        D_L_List(const S_L_List<L2> &ob);
        D_L_List(std::initializer_list<L2> li);
        D_L_List(int size, L2 value);
        D_L_List(const D_L_List<L2> &ob);
    
    // Create the accessors
        int get_size() const;
        L2 get_element(int index) const;
        void set_size(int size, L2 value);


    // Creating all the methods
        //* Adding methods
        D_L_List<L2> &push_back(L2 value);
        D_L_List<L2> &push_front(L2 value);
        D_L_List<L2> &insert(int index, L2 value);
        D_L_List<L2> &extend(const D_L_List<L2> &ob);

        //* Removing elements methods
        D_L_List<L2> &pop_back();
        D_L_List<L2> &pop_front();
        D_L_List<L2> &remove_by_index(int index, int total_pos);
        D_L_List<L2> &remove_by_value(L2 value, bool dupl);
        D_L_List<L2> &one_val(L2 value);
        void clear();

        //* Sorrting methods
        D_L_List<L2> &sort();
        D_L_List<L2> &reverse_sort();
        D_L_List<L2> &set_with_sort();

        //* Reverse method
        D_L_List<L2> &reverse();

        //* Copy method
        D_L_List<L2> &copy(const D_L_List<L2> &ob);

		//* Count and index methods
		int count(L2 value) const;
		int index(L2 value) const;
        D_L_List<int> index(L2 value, bool nes);

		//* Methods that gives us eazy the first and the last element of the list
		L2 first();
		L2 last();

	// Creating the overloading methods
		D_L_List<L2> &operator=(const D_L_List<L2> &ob);

		bool operator==(const D_L_List<L2> &ob);
		bool operator!=(const D_L_List<L2> &ob);
		bool operator<(const D_L_List<L2> &ob);
		bool operator>(const D_L_List<L2> &ob);
		bool operator<=(const D_L_List<L2> &ob);
		bool operator>=(const D_L_List<L2> &ob);

		L2 &operator[](int index);

		D_L_List<L2> &operator+=(const D_L_List<L2> &ob);
		D_L_List<L2> &operator-=(const D_L_List<L2> &ob);
        D_L_List<L2> &operator*=(int times);

        template <typename Ll2> friend std::ostream &operator<<(std::ostream &left, D_L_List<Ll2> &right);
        template <typename Ll2> friend std::istream &operator>>(std::istream &left, D_L_List<Ll2> &right);
};





















// int main() {

// }




















//! ############################################################################################################################################ !\\

//!                                                   All The Array's Class Mehtods                                                              !\\

//! ############################################################################################################################################ !\\



// This a the default constructor, that will initialize the array pointer and the array size
template <typename A>
Array<A>::Array() { 
    arr = NULL;
    array_size = 0;
}





// This constructor helps us initialize an array usring {}
template <typename A>
Array<A>::Array(std::initializer_list<A> ai) {
    // Get the array size
    this->array_size = ai.size();

    // Dynamic memory commitment
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Adding the elements to the list
    for (int i=0; i<ai.size(); i++) {
        arr[i] = *(ai.begin()+i);
    }

}





// This is a constructor that takes as an argument a vector. This helps us if we want to initialize the array with elements
template <typename A>
Array<A>::Array(std::vector <A> args) {
    this->array_size = args.size();  //* Setting the array size equal to the total elements at the vector

    // Dynamic memory commitment
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Pass the values of the vector to the array
    for (int i=0; i<this->array_size; i++) {
        arr[i] = args[i];
    }
}





// This constuctor convert a single list to array 
template <typename A>
Array<A>::Array(const D_L_List<A> &ob) {
    // Get size
    this->array_size = ob.get_size();
    
    // Create the array
    this->arr = new A [this->array_size];
    // Commitment condition
    if (!this->arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the elements
    for (int i=0; i<this->array_size; i++) {
        arr[i] = ob.get_element(i);
    }
}





// This constuctor convert a double list to array 
template <typename A>
Array<A>::Array(S_L_List<A> &ob) {
    // Get size
    this->array_size = ob.get_size();
    
    // Create the array
    this->arr = new A [this->array_size];
    // Commitment condition
    if (!this->arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the elements
    for (int i=0; i<this->array_size; i++) {
        arr[i] = ob[i];
    }
}





// This is a constructor that takes as arguments the size of the array and the starting values of all the index positions
template <typename A>
Array<A>::Array(int size, A value) {
    this->array_size = size; //* Setting the size of the array equal to the given size

    // Dynamic memory commitment
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Setting all the array's index positions equal to the given value
    for (int i=0; i<this->array_size; i++) {
        arr[i] = value; 
    }
}





// This is a copy constructor to help us deal with situations when we want to copy an object
template <typename A>
Array<A>::Array(const Array<A> &ob) {
    // The object we pass as an argument is the object that are going to copy fram
    this->array_size = ob.array_size; //* Setting the arrya size equal to the array size of the given array object

    // Creating the new array
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Pass the argumented object array values to the new one
    for (int i=0; i<this->array_size; i++) {
        arr[i] = ob.arr[i];
    }
}





// This is a copy destructor to help us auto dismiss the dynamic memory commitment
template <typename A>
Array<A>::~Array() {
    delete [] this->arr;
}





// This method giving us access to the array size, whenever we want
template <typename A>
int Array<A>::get_array_size() const {
    return this->array_size;
}





/*
    This method helps us to set the and modify the size of the array ( only increase it )
    The new indexes will take the given value as their value
*/
template <typename A>
void Array<A>::set_array_size(int size, A value) {
    //! Nessacary Condition
    if (size > 0 && size > this->array_size) {
        // Creating a temporary array to copy all the elements of the original array
        A *curr = new A [this->array_size];
        // Commitment condition
        if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

        // Setting the temporary arrar's values equal to the array ones
        int index;
        for (index = 0; index<this->array_size; index++) {
            curr[index] = arr[index];
        }
        
        // Dismiss the memory space that the old array was commiting
        delete [] arr;

        this->array_size = size; //* Setting the new array size ( to the given one )

        // Commit new memory space at the heap
        arr = new A [this->array_size];
        // Commitment condition
        if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

        // Pass all the values to the array
        for (int i=0; i<this->array_size; i++) {
            if (i >= index) {
                arr[i] = value;
            } else {
                arr[i] = curr[i];
            }
        }

        // Dismiss the memory space that the temporary array was commiting
        delete [] curr;
    }
    // Those are some restrictions ( lemitations ) to make our class more functional
    else if (size <= 0) {std::cout << "The array size must be bigger than 0" << std::endl;}
    else if (size <= this->array_size) {std::cout << "The given size must be heighter than the already one" << std::endl;}
}





// With this method we have access to each array element whenever we want
template <typename A>
A Array<A>::get_elem(int index) {
    //! Detairminig if the index is valid
    if (index >= 0 && index < this->array_size) {
        return this->arr[index];
    }
    std::cout << "Invalid index position" << std::endl;
    exit(0);
}





// This method is adding a value ( the given one ) at the end of the array 
template <typename A>
Array<A> &Array<A>::push_back(A value) {
    // Creating temporary array to hold the array's element
    A *curr = new A [this->array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Pass all the array's elements to the temporary one
    for (int i=0; i<this->array_size; i++) {
        curr[i] = arr[i];
    }

    // Dismiss the memory space that the old array was commiting
    delete [] arr;

    this->array_size ++; //* Increase the array's size by one 
    // Commit new memory space at the heap
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);} 

    // Copy all the values from the temporary array to the new array
    for (int i=0; i<this->array_size-1; i++) {
        arr[i] = curr[i];
    }
    arr[this->array_size - 1] = value; //* Adding the new value

    // Dismiss the memory space that the temporary array was commiting
    delete [] curr;

    return *this; //* Return the pointer that shows to this array object
}





// This array works the same as the push_back(), with the only difference that this one is adding the given value at the front of the array
template <typename A>
Array<A> &Array<A>::push_front(A value) {
    // Creating a new temporary array to copy the old one
    A *curr = new A [this->array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy all the array's elements to the temporary array
    for (int i=0; i<this->array_size; i++) {
        curr[i] = arr[i];
    }

    // Dismiss the memory space that the old array was commiting
    delete [] arr;

    this-array_size ++; //* Increase the arrya's size by one
    // Commit new memory space at the heap
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);} 

    // Copy all the element from the temporary array to the new one
    int index = 0;
    for (int i=1; i<this->array_size; i++) {
        arr[i] = curr[index];
        index ++;
    }
    arr[0] = value; //* Adding the new element at the array

    // Dismiss the memory space that the temporary array was commiting
    delete [] curr;

    return *this; //* Return the pointer that showing to this array object
}





// This method gives us the oportunity to add an element at a specific index position
template <typename A>
Array<A> &Array<A>::insert(int index, A value) {
    //! Determing if the index is a valid index
    if (index > this->array_size || index < 0) {
        std::cout << "Invalid Index Position: Index out of bounds" << std::endl;
        
        return *this; //* Return the pointer that showing to this array object
    }
    
    // Creating a temporary array to hold the original array's elements
    A *curr = new A [this->array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the array's elements to the temporary one
    for (int i=0; i<this->array_size; i++) {
        curr[i] = arr[i];
    }

    // Dismiss the memory space of the old array
    delete [] arr;

    this-array_size ++; //* Increase the array's size by one
    // Dynamic memory commitment to the array 
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);} 

    // Copy the element from the temporary array to the new array and add the new element at the given index
    int help_index = 0;
    for (int i=0; i<this->array_size; i++) {
        if (i == index) {
            arr[index] = value;
        } else {
            arr[i] = curr[help_index];
            help_index ++;
        }
    }

    // Dismiss the memory space of the temporary array
    delete [] curr;

    return *this; //* Return the pointer that showing to this array object
}





// This method is adding the argumented array to the end of this one
template <typename A>
Array<A> Array<A>::extend(const Array<A> aArray) {
    // Save the first array size
    int size = this->array_size;

    // Creating a temporary array to hold all the elements of this array
    A *curr = new A [this->array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the elements of the array to the temporary one
    for (int i=0; i<this->array_size; i++) {
        curr[i] = this->arr[i];
    }

    // Dismiss the memory space of the original array    
    delete [] this->arr;

    this->array_size += aArray.array_size; //* Set the new array size
    // Dynamicly memory commitment
    this->arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);} 

    // Add the element of the argumented array to the original one
    int helping_index = 0;
    for (int i=0; i<this->array_size; i++) {
        if (i > size-1) {
            this->arr[i] = aArray.arr[helping_index];
            helping_index ++;
        } else {
            this->arr[i] = curr[i];
        }
    }

    delete [] curr;
    return *this;
}





template <typename A>
Array<A> Array<A>::extend(const std::vector<A> aVector) {
    if (this->array_size == 0) {
        *this = aVector;
    }
    else {
        for (int i=0; i<aVector.size(); i++) {
            this->push_back(aVector[i]);
        }
    }

    return *this;
}





template <typename A>
Array<A> Array<A>::extend(const D_L_List<A> aList) {
    if (this->array_size == 0) {
        *this = aList;
    }
    else {
        for (int i=0; i<aList.get_size(); i++) {
            this->push_back(aList.get_element(i));
        }
    }

    return *this;
}





template <typename A>
Array<A> Array<A>::extend(const S_L_List<A> aList) {
    if (this->array_size == 0) {
        *this = aList;
    }
    else {
        for (int i=0; i<aList.get_size(); i++) {
            this->push_back(aList.get_elem(i));
        }
    }

    return *this;
}





// This method deleting the lats element of the array
template <typename A>
Array<A> &Array<A>::pop_back() {
    //! Length condition
    if (this->array_size == 0) {
        std::cout << "No elements to delete" << std::endl;
        
        return *this; //* Return the pointer that is showing to this objetc array
    }

    // Creating a temporary array to hold the elements of the original array
    A *curr = new A [this->array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the array's element to the temporary one
    for (int i=0; i<this->array_size; i++) {
        curr[i] = arr[i];
    }

    // Dismiss the memory space of the old array
    delete [] arr;

    this->array_size --; //* Decrease the array's size by one
    // Dynamic memory commitment to the new array
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);} 

    // Copy all the temporary array's elements except of the last one
    for (int i=0; i<this->array_size; i++) {
        arr[i] = curr[i];
    }

    // Dismiss the memory space of the temporary array
    delete [] curr;

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method is deleting the first element of the array
template <typename A>
Array<A> &Array<A>::pop_front() {
    //! Length condition
    if (this->array_size == 0) {
        std::cout << "No elements to delete" << std::endl;

        return *this; //* Return the pointer that is showing to this objetc array
    }

    // Creating a temporary array to hold the values of the original one
    A *curr = new A [this->array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the elements of the array to the temporary
    for (int i=0; i<this->array_size; i++) {
        curr[i] = arr[i];
    }

    // Dismiss the memory space of the array 
    delete [] arr;

    this->array_size --; //* Decrease the array's size by one
    // Dynamic memory commitment to the new array
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);} 

    // Copy all the temporary array's element ( except of the first one ) to the new array
    int help_index = 1;
    for (int i=0; i<this->array_size; i++) {
        arr[i] = curr[help_index];
        help_index ++;
    }

    // Dismiss the momory space of the temporary array
    delete [] curr;

    return *this; //* Return the pointer that is showing to this objetc array
}





// This array is deleting all the array's elements 
template <typename A>
Array<A> &Array<A>::clear() {
    //! Length condition
    if (this->array_size == 0) {
        return *this; //* Return the pointer that is showing to this objetc array
    }

    // Dismiss the memory space of the array at the heap
    delete [] arr;
    
    this->array_size = 0; //* Setting the size of the array back to zero
    // Dynamic memory commitment to the array
    arr = new A [array_size]; 
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method is deleting an element ( or more, default = 1 ) that is on a specific index positions 
template <typename A>
Array<A> &Array<A>::remove_by_index(int index, int total_pos) {
    //! Index condition
    if (index < 0 || index > this->array_size) {
        std::cout << "Invalid Index Position: Index out of bounds" << std::endl;

        return *this; //* Return the pointer that is showing to this objetc array
    }
    //! Length condition
    if (this->array_size == 0) {
        std::cout << "No elements to delete" << std::endl;
        
        return *this; //* Return the pointer that is showing to this objetc array
    }
    //! Total removes condition
    if (total_pos + index > this->array_size - 1) {
        std::cout << "Invalid removing position: Array has not such positions" << std::endl;

        return *this; //* Return the pointer that is showing to this objetc array
    }
    
    // Creating a temporary array to hold the values of the original one
    A *curr = new A [this->array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the elements of the array to the temporary one
    for (int i=0; i<this->array_size; i++) {
        curr[i] = arr[i];
    }

    // Dismiss the memory space of the old array
    delete [] arr;

    this->array_size -= total_pos+1; //* Decrease the array size by the given total index the user want to destroy
    // Dynamic memory commitment to the new array
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);} 

    // Copy the elements from the temporary array to the new one and remove the element at the given position
    int help_index = 0;
    for (int i=0; i<this->array_size; i++) {
        if (i == index) {
            help_index += total_pos+1;
        }
        arr[i] = curr[i + help_index];
    }

    // Dismiss the memory space of the temporary array
    delete [] curr;

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method is searching throught the array and deleting all ( or not ) the element with a specific value
template <typename A>
Array<A> &Array<A>::remove_by_value(A value, bool dupl, bool err) {
    //! Length condition
    if (this->array_size > 0) {
        // If the user want to remove all the duplications or not
        if (dupl) {
            int helping_index;
            for (int i=0; i<this->array_size; i++) {

                if (this->arr[i] == value) {
                    helping_index = i;

                    // Calling this function to delete the element at the given value's index position
                    remove_by_index(helping_index, 0);
                    i--;
                }
            }
            if (err) {
                // If the given value id not at the array
                if (helping_index > this->array_size || helping_index < 0) {
                    std::cout << "No such element at the array" << std::endl;
                }
            }
        }
        else {
            int helping_index;
            for (int i=0; i<this->array_size; i++) {
                if (arr[i] == value) {
                    helping_index = i;
                    // Calling this method to delete the first element who has the same value of the given one
                    remove_by_index(helping_index, 0);
                    break;
                }
            }
            if (err) {
                // If the element the user want to delete is not at the array
                if (helping_index > this->array_size || helping_index < 0) {
                    std::cout << "No such element at the array" << std::endl;
                }
            }
        }
    }
    else {
        // If the array's size = 0
        std::cout << "Array size = 0, no elements to remove" << std::endl;
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





template <typename A>
Array<A> &Array<A>::ndpl() {
    if (this->array_size != 0) {
        array<A> a = {this->arr[0]};

        for (int i=1; i<this->array_size; i++) {
            bool yes = false;
            for (int j=0; j<a.array_size; j++) {
                if (this->arr[i] == a[j]) {
                    yes = true;
                    break;
                }
            }

            if (!yes) {
                a.push_back(this->arr[i]);
            }
        }

        *this = a;

        return *this;
    }
    else {
        return *this;
    }
}





// This method is deleting all the duplicates and sorts the array
template <typename A>
Array<A> &Array<A>::set_with_sort() {
    // Call the sorting method
    sort();

    int index = 0; //* This helps us to calculate the new array's size

    // Creating a new temporary array to hold the arrays of the first array
    A *curr = new A [this->array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Get the total size of the new array and copy all the not duplicate array's elements to the temporary one
    for (int i=0; i<this->array_size; i++) {
        if (this->arr[i] != this->arr[i+1]) {
            curr[index] = this->arr[i];
            index++;
        }
    }

    this->array_size = index; //* Setting the new array size

    // Dismiss the memory space of the old array
    delete [] arr;

    // Commiting memory space at the heap
    this->arr = new A [this->array_size];
    // Commitment condition
    if (!this->arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Pass all the temporary array's elements to the new array
    for (int i=0; i<this->array_size; i++) {
        this->arr[i] = curr[i];
    }

    // Dismiss the memory space of the temporary array
    delete [] curr;

    return *this; //* Return the pointer that is showing to this objetc array
}





// This is the method that will sort the array
template <typename A>
Array<A> &Array<A>::sort() {
    // Sort with the sort by choice algorith
    for (int i=0; i<this->array_size; i++) {
        int j = i;
        A min = this->arr[j];

        for (int k=i+1; k<this->array_size; k++) {
            if (this->arr[k] < min) {
                j = k;
                min = this->arr[j];
            }
        }

        A temp = this->arr[i];
        this->arr[i]= this->arr[j];
        this->arr[j] = temp;
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method is going to sort the array backwords
template <typename A> 
Array<A> &Array<A>::reverse_sort() {
    for (int i=0; i<this->array_size; i++) {
        int j = i;
        A max = this->arr[j];

        for (int k=i+1; k<this->array_size; k++) {
            if (this->arr[k] > max) {
                j = k;
                max = this->arr[j];
            }
        }

        A temp = this->arr[i];
        this->arr[i] = this->arr[j];
        this->arr[j] = temp;
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method is reversing the array
template <typename A>
Array<A> &Array<A>::reverse() {
    // Get the total loops
    int size = this->array_size / 2; //* Must be the half because we are swaping the symetric elements

    for (int i=0; i<size; i++) {
        A temp = arr[i];
        arr[i] = arr[this->array_size-1-i];
        arr[this->array_size-1-i] = temp;
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method does the the same job as the copy constructor
template <typename A>
Array<A> Array<A>::copy(const Array<A> &ob) {
    //! Array Contdition
    if (arr) {
        // If the array exist we have to estroy it
        delete [] arr;
    }
    
    // Get the array size by the object we pass as the argument
    this->array_size = ob.array_size;

    // Commiting new memory space for the new array
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the elements of argumented array to the original one
    for (int i=0; i<this->array_size; i++) {
        arr[i] = ob.arr[i];
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





template <typename A>
Array<A> Array<A>::copy(const std::vector<A> &ob) {
    if (this->array_size != 0) {
        delete [] this->arr;
    }

    *this = ob;

    return *this;
}





template <typename A>
Array<A> Array<A>::copy(const D_L_List<A> &ob) {
    if (this->array_size != 0) {
        delete [] this->arr;
    }

    *this = ob;

    return *this;
}





template <typename A>
Array<A> Array<A>::copy(const S_L_List<A> &ob) {
    if (this->array_size != 0) {
        delete [] this->arr;
    }

    *this = ob;

    return *this;
}





// This method returns all the index positions of the given value
template <typename A>
Array<int> Array<A>::index(A value, bool nes) {
    // Create the returned array
    Array<int> Arr;

    //! Length condition
    if (this->array_size > 0) {
        for (int i=0; i<this->array_size; i++) {
            if (this->arr[i] == value) {
                Arr.push_back(i);
            }
        }

        // If not in array
        if (Arr.get_array_size() == 0) {
            Arr.push_back(-1);
        }
    }
    else {
        Arr.push_back(-1);
    }

    return Arr;
}





// This method is counting how many times the given value exist at the array
template <typename A>
int Array<A>::count(A value) {
    // Some usefull variables
    bool found = false;
    int count_var = 0;

    //! Length condition
    if (this->array_size > 0) {
        for (int i=0; i<this->array_size; i++) {
            if (this->arr[i] == value) {
                found = true;
                count_var ++;
            }
        }
        if (!found) {
            return 0;
        } 
    } 
    else {
        return 0;
    }

    return count_var; //* Return the counting valiable
}





// This method is returning the index of the given value
template <typename A>
int Array<A>::index(A value) {
    //! Length condition
    if (this->array_size > 0) {
        bool found = false; //* Helping var
        for (int i=0; i<this->array_size; i++) {
            if (this->arr[i] == value) {
                found = true;
                return i;
            }
        }
        if (!found) {
            return -1;
        } 
    } 
    else {
        return -1;
    }

    return EXIT_SUCCESS;
}





// This method is returning the first element of the array
template <typename A>
A Array<A>::first() {
    //! Lenght condition
    if (this->array_size == 0) {
        std::cout << "The array is empty" << std::endl;
        exit(0);
    } else {
        return arr[0];
    }
}





// This method is returning the last element of the array
template <typename A>
A Array<A>::last() {
    //! Lenght condition
    if (this->array_size == 0) {
        std::cout << "The array is empty" << std::endl;
        exit(0);
    } else {
        return arr[this->array_size - 1];
    }
}





// This mehtod overloads the = operatos
template <typename A>
Array<A> &Array<A>::operator=(const Array<A> &left) { 
    // If the two objects are already the same
    if (*this == left) {
        return *this; //* Return the pointer that is showing to this objetc array
    }

    //! If array exist
    if (this->arr) {
        delete [] arr;
    }
    
    // Get the new array size of the argumented object
    this->array_size = left.array_size;

    // Commiting memory space at the heap for the new array
    arr = new A [this->array_size];
    // Commitment condition
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Copy the elements of argumented array to the original array
    for (int i=0; i<this->array_size; i++) {
        arr[i] = left.arr[i];
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the = operator so we can fill the array with elements at decraration time
template <typename A>
Array<A> &Array<A>::operator=(const std::vector<A> &ob) {
    //! If array exist
    if (this->arr) {
        delete [] arr;
    }

    // Get the new array's size
    this->array_size = ob.size();

    // Commiting memory space at the heap
    arr = new A [this->array_size];
    // Commitmnet condiiton
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Fil the array with elements
    for (int i=0; i<this->array_size; i++) {
        arr[i] = ob[i];
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the = operator so we can fill the array with elements at decraration time
template <typename A>
Array<A> &Array<A>::operator=(const S_L_List<A> &ob) {
    //! If array exist
    if (this->arr) {
        delete [] arr;
    }

    // Get the new array's size
    this->array_size = ob.get_size();

    // Commiting memory space at the heap
    arr = new A [this->array_size];
    // Commitmnet condiiton
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Fil the array with elements
    for (int i=0; i<this->array_size; i++) {
        arr[i] = ob.get_elem(i);
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the = operator so we can fill the array with elements at decraration time
template <typename A>
Array<A> &Array<A>::operator=(const D_L_List<A> &ob) {
    //! If array exist
    if (this->arr) {
        delete [] arr;
    }

    // Get the new array's size
    this->array_size = ob.get_size();

    // Commiting memory space at the heap
    arr = new A [this->array_size];
    // Commitmnet condiiton
    if (!arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Fil the array with elements
    for (int i=0; i<this->array_size; i++) {
        arr[i] = ob.get_element(i);
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the == operator
template <typename A>
bool Array<A>::operator==(const Array<A> &left) {
    if (this->array_size == left.array_size) {
        bool equal = true;

        for (int i=0; i<this->array_size; i++) {
            if (arr[i] != left.arr[i]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            return true;
        } 
        else {
            return false;
        }
    } 
    else {
        return false;
    } 
}





// This method overloads the == operator
template <typename A>
bool Array<A>::operator==(const std::vector<A> &left) {
    if (this->array_size == left.size()) {
        bool equal = true;

        for (int i=0; i<this->array_size; i++) {
            if (arr[i] != left[i]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            return true;
        } 
        else {
            return false;
        }
    } 
    else {
        return false;
    } 
}





// This method overloads the == operator
template <typename A>
bool Array<A>::operator==(const D_L_List<A> &left) {
    if (this->array_size == left.get_size()) {
        bool equal = true;

        for (int i=0; i<this->array_size; i++) {
            if (arr[i] != left.get_element(i)) {
                equal = false;
                break;
            }
        }
        if (equal) {
            return true;
        } 
        else {
            return false;
        }
    } 
    else {
        return false;
    } 
}





// This method overloads the == operator
template <typename A>
bool Array<A>::operator==(const S_L_List<A> &left) {
    if (this->array_size == left.get_size()) {
        bool equal = true;

        for (int i=0; i<this->array_size; i++) {
            if (arr[i] != left.get_elem(i)) {
                equal = false;
                break;
            }
        }
        if (equal) {
            return true;
        } 
        else {
            return false;
        }
    } 
    else {
        return false;
    } 
}





// This method overloads the == operator
template <typename A>
bool Array<A>::operator!=(const Array<A> &left) {
    if (this->array_size == left.array_size) {
        bool equal = true;

        for (int i=0; i<this->array_size; i++) {
            if (arr[i] != left.arr[i]) {
                equal = false;
            }
        }
        if (equal) {
            return false;
        } 
        else {
            return true;
        }
    } 
    else {
        return true;
    } 
}





// This method overloads the == operator
template <typename A>
bool Array<A>::operator!=(const std::vector<A> &left) {
    if (this->array_size == left.size()) {
        bool equal = true;

        for (int i=0; i<this->array_size; i++) {
            if (arr[i] != left[i]) {
                equal = false;
            }
        }
        if (equal) {
            return false;
        } 
        else {
            return true;
        }
    } 
    else {
        return true;
    } 
}





// This method overloads the == operator
template <typename A>
bool Array<A>::operator!=(const D_L_List<A> &left) {
    if (*this == left) {
        return false;
    }

    return true;
}





// This method overloads the == operator
template <typename A>
bool Array<A>::operator!=(const S_L_List<A> &left) {
    if (*this == left) {
        return false;
    }

    return true;
}






// This method overloads the > operator
template <typename A>
bool Array<A>::operator>(const Array<A> &right) {
    if (this->array_size > right.array_size) {
        return true;
    } else {
        return false;
    }
}





// This method overloads the > operator
template <typename A>
bool Array<A>::operator>(const std::vector<A> &right) {
    if (this->array_size > right.size()) {
        return true;
    } else {
        return false;
    }
}





// This method overloads the > operator
template <typename A>
bool Array<A>::operator>(const D_L_List<A> &right) {
    if (this->array_size > right.get_size()) {
        return true;
    } else {
        return false;
    }
}





// This method overloads the > operator
template <typename A>
bool Array<A>::operator>(const S_L_List<A> &right) {
    if (this->array_size > right.get_size()) {
        return true;
    } else {
        return false;
    }
}





// This method overloads the >= operator
template <typename A>
bool Array<A>::operator>=(const Array<A> &right) {
    if (this->array_size < right.array_size) {
        return false;
    }
    else if (this->array_size > right.array_size) {
        return true;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the >= operator
template <typename A>
bool Array<A>::operator>=(const std::vector<A> &right) {
    if (this->array_size < right.size()) {
        return false;
    }
    else if (this->array_size > right.size()) {
        return true;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the >= operator
template <typename A>
bool Array<A>::operator>=(const D_L_List<A> &right) {
    if (this->array_size < right.get_size()) {
        return false;
    }
    else if (this->array_size > right.get_size()) {
        return true;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the >= operator
template <typename A>
bool Array<A>::operator>=(const S_L_List<A> &right) {
    if (this->array_size < right.get_size()) {
        return false;
    }
    else if (this->array_size > right.get_size()) {
        return true;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the <= operator
template <typename A>
bool Array<A>::operator<=(const Array<A> &right) {
    if (this->array_size < right.array_size) {
        return true;
    }
    else if (this->array_size > right.array_size) {
        return false;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the <= operator
template <typename A>
bool Array<A>::operator<=(const std::vector<A> &right) {
    if (this->array_size < right.size()) {
        return true;
    }
    else if (this->array_size > right.size()) {
        return false;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the <= operator
template <typename A>
bool Array<A>::operator<=(const D_L_List<A> &right) {
    if (this->array_size < right.get_size()) {
        return true;
    }
    else if (this->array_size > right.get_size()) {
        return false;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the <= operator
template <typename A>
bool Array<A>::operator<=(const S_L_List<A> &right) {
    if (this->array_size < right.get_size()) {
        return true;
    }
    else if (this->array_size > right.get_size()) {
        return false;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the < operator
template <typename A>
bool Array<A>::operator<(const Array<A> &right) {
    if (this->array_size < right.array_size) {
        return true;
    } else {
        return false;
    }
}





// This method overloads the < operator
template <typename A>
bool Array<A>::operator<(const std::vector<A> &right) {
    if (this->array_size < right.size()) {
        return true;
    } else {
        return false;
    }
}





// This method overloads the < operator
template <typename A>
bool Array<A>::operator<(const D_L_List<A> &right) {
    if (this->array_size < right.get_size()) {
        return true;
    } else {
        return false;
    }
}





// This method overloads the < operator
template <typename A>
bool Array<A>::operator<(const S_L_List<A> &right) {
    if (this->array_size < right.get_size()) {
        return true;
    } else {
        return false;
    }
}





// This method overloads the [] operator ( to have access at the array elements eazily )
template <typename A>
A &Array<A>::operator[](int index) {
    //! Index condition
    if (index < 0 || index >= this->array_size) {
        std::cout << "Invalid index position" << std::endl;
        exit(0);
    } 
    else {
        return this->arr[index];
    }
}





// This method overloads the += operator ( increase the size by the given value )
template <typename A>
Array<A> &Array<A>::operator+=(int value) {
    //! Value condition
    if (value < 0) {
        std::cout << "Given value must be bigger or equal than 0" << std::endl;

        return *this; //* Return the pointer that is showing to this objetc array
    }
    else {

        // Get the first array size 
        int size = this->array_size;

        // Creating a temporary array to hold all the arrya's elements
        A *curr = new A [size];
        // Commitment condiiton
        if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

        // Copy the array's elements to temporary array
        for (int i=0; i<this->array_size; i++) {
            curr[i] = this->arr[i];
        }

        // Dismiss the memory space of the old array
        delete [] arr; 

        this->array_size += value; //* Increase the new length by the value
        // Commit new memory space for the new arr
        arr = new A [this->array_size];

        // Copy the temporary array's valus to the new array and adding 0 to each new index position
        for (int i=0; i<this->array_size; i++) {
            if (i >= size) {
                // This helps us us this overloading operator with string data type
                if (sizeof(arr[i]) == 4 || sizeof(arr[i]) == 8) {
                    arr[i] = ' ' - 32;
                } else if (sizeof(arr[i]) == 1 || sizeof(arr[i]) == 24) {
                    arr[i] = '_';
                } 
            }
            else {
                arr[i] = curr[i];
            }
        }

        // Dismiss the temporary array's memory space
        delete [] curr;

        return *this; //* Return the pointer that is showing to this objetc array
    }
}





// This method overloads the += operator to extend the argumented array to this one
template <typename A>
Array<A> &Array<A>::operator+=(const Array<A> &right) {
    *this = this->extend(right);

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the += operator to extend the argumented array to this one
template <typename A>
Array<A> &Array<A>::operator+=(const std::vector<A> &right) {
    *this = this->extend(right);

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the += operator to extend the argumented array to this one
template <typename A>
Array<A> &Array<A>::operator+=(const D_L_List<A> &right) {
    *this = this->extend(right);

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the += operator to extend the argumented array to this one
template <typename A>
Array<A> &Array<A>::operator+=(const S_L_List<A> &right) {
    *this = this->extend(right);

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the -= operatos to delete the index positions starting at the start and going total_indexes indexes
template <typename A>
Array<A> &Array<A>::operator-=(int total_indexes) {
    //! Length condition
    if (this->get_array_size() < total_indexes) {
        std::cout << "No such elements to delete" << std::endl;
    }
    else {
        for (int i=0; i<total_indexes; i++) {
            this->pop_back();
        }
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the -= operator to delete the same elements between the argumented array and this array
template <typename A>
Array<A> &Array<A>::operator-=(const Array<A> &right) {
    if (*this == right) {
        this->clear();
    }
    for (int i=0; i<this->array_size; i++) {
        for (int j=0; j<right.array_size; j++) {
            if (this->arr[i] == right.arr[j]) {
                this->remove_by_value(this->arr[i], false, false);
            }
        }
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the -= operator to delete the same elements between the argumented array and this array
template <typename A>
Array<A> &Array<A>::operator-=(const std::vector<A> &right) {
    for (int i=0; i<this->array_size; i++) {
        for (int j=0; j<right.size(); j++) {
            if (this->arr[i] == right[j]) {
                this->remove_by_value(this->arr[i], false, false);
            }
        }
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the -= operator to delete the same elements between the argumented array and this array
template <typename A>
Array<A> &Array<A>::operator-=(const D_L_List<A> &right) {
    for (int i=0; i<this->array_size; i++) {
        for (int j=0; j<right.get_size(); j++) {
            if (this->arr[i] == right.get_element(j)) {
                this->remove_by_value(this->arr[i], false, false);
            }
        }
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the -= operator to delete the same elements between the argumented array and this array
template <typename A>
Array<A> &Array<A>::operator-=(const S_L_List<A> &right) {
    for (int i=0; i<this->array_size; i++) {
        for (int j=0; j<right.get_size(); j++) {
            if (this->arr[i] == right.get_elem(j)) {
                this->remove_by_value(this->arr[i], false, false);
            }
        }
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This method overloads the *= operator to copy this array total_copies times
template <typename A>
Array<A> &Array<A>::operator*=(int total_copies) {
    //! Given value condition
    if (total_copies == 0) {
        this->clear();

        return *this;
    }
    else if (total_copies < 0) {
        std::cout << "Only positive values are accepted" << std::endl;

        return *this;
    }

    int size = this->array_size;
    for (int i=0; i<total_copies - 1; i++) {
        for (int j=0; j<size; j++) {
            *this += 1;
            this->arr[this->array_size - 1] = this->arr[j];
        }
    }

    return *this; //* Return the pointer that is showing to this objetc array
}





// This function overloads th << operator to print the array at the console
template <typename U> 
std::ostream &operator<<(std::ostream &left, Array<U> &ob) {
    left << "[";
    for (int i=0; i<ob.array_size; i++) {
        if (ob.get_array_size() - 1 == i) {
            left << ob.arr[i];   
        }
        else {
            left << ob.arr[i] << ", "; 
        }
    }
    left << "]";

    return left; //* Return the left object, because in that case we can use the << operator many times at a line
}





// This function is overloading the >> operator ( adding items at the end of the array )
template <typename U> 
std::istream &operator>>(std::istream &left, Array<U> &ob) {
    // Creating a temporary array to hold the object array values
    U *curr = new U [ob.array_size];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    
    // Copy the element of the objetc array to the temporary one
    for (int i=0; i<ob.array_size; i++) {
        curr[i] = ob.arr[i];
    }

    // Dismiss the memory space of the original object array
    delete [] ob.arr;

    ob.array_size ++;  //* Increase the array size by one
    // Commit memory space at the heap for the new object array
    ob.arr = new U [ob.array_size];
    // Commitment condition
    if (!ob.arr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Get the user input
    U user_input;
    std::cout << "Enter value at " << ob.array_size - 1 << " index position: ";
    left >> user_input;

    // Copy the elements of the temporary array to the new object array
    for (int i=0; i<ob.array_size - 1; i++) {
        ob.arr[i] = curr[i];
    }
    ob.arr[ob.array_size - 1] = user_input; //* Add the user input at the end of the array 

    // Dismiss the memory space of the temporary array
    delete [] curr;

    return left; //* Return the left object, because in that case we can use the >> operator many times at a line
}




















//! ############################################################################################################################################ !\\

//!                                                   All The Linkded List's Class Mehtods                                                       !\\

//! ############################################################################################################################################ !\\



// This is the default constructor
template <typename L>
S_L_List<L>::S_L_List() {
    this->head = NULL;
}





// This is the constructor that takes elements as arguments
template <typename L>
S_L_List<L>::S_L_List(std::vector <L> v) {
    // Initialize the head pointer
    this->head = NULL;

    // Pass the argumented element to the list
    for (int i=0; i<v.size(); i++) {
        push_back(v[i]);
    }
}




// This constructor take as an argument an array
template <typename L>
S_L_List<L>::S_L_List(const array<L> &ob) {
    // Initialze the head pointer
    this->head = NULL;

    // Copy the elements
    for (int i=0; i<ob.get_array_size(); i++) {
        push_back(ob[i]);
    }
}





// This constructor take as an argument a double linked list
template <typename L>
S_L_List<L>::S_L_List(const D_L_List<L> &ob) {
    // Initialze the head pointer
    this->head = NULL;

    // Copy the elements
    for (int i=0; i<ob.get_size(); i++) {
        push_back(ob[i]);
    }
}






// This constructor help us initialize a list using {}
template <typename L>
S_L_List<L>::S_L_List(std::initializer_list <L> li) {
    // Initialize the head pointer
    this->head = NULL;

    // Copy the given elements
    for (int i=0; i<li.size(); i++) {
        push_back(*(li.begin() + i));
    }
}





// This constructor fill the list with some specific elements
template <typename L>
S_L_List<L>::S_L_List(int size, L value) {
    //! Size condition
    if (size < 0) {
        std::cout << "Invalid given size" << std::endl;
        this->head = NULL;
    }
    else {
        // Initialize the head pointer
        this->head = NULL;

        // Pass the given values to the list
        for (int i=0; i<size; i++) {
            push_back(value);
        }
    }
}





// This a copy constructor just in case
template <typename L>
S_L_List<L>::S_L_List(const S_L_List<L> &ob) {
    //! Given list length condition
    if (!ob.head) {
        std::cout << "THe given list is empty" << std::endl;
        this->head = NULL;
    }
    else {
        // Initialize the head pointer
        this->head = NULL;

        // Copy the values of the argumented list
        for (int i=0; i<ob.get_size(); i++) {
            push_back(ob.get_elem(i));                
        }
    }
}





// This method is returning the total length of the list
template <typename L>
int S_L_List<L>::get_size() const {
    // Create a new node pointer to iderate throught the list
    Node<L> *curr = this->head;
    int size = 0;
    // Get the list's size
    while (curr) {
        curr = curr->next;
        size ++;
    }

    return size; //* Equal to the size of the list
}





// This method returns an element of the list by a given index
template <typename L>
L S_L_List<L>::get_elem(int index) const {
    //! Index condition
    if (index > get_size() - 1 || index < 0) {
        std::cout << "Invalid index position" << std::endl;
    }
    else {
        //! Length condition
        if (!this->head) {
            std::cout << "The list is empty" << std::endl;
        }
        else {
            // Create a temporary node pointer
            Node<L> *curr = this->head;
            
            for (int i=0; i<index; i++) {
                curr = curr->next;
            }

            return curr->data; //* Return the element
        }
    }

    return EXIT_SUCCESS;
}





// This method is adding an element at the front of the list
template <typename L>
S_L_List<L> &S_L_List<L>::push_front(L user_data) {
    // Creating the new node
    Node<L> *new_node = new Node<L>;
    // Commitment condition
    if (!new_node) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    
    // Add the given data to the node
    new_node->data = user_data;

    // Point the new node at the same node that the head is pointing ( at the next node )
    new_node->next = this->head; 
    // Point the head node at the new node ( to add the new node at the list )
    this->head = new_node;

    return *this; //* Return the pointer that shows to this array object
}





// This method is adding an element at the end of the list
template <typename L>
S_L_List<L> &S_L_List<L>::push_back(L user_data) {
    // Creating a new node
    Node<L> *new_node = new Node<L>;
    // Commitment condition
    if (!new_node) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Add the given data to the new node
    new_node->data = user_data;
    new_node->next = NULL;

    // Detairming if the list is empty    
    if (!this->head) {
        this->head = new_node; //* Point the head pointer at the new node
    } 
    else {
        // Create a temporary node pointer and point it at the first element of the list point to interate throught the list
        Node<L> *temp = this->head;

        // Going at the end of the list
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node; //* Add the new element at the end of the list
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is inserting an element at to the given index position
template <typename L>
S_L_List<L> &S_L_List<L>::insert(int index, L value) {
    //! Index condition
    if (index > get_size() || index < 0) {
        std::cout << "Invalid index position" << std::endl;
    } 
    else if (index == 0) {
        push_front(value); //* Insert the value at the start of the array
    } 
    else if (index == get_size()) {
        push_back(value); //* Insert the new value at the end of the array
    } 
    else {
        Node<L> *curr = this->head; //* Point the temporary pointer at the first element of the list

        // Get to the element prior to the index position we want to insert the new node
        for (int i=0; i<index-1; i++) {
            curr = curr->next;
        }     

        // Creating the new node
        Node<L> *new_node = new Node<L>;
        // Commitment condition
        if (!new_node) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

        // Pass the given value to the new node
        new_node->data = value;
        // Point the new node to next ( from the given index position ) element memory location  
        new_node->next = curr->next;
        // Point the previous ( from the given insdex position ) element to the new node
        curr->next = new_node;
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is extending the list by another given one
template <typename L>
S_L_List<L> &S_L_List<L>::extend(const S_L_List<L> &list) {
    //! Given list length condition
    if (list.get_size() == 0) {
        std::cout << "Given list is empty" << std::endl;
    }
    else {
        for (int i=0; i<list.get_size(); i++) {
            push_back(list.get_elem(i));
        }
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is printing the values of the list
template <typename L>
void S_L_List<L>::print() {
    Node<L> *curr = this->head; //* Creating a new node pointer to iterate throught the list

    while (curr != NULL) {
        std::cout << curr->data << std::endl;
        // Change to the next node
        curr = curr->next;
    }
}





// This method is deleting the last element of the list
template <typename L>
S_L_List<L> &S_L_List<L>::pop_back() {
    if (!this->head) {
        std::cout << "The list is already empty" << std::endl;
    }
    else {
        // Create a new node pointer to iterate throught the list
        Node<L> *curr = this->head;
        
        for (int i=0; i<get_size() - 2; i++) {
            curr = curr->next; //* Going to the node before the last one 
        }
        curr->next = NULL; //* Set the previous node pointer NULL
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is deleting the first element of the list
template <typename L>
S_L_List<L> &S_L_List<L>::pop_front() {
    if (!this->head) {
        std::cout << "The list is already empty" << std::endl;
    }
    else {
        this->head = this->head->next; //* Skip the first element of the list
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is deleting an element by each index
template <typename L>
S_L_List<L> &S_L_List<L>::remove_by_index(int index, int total_pos) {
    //! Length condition
    if (!this->head) {
        std::cout << "The list is already empty" << std::endl;
    }
    else {
        //! Index condition
        if (index > get_size() - 1 || index < 0) {
            std::cout << "Invalid index position" << std::endl;
        }
        else if (index == get_size() - 1) {
            // get_size() - 1 is the index of the last element of the list
            pop_back();
        }
        else if (index == 0) {
            pop_front();
            for (int i=0; i<total_pos; i++) {
                pop_front();
            }
        }
        else if (index + total_pos > get_size()-1) {
            std::cout << "List has not such index position to delete" << std::endl;
        }
        else {
            // Create a new temporary node to iterate throught the list
            Node<L> *curr = this->head;

            // Go the node that is behind from the one that the user want to delete
            for (int i=0; i<index - 1; i++) {
                curr = curr->next;
            }

            // Create a new node to help us delete more than one elements at one
            Node<L> *temp = curr->next;

            // Go to the next wanted element of the list
            for (int i=0; i<total_pos; i++) {
                temp = temp->next;
            }
            curr->next = temp->next; //* Delete all the between nodes
        }
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is deleting nodes by each values
template <typename L>
S_L_List<L> &S_L_List<L>::remove_by_value(L value, bool dupl) {
    //! Length condition
    if (!this->head) {
        std::cout << "The list is already empty" << std::endl;
    }
    else {
        if (!dupl) {
            for (int i=0; i<get_size(); i++) {
                if (get_elem(i) == value) {
                    remove_by_index(i, 0); //* 0 is the total nodes after the given one ( because we only want to delete only the node of that node we pass 0 )
                    break;
                }
            }
        }
        else {
            for (int i=0; i<get_size(); i++) {
                if (get_elem(i) == value) {
                    remove_by_index(i, 0);
                    i--;
                }
            }
        }
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is clearing the list
template <typename L>
S_L_List<L> &S_L_List<L>::clear() { 
    //! Length condition
    if (!this->head) {
        std::cout << "The list is already empty" << std::endl;
    }
    else {
        this->head = NULL;
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is removing the duplicates and sort the list
template <typename L>
S_L_List<L> &S_L_List<L>::set_with_sort() {
    //! Length condition
    if (!this->head) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        // Sort the array 
        sort();
        // Create a new node pointer to iterate throught the list
        Node<L> *curr = this->head;
        // Get the total size of the list
        int size = get_size() - 1;
        // Start the removings
        for (int i=0; i<size; i++) {
            if (curr->data == curr->next->data) {
                remove_by_value(curr->data, false);
            }
            curr = curr->next; //* Point to the next node
        }
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is sorting the list ( Bubble Sort method )
template <typename L>
S_L_List<L> &S_L_List<L>::sort(){
    // Instead of moving the pointers to rearange the nodes, we can only swap the values 

    // Creating 2 temporary nodes pointer sto help us sort the list ( they will iterate throught the list )
    Node<L> *cur1 = this->head;
    Node<L> *cur2 = cur1->next;

    // The first pointer will point to all the nodes one time ( get their values )
    // The second pointer will be inside the second loop to compare the nodes with the node that the first pointer is pointing

    // Starting the Bubble Sort
    for (int i=0; i<get_size(); i++) {
        for (int j=0; j<get_size()-1; j++) {
            if (cur2->data > cur1->data) {
                // Swap the data of the nodes
                int temp = cur1->data;
                cur1->data = cur2->data;
                cur2->data = temp;
            }
            cur2 = cur2->next; //* Move the second pointer to the next node
        }
        cur1 = cur1->next; //* Get the next element of the list, via the first pointer
        cur2 = this->head; //* Face the second pointer at the start of the list
    } 

    return *this; //* Return the pointer that shows to this array object
}





// This method is going to sort the list in the oposite direktion
template <typename L>
S_L_List<L> &S_L_List<L>::reverse_sort() {
    // Instead of moving the pointers to rearange the nodes, we can only swap the values 

    // Creating 2 temporary nodes pointer sto help us sort the list ( they will iterate throught the list )
    Node<L> *cur1 = this->head;
    Node<L> *cur2 = cur1->next;

    // The first pointer will point to all the nodes one time ( get their values )
    // The second pointer will be inside the second loop to compare the nodes with the node that the first pointer is pointing

    // Starting the Bubble Sort
    for (int i=0; i<get_size(); i++) {
        for (int j=0; j<get_size()-1; j++) {
            if (cur2->data < cur1->data) {
                // Swap the data of the nodes
                int temp = cur1->data;
                cur1->data = cur2->data;
                cur2->data = temp;
            }
            cur2 = cur2->next; //* Move the second pointer to the next node
        }
        cur1 = cur1->next; //* Get the next element of the list, via the first pointer
        cur2 = this->head; //* Face the second pointer at the start of the list
    } 

    return *this; //* Return the pointer that shows to this array object
}





// This method is reversing the list
template <typename L>
S_L_List<L> &S_L_List<L>::reverse() {
    // Create 2 temporary node pointers to iterate throught the list and swap the values
    Node<L> *cur1 = this->head;
    Node<L> *cur2 = this->head;
    
    // Starting the reversing algorithm
    for (int i=0; i<(get_size() / 2); i++) {
        // Get the first element at ta variable
        int temp = cur1->data;
        // Set the first element equal to the last one
        cur1->data = get_elem(get_size() - 1 - i);
        
        // Go to the last node of the list
        for (int j=0; j<(get_size() - 1 - i); j++) {
            cur2 = cur2->next;
        }
        // Give the last node the first value
        cur2->data = temp;

        // Procced to the next node
        cur1 = cur1->next;
        // Reseat to find the new last element
        cur2 = this->head;
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is copying the 
template <typename L>
S_L_List<L> &S_L_List<L>::copy(const S_L_List<L> &ob) {
    //! Given list length condition
    if (!ob.head) {
        std::cout << "The given list is empty" << std::endl;
    }
    else if (*this == ob) {
        return *this;
    }
    else {
        // Deleting the current list
        this->head = NULL;
        
        // Pass the given list values to the the new one
        for (int i=0; i<ob.get_size(); i++) {
            push_back(ob.get_elem(i));
        }
    }

    return *this; //* Return the pointer that shows to this array object
}





// This method is counting how many times a certain value is appeard on the list
template <typename L>
int S_L_List<L>::count(L value) {
    int times = 0; //* The adding variable
    
    //! Length condition
    if (!this->head) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        // Start the procces
        for (int i=0; i<get_size(); i++) {
            if (get_elem(i) == value) {
                times++;
            }
        }
    }

    return times;
}





// This method return the first index position of the given value
template <typename L>
int S_L_List<L>::index(L value) {
    //! Length condition
    if (!this->head) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        // Start the process
        for (int i=0; i<get_size(); i++) {
            if (get_elem(i) == value) {
                return i;
            }
        }
    }

    return -1; //* Default return ( if not found )
}





// This method returns a list of the index positions
template <typename L>
S_L_List<int> S_L_List<L>::index(L value, bool nes) {
    // Create the returned list
    S_L_List<int> list;

    //! Length condiiton
    if (!this->head) {
        std::cout << "List is empty" << std::endl;
        list.push_back(-1);
    }
    else {
        for (int i=0; i<get_size(); i++) {
            if (get_elem(i) == value) {
                list.push_back(i);
            }
        }
        
        // If not in list
        if (list.get_size() == 0) {
            std::cout << "Element not in list" << std::endl;
            list.push_back(-1);
        }
    }

    return list;
}





// This method is returning the value of the first element of the list
template <typename L>
L S_L_List<L>::first() {
    //! Lenght condition
    if (!this->head) {
        std::cout << "List is empty" << std::endl;

        return -1;
    }
    else {
        return get_elem(0);
    }
}





// This method is returning the last element of the list
template <typename L>
L S_L_List<L>::last() {
    //! Length Condition
    if (!this->head) {
        std::cout << "List is empty" << std::endl;

        return -1;
    }
    else {
        return get_elem(get_size() - 1);
    }
}





// This is the = operator overloading
template <typename L>
S_L_List<L> &S_L_List<L>::operator=(const S_L_List<L> &right) {
    copy(right);

    return *this; //* Return the pointer that shows to this array object
}





// This is the == opeartor overloading methdod
template <typename L>
bool S_L_List<L>::operator==(const S_L_List<L> &right) {
    if (this->get_size() == right.get_size()) {
        for (int i=0; i<get_size(); i++) {
            if (get_elem(i) != right.get_elem(i)) {
                return false;
            }
        }
        
        return true;
    }
    else {
        return false;
    }
}





// This is the != operator overloading
template <typename L>
bool S_L_List<L>::operator!=(const S_L_List<L> &right) {
    if (*this == right) {
        return false;
    }

    return true;
}





// This is the > overloading operator
template <typename L>
bool S_L_List<L>::operator>(const S_L_List<L> &right) {
    if (get_size() > right.get_size()) {
        return true;
    }

    return false;
}





// This method overloads the >= operator
template <typename L>
bool S_L_List<L>::operator>=(const S_L_List<L> &right) {
    if (get_size() < right.get_size()) {
        return false;
    }
    else if (get_size() > right.get_size()) {
        return true;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the <= operator
template <typename L>
bool S_L_List<L>::operator<=(const S_L_List<L> &right) {
    if (get_size() < right.get_size()) {
        return true;
    }
    else if (get_size() > right.get_size()) {
        return false;
    }
    else {
        if (*this == right) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This is the < operator overloading
template <typename L>
bool S_L_List<L>::operator<(const S_L_List<L> &right) {
    if (*this > right || *this == right) {
        return false;
    }

    return true;
}





// This method is going to help us getting list element faster
template <typename L>
L &S_L_List<L>::operator[](int index) {
    //! Index condition
    if (index > this->get_size() - 1 || index < 0) {
        std::cout << "Invalid given index" << std::endl;
        exit(0);
    }
    else {
        Node<L> *curr = this->head;

        for (int i=0; i<index; i++) {
            curr = curr->next;
        }
        return curr->data;
    }
}





// This is an eazier extend method
template <typename L>
S_L_List<L> &S_L_List<L>::operator+=(S_L_List<L> &right) {
    extend(right);
}





// This is the same mehtod that the push back
template <typename L>
S_L_List<L> &S_L_List<L>::operator+=(L value) {
    push_back(value);


}



// This method is removing total_indexes from the back of the list
template <typename L>
S_L_List<L> &S_L_List<L>::operator-=(int total_indexes) {
    //! Length condition
    if (!this->head) {
        std::cout << "List is empty" << std::endl;
    }
    else if (total_indexes >= get_size()) {
        clear();
    }
    else if (total_indexes == 0) {
        std::cout << "Cant delete with 0" << std::endl;
    }
    else {
        /*
        Because we want to start at the back of the list and delete total nodes to the start
        We have to get modify ( calculate ) a way to use the remove_by_index method
        So we can get the start index position ( that would been the last element to be destroyed )
         and we delete total_index nodes from left to right ( those nodes would have been deleted 
         long after the node at the start index position )
        */
        int start = get_size() - total_indexes - 1; 
        // Active the method
        remove_by_index(start+1, total_indexes);
    }
}





// This method is deleting the same elements of the list and the given one
template <typename L>
S_L_List<L> &S_L_List<L>::operator-=(S_L_List<L> &ob) {
    for (int i=0; i<get_size(); i++) {
        for (int j=0; j<ob.get_size(); j++) {
            if (get_elem(i) == ob.get_elem(j)) {
                remove_by_index(i, 0);
            }
        }
    }
}





// This overloading method is copying the list total copies times
template <typename L>
S_L_List<L> &S_L_List<L>::operator*=(int total_copies) {
    //! Lenght condition
    if (!this->head) {
        std::cout << "List is empty" << std::endl;
    }
    //! Copyies conditiob
    else if (total_copies <= 0) {
        std::cout << "Allowed values ( 1,2,3,... )" << std::endl;
    }
    else {
        // Getting the first list size
        int size = get_size();

        for (int i=0; i<total_copies-1; i++) {
            for (int j=0; j<size; j++) {
                push_back(get_elem(j));
            }
        }
    }
}





// Printing the list on the screen
template <typename M>
std::ostream &operator<<(std::ostream &left, S_L_List<M> &right) {
    //! Length condition
    if (!right.head) {
        left << "[]";
    }
    else {
        left << "[";
        for (int i=0; i<right.get_size() - 1; i++) {
            left << right.get_elem(i) << ", ";
        }
        left << right[right.get_size() - 1] << "]";
    }

    return left;
}





// Add element at run time
template <typename M>
std::istream &operator>>(std::istream &left, S_L_List<M> &right) {
    // Get the user's input
    M user_input;
    std::cout << "Insert element at " << right.get_size() << " index position: ";
    left >> user_input; 

    // Append the input on the list
    right.push_back(user_input);

    return left;
}



















//! ############################################################################################################################################ !\\

//!                                                        All The Stack's Class Mehtods                                                         !\\

//! ############################################################################################################################################ !\\

//* Stack using the dynamic array data structur

// This is the default constructor
template <typename AS>
stack_array<AS>::stack_array() {
    // We pass -1 because we need the first element to be inserted to have the 0 index position
    this->top = -1;
}





// This constructor is taking us an argument a vector with elements to be inserted to the stack
template <typename AS>
stack_array<AS>::stack_array(std::vector<AS> v) {
    //! Vetcor condition
    if (v.size() == 0) {
        this->top = -1;
    }
    else {
        // Initialize the top index
        this->top = -1;

        // Append the vector elements to the stack
        for (int i=0; i<v.size(); i++) {
            stack.push_back(v[i]);
            this->top ++; //* Increase by one the index of the first element of the stack 
        }
    }
}





// This method helps us initialize a stack by using the {}
template <typename AS>
stack_array<AS>::stack_array(std::initializer_list<AS> asi) {
    // Initialize the top pointer
    this->top = -1;

    // Copy the given elements
    for (int i=0; i<asi.size(); i++) {
        stack.push_back(*(asi.begin() + i));
    }
}





// This constuctor is going to fill the stack with a given element size amount of times
template <typename AS>
stack_array<AS>::stack_array(int size, AS value) {
    //! Size condition
    if (size == 0) {
        this->top = -1;
    }
    else {
        // Initialize the top index
        this->top = -1;
        
        // Passing the value to the stack
        for (int i=0; i<size; i++) {
            stack.push_back(value);
            this->top ++;
        }
    }
}





// This is a copy constructor
template <typename AS>
stack_array<AS>::stack_array(const stack_array<AS> &ob) {
    //! Given stack size condition
    if (ob.top == -1) {
        this->top = -1; //* Making the stack empty
    }
    else if (ob.top == 0) {
        // Initialize the top index
        this->top = -1;
        
        // Add the first element of the given stack to this pne
        stack.push_back(ob.stack[0]);
        this->top ++; //* Inceament the top index
    }
    else {
        // Initialize the top index
        this->top = -1;
        
        // Adding the elements of the given stack to this one
        for (int i=0; i<ob.top+1; i++) {
            stack.push_back(ob.stack[i]);
            this->top ++;
        }
    }
}





// This method is adding an element at the end of the stack
template <typename AS>
stack_array<AS> &stack_array<AS>::push(AS value) {
    // Calling the push_back method from the array class
    stack.push_back(value);
    this->top ++; //* Icreament the top index position by one

    return *this;
}





// This method is deleting and returning the first element of the stack
template <typename AS>
AS stack_array<AS>::pop() {
    //! Stack size method
    if (this->top != -1) {
        // Storing the last element at a variable
        AS top_elem = stack.last();
        // Deleting the last element
        stack.pop_back();
        
        // Decrease the top index position by one
        this->top --;

        // Return the last element of the stack
        return top_elem;
    }
    else {
        std::cout << "Stack underflow" << std::endl;
        exit(0);
    }
}





// This method is returning the last element of the satck but not deleting it
template <typename AS>
AS stack_array<AS>::peek() {
    //! Length condition
    if (this->top == -1) {
        std::cout << "Stack is empty" << std::endl;
        exit(0);
    }
    else {
        return stack.last();
    }
}





// This is the = operator overloading 
template <typename AS>
stack_array<AS> &stack_array<AS>::operator=(stack_array<AS> &right) {
    //! Given stack size condition
    if (right.top == -1) {
        this->top = -1;
    }
    else {
        // Copy the given stack's values to the this stack
        for (int i=0; i<right.top; i++) {
            stack[i] = right.stack[i];
            this->top ++;
        }
    }

    return *this;
}





// This overloading method is printing the stack in the console
template <typename SA>
std::ostream &operator<<(std::ostream &left, stack_array<SA> &ob) {
    left << ob.stack;

    return left;
}





// This overloading method is getting the user input
template <typename SA>
std::istream &operator>>(std::istream &left, stack_array<SA> &ob) {
    left >> ob.stack;

    return left;
}












//* Stack using the linked list data structur

// This is the default constructor
template <typename LS>
stack_list<LS>::stack_list() {
    this->top = -1;
}





// This constructor has asargument a vector with elements
template <typename LS>
stack_list<LS>::stack_list(std::vector<LS> v) {
    //! Given vector length condition
    if (v.size() == 0) {
        this->top = -1;
    }
    else {
        // Initialize the top index
        this->top = -1;
        
        // Pass the elements of the vector to the stack
        for (int i=0; i<v.size(); i++) {
            stack.push_back(v[i]);
            this->top ++; //* Increament the top index by one 
        }
        
    }
}





// This method helps us initialize the stack using {}
template <typename LS>
stack_list<LS>::stack_list(std::initializer_list<LS> sli) {
    // Initialize the top pointer
    this->top = -1;

    // Copy the given elements
    for (int i=0; i<sli.size(); i++) {
        stack.push_back(*(sli.begin() + i));
    }
}





// This is a constuctor that fills the stack with same elements
template <typename LS>
stack_list<LS>::stack_list(int size, LS value) {
    //! Size condition
    if (size <= 0) {
        this->top = -1;
    }
    else {
        // Initialize the top index
        this->top = -1;

        // Add the elements to the stack
        for (int i=0; i<size; i++) {
            stack.push_back(value);
        } 
    }
}





// This is the copy constructor
template <typename LS>
stack_list<LS>::stack_list(const stack_list<LS> &ob) {
    //! Given stack length condition
    if (ob.top == -1) {
        this->top = -1;
    }
    else if (ob.top == 0) {
        this->top = 0;
        stack.push_back(ob.stack[0]);
    }
    else {
        // Initializε the top index
        this->top = -1;

        // Copy the given stack to the this one
        for (int i=0; i<ob.stack.get_size(); i++) {
            stack.push_back(ob.stack[i]);
            this->top ++; //* Increament the top index by one
        }
    }
}





// This method is adding an element at the end of the stack
template <typename LS>
stack_list<LS> &stack_list<LS>::push(LS value) {
    // Activate the method
    stack.push_back(value);
    this->top ++; //* Increase the top index by one

    return *this;
}




// This method is deleting and returning the last element of the stack
template <typename LS>
LS stack_list<LS>::pop() {
    //! Stack size condition
    if (this->top != -1) {
        // Store the last element at a valieable
        LS top_elem = stack.last();
        // Deleting the last element
        stack.pop_back();

        // Decrease the top index by one
        this->top --;

        // Return the deleted element
        return top_elem;   
    }
    else {
        std::cout << "Stack underflow" << std::endl;
        exit(0);
    }
}





// This method returnong the top element of the stack, without deleting it
template <typename LS>
LS stack_list<LS>::peek() {
    //! Length condition
    if (this->top == -1) {
        std::cout << "Stack is empty" << std::endl;
        exit(0);
    }
    else {
        return stack.last();
    }
}





// This is the = operator overloading 
template <typename LS>
stack_list<LS> &stack_list<LS>::operator=(stack_list<LS> &right) {
    //! Given stack size condition
    if (right.top == -1) {
        this->top = -1;
    }
    else {
        // Initializ the new top index
        this->top = -1;

        // Copy the given stack's values to the this stack
        for (int i=0; i<right.top; i++) {
            stack.push_back(right.stack[i]);
            this->top ++;
        }
    }

    return *this;
}





// This overloading method is printing the stack in the console
template <typename SL>
std::ostream &operator<<(std::ostream &left, stack_list<SL> &ob) {
    left << ob.stack;

    return left;
}





// This overloading method is getting the user input
template <typename SL>
std::istream &operator>>(std::istream &left, stack_list<SL> &ob) {
    left >> ob.stack;

    return left;
}



















//! ############################################################################################################################################ !\\

//!                                                        All The Queue's Class Mehtods                                                         !\\

//! ############################################################################################################################################ !\\

//* Queue using the array data structur

// This is the default constructor
template <typename AQ>
queue_array<AQ>::queue_array() {
    this->back = -1;
}





// This constructor contains as arguments the values that will be fill the queue
template <typename AQ>
queue_array<AQ>::queue_array(const std::vector<AQ> &v) {
    // Initialize the indexes
    this->back = -1;

    // Pass the vector values to the queue
    for (int i=0; i<v.size(); i++) {
        queue.push_back(v[i]);
        this->back ++; //* Increase the back index by one
    }
}





// This method helps us initialize the queue using {}
template <typename AQ>
queue_array<AQ>::queue_array(std::initializer_list<AQ> qai) {
    // Initialize the back pointer
    this->back = -1;

    // Copy the given elements
    for (int i=0; i<qai.size(); i++) {
        queue.push_back(*(qai.begin() + i));
    }
}





// This constructor is filling the queue with elements
template <typename AQ>
queue_array<AQ>::queue_array(int size, AQ value) {
    // Initialize the indexes
    this->back = -1;

    // Fill the stack with the given value
    for (int i=0; i<size; i++) {
        queue.push_back(value);
        this->back ++; //* Increase the back index by one
    }
}





// This is the copy constructor
template <typename AQ>
queue_array<AQ>::queue_array(const queue_array<AQ> &ob) {
    // Initialize the indexes
    this->back = -1;

    // Pass the values of the given queue to this one
    for (int i=0; i<ob.back + 1; i++) {
        queue.push_back(ob.queue[i]);
        this->back ++; //* Increase the back index by one
    } 
}





// This method is adding an element at the end of the queue
template <typename AQ>
queue_array<AQ> &queue_array<AQ>::enqueue(AQ value) {
    // Activate the method
    queue.push_back(value);
    this->back ++; //* Increase the top index by one

    return *this;
}




// This method is deleting and returning the last element of the queue
template <typename AQ>
AQ queue_array<AQ>::dequeue() {
    //! Stack size condition
    if (this->back != -1) {
        // Store the last element at a variable
        AQ first_elem = queue.first();
        // Deleting the last element
        queue.pop_front();

        // Decrease the queue size by one
        this->back --;

        // Return the deleted element
        return first_elem;   
    }
    else {
        std::cout << "Queue underflow" << std::endl;
        exit(0);
    }
}





// This method returnong the top element of the queue, without deleting it
template <typename AQ>
AQ queue_array<AQ>::peek() {
    //! Length condition
    if (this->back == -1) {
        std::cout << "Queue is empty" << std::endl;
        exit(0);
    }
    else {
        return queue.first();
    }
}





// This is the = operator overloading 
template <typename AQ>
queue_array<AQ> &queue_array<AQ>::operator=(queue_array<AQ> &right) {
    //! Given stack size condition
    if (right.back == -1) {
        this->back = -1;
    }
    else {
        // Initializ the new top index
        this->back = -1;

        // Copy the given queue's values to the this queue
        for (int i=0; i<right.back+1; i++) {
            queue.push_back(right.queue[i]);
            this->back ++;
        }
    }

    return *this;


}



// This overloading method is printing the queue in the console
template <typename QA>
std::ostream &operator<<(std::ostream &left, queue_array<QA> &ob) {
    left << ob.queue;

    return left;
}





// This overloading method is getting the user input
template <typename QA>
std::istream &operator>>(std::istream &left, queue_array<QA> &ob) {
    left >> ob.queue;

    return left;
}












//* Queue using the linked list data structur

// This is the default constructor
template <typename LQ>
queue_list<LQ>::queue_list() {
    this->back = -1;
}





// This constructor contains as arguments the values that will be fill the queue
template <typename LQ>
queue_list<LQ>::queue_list(const std::vector<LQ> &v) {
    // Initialize the indexes
    this->back = -1;

    // Pass the vector values to the queue
    for (int i=0; i<v.size(); i++) {
        queue.push_back(v[i]);
        this->back ++; //* Increase the back index by one
    }
}





// This method helps us initialize the queue using {}
template <typename LQ>
queue_list<LQ>::queue_list(std::initializer_list<LQ> qli) {
    // Initialize the back pointer
    this->back = -1;

    // Copy the given elements
    for (int i=0; i<qli.size(); i++) {
        queue.push_back(*(qli.begin() + i));
    }
}





// This constructor is filling the queue with elements
template <typename LQ>
queue_list<LQ>::queue_list(int size, LQ value) {
    // Initialize the indexes
    this->back = -1;

    // Fill the stack with the given value
    for (int i=0; i<size; i++) {
        queue.push_back(value);
        this->back ++; //* Increase the back index by one
    }
}





// This is the copy constructor
template <typename LQ>
queue_list<LQ>::queue_list(const queue_list<LQ> &ob) {
    // Initialize the indexes
    this->back = -1;

    // Pass the values of the given queue to this one
    for (int i=0; i<ob.back + 1; i++) {
        queue.push_back(ob.queue[i]);
        this->back ++; //* Increase the back index by one
    } 
}





// This method is adding an element at the end of the queue
template <typename LQ>
queue_list<LQ> &queue_list<LQ>::enqueue(LQ value) {
    // Activate the method
    queue.push_back(value);
    this->back ++; //* Increase the top index by one

    return *this;
}




// This method is deleting and returning the last element of the queue
template <typename LQ>
LQ queue_list<LQ>::dequeue() {
    //! Stack size condition
    if (this->back != -1) {
        // Store the last element at a variable
        LQ first_elem = queue.first();
        // Deleting the last element
        queue.pop_front();

        // Decrease the queue size by one
        this->back --;

        // Return the deleted element
        return first_elem;   
    }
    else {
        std::cout << "Queue underflow" << std::endl;
        exit(0);
    }
}





// This method returnong the top element of the queue, without deleting it
template <typename LQ>
LQ queue_list<LQ>::peek() {
    //! Length condition
    if (this->back == -1) {
        std::cout << "Queue is empty" << std::endl;
        exit(0);
    }
    else {
        return queue.first();
    }
}





// This is the = operator overloading 
template <typename LQ>
queue_list<LQ> &queue_list<LQ>::operator=(queue_list<LQ> &right) {
    //! Given stack size condition
    if (right.back == -1) {
        this->back = -1;
    }
    else {
        // Initializ the new top index
        this->back = -1;

        // Copy the given queue's values to the this queue
        for (int i=0; i<right.back+1; i++) {
            queue.push_back(right.queue[i]);
            this->back ++;
        }
    }

    return *this;
}





// This overloading method is printing the queue in the console
template <typename QL>
std::ostream &operator<<(std::ostream &left, queue_list<QL> &ob) {
    left << ob.queue;

    return left;
}





// This overloading method is getting the user input
template <typename QL>
std::istream &operator>>(std::istream &left, queue_list<QL> &ob) {
    left >> ob.queue;

    return left;
}



















//! ############################################################################################################################################ !\\

//!                                                       All The 2D Array's Class Mehtods                                                       !\\

//! ############################################################################################################################################ !\\



/*
    This is the block of code that extend dynamicly the size of the array
    This block of code we have to write when we want to modify the array
    This way we can have access to this code via a method call
*/
template <typename A2D>
void array_2d<A2D>::expand_array(int rows, int columns) {
    //! Row Condition
    if (rows < 0 || rows < this->rows) {
        std::cout << "Row index must be heighter both than 0 and the previous array row number" << std::endl;
        exit(0);
    }
    //! Column Condition
    if (columns < 0 || columns < this->columns) {
        std::cout << "Column index must be heighter both than 0 and the previous array column number" << std::endl;
        exit(0);
    }
    
    // Store the previous array size
    int pre_rows = this->rows;
    int pre_columns = this->columns;

    // If the array already exist we need to create a temporary one to store it's values
    A2D **curr = new A2D *[this->rows];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Now we need to create the inside arrays
    for (int i=0; i<this->columns; i++) {
        curr[i] = new A2D [this->columns];
        // Commitment condition
        if (!curr[i]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}    
    }

    // Copying the elements of the array to the temporary array
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            curr[i][j] = this->array_of_pointers[i][j];
        }
    }

    // Dismiss the memory space of the array
    for (int i=0; i<this->rows; i++) {
        delete [] this->array_of_pointers[i];
    }
    delete [] this->array_of_pointers;



    // Pass the new values to the size of the array
    this->rows = rows;
    this->columns = columns;

    // Creating the new array
    this->array_of_pointers = new A2D *[this->rows];
    // Commtimnet condition
    if (!this->array_of_pointers) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Creating the inside arrays
    for (int i=0; i<this->rows; i++) {
        this->array_of_pointers[i] = new A2D [this->columns];
        // Commitment condition
        if (!this->array_of_pointers[i]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    }

    // Assign the temporary array values to the new array
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            if (j >= pre_columns || i >= pre_rows) {
                if (sizeof(A2D) == 1 || sizeof(A2D) == 24) {
                    this->array_of_pointers[i][j] = '_';
                }
                else if (sizeof(A2D) == 4 || sizeof(A2D) == 8) {
                    this->array_of_pointers[i][j] = ' ' - 32;
                }
            }
            else {
                this->array_of_pointers[i][j] = curr[i][j];
            }
        }
    }

    // Deleting the temporary array
    for (int i=0; i<pre_rows; i++) {
        delete [] curr[i];
    }
    delete [] curr;
}





// This is the default constructor
template <typename A2D>
array_2d<A2D>::array_2d() {
    // Initialize the class members
    this->array_of_pointers = NULL;
    this->rows = 0;
    this->columns = 0;
}





// This constructor is taking as arguments a vector with elements
template <typename A2D>
array_2d<A2D>::array_2d(std::vector<std::vector<A2D>> &v) {
    // Pass the total number of rows from the given vector to the 2d array
    this->rows = v.size();
    
    // Pass the number of columns of the first rows from the vector
    this->columns = v[0].size();
    
    // Creating the for loop to get the max number of elements per row from the vector
    for (int i=1; i<v.size(); i++) {
        // Get the maximum numver of the vector columns
        if (this->columns < v[i].size()) {
            this->columns = v[i].size(); //* Get the maximum number of columns
        }
    }

    // Create the array of arrays ( by commiting memory space at the heap, dynamicly )
    this->array_of_pointers = new A2D *[this->columns];
    // Commitment condition
    if (!this->array_of_pointers) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // For each row of the 2d array we need to create another array to store the current row elements
    for (int i=0; i<this->rows; i++) {
        this->array_of_pointers[i] = new A2D [this->columns];
        // Commitment condition
        if (!this->array_of_pointers[i]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    }

    // Copy the 2d vector elements to the 2d array
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            if (j >= v[i].size()) {
                if (sizeof(A2D) == 1 || sizeof(A2D) == 24) {
                    this->array_of_pointers[i][j] = '_';
                }
                else if (sizeof(A2D) == 4 || sizeof(A2D) == 8) {
                    this->array_of_pointers[i][j] = ' ' - 32;
                }
            }
            else {
                this->array_of_pointers[i][j] = v[i][j];
            }
        }
    }
}





// This mehtod helps us initialize an array using {}
template <typename A2D>
array_2d<A2D>::array_2d(std::initializer_list<std::initializer_list<A2D>> a2di) {
    // Get the number of rows
    this->rows = a2di.size();

    // Getting the max number of columns
    this->columns = a2di.begin()->size();
    for (int i=0; i<this->rows; i++) {
        if (this->columns < (a2di.begin() + i)->size()) {
            this->columns = (a2di.begin() + i)->size();
        }
    }

    // Create the 2d array
    this->array_of_pointers = new A2D *[this->rows];
    // Commitment condition
    if (!this->array_of_pointers) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    
    // Create the inside arrays
    for (int i=0; i<this->rows; i++) {
        this->array_of_pointers[i] = new A2D [this->columns];
        // Commitment condition
        if (!this->array_of_pointers[i]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    }

    // Copy to the 2d array the given elements
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            if (j >= (a2di.begin() + i)->size()) {
                if (sizeof(A2D) == 1 || sizeof(A2D) == 24) {
                    this->array_of_pointers[i][j] = '_';
                }
                else if (sizeof(A2D) == 4 || sizeof(A2D) == 8) {
                    this->array_of_pointers[i][j] = ' ' - 32;
                }
            }
            else {
                this->array_of_pointers[i][j] = *((a2di.begin() + i)->begin() + j);
            }
        }
    }

}





// This constructor is filling the array with one element
template <typename A2D>
array_2d<A2D>::array_2d(int rows, int columns, A2D value) {
    // Initialize the size of the array
    this->rows = rows;
    this->columns = columns;

    // Create the array that will store pointers that will point to another array
    this->array_of_pointers = new A2D *[this->rows];
    // Commitment condition
    if (!this->array_of_pointers) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Creating the arrays that the pointers of the first array will pointing
    for (int i=0; i<this->columns; i++) {
        this->array_of_pointers[i] = new A2D [this->columns]; //* Commit space at the heap
        // Commitment condition
        if (!this->array_of_pointers[i]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    }

    // Now its time to add the values to the 2d array
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            this->array_of_pointers[i][j] = value;
        }
    }
}





// This is the copy constructor
template <typename A2D>
array_2d<A2D>::array_2d(const array_2d<A2D> &ob) {
    // Initialize the size of the array
    this->rows = ob.rows;
    this->columns = ob.columns;

    // Creating the array that will store array pointers
    this->array_of_pointers = new A2D *[this->rows];
    // Commitment condition
    if (!this->array_of_pointers) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Creating the arrays of each pointer array inside the first array
    for (int i=0; i<this->columns; i++) {
        this->array_of_pointers[i] = new A2D [this->columns];
        // Commitment condition
        if (!this->array_of_pointers[i]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    }

    // Copy the given array's elements to this 2d array
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            this->array_of_pointers[i][j] = ob.array_of_pointers[i][j];
        }
    }
}





// This is the destructor that will dismiss all the memory space of our array
template <typename A2D>
array_2d<A2D>::~array_2d() {
    // First we need to dismiss the memory commitment of the inside arrays
    for (int i=0; i<this->rows; i++) {
        delete [] this->array_of_pointers[i];
    }
    // Then we are ready to delete the first array
    delete [] this->array_of_pointers;
}





// This method returns the number of rows
template <typename A2D>
int array_2d<A2D>::get_row_size() const {
    return this->rows;
}





// This method returns the number of columns
template <typename A2D>
int array_2d<A2D>::get_column_size() const {
    return this->columns;
}





// This method is returning an element from the array
template <typename A2D>
A2D array_2d<A2D>::get_element(int row, int column) const {
    //! Row Condition
    if (row > this->rows - 1 || row < 0) {
        std::cout << "Row out of bounds" << std::endl;
        exit(0);
    }
    //! Colunmn Codntion
    if (column > this->columns - 1 || column < 0) {
        std::cout << "Column out of bounds" << std::endl;
        exit(0);
    }

    return this->array_of_pointers[row][column];
}





// This method set's the array size
template <typename A2D>
void array_2d<A2D>::set_array_size(int rows, int columns) {
    expand_array(rows, columns);
}





// This method is inserting a new row at a given position and assign it to the given vector values
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::insert_row(int row_index, const std::vector<A2D> &v) {
    //! Row index condition
    if (row_index > this->rows || row_index < 0) {
        std::cout << "Invalid row index position" << std::endl;
        exit(0);
    }

    // Pass the size of the array to those variables
    int pre_row = this->rows;
    int pre_cols = this->columns;

    // Creating the new row
    expand_array(pre_row + 1, pre_cols);

    // This takes the new row from the back of the array to the given index position and push all the other one index right 
    for (int i=row_index; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            A2D temp = this->array_of_pointers[row_index][j];
            this->array_of_pointers[row_index][j] = this->array_of_pointers[i][j];
            this->array_of_pointers[i][j] = temp; 
        }
    }

    // Take the size for looping ( this exeptions is when we working with strings )
    int size;
    if (v.size() > this->columns) {
        size = this->columns;
    }
    else {
        size = v.size();
    }

    // Add the vector to the correct row of the 2d array
    for (int i=0; i<size; i++) {
        this->array_of_pointers[row_index][i] = v[i];
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This is an overloading method to help us insert a row with same elements 
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::insert_row(int row_index, A2D value) {
    //! Row index condition
    if (row_index > this->rows || row_index < 0) {
        std::cout << "Invalid row index position" << std::endl;
        exit(0);
    }

    int pre_row, pre_cols;

    //! Row index conditon
    if (this->columns == 0) {
        pre_row = this->rows;
        pre_cols = 1;
    }
    else {
        // Pass the size of the array to those variables
        pre_row = this->rows;
        pre_cols = this->columns;
    }

    // Creating the new row
    expand_array(pre_row + 1, pre_cols);

    // This takes the new row from the back of the array to the given index position and push all the other one index right
    for (int i=row_index; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            A2D temp = this->array_of_pointers[row_index][j];
            this->array_of_pointers[row_index][j] = this->array_of_pointers[i][j];
            this->array_of_pointers[i][j] = temp; 
        }
    }

    // Add the elements to the array
    for (int i=0; i<this->columns; i++) {
        this->array_of_pointers[row_index][i] = value;
    }

    return *this; //* Return the pointer that is pointing to the object we are working 
}





// This method add a new column to the array 
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::insert_column(int column_index, const std::vector<A2D> &v) {
    //! Column index condition
    if (column_index > this->columns || column_index < 0) {
        std::cout << "Invalid column index position" << std::endl;
        exit(0);
    }  

    int pre_row, pre_cols;

    //! Row size condition
    if (this->rows == 0) {
        pre_row = 1;
        pre_cols = this->columns;
    }
    else {
        // Pass the size of the array to those variables
        pre_row = this->rows;
        pre_cols = this->columns;
    }

    // Extend the array size
    expand_array(pre_row, pre_cols + 1);

    // This block of code put the new column to the correct place and push all the other column to the right
    for (int i=0; i<this->rows; i++) {
        for (int j=column_index; j<this->columns; j++) {
            A2D temp = this->array_of_pointers[i][column_index];
            this->array_of_pointers[i][column_index] = this->array_of_pointers[i][j];
            this->array_of_pointers[i][j] = temp; 
        }
    }

    // Take the size for looping ( this exeptions is when we working with strings )
    int size;
    if (v.size() > this->rows) {
        size = this->rows;
    }
    else {
        size = v.size();
    }

    // Add the vector to the correct row of the 2d array
    for (int i=0; i<size; i++) {
        this->array_of_pointers[i][column_index] = v[i];
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This is an overloading method to help us insert a column with same elements 
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::insert_column(int column_index, A2D value) {
    //! Column index condition
    if (column_index > this->columns || column_index < 0) {
        std::cout << "Invalid column index position" << std::endl;
        exit(0);
    }

    // Pass the size of the array to those variables
    int pre_row = this->rows;
    int pre_cols = this->columns;

    // Creating the new row
    expand_array(pre_row, pre_cols+1);

    // This takes the new column from the back of the array to the given index position and push all the other one index right
    for (int i=0; i<this->rows; i++) {
        for (int j=column_index; j<this->columns; j++) {
            A2D temp = this->array_of_pointers[i][column_index];
            this->array_of_pointers[i][column_index] = this->array_of_pointers[i][j];
            this->array_of_pointers[i][j] = temp; 
        }
    }

    // Add the elements to the array
    for (int i=0; i<this->rows; i++) {
        this->array_of_pointers[i][column_index] = value;
    }


    return *this; //* Return the pointer that is pointing to the object we are working
}





// This mehtod add an element at a specific place
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::insert_element(int row_index, int column_index, A2D element) {
    //! Row index condition
    if (row_index > this->rows - 1 || row_index < 0) {
        std::cout << "Invalid row index position" << std::endl;
        exit(0);
    }
    //! Column index condition
    if (column_index > this->columns || column_index < 0) {
        std::cout << "Invalid column index position" << std::endl;
        exit(0);
    }

    // Pass the size of the array to those variables
    int pre_row = this->rows;
    int pre_cols = this->columns;

    // Creating the new row
    if (this->rows == 0 && this->columns == 0) {
        expand_array(pre_row+1, pre_cols+1);
    }
    else {
        expand_array(pre_row, pre_cols+1);
    }

    for (int j=column_index; j<this->columns; j++) {
        A2D temp = this->array_of_pointers[row_index][column_index];
        this->array_of_pointers[row_index][column_index] = this->array_of_pointers[row_index][j];
        this->array_of_pointers[row_index][j] = temp;
    }
    // Add the new element
    this->array_of_pointers[row_index][column_index] = element;

    return *this; //* Return the pointer that is pointing to the object we are working    
}





// This method deletes a hole row out of the array
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::delete_row(int row_index) {
    //! If array empty
    if (this->rows == 0 || this->columns == 0) {
        std::cout << "Array is empty" << std::endl;
        exit(0);
    }
    //! Row index condition
    if (row_index > this->rows - 1 || row_index < 0) {
        std::cout << "Invalid row index position" << std::endl;
        exit(0);
    }

    // Get the index row at the end of the array to delete it
    for (int i=row_index; i<this->rows-1; i++) {
        A2D *temp = this->array_of_pointers[i]; 
        this->array_of_pointers[i] = this->array_of_pointers[i+1];
        this->array_of_pointers[i+1] = temp;
    }

    // Delete the given index row
    delete [] array_of_pointers[this->rows - 1];

    this->rows --; //* Decrease the array rows by one

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method delete an entire column
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::delete_column(int column_index) {
    //! If array empty
    if (this->rows == 0 || this->columns == 0) {
        std::cout << "Array is empty" << std::endl;
        exit(0);
    }
    //! Column index condition
    if (column_index > this->columns - 1 || columns < 0) {
        std::cout << "Invalid column index position" << std::endl;
        exit(0);
    }

    // Create a new temporary pointer that will point at an array full od array pointers
    A2D **curr = new A2D *[this->rows];
    // Commitment condition
    if (!curr) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Creating the array pointers
    for (int i=0; i<this->rows; i++) {
        curr[i] = new A2D [this->columns];
        // Commitment condition
        if (!curr[i]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    }

    // Copy the array values to this temporary array
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            curr[i][j] = this->array_of_pointers[i][j];
        }
    }

    // Delete the 2d array to rebuilt it
    for (int i=0; i<this->rows; i++) {
        delete [] this->array_of_pointers[i];
    }
    delete [] this->array_of_pointers;

    // Pass the new value to the number of columns of the array
    this->columns --;

    // Commiting new memory space for the array
    this->array_of_pointers = new A2D *[this->rows];
    // Commitment condition
    if (!this->array_of_pointers) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Creating the inside arrays
    for (int i=0; i<this->rows; i++) {
        this->array_of_pointers[i] = new A2D [this->columns];
        // Commitment condition
        if (!this->array_of_pointers[i]) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}
    }

    // Copy to this new array the elements of the temporary array
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            int helping_index = j+1; //* Helps us remove the first element
            if (j >= column_index) {
                this->array_of_pointers[i][j] = curr[i][helping_index];
            }
            else {
                this->array_of_pointers[i][j] = curr[i][j];
            }
            
        }
    }

    // Dismiss the memory space of the temporary array
    for (int i=0; i<this->rows; i++) {
        delete [] curr[i];
    }
    delete [] curr;

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method is deleting an element from the array by it's index
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::delete_element_by_index(int row_index, int column_index) {
    //! If array empty
    if (this->rows == 0 || this->columns == 0) {
        std::cout << "Array is empty" << std::endl;
        exit(0);
    }
    //! Row index condition
    if (row_index > this->rows || row_index < 0) {
        std::cout << "Invalid row index condition" << std::endl;
        exit(0);
    }
    //! Column index condition
    if (column_index > this->columns || column_index < 0) {
        std::cout << "Invalid column index position" << std::endl;
        exit(0);
    }
    
    /*
        Because if I try to delete the element that the user want the array size will messed up
        So if the data type is int or double I will assing 0 at the given index positon and 
         if is char or string I will pass _     
    */

   // Get to the given size
   for (int i=0; i<this->rows; i++) {
       for (int j=0; j<this->columns; j++) {
           if (i == row_index && j == column_index) {
               if (sizeof(A2D) == 1 || sizeof(A2D) == 24) {
                   this->array_of_pointers[i][j] = '_';
               }
               else if (sizeof(A2D) == 4 || sizeof(A2D) == 8) {
                   this->array_of_pointers[i][j] = ' ' - 32;
               }
           }
       }
   }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method deletes an element by it's value
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::delete_element_by_value(A2D value, bool dupl) {
    //! If array empty
    if (this->rows == 0 || this->columns == 0) {
        std::cout << "Array is empty" << std::endl;
        exit(0);
    }
    // If the user wants to remove all the vlaues with the given values
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            if (this->array_of_pointers[i][j] == value) {
                if (sizeof(A2D) == 1 || sizeof(A2D) == 24) {
                    this->array_of_pointers[i][j] = '_';
                }
                else if (sizeof(A2D) == 4 || sizeof(A2D) == 8) {
                    this->array_of_pointers[i][j] = ' ' - 32;
                }

                if (!dupl) {

                    return *this; //* Return the pointer that is pointing to the object we are working
                }
            }
        }
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method clears the array
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::clear() {
    // Initialize the new array size
    this->rows = 0;
    this->columns = 0;
    this->array_of_pointers = NULL;

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method is filling the current array with the given element
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::fill(A2D value) {
    //! If array is empty
    if (this->rows == 0 || this->columns == 0) {
        std::cout << "Array is empty" << std::endl;
        exit(0);
    }

    // Change the values
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            this->array_of_pointers[i][j] = value;
        }
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This is a sorting method
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::sort() {
    // To sort a 2d array we need 4 for loops ( 2 for the element that will be conpared with all the element and 2 to collect all the other elements )

    for (int k=0; k<this->rows; k++) {
        for (int p=0; p<this->columns; p++) {
            // This variable is volumn index ( we pre declare this because after each loop we need it to be 0 )
            int x = p + 1;
            for (int i=k; i<this->rows; i++) { //* We don't pass k+1 because we need to start at the same row ( to start the comparsisson )
               for (int j=x; j<this->columns; j++) {
                   // Declairing if we need to swap the elements
                   if (this->array_of_pointers[k][p] > this->array_of_pointers[i][j]) {
                       A2D temp = this->array_of_pointers[i][j];
                       this->array_of_pointers[i][j] = this->array_of_pointers[k][p];
                       this->array_of_pointers[k][p] = temp;
                   }
                }
                x = 0; //* Assign the 0 value to the column index position
            }
        }
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method sorts the array backwords
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::reverse_sort() {
    // To sort a 2d array we need 4 for loops ( 2 for the element that will be conpared with all the element and 2 to collect all the other elements )

    for (int k=0; k<this->rows; k++) {
        for (int p=0; p<this->columns; p++) {
            // This variable is volumn index ( we pre declare this because after each loop we need it to be 0 )
            int x = p + 1;
            for (int i=k; i<this->rows; i++) { //* We don't pass k+1 because we need to start at the same row ( to start the comparsisson )
               for (int j=x; j<this->columns; j++) {
                   // Declairing if we need to swap the elements
                   if (this->array_of_pointers[k][p] < this->array_of_pointers[i][j]) {
                       A2D temp = this->array_of_pointers[i][j];
                       this->array_of_pointers[i][j] = this->array_of_pointers[k][p];
                       this->array_of_pointers[k][p] = temp;
                   }
                }
                x = 0; //* Assign the 0 value ( so if the comparisso of the first row finished it will start at the 0 instead of the p+1 )
            }
        }
    }

    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            std::cout << this->array_of_pointers[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method only sort the each row of the array
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::sort_rows() {
    // Start the sorting procces
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            for (int k=j+1; k<this->columns; k++) {
                if (this->array_of_pointers[i][j] > this->array_of_pointers[i][k]) {
                    A2D temp = this->array_of_pointers[i][j];
                    this->array_of_pointers[i][j] = this->array_of_pointers[i][k];
                    this->array_of_pointers[i][k] = temp;                   
                }
            }
        }
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method sorts each row backwords
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::reverse_sort_rows() {
    // Start the sorting procces
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            for (int k=j+1; k<this->columns; k++) {
                if (this->array_of_pointers[i][j] < this->array_of_pointers[i][k]) {
                    A2D temp = this->array_of_pointers[i][j];
                    this->array_of_pointers[i][j] = this->array_of_pointers[i][k];
                    this->array_of_pointers[i][k] = temp;                   
                }
            }
        }
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method sort each column
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::sort_columns() {
    // Start the sorting procces
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            for (int k=i+1; k<this->rows; k++) {
                if (this->array_of_pointers[i][j] > this->array_of_pointers[k][j]) {
                    A2D temp = this->array_of_pointers[i][j];
                    this->array_of_pointers[i][j] = this->array_of_pointers[k][j];
                    this->array_of_pointers[k][j] = temp;                   
                }
            }
        }
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method sorts each column backwords
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::reverse_sort_columns() {
    // Start the sorting procces
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            for (int k=i+1; k<this->rows; k++) {
                if (this->array_of_pointers[i][j] < this->array_of_pointers[k][j]) {
                    A2D temp = this->array_of_pointers[i][j];
                    this->array_of_pointers[i][j] = this->array_of_pointers[k][j];
                    this->array_of_pointers[k][j] = temp;                   
                }
            }
        }
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method is taking an array object as argument and copyies each value to the original array ( if array exist the methdo delete each elements )
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::copy(const array_2d<A2D> &ob) {
    //! Arra size condition
    if (this->rows != 0 && this->columns != 0) {
        // Initialize the size variables and the array pointer
        this->rows = 0;
        this->columns = 0;
        this->array_of_pointers = NULL;
    }

    // Create the new array
    expand_array(ob.get_row_size(), ob.get_column_size());

    // Copy the argumented array's elements to the original array
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            this->array_of_pointers[i][j] = ob.get_element(i, j);
        }
    }

    return *this; //* Return the pointer that is pointing to the object we are working
}





// This method is calculating how many times an element is appeard to the array
template <typename A2D>
int array_2d<A2D>::count(A2D value) {
    //! If array is empty
    if (this->rows == 0 || this->columns == 0) {
        return 0;
    }

    int count_var = 0; //* This is counting variable
    // Start the counting process
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            if (this->array_of_pointers[i][j] == value) {
                count_var ++;
            }
        }
    }

    return count_var;
}





// This method is returning the index position of the first element that match with the given value
template <typename A2D>
Array<int> array_2d<A2D>::index(A2D value, bool all) {
    // Creating the returned array
    Array<int> arr;
    
    //! If array is empty
    if (this->rows == 0 || this->columns == 0) {
        return arr;
    }
    
    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->columns; j++) {
            if (this->array_of_pointers[i][j] == value) {
                arr.push_back(i);
                arr.push_back(j);
                
                // Break out off the loop
                if (!all) {
                    return arr;
                }
                // This is a seperator
                arr.push_back(-1);
            }
        }
    }
    
    // Removing the last seperator of the array 
    if (arr.get_array_size() != 0) {
        arr.pop_back();
    }

    return arr; //* This contains all the index positions of all given elements
}





// This method overloads the = operator
template <typename A2D>
array_2d<A2D> &array_2d<A2D>::operator=(const array_2d<A2D> &right) {
    // Activating the copy method
    copy(right);

    return *this; //* Return the pointer that is pointing to the object we are working
}


// This method overloads the == operator
template <typename A2D>
bool array_2d<A2D>::operator==(const array_2d<A2D> &right) {
    //! Lenght comparison
    if (this->rows != right.rows || this->columns != right.columns) {
        return false;
    }

    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->rows; j++) {
            if (this->array_of_pointers[i][j] != right.array_of_pointers[i][j]) {
                return false;
            }
        }
    }

    return true;
}





// This method overloads the != operator
template <typename A2D>
bool array_2d<A2D>::operator!=(const array_2d<A2D> &right) {
    //! Lenght comparison
    if (this->rows != right.rows || this->columns != right.columns) {
        return true;
    }

    for (int i=0; i<this->rows; i++) {
        for (int j=0; j<this->rows; j++) {
            if (this->array_of_pointers[i][j] != right.array_of_pointers[i][j]) {
                return true;
            }
        }
    }

    return false;
}





template <typename A2D>
array<A2D> &array_2d<A2D>::operator[](int row_index) {
    //! Size condition
    if (this->rows == 0 || this->columns == 0) {
        std::cout << "Array is empty" << std::endl;
        exit(0);
    }
    //! Row index condition
    if (row_index > this->rows - 1 || row_index < 0) {
        std::cout << "Invalid row index positon" << std::endl;
        exit(0);
    }    
    
    // Creating the 1d array that will travel to the [] operator overloading at the 1d array to return us the value we want
    array<A2D> array_1d;

    // Fill the temporary with the values of the given row 
    for (int i=0; i<this->columns; i++) {
        array_1d.push_back(this->array_of_pointers[row_index][i]);
    }

    return array_1d; //* Return the 1d array
}





// This overloading method print the elements of the array to the screen
template <typename D2A>
std::ostream &operator<<(std::ostream &left, array_2d<D2A> &right) {
    //! Size condition
    if (right.rows == 0 || right.columns == 0) {
        std::cout << "Array is empty" << std::endl;
        exit(0);
    }

    // Print the array
    left << "[\n";
    for (int i=0; i<right.rows; i++) {
        left << " [";
        for (int j=0; j<right.columns; j++) {
            if (j == right.columns - 1) {
            left << right.array_of_pointers[i][j];
            }
            else {
                left << right.array_of_pointers[i][j] << ",";
            }
        }
        left << "]\n";
    }
    left << "]";

    return left; //* Return this object so we could use this overloading again and again at the same line
}




















//! ############################################################################################################################################ !\\

//!                                                All The Double Linkled List's Class Mehtods                                                   !\\

//! ############################################################################################################################################ !\



// This is the default constructor
template <typename L2>
D_L_List<L2>::D_L_List() {
    // Initialize the list poinetrs
    this->head = NULL;
    this->teil = NULL;
}




// This is the consructor that allow us to intialize the ocntainer using the {}
template <typename L2>
D_L_List<L2>::D_L_List(std::initializer_list<L2> li) {
    // Initialze the list pointers
    this->head = NULL;
    this->teil = NULL;

    // Adding the elements to the list
    for (int i=0; i<li.size(); i++) {
        push_back(*(li.begin() + i));
    }
}





// This is the constructor that takes many elements as argument
template <typename L2>
D_L_List<L2>::D_L_List(const std::vector<L2> &v) {
    // Initialize the pointers
    this->head = NULL;
    this->teil = NULL;

    // Adding the elements to the list
    for (int i=0; i<v.size(); i++) {
        push_back(v[i]);
    }
}




// This constructor build a list by a given array
template <typename L2>
D_L_List<L2>::D_L_List(const array<L2> &ob) {
    // Initialize the poinetrs
    this->head = NULL;
    this->teil = NULL;

    // Copy the elements
    for (int i=0; i<ob.get_array_size(); i++) {
        push_back(ob[i]);
    }
}





// This constructor build a list by a given single linekd list
template <typename L2>
D_L_List<L2>::D_L_List(const S_L_List<L2> &ob) {
    // Initialize the poinetrs
    this->head = NULL;
    this->teil = NULL;

    // Copy the elements
    for (int i=0; i<ob.get_size(); i++) {
        push_back(ob[i]);
    }
}





// This constructor is filling the list with a given value size times
template <typename L2>
D_L_List<L2>::D_L_List(int size, L2 value) {
    // Initialize our pointers
    this->head = NULL;
    this->teil = NULL;

    // Fill the list with elements
    for (int i=0; i<size; i++) {
        push_back(value);
    }
}





// This is the copy constructor
template <typename L2>
D_L_List<L2>::D_L_List(const D_L_List<L2> &ob) {
    // Initialize our pointers
    this->head = NULL;
    this->teil = NULL;

    // Copy the given list
    for (int i=0; i<ob.get_size(); i++) {
        push_back(ob.get_element(i));
    }
}





// This getter returns us the size of the list, to help us with all the methods
template <typename L2>
int D_L_List<L2>::get_size() const {
    //! Pointer condition
    if (!this->head || !this->teil) {
        return 0;
    }
    else {
        int size = 0; //* The returned varialbe

        // Create a temporary node to help us iterate throught the list
        node<L2> *curr = this->head;
        // Start the process
        while (curr) {
            size ++; //* Increase the size by one
            curr = curr->next; //* Procead to the next node ( until reach the end, NULL pointer )
        }

        return size; //* The size of the list
    }
}





// This method return the element at the given index
template <typename L2>
L2 D_L_List<L2>::get_element(int index) const {
    //! Index condition
    if (index > get_size() - 1 || index < 0) {
        std::cout << "Invalid index position" << std::endl;
    }
    else {
        // Create a temporary node to go throught the list
        node<L2> *curr;

        // Create the middle variable to iterate faster throught the list
        int middle = (get_size() / 2) - 1;

        // This condition saves us time ( from O(n) going to O(n/2) )
        if (index >= middle) {
            // Point the temporary node to the last element of the list
            curr = this->teil;

            // Finding for the wanted element
            for (int i=get_size() - 1; i>=middle; i--) {
                if (i == index) {
                    return curr->data;
                }
                curr = curr->previous; //* Go to the previous node
            }
        }
        else {
            // Point the teporary pointer to the first element of the list
            curr = this->head;

            // Finding the wanted element
            for (int i=0; i<middle; i++) { //* Because middle is the index position we need to increase it by one to be a size
                if (i == index) {
                    return curr->data;
                }
                curr = curr->next; //* Go to the next node
            }
        }
    }

    return EXIT_SUCCESS;
}





// This setter is setting the list size
template <typename L2>
void D_L_List<L2>::set_size(int size, L2 value) {
    //! Size condition
    if (size < get_size() || size < 0) {
        std::cout << "Given size must be greater than the existed size and also greater than 0" << std::endl;
        exit(0);
    }
    
    // Fill the new list position with the given value
    for (int i=get_size(); i<size; i++) {
        push_back(value);
    }
}





// This method append an element at the back of the list
template <typename L2>
D_L_List<L2> &D_L_List<L2>::push_back(L2 value) {
    // Creating the new node
    node<L2> *new_node = new node<L2>;
    // Commitment condition
    if (!new_node) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Assigne the values to the node
    new_node->next = NULL;
    new_node->data = value;

    if (!this->teil || !this->head) {
        // Inserting this node to the list
        this->head = new_node;
        this->teil = new_node;
        
        // Assign NULL because this node will be the first of the list
        new_node->previous = NULL;
    }
    else {
        // Add the element at the end of the list
        this->teil->next = new_node; //* This line makes the first node link with the socond one
        new_node->previous = this->teil;
        this->teil = new_node;
    }

    return *this; //* Returning the pointer that is pointing to the object we are working with
}





// This method adds an element at the start of the list
template <typename L2>
D_L_List<L2> &D_L_List<L2>::push_front(L2 value) {
    // Creating the new node that will entered to the list
    node<L2> *new_node = new node<L2>;
    // Commitment condition
    if (!new_node) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

    // Assign the new node's values
    new_node->data = value;
    new_node->previous = NULL;

    //! If list is empty
    if (!this->head || !this->teil) {
        // Add the given element to the list
        this->head = new_node;
        this->teil = new_node;

        // Assing the NULL value to the new node, because this node is the last of the list
        new_node->next = NULL;
    }
    else {
        // Point the first element to the new node
        this->head->previous = new_node;
        // Point the ne node pointer at the first elment of the list 
        new_node->next = this->head;
        // Point the head pointer to the new node so this node will be the new first node 
        this->head = new_node;
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with 
}





// This method inserting an element at the given index position
template <typename L2>
D_L_List<L2> &D_L_List<L2>::insert(int index, L2 value) {
    //! Index condition
    if (index > get_size() || index < 0) {
        std::cout << "Invalid index position" << std::endl;
        exit(0);
    }
    //! Push Front
    if (index == 0) {
        push_front(value);
    }

    //! Push Back
    else if (index == get_size()) {
        push_back(value);
    }

    else {
        // Create a temporary node to iterate throught the list
        node<L2> *curr;

        // Create the new node
        node<L2> *new_node = new node<L2>;
        // Commitment condition
        if (!new_node) {std::cout << "Error Allocating Memory" << std::endl; exit(0);}

        // Pass the given value to the new element
        new_node->data = value;

        // This variable reduce the complesity by a half
        int middle = (get_size() / 2) - 1;

        if (index > middle) {
            // Point the temporary node to the lats element of the list
            curr = this->teil;

            // Go to the correct index position
            for (int i=get_size()-1; i>=middle; i--) {
                if (i == index) {
                    break;
                }
                curr = curr->previous;
            }
        }

        else {
            // Point the temporrary pointer to the first element of the list
            curr = this->head;

            // Go to the correct index position
            for (int i=0; i<middle; i++) {
                if (i == index) {
                    break;
                }
                curr = curr->next;
            }
        }

        // Inserting the new node to the list
        new_node->next = curr->previous->next; //* Point the new node to the next node
        new_node->previous = curr->previous; //* Point the new node to the previous node

        curr->previous->next = new_node; //* Point the next node to the new one
        curr->previous = new_node; //* Point the previous node to the new one
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method extend the list by the given one
template <typename L2>
D_L_List<L2> &D_L_List<L2>::extend(const D_L_List<L2> &ob) {
    for (int i=0; i<ob.get_size(); i++) {
        push_back(ob.get_element(i));
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method deletes the last element of the list
template <typename L2>
D_L_List<L2> &D_L_List<L2>::pop_back() {
    //! Length condition
    if (get_size() == 0) {
        std::cout << "List is empty" << std::endl;
        exit(0);
    }
    else if (get_size() == 1) {
        // Clearing the list
        this->head = NULL;
        this->teil = NULL;
    }
    else {
        this->teil = this->teil->previous; //* Point the teil pointer to the element prior the last one
        this->teil->next->previous = NULL; //* Delete the pointer of the last element ( disconnect from the list )
        this->teil->next = NULL; //* Delete the next pointer of the new last element
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method removes the first node of the list
template <typename L2>
D_L_List<L2> &D_L_List<L2>::pop_front() {
    //! Size condition
    if (!this->head || !this->teil) {
        std::cout << "List is empty" << std::endl;
        exit(0);
    }
    else if (get_size() == 1) {
        // Clearing the list
        this->head = NULL;
        this->teil = NULL;
    }
    else {
        this->head = this->head->next; //* Pointing the head pointer to the secont element of the list 
        this->head->previous->next = NULL; //* Delete the pointer that is connecting the first element with the new first 
        this->head->previous = NULL; //* Delete the pointer that is connecting the new first pointer with the old one
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method can delete a node at the given index position
template <typename L2>
D_L_List<L2> &D_L_List<L2>::remove_by_index(int index, int total_pos) {
    //! Index condition
    if (index > get_size() - 1 || index < 0 || index + total_pos > get_size() - 1) {
        std::cout << "Invalid index position" << std::endl;
    }
    else if (index == get_size() - 1) {
        // Delete the last element of the list
        pop_back();
    }
    else if (index == 0) {
        // Start from the start and delete total pos elements to the right
        int index = 0;
        do {
            pop_front();
            index++;
        } while (index < total_pos+1);
    }
    else if (total_pos + index == get_size() - 1) { //* This condition help us solve the next pointer NULL problem
        // Deleting total pos + 1 ( + 1 is the node at the given index position ) elelments from the end to start
        for (int i=0; i<total_pos+1; i++) {
            pop_back();
        }
    }
    else {
        // Creating 2 temporary node pointers to iterate throught the list and delete the elements the user want
        node<L2> *curr;
        node<L2> *temp;
        // This index position help us reduce the time complexity of the program
        int middle = (get_size() / 2) - 1;

        // This for loops proceeds the curr pointer to the element we want to delete ( not include total pos )
        if (index >= middle) {
            // Point the curr pointer to the last node
            curr = this->teil;
            for (int i=get_size() - 1; i>=middle; i--) {
                if (i == index) {
                    break;
                }
                else {
                    curr = curr->previous;
                }
            }
        }
        else {
            // Poin the curr pointer to the first node
            curr = this->head;
            for (int i=0; i<middle; i++) {
                if (i == index) {
                    break;
                }
                else {
                    curr = curr->next;
                }
            }
        }
        
        // Point the temp pointer to the same node as the curr one
        temp = curr;

        // Proceed the temp pointer to the next element that the user want to be at the list
        for (int i=0; i<total_pos; i++) {
            temp = temp->next;
        }

        curr->previous->next = temp->next; //* Point the next pointer of the previous node than the curr node pointer element to the next of temp
        temp->next->previous = curr->previous; //* Point the previous pointer of the next node than the temp to the previous of curr node 
        // Disconnect the elements from the list
        curr->previous = NULL;
        temp->next = NULL;
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method deletes elements based on their values than their index
template <typename L2>
D_L_List<L2> &D_L_List<L2>::remove_by_value(L2 value, bool dupl) {
    //! Size condition
    if (!this->head || !this->teil) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        for (int i=0; i<get_size(); i++) {
            if (get_element(i) == value) {
                remove_by_index(i, 0);
                i = 0; //* This line help prevent falling out of the list 
                //! Breaking condition
                if (!dupl) {
                    break;
                }
            }
        }
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method clears the list
template <typename L2>
void D_L_List<L2>::clear() {
    this->head = NULL;
    this->teil = NULL;
}





// This method fill the list with one value
template <typename L2>
D_L_List<L2> &D_L_List<L2>::one_val(L2 value) {
    //! Size condition
    if (!this->head || !this->teil) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        // Create a temporary node pointer to iterate throught the list
        node<L2> *curr = this->head;
        // Change the list values
        for (int i=0; i<get_size(); i++) {
            curr->data = value; //* Assing the value
            curr = curr->next; //* Proceed to the next node
        }
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method sorts the list
template <typename L2>
D_L_List<L2> &D_L_List<L2>::sort() {
    //! Length condition
    if (!this->head || !this->teil) {
        std::cout << "List is empty" << std::endl;
        exit(0);
    }
    // Creating 2 temporary node pointers to sort the list
    node<L2> *curr = this->head;
    node<L2> *temp = this->head;

    // Start the algorithm
    for (int i=0; i<get_size(); i++) {
        for (int j=0; j<get_size()-1; j++) {
            if (temp->data > curr->data) {
                L2 T = curr->data;
                curr->data = temp->data;
                temp->data = T;
            }
            temp = temp->next;
        }
        curr = curr->next;
        temp = this->head;
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method sorts the list
template <typename L2>
D_L_List<L2> &D_L_List<L2>::reverse_sort() {
    //! Length condition
    if (!this->head || !this->teil) {
        std::cout << "List is empty" << std::endl;
        exit(0);
    }
    // Creating 2 temporary node pointers to sort the list
    node<L2> *curr = this->head;
    node<L2> *temp = this->head;

    // Start the algorithm
    for (int i=0; i<get_size(); i++) {
        for (int j=0; j<get_size()-1; j++) {
            if (temp->data < curr->data) {
                L2 T = curr->data;
                curr->data = temp->data;
                temp->data = T;
            }
            temp = temp->next;
        }
        curr = curr->next;
        temp = this->head;
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method sorts the list and deletes the suplicates
template <typename L2>
D_L_List<L2> &D_L_List<L2>::set_with_sort() {
    //! Size condition
    if (!this->head || !this->teil) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        // Sorts the array
        sort();
        // Remove duplicates ( with a little different way )
        int i = 0;
        do {
            if (get_element(i) == get_element(i+1)) {
                remove_by_index(i, 0);
                i --;
            }
            i++;

        } while (i < get_size() - 1);
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method reverses the list
template <typename L2>
D_L_List<L2> &D_L_List<L2>::reverse() {
    //! Size condition
    if (!this->head || !this->teil) {
        std::cout << "The list is empty" << std::endl;
    }
    else {
        // Create 2 temporary node to iterate throught the array
        node<L2> *curr = this->head;
        node<L2> *temp = this->teil;

        for (int i=0; i<get_size() / 2; i++) {
            L2 T = curr->data;
            curr->data = temp->data;
            temp->data = T;

            curr = curr->next;
            temp = temp->previous;
        }
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method copies the argumented list object to the original one
template <typename L2>
D_L_List<L2> &D_L_List<L2>::copy(const D_L_List<L2> &ob) {
    //! If lists are same
    if (*this == ob) {
        return *this;
    }

    //! If list exists
    if (this->head || this->teil) {
		// Delete the list
		this->head = NULL;
		this->teil = NULL;
	}

	// Start copying
	for (int i=0; i<ob.get_size(); i++) {
		push_back(ob.get_element(i));
	}

	return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method counts the given value in the list
template <typename L2>
int D_L_List<L2>::count(L2 value) const {
	//! List condiiton
	if (!this->head || !this->teil) {
		std::cout << "List is empty" << std::endl;
		return 0;
	}

	// Creating a temporary node to iterate throught the list
	node<L2> *curr = this->head;

	// Declare and assigne the returned counting variable
	int count_var = 0;

	// Start process
	for (int i=0; i<get_size(); i++) {
		if (get_element(i) == value) {
			count_var ++;
		}
	}

	return count_var;
}





// This method returns us the first index position of the given value
template <typename L2>
int D_L_List<L2>::index(L2 value) const {
	//! Size condition
	if (!this->head || !this->teil) {
		std::cout << "List is empty" << std::endl;
		return -1;
	}

	// Create a temporary node pointer to iterate throught the list
	node<L2> *curr = this->head;

	// Start process
	for (int i=0; i<get_size(); i++) {
		if (get_element(i) == value) {
			return i;
		}
	}

	// If not in list
	return -1;
}





// This method returns all the index positions that the given element exist at the list
template <typename L2>
D_L_List<int> D_L_List<L2>::index(L2 value, bool nes) {
    // Create the returned list
    D_L_List<int> list;
    
    //! Lenght condition
    if (!this->head || !this->teil) {
        std::cout << "List is empty" << std::endl;
        list.push_back(-1);
    }
    else {
        for (int i=0; i<get_size(); i++) {
            if (get_element(i) == value) {
                list.push_back(i);
            }
        }

        // If not in list
        if (list.get_size() == 0) {
            std::cout << "Element not in list" << std::endl;
            list.push_back(-1);
        }
    }

    return list;
}





// This method gives us the first element of the list
template <typename L2>
L2 D_L_List<L2>::first() {
	//! Size condition
	if (!this->head || !this->teil) {
		std::cout << "list is empty" << std::endl;
		exit(0);
	}

	return this->head->data;
}





// This method gives us the first element of the list
template <typename L2>
L2 D_L_List<L2>::last() {
	//! Size condition
	if (!this->head || !this->teil) {
		std::cout << "list is empty" << std::endl;
		exit(0);
	}

	return this->teil->data;
}





// This method overloads the = operator
template <typename L2>
D_L_List<L2> &D_L_List<L2>::operator=(const D_L_List<L2> &ob) {
	//! If list exist
	if (this->head || this->teil) {
		// Clearing the list
		this->head = NULL;
		this->teil = NULL;
	}

	// Activate the copy method
	copy(ob);

	return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method overloads the == operator
template <typename L2>
bool D_L_List<L2>::operator==(const D_L_List<L2> &ob) {
	//! Size comparisson
	if (get_size() != ob.get_size()) {
		return false;
	}
	
	// Start the node comparisson
	for (int i=0; i<get_size(); i++) {
		if (get_element(i) != ob.get_element(i)) {
			return false;
		}
	}

	return true;
}





// This method overloads the != operator
template <typename L2>
bool D_L_List<L2>::operator!=(const D_L_List<L2> &ob) {
	//! Size comparisson
	if (get_size() != ob.get_size()) {
		return true;
	}
	
	// Start the node comparisson
	for (int i=0; i<get_size(); i++) {
		if (get_element(i) != ob.get_element(i)) {
			return true;
		}
	}

	return false;
}





// THis method overloads the < operator overloading
template <typename L2>
bool D_L_List<L2>::operator<(const D_L_List<L2> &ob) {
	// Start the comparison
	if (get_size() < ob.get_size()) {
		return true;
	}

	return false;
}





// THis method overloads the < operator overloading
template <typename L2>
bool D_L_List<L2>::operator>(const D_L_List<L2> &ob) {
	// Start the comparison
	if (get_size() > ob.get_size()) {
		return true;
	}

	return false;
}





// This method overloads the <= operator
template <typename L2>
bool D_L_List<L2>::operator<=(const D_L_List<L2> &ob) {
	// Start the comparison
	if (get_size() < ob.get_size()) {
		return true;
	}
	else if (get_size() > ob.get_size()) {
		return false;
	}
    else {
        if (*this == ob) {
            return true;
        }
        else {
            return false;
        }
    }
}





// This method overloads the >= operator
template <typename L2>
bool D_L_List<L2>::operator>=(const D_L_List<L2> &ob) {
	// Start the comparison
	if (get_size() > ob.get_size()) {
		return true;
	}
	else if (get_size() < ob.get_size()) {
		return false;
	}
    else {
        if (*this == ob) {
            return true;
        }
        else {
            return false;
        }
    }

}



// This method overload the [] operator
template <typename L2>
L2 &D_L_List<L2>::operator[](int index) {
	//! Index condition
	if (index > get_size() - 1 || get_size() < 0) {
		std::cout << "Invalid index condition" << std::endl;
		exit(0);
	}

    int middle = (this->get_size() - 1) / 2;

    if (index >= middle) {
        node<L2> *curr = this->teil;
        for (int i=middle; i<index; i++) {
            curr = curr->previous;
        }

        return curr->data;
    }
    else {
        node<L2> *temp = this->head;
        for (int i=0; i<index; i++) {
            temp = temp->next;
        }

        return temp->data;
    }
}





// This method overloads the += operator 
template <typename L2>
D_L_List<L2> &D_L_List<L2>::operator+=(const D_L_List<L2> &ob) {
	// Activate the extend method
	extend(ob);
	
	return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method removes the nodes that is the same as the argumented list
template <typename L2>
D_L_List<L2> &D_L_List<L2>::operator-=(const D_L_List<L2> &ob) {
    // Start the algorith
	for (int i=0; i<get_size(); i++) {
		if (ob.count(get_element(i)) != 0) {
			remove_by_index(i, 0);
			i--;
		}
	}

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method overloads the *= operator
template <typename L2>
D_L_List<L2> &D_L_List<L2>::operator*=(int times) {
    // Get the original size
    int size = get_size();

    for (int i=0; i<times; i++) {
        for (int j=0; j<size; j++) {
            push_back(get_element(j));
        }
    }

    return *this; //* Returning the value of the pointer that is pointing to the object we are working with
}





// This method overloads the << operator
template <typename Ll2>
std::ostream &operator<<(std::ostream &left, D_L_List<Ll2> &right) {
    //! Size condition
    if (!right.head || !right.teil) {
        std::cout << "[]";
    }
    else {
        left << "[";
        for (int i=0; i<right.get_size(); i++) {
            if (i == right.get_size() - 1) {
                left << right.get_element(i);
            }
            else {
                left << right.get_element(i) << ", ";
            }
        }
        left << "]";
    }
    return left;
}





// This method overloads the << operator
template <typename Ll2>
std::istream &operator>>(std::istream &left, D_L_List<Ll2> &right) {
    // Get the user's input
    Ll2 user_choice;
    std::cout << "Enter element at the " << right.get_size() - 1 << " index position: ";
    left >> user_choice;

    // Append the new element
    right.push_back(user_choice);

    return left;
}
