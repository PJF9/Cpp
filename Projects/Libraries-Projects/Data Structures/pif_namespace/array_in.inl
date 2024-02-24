#ifdef ARRAY


namespace pif {

    template <typename _ArrayType>
    inline int array<_ArrayType>::length() const {
        return this->array_size;
    }



    template <typename _ArrayType>
    inline int array<_ArrayType>::size() const {
        return this->extended_size;
    }



    template <typename _ArrayType>
    inline _ArrayType *array<_ArrayType>::data() const {
        return this->arr;
    }
    
    
    
    template <typename _ArrayType>
    inline void array<_ArrayType>::shrink() {
        this->extended_size = this->array_size;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::is_equal(const array<_ArrayType> &right) const {
        return (*this == right) ? true : false;
    }




    template <typename _ArrayType>
    inline bool array<_ArrayType>::is_equal(const std::vector<_ArrayType> &right) const {
        return (*this == right) ? true : false;
    }



    template <typename A>
    inline bool array<A>::is_empty() const {
        return (this->length() == 0) ? true : false;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::is_inside(const array<_ArrayType> &ob) const {
        return (this->index(ob) == -1) ? false : true;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::is_inside(const std::vector<_ArrayType> &ob) const {
        return (this->index(ob) == -1) ? false : true;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator!=(const array<_ArrayType> &left) const {
        return (*this == left) ? false : true;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator!=(const std::vector<_ArrayType> &left) const {
        return (*this == left) ? false : true;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator>(const array<_ArrayType> &right) const {
        return (this->length() > right.length()) ? true : false;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator>(const std::vector<_ArrayType> &right) const {
        return (this->length() > right.size()) ? true : false;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator>=(const array<_ArrayType> &right) const {
        return (this->length() >= right.length()) ? true : false;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator>=(const std::vector<_ArrayType> &right) const {
        return (this->length() >= right.size()) ? true : false;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator<=(const array<_ArrayType> &right) const {
        return (this->length() <= right.length()) ? true : false;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator<=(const std::vector<_ArrayType> &right) const {
        return (this->length() <= right.size()) ? true : false;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator<(const array<_ArrayType> &right) const {
        return (this->length() < right.length()) ? true : false;
    }



    template <typename _ArrayType>
    inline bool array<_ArrayType>::operator<(const std::vector<_ArrayType> &right) const {
        return (this->length() < right.size()) ? true : false;
    }


    template <typename _ArrayType>
    inline const _ArrayType array<_ArrayType>::operator[](const int index) const {
        return this->get(index);
    }
}


#endif
