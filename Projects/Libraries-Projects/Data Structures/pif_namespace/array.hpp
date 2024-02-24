#ifndef ARRAY
#define ARRAY

#define ARRAY_GAP 3
#define BAD_ALLOCATION_MESSAGE std::cout << "Error Allocating Memory." << std::endl

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // srand(...)
#include <ctime> // time(NULL);
#include <typeinfo> // *typeid(type).name();

// Check retrun types.
//Todo: more pointers on this->arr[i]
// I have a function for error memory allocating.
// Becarefuul for call be value and const...
// becarefull on delete


namespace pif {
    class string;

    template <typename _ArrayType>
    class array {

        private:
            _ArrayType *arr;
            int array_size, extended_size;

            template <typename U>
            void exit_if_not_allocated(U* arr);

            pif::array<_ArrayType> selection_sort(const bool rev=false);
            pif::array<_ArrayType> bubble_sort(const bool rev=false);
            pif::array<_ArrayType> insertion_sort(const bool rev=false);
            pif::array<_ArrayType> improved_selection_sort(const bool rev=false);

            bool __link_iter_to_vector(std::vector<_ArrayType> &vect, typename std::vector<_ArrayType>::iterator &it) const;
            bool __link_iter_to_vector(const std::vector<_ArrayType> &vect, typename std::vector<_ArrayType>::const_iterator &it) const;
            int __get_random_number(const int min, const int max) const;
            pif::array<int> __new_indexes() const;
        
        public:
            class __common_iterator;
            class const_iterator;
            class iterator;

            friend string;

            array();
            array(const std::initializer_list<_ArrayType> &init_list);
            array(const std::vector<_ArrayType> &constructing_vector);
            array(const pif::array<_ArrayType> &constructing_array);
            array(int total_size, const _ArrayType &value);
            array(const std::string &constructing_string);
            ~array();

            _ArrayType get(int index) const;
            pif::array<_ArrayType>::iterator get_iter(const int index) const; //
            pif::array<_ArrayType>::const_iterator get_citer(const int index) const; //

            inline int length() const;
            inline int size() const;
            inline _ArrayType *data() const;
            void set_length(int new_size, const _ArrayType &value);
            void set_size(int new_extended_size);
            inline void shrink();

            pif::array<_ArrayType> push_back(const _ArrayType &value);
            pif::array<_ArrayType> push_front(const _ArrayType &value);
            pif::array<_ArrayType> insert(int index, const _ArrayType &value);
            pif::array<_ArrayType> insert(pif::array<_ArrayType>::iterator &position, const _ArrayType new_value);
            pif::array<_ArrayType> insert(pif::array<_ArrayType>::const_iterator &position, const _ArrayType new_value);
            pif::array<_ArrayType> extend(const pif::array<_ArrayType> &aArray);
            pif::array<_ArrayType> extend(const pif::array<_ArrayType> &aArray, int start);
            pif::array<_ArrayType> extend(const std::vector<_ArrayType> &aVector);
            pif::array<_ArrayType> extend(const std::vector<_ArrayType> &aVector, int start); // Here
            pif::array<_ArrayType> extend(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end, const pif::array<_ArrayType> &iters_object);
            pif::array<_ArrayType> extend(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end, const pif::array<_ArrayType> &iters_object);
            pif::array<_ArrayType> extend(typename std::vector<_ArrayType>::iterator &start, typename std::vector<_ArrayType>::iterator &end, std::vector<_ArrayType> &iters_object);
            pif::array<_ArrayType> extend(typename std::vector<_ArrayType>::const_iterator &start, typename std::vector<_ArrayType>::const_iterator &end, std::vector<_ArrayType> &iters_object);

            pif::array<_ArrayType> pop_back();
            pif::array<_ArrayType> pop_front();
            pif::array<_ArrayType> clear();
            void reset();
            pif::array<_ArrayType> pop(const int index, const int total_pos=0);
            pif::array<_ArrayType> pop(pif::array<_ArrayType>::iterator &position);
            pif::array<_ArrayType> pop(pif::array<_ArrayType>::const_iterator &position);
            pif::array<_ArrayType> pop(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end);
            pif::array<_ArrayType> pop(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end);
            pif::array<_ArrayType> remove(const _ArrayType value, const bool dupl=false);
            pif::array<_ArrayType> remove(const pif::array<_ArrayType> &arr, const bool dupl=false);
            pif::array<_ArrayType> remove(const std::vector<_ArrayType> &vect, const bool dupl=false);
            pif::array<_ArrayType> remove_last(const _ArrayType value);
            pif::array<_ArrayType> remove_last(const pif::array<_ArrayType> &arr);
            pif::array<_ArrayType> remove_last(const std::vector<_ArrayType> &vect);
            pif::array<_ArrayType> &delete_dupls();
            pif::array<_ArrayType> set();

            pif::array<_ArrayType> sort(const int sorting_alg=0, const bool rev=false);
            pif::array<_ArrayType> rev_array();
            pif::array<_ArrayType> rev_array(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end);
            pif::array<_ArrayType> rev_array(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end);
            pif::array<_ArrayType> shuffle();
            pif::array<_ArrayType> copy(const pif::array<_ArrayType> &ob);
            pif::array<_ArrayType> copy(const pif::array<_ArrayType> &ob, const int start_i, const int end_i);
            pif::array<_ArrayType> copy(const std::vector<_ArrayType> &ob);
            pif::array<_ArrayType> copy(const std::vector<_ArrayType> &ob, const int start_i, const int end_i);
            pif::array<_ArrayType> copy(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end, const pif::array<_ArrayType> &iters_object);
            pif::array<_ArrayType> copy(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end, const pif::array<_ArrayType> &iters_object);
            pif::array<_ArrayType> copy(typename std::vector<_ArrayType>::iterator &start, typename std::vector<_ArrayType>::iterator &end, std::vector<_ArrayType> &iters_object);
            pif::array<_ArrayType> copy(typename std::vector<_ArrayType>::const_iterator &start, typename std::vector<_ArrayType>::const_iterator &end, std::vector<_ArrayType> &iters_object);

            std::vector<_ArrayType> to_vector();
            const std::vector<_ArrayType> to_cvector();
            const pif::array<_ArrayType> to_carray();
            pif::array<_ArrayType> invoke(_ArrayType (*funct)(_ArrayType));
            pif::array<_ArrayType> filter(bool (*funct)(_ArrayType));

            int count(const _ArrayType value) const;
            int b_search(const _ArrayType value) const;
            int index(const _ArrayType value) const;
            int index(const _ArrayType value, const int start, const int end, const int step=1) const;
            int index(const pif::array<_ArrayType> &ob) const;
            int index(const std::vector<_ArrayType> &ob) const;
            pif::array<int> indexes(const _ArrayType value) const;
            pif::array<int> indexes(const pif::array<_ArrayType> &ob) const;
            pif::array<int> indexes(const std::vector<_ArrayType> &ob) const;
            int last_index(const _ArrayType value) const;
            int last_index(const pif::array<_ArrayType> &ob) const;
            int last_index(const std::vector<_ArrayType> &ob) const;
            pif::array<_ArrayType> swap(const int first_index, const int second_index);
            pif::array<_ArrayType> swap(pif::array<_ArrayType>::iterator &first, pif::array<_ArrayType>::iterator &second);
            pif::array<_ArrayType> swap(pif::array<_ArrayType>::const_iterator &first, pif::array<_ArrayType>::const_iterator &second);
            pif::array<_ArrayType> swap(pif::array<_ArrayType> &other_arr);
            pif::array<_ArrayType> swap(std::vector<_ArrayType> &vect);
            pif::array<_ArrayType> slice(const int start, const int end, const int step=1) const;
            std::string join(const std::string &seperator) const;
            std::string join(const char seperator) const;

            _ArrayType first() const;
            _ArrayType last() const;

            iterator begin() const;
            iterator rbegin() const;
            iterator end() const;
            iterator rend() const;
            int at(pif::array<_ArrayType>::iterator &it) const;
            const const_iterator cbegin() const;
            const const_iterator crbegin() const;
            const const_iterator cend() const;
            const const_iterator crend() const;
            int at(pif::array<_ArrayType>::const_iterator &it) const;

            bool is_sorted(const int sorting_algorithm=0, const bool rev=false) const;
            inline bool is_equal(const pif::array<_ArrayType> &right) const;
            inline bool is_equal(const std::vector<_ArrayType> &right) const;
            bool is_symmetric() const;
            inline bool is_empty() const;
            bool is_inside(const _ArrayType value) const;
            inline bool is_inside(const pif::array<_ArrayType> &ob) const;
            inline bool is_inside(const std::vector<_ArrayType> &ob) const;

            pif::array<_ArrayType> &operator=(const pif::array<_ArrayType> &left);
            pif::array<_ArrayType> &operator=(const std::vector<_ArrayType> &ob);

            bool operator==(const pif::array<_ArrayType> &left) const;
            bool operator==(const std::vector<_ArrayType> &left) const;
            inline bool operator!=(const pif::array<_ArrayType> &left) const;
            inline bool operator!=(const std::vector<_ArrayType> &left) const;
            inline bool operator>(const pif::array<_ArrayType> &right) const;
            inline bool operator>(const std::vector<_ArrayType> &right) const;
            inline bool operator>=(const pif::array<_ArrayType> &right) const;
            inline bool operator>=(const std::vector<_ArrayType> &right) const;
            inline bool operator<(const pif::array<_ArrayType> &right) const;
            inline bool operator<(const std::vector<_ArrayType> &right) const;
            inline bool operator<=(const pif::array<_ArrayType> &right) const;
            inline bool operator<=(const std::vector<_ArrayType> &right) const;
            
            inline const _ArrayType operator[](const int index) const;
            _ArrayType &operator[](const int index);
            
            pif::array<_ArrayType> operator+=(const int value);
            pif::array<_ArrayType> operator+=(const pif::array<_ArrayType> &right);
            pif::array<_ArrayType> operator+=(const std::vector<_ArrayType> &right);
            pif::array<_ArrayType> operator-=(const int total_indexes);
            pif::array<_ArrayType> operator-=(const pif::array<_ArrayType> &right);
            pif::array<_ArrayType> operator-=(const std::vector<_ArrayType> &right);
            pif::array<_ArrayType> operator*=(const int total_copies);

            pif::array<_ArrayType> operator+(const _ArrayType value) const;
            pif::array<_ArrayType> operator+(const pif::array<_ArrayType> &right) const;
            pif::array<_ArrayType> operator+(const std::vector<_ArrayType> &right) const;
            pif::array<_ArrayType> operator-(const int value) const;
            pif::array<_ArrayType> operator-(const pif::array<_ArrayType> &right) const;
            pif::array<_ArrayType> operator-(const std::vector<_ArrayType> &right) const;
            pif::array<_ArrayType> operator*(const int value) const;

            pif::array<_ArrayType> operator++(int);
            pif::array<_ArrayType> operator++();
            pif::array<_ArrayType> operator--(int);
            pif::array<_ArrayType> operator--();

            bool __link_iter_to_arr(typename pif::array<_ArrayType>::iterator &it);
            bool __link_iter_to_arr(typename pif::array<_ArrayType>::const_iterator &it);


            class __common_iterator {
                public:
                    _ArrayType *current;

                    bool operator!=(const __common_iterator &element) const;
                    bool operator==(const __common_iterator &element) const;
                    bool operator==(const typename std::vector<_ArrayType>::iterator &element) const;
                    bool operator>(const __common_iterator &_it) const;
                    bool operator>=(const __common_iterator &_it) const;
                    bool operator<(const __common_iterator &_it) const;
                    bool operator<=(const __common_iterator &_it) const;
                    __common_iterator &operator++();
                    __common_iterator &operator--();
                    __common_iterator &operator++(int);
                    __common_iterator &operator--(int);
            };

            class const_iterator: public __common_iterator {
                public:
                    const_iterator();
                    const_iterator(_ArrayType *elem);
                    const _ArrayType &operator*() const;
                    const const_iterator operator+(int value) const;
                    const const_iterator operator-(int value) const;
            };

            class iterator: public __common_iterator {
                public:
                    iterator();
                    iterator(_ArrayType *elem);
                    _ArrayType& operator*();
                    iterator& operator+=(int value);
                    iterator& operator-=(int value);
                    iterator operator+(int value);
                    iterator operator-(int value);
            };

            template <typename _Type> friend std::ostream &operator<<(std::ostream &left, const pif::array<_Type> &ob);
            template <typename _Type> friend std::istream &operator>>(std::istream &left, const pif::array<_Type> &ob);
    };
}

#include "array_in.inl"
#include "array_code.cpp"
#endif
