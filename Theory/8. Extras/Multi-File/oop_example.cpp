#ifdef OOP_EX


namespace ex {
    template <typename _Type>
    Point<_Type>::Point(int x, int y) {
        this->x = x;
        this->y = y;
        Point::points ++;
    }


    template <typename _Type>
    Point<_Type>::Point (const Point<_Type> &copy_point) {
        this->x = copy_point.get_x();
        this->y = copy_point.get_y();

    }


    template <typename _Type>
    Point<_Type> Point<_Type>::operator+(int value) const {
        return Point(this->x + value, this->y + value);
    }


    template <typename _Type>
    Point<_Type> Point<_Type>::operator+(const Point<_Type> &right_obj) {
        return Point(this->x + right_obj.get_x(), this->y + right_obj.get_y());
    }


    template <typename _Type>
    Point<_Type> Point<_Type>::operator-(int value) const {
        return Point(this->x - value, this->y - value);
    }


    template <typename _Type>
    Point<_Type> Point<_Type>::operator-(const Point<_Type> &right_obj) {
        return Point(this->x - right_obj.get_x(), this->y - right_obj.get_y());
    }


    template <typename _Type>
    Point<_Type> Point<_Type>::operator*(int value) const {
        return Point(this->x * value, this->y * value);
    }


    template <typename _Type>
    Point<_Type> Point<_Type>::operator++(int nes) {
        this->x ++;
        this->y ++;

        return *this;
    }


    template <typename _Type>
    Point<_Type> Point<_Type>::operator--(int nec) {
        this->x --;
        this->y --;

        return *this;
    }


    template <typename _Type>
    int &Point<_Type>::operator[](int index) {
        if (index == 0) {
            return this->x;
        }
        return this->y;
    }


    template <typename _Type>
    int Point<_Type>::operator[](int index) const {
        if (index == 0) {
            return this->x;
        }
        return this->y;
    }


    template <typename _Type>
    Point<_Type> &Point<_Type>::operator=(const Point<_Type> &right_obj) {
        if (this != &right_obj) {
            this->x = right_obj.get_x();
            this->y = right_obj.get_y();
        }
        return *this;
    }


    template <typename _T>
    std::ostream &operator<<(std::ostream &left, const Point<_T> &obj) {
        left << "(" << obj.get_x() << ", " << obj.get_y() << ")";
        return left;
    }



    template <typename _T>
    std::istream &operator>>(std::istream &left, Point<_T> &obj) {
        int x, y;
        
        std::cout << "x: ";
        left >> x;

        std::cout << "y: ";
        left >> y;

        obj.set_x(x);
        obj.set_y(y);

        return left;
    }


    template <typename _T>
    int Point<_T>::points = 0;
}

#endif
