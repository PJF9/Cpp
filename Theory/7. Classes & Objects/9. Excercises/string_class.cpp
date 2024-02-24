#include <iostream>

class String {
    private:
        char *str;
        int n;
    
    public:
        String() {
            str = NULL;
            n = 0;
        }

        // Creating the constructor
        String(char *str) {
            // Get the size of the argument string
            //? First way to get the size of the string
            // for (int j=0; ; j++) {
            //     if (str[j] == 0) {
            //         this->n = j;
            //         break;
            //     }
            // }

            //? Second way to get the size of the string
            int j = 0;
            while (true) {
                if (str[j] == '\0') { //* We are using '\0' because a char array is like ['a', 'b', '\0'] --> Finishes at \0 
                    // Assinging the j value to the class member n
                    this->n = j;
                    break;
                }
                j++;
            }

            // Dynamik memory commitment
            this->str = new char [n];

            // Commitment condition
            if (!this->str) {std::cout << "Error Allocating Memory" << std::endl;}

            // Copy the string from the argumented object
            for (int i=0; i<n; i++) {
                this->str[i] = str[i];
            }
        }

        ~String() {
            delete [] this->str;
        }

        // Creating a copy constructor
        String(const String &ob) {
            // Get the size of the string we want to copy from
            this->n = ob.n;

            // Dynamik memory commitment based to the previous length
            this->str = new char [n];

            //Commitment condition
            if (!this->str) {std::cout << "Error Allocating Memory" << std::endl;}

            // Asinging value to the char array ( by the argumented string )
            for (int i=0; i<n; i++) {
                this->str[i] = ob.str[i];
            }
        }

        // Overloading the = operator
        String &operator=(const String &right_object) {
            // If the 2 object are the same
            if (this == &right_object) {
                return *this;
            }
            
            // Seeing if the this object has str value
            if (this->str) {
                delete [] this->str;
                this->n = 0;
            }

            // Get the size of the argumented string
            this->n = right_object.n;

            // New dynamik memory commitment
            this->str = new char [n];

            // COmmitment condition
            if (!this->str) {std::cout << "Error Allocating Memory" << std::endl;}

            // Copy the argumented string
            for (int i=0; i<n; i++) {
                this->str[i] = right_object.str[i];
            }

            // Returning the final string
            return *this;
        }

        // Overloading the > operator
        bool operator>(const String &right_object) {
            if (this->n > right_object.n) {
                return true;
            }
            return false;
        }

        // Overloading the < operator
        bool operator<(const String &right_object) {
            if (this->n < right_object.n) {
                return true;
            }
            return false;
        }

        // Overloading the == operator
        bool operator==(const String &right_object) {
            if (this->n == right_object.n) {
                return true;
            }
            return false;
        }

        // Overloading the [] operator
        char operator[] (int index) {
            if (index >= 0 && index < this->n) {
                return this->str[index];
            }
            std::cout << "Invalid Index Position";
            return ' ';
        }
        
        // Overloading the << operator
        friend std::ostream &operator<<(std::ostream &left, const String &ob) {
            for (int i=0; i<ob.n; i++) {
                left << ob.str[i];
            }

            return left;
        }
        
        // Overloading the >> operator
        friend std::istream &operator>>(std::istream &left, String &ob) {
            // Declare a new array of chars to pass the inputed string
            char curr[100];
            // Get the inputed string
            std::cout << "Give string: ";
            left >> curr;
            
            // If we have already passed a string to this object
            if (ob.str != NULL) {
                delete [] ob.str;
            }

            // Get the length of the inputed string
            int index = 0;
            while (true) {
                if (curr[index] == '\0') {
                    break;
                }
                index++;
            }
            
            // Dynamic memory commitment
            ob.str = new char [index];
            // Commitment condition
            if (!ob.str) {std::cout << "Error Allocating Memory" << std::endl;}

            // Give the value of the inputed string to the object string
            ob.n = index;

            // Copy the inputed char array with the object one
            for (int i=0; i<ob.n; i++) {
                ob.str[i] = curr[i];
            }

            return left;
        }

        // Creating the accessors
        void set_string(char *str) {
            // If we had passt a string before
            if (this->str) {
                delete [] this->str;
                this->n = 0;
            }

            // Get the size of the given string ( char array )
            for (int i=0; ; i++) {
                if (str[i] == '\0') {
                    this->n = i;
                    break;
                }
            }

            // Dynamik memory commitment
            this->str = new char [n];

            // Commitment condition
            if (!this->str) {std::cout << "Error Allocating Memory" << std::endl;}

            // Copy the argumented string
            for (int i=0; i<n; i++) {
                this->str[i] = str[i];
            }
        }

        int get_length() {
            // Returning the length of the string
            return this->n;
        }
        char *get_string() { //* We need the * or else this function is only going to return the first letter of the string
            // Returning the entire string
            return this->str;
        }
};

int main() {
    // Creating the prime object
    char st1[10] = "Hallaaaao";
    String str1(st1);

    // Enable the copy constructor
    String str2 = str1;

    // Printing results
    std::cout << "str1 = " << str1.get_string() << std::endl;
    std::cout << "str2 = " << str2.get_string() << std::endl;

    // Change the value of the prime object
    char st2[6] = "Hallo";
    str1.set_string(st2);

    // Printing results
    std::cout << "new str1 = " << str1.get_string() << std::endl;

    // Checking the = operator overloading
    String str3;
    
    // Enable the overloading
    str3 = str1;

    //Printing results
    std::cout << "str3 = " << str3.get_string() << std::endl;

    // Checking the > operator overloading
    String str4;
    str4 = str2;

    if (str3 > str4) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    // Checking the < operator overloading
    if (str3 < str4) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    // Checking the == operator overloading
    if (str1 == str3) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    // Checking the [] operator overloading
    std::cout << str1[0] << std::endl;
    std::cout << str1[str1.get_length()] << std::endl; //* One more than the lenght of the string

    // Check the << operator overloading
    std::cout << str1 << std::endl;

    // Check the >> operator overloading
    String str5;
    std::cin >> str5;
    std::cout << str5 << std::endl;

    return 0;
}
