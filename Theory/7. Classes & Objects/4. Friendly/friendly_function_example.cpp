#include <iostream>

class Table;

// Create the chair class
class Chair {
    private:
        // All the class members we need
        std::string color;
        double height;
    
    public:
        // Creating the constructor
        Chair(std::string aColor, double aHeight): color(aColor), height(aHeight) {};

        // Overloading the << operator
        friend std::ostream &operator<<(std::ostream &left, const Chair &ob) {  
            left << "Chair -> color: " << ob.color << ", heght: " << ob.height;

            return left;
        }

        // Decalare a frindly function for this class
        friend void shrink(Table &table, Chair &chair);
};

// Create the table class
class Table {
    private:
        // All the class members we need
        std::string color;
        double width;
    
    public:
        // Creating the constructor
        Table(std::string aColor, double aWidth): color(aColor), width(aWidth) {};

        // Overloading the << operator
        friend std::ostream &operator<<(std::ostream &left, const Table &ob) {
            left << "Table -> clor: " << ob.color << ", width: " << ob.width;

            return left;
        }

        // Declare a friendly function for this class
        friend void shrink(Table &table, Chair &chair);
};

// Inisialize the friendly function
void shrink(Table &table, Chair &chair) {
    table.width = table.width - (table.width * 10) / 100;
    chair.height = chair.height - ((chair.height * 10) / 100);
}

int main() {
    // Creating the objects
    Chair chair("yellow", 100);
    Table table("white", 100);

    // Printing results
    std::cout << chair << std::endl;
    std::cout << table << std::endl;

    shrink(table, chair);
    std::cout << std::endl;

    std::cout << chair << std::endl;
    std::cout << table << std::endl;
    
    return 0;
}