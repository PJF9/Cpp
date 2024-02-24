#include <iostream>

/*
    With friendy functions we can overload operators such us:
        - The left will have a data type and at the right will have an object ( We could only do the oposite )
            data_type + object
        
        - The << operator
            std::cout << object

    Also, a lot of overloading we already know can be done by friendly function

    ! First option ( data_type operator object )
    lets say we want to overload the + operator

    Syntax: friend class_name operator+(int left, class_name &object);

    ! Second option ( overloading the << operator )
    Syntax: friend std::ostream &operator<<(std::ostream &left, const class_name &ob);
*/

// Create the point class
class Point {
    private:
        // All the class members we need
        int x;
        int y;

    public:
        // Creating the constructor
        Point(int aX=0, int aY=0): x(aX), y(aY) {};

        // Creating the accessors
        void set_x(int x) {
            this->x = x;
        }
        void set_y(int y) {
            this->y = y;
        }
        int get_x() {
            return this->x;
        }
        int get_y() {
            return this->y;
        }

        // Overload the + operator
        friend Point operator+(int left, Point &ob) {
            Point result;

            result.x = left + ob.x;
            result.y = left + ob.y;

            return result;
        }

        // Overload the << operator
        friend std::ostream &operator<<(std::ostream &left, const Point &ob) {
            left << "(" << ob.x << ", " << ob.y << ")";

            return left;
        }
};

int main() {
    // Creating all the objects
    Point a(3, 6);
    Point c;

    // Activate the overloading operator
    c = 3 + a;

    // Printing results
    std::cout << "c(" << c.get_x() << ", " << c.get_y() << ")" << std::endl;
    std::cout << "c" << c << std::endl;

}