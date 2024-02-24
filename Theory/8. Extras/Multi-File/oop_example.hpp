#ifndef OOP_EX
#define OOP_EX

#include <string>
#include <iostream>


namespace ex {
    template <typename _Type>
    class Point {
        
        private:
            int x;
            int y;
            static int points;
        
        public:
            Point(int x=0, int y=0);
            Point (const Point &copy_point);

            inline int get_x() const;
            inline int get_y() const;
            inline void set_x(int x);
            inline void set_y(int y);
            inline int number_of_points() const;

            Point operator+(int value) const;
            Point operator+(const Point &right_obj);
            Point operator-(int value) const;
            Point operator-(const Point &right_obj);
            Point operator*(int value) const;
            Point operator++(int nes);
            Point operator--(int nec);

            int &operator[](int index);
            int operator[](int index) const;

            Point &operator=(const Point &right_obj);

            template <typename _T> friend std::ostream &operator<<(std::ostream &left, const Point<_T> &obj);
            template <typename _T> friend std::istream &operator>>(std::istream &left, Point<_T> &obj);
    };
}

#include "oop_example.inl"
#include "oop_example.cpp"
#endif
