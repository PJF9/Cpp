#include <iostream>

/*
    ? What is a linked list ? 
    Linked List is a data structure. It's a collection of same data types
    The linked list is composed by 2 classes:
        -The node ( κομβο ) -> ( members: data=(τιμη), next=(δεικτης που δειχνει το επομενο στοιχειο της λιστας) )
        -The list ( ολη την λιστ ) -> ( members: head=(δεικτης που δειχνει το πρωτο στοιχειο της λιστας) ), this class has all the method of the list

    The list class will have access to the node class
    So the list class will be a friendy class of the node class
*/

// Create ehe node class
class Node {
    private:
        // All the class members we need
        int data;
        Node *next; //* The object that its element will face
    
    public:
        // Making the List class friendly to the Node
        friend class Linked_List;
};

// Create the linked list class
class Linked_List {
    private:
        // All the class menmbers we need
        Node *head;
    
    public:
        // Creating the constructor
        Linked_List() {
            // Inisialize the head pointer 
            head = NULL;
        };

        // Creating a method to insert data to the start of the list
        bool insert_to_start(int aData) {
            // This new_node will have all the private class members at the Node class in its arsenal
            Node *new_node; //* Create a new pointer that will show to the new first element

            // Dynamic memory commitment
            new_node = new Node;
            // Commitment condition
            if (!new_node) {std::cout << "Error Allocating Memory" << std::endl; return false;}

            // Assigning to the new_node at data class member the given data
            new_node->data = aData;

            // We are facing the new_node at the same position that the head pointer is facing ( at the first element )
            new_node->next = head;

            // Facing the head pointer at the new node, so the new_node will be the first element at the list
            head = new_node;

            return true;
        }

        bool insert_to_end(int aData) {
            // Creating a new Node pointer that will show to a Node object
            Node *new_node = new Node;
            // Commitment Condition
            if (!new_node) {std::cout << "Error Allocating Memory" << std::endl; return false;}
            
            // Assinge the values to the new Node
            new_node->data = aData;
            new_node->next = NULL;

            // Creating a temporary Node to calculate the lenght of the already list
            Node *temp;
            temp = head;

            // Get the size of the list
            int index = 0;  
            while (temp != NULL) {
                temp = temp->next;
                index ++;
            }

            // If the list has no elements
            if (index == 0) {
                head = new_node;
                return true;
            }

            // Back again ( This time to add the element at the back of the list )
            temp = head;

            // Get the the last element of the list ( we pass index -1 because we nedd the last element to show to the new Node )
            for (int i=0; i<index-1; i++) {
                temp = temp->next;
            }

            temp->next = new_node; //* Adding the new Node to the list

            return true;
        }

        // Creating a method to print the list
        void print() {
            Node *current; //* Create a new pointer that will show at the all the elements one by one

            // Face the current pointer to the first element at the list ( the same as the head's )
            current = head;

            // Printing the list
            std::cout << "[ ";
            while (current != NULL) {
                std::cout << current->data << " ";
                // Face the current pointer to the next element of the list
                current = current->next; //* First the current will show the same element as the head. Then is will show the next element, and the next...
            }
            std::cout << "]" << std::endl;
        }
};

int main() {
    // Create the linked list object
    Linked_List list;

    // Insert data to the list
    for (int i=0; i<10; i++) {
        list.insert_to_start(i);
    }

    list.insert_to_end(99);
    list.insert_to_end(100);

    // Printing the List
    list.print();
}
