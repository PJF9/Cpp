template <typename _Type>
int ex::Point<_Type>::get_x() const {
    return this->x;
}


template <typename _Type>
int ex::Point<_Type>::get_y() const {
    return this->y;
}


template <typename _Type>
void ex::Point<_Type>::set_x(int x) {
    this->x = x;
}


template <typename _Type>
void ex::Point<_Type>::set_y(int y) {
    this->y = y;
}


template <typename _Type>
int ex::Point<_Type>::number_of_points() const {
    return this->points;
}
