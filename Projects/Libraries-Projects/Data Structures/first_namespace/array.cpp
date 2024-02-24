#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <bits/stdc++.h>
#include <math.h>


#define ARRAY_GAP 3


//Todo: fix extend so __link_iter_to_arr work for also other arrs.
//Todo: make array compatable with string.
//Todo: insert and extend methods with iterators fix. (the clue is the pif::iter_link_to_array() function).
//Todo: maby see again the iteartors calsses. (make __common_iterator private)
//Todo: functions with iterators.
//Todo: '&' on methods.
//Todo: Exceptions.


namespace pif {
    class string;

    template <typename _ArrayType>
    class array {
        private:
            _ArrayType *arr;
            int *array_size, *extended_size;

            pif::array<_ArrayType> selection_sort(const bool rev=false);
            pif::array<_ArrayType> bubble_sort(const bool rev=false);
            pif::array<_ArrayType> insertion_sort(const bool rev=false);
            pif::array<_ArrayType> improved_selection_sort(const bool rev=false);

        public:
            class __common_iterator;
            class const_iterator;
            class iterator;

            friend string;

            array();
            array(const std::vector<_ArrayType> &args);
            array(const std::initializer_list<_ArrayType> &ai);
            array(const int size, const _ArrayType value);
            array(const pif::array<_ArrayType> &ob);
            array(const std::string &str);

            ~array();

            _ArrayType get(const int index) const;
            pif::array<_ArrayType>::iterator get_iter(const int index) const;
            pif::array<_ArrayType>::const_iterator get_citer(const int index) const;

            inline int length() const;
            inline int size() const;
            inline _ArrayType *data() const;
            void set_size(const int size, const _ArrayType value);
            void change_capacity(const int new_extended_size);
            inline void shrink();

            pif::array<_ArrayType> push_back(const _ArrayType value);
            pif::array<_ArrayType> push_front(const _ArrayType value);
            pif::array<_ArrayType> insert(const int index, const _ArrayType value);
            pif::array<_ArrayType> insert(pif::array<_ArrayType>::iterator &position, const _ArrayType new_value);
            pif::array<_ArrayType> insert(pif::array<_ArrayType>::const_iterator &position, const _ArrayType new_value);
            pif::array<_ArrayType> extend(const pif::array<_ArrayType> &aArray);
            pif::array<_ArrayType> extend(const pif::array<_ArrayType> &aArray, const int start);
            pif::array<_ArrayType> extend(const std::vector<_ArrayType> &aVector);
            pif::array<_ArrayType> extend(const std::vector<_ArrayType> &aVector, const int start);
            pif::array<_ArrayType> extend(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end, const pif::array<_ArrayType> &iters_object);
            pif::array<_ArrayType> extend(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end, const pif::array<_ArrayType> &iters_object);
            pif::array<_ArrayType> extend(typename std::vector<_ArrayType>::iterator &start, typename std::vector<_ArrayType>::iterator &end, std::vector<_ArrayType> &iters_object);
            pif::array<_ArrayType> extend(typename std::vector<_ArrayType>::const_iterator &start, typename std::vector<_ArrayType>::const_iterator &end, std::vector<_ArrayType> &iters_object);

            pif::array<_ArrayType> pop_back();
            pif::array<_ArrayType> pop_front();
            pif::array<_ArrayType> clear();
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
            std::string join();
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


            class __common_iterator {
                public:
                    _ArrayType *current;

                    bool operator!=(const __common_iterator &element) const;
                    bool operator==(const __common_iterator &element) const;
                    bool operator==(const typename std::vector<_ArrayType>::iterator &element) const;
                    inline bool operator>(const __common_iterator &_it) const;
                    inline bool operator>=(const __common_iterator &_it) const;
                    inline bool operator<(const __common_iterator &_it) const;
                    inline bool operator<=(const __common_iterator &_it) const;
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


            friend std::ostream &operator<<(std::ostream &left, const pif::array<_ArrayType> &ob) {
                left << "[";
                for (int i=0; i<ob.length(); i++) {
                    if (ob.length() - 1 == i) {
                        left << ob[i];   
                    }
                    else {
                        left << ob[i] << ", "; 
                    }
                }
                left << "]";

                return left; 
            }

            friend std::istream &operator>>(std::istream &left, const pif::array<_ArrayType> &ob) {
                _ArrayType user_input;
                std::cout << "Enter value at " << ob.length() << " index position: ";
                left >> user_input;

                ob.push_back(user_input);    

                return left;
            }
    };


    template <typename _ArrayType> bool iter_link_to_array(const pif::array<_ArrayType> &arr, typename pif::array<_ArrayType>::iterator &it);
    template <typename _ArrayType> bool iter_link_to_array(const pif::array<_ArrayType> &arr, typename pif::array<_ArrayType>::const_iterator &it);
    template <typename _ArrayType> bool iter_link_to_array(const std::vector<_ArrayType> &vect, typename std::vector<_ArrayType>::iterator &it);
    template <typename _ArrayType> bool iter_link_to_array(const std::vector<_ArrayType> &vect, typename std::vector<_ArrayType>::const_iterator &it);

    template <typename _ArrayType> pif::array<_ArrayType> to_array(const std::vector<_ArrayType> &vect);
    template <typename _ArrayType> pif::array<_ArrayType> to_array(const _ArrayType arr[], const int size);
    template <typename _ArrayType> std::vector<_ArrayType> to_vector(const pif::array<_ArrayType> &arr);
    template <typename _ArrayType> std::vector<_ArrayType> to_vector(const _ArrayType arr[], const int size);
    
    template <typename _CheckType, typename _ObjectType> inline bool isinstance(const _ObjectType &obj); // usage: pif::isinstance <check_type> (object)
    
    template <typename _ArrayType> int sum(const pif::array<_ArrayType> &arr);
    template <typename _ArrayType> int sum(const std::vector<_ArrayType> &vect);
    template <typename _ArrayType> int max(const pif::array<_ArrayType> &arr);
    template <typename _ArrayType> int max(const std::vector<_ArrayType> &vect);
    template <typename _ArrayType> int min(const pif::array<_ArrayType> &arr);
    template <typename _ArrayType> int min(const std::vector<_ArrayType> &vect);

    template <typename _ArrayType> pif::array<_ArrayType> invoke(pif::array<_ArrayType> &arr, _ArrayType (*funct)(_ArrayType));
    template <typename _ArrayType> std::vector<_ArrayType> invoke(std::vector<_ArrayType> &vect, _ArrayType (*funct)(_ArrayType));
    template <typename _ArrayType> pif::array<_ArrayType> filter(pif::array<_ArrayType> &arr, bool (*funct)(_ArrayType));
    template <typename _ArrayType> std::vector<_ArrayType> filter(std::vector<_ArrayType> &vect, bool (*funct)(_ArrayType));

    int get_cstring_size(const char* string);
}










template <typename _ArrayType>
pif::array<_ArrayType>::array() {
    this->array_size = new(std::nothrow) int;
    this->extended_size = new(std::nothrow) int;
    if (!this->extended_size || !this->array_size) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    this->arr = nullptr;

    *this->array_size = 0;
    *this->extended_size = ARRAY_GAP;
}





template <typename _ArrayType>
pif::array<_ArrayType>::array(const std::initializer_list<_ArrayType> &il) {
    this->array_size = new(std::nothrow) int;
    this->extended_size = new(std::nothrow) int;
    if (!this->extended_size || !this->array_size) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    *this->array_size = il.size();
    *this->extended_size = il.size() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType [this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<il.size(); i++) {
        this->arr[i] = *(il.begin()+i);
    }
}





template <typename _ArrayType>
pif::array<_ArrayType>::array(const std::vector<_ArrayType> &args) {
    this->array_size = new(std::nothrow) int;
    this->extended_size = new(std::nothrow) int;
    if (!this->extended_size || !this->array_size) {std::cout << "Error Allocating Memory." << std::endl; this->~array();exit(0);}

    *this->array_size = args.size();
    *this->extended_size = args.size() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType [this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<args.size(); i++) {
        this->arr[i] = args[i];
    }
}





template <typename _ArrayType>
pif::array<_ArrayType>::array(const array<_ArrayType> &ob) {
    this->array_size = new(std::nothrow) int;
    this->extended_size = new(std::nothrow) int;
    if (!this->extended_size || !this->array_size) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    *this->array_size = ob.length();
    *this->extended_size = ob.length() + ARRAY_GAP;
    
    this->arr = new(std::nothrow) _ArrayType [this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<ob.length(); i++) {
        this->arr[i] = ob.get(i);
    }
}





template <typename _ArrayType>
pif::array<_ArrayType>::array(const int size, const _ArrayType value) {
    if (size < 0) {
        std::cout << "Size argument must be positive or zero, not negative." << std::endl;
        exit(0);
    }

    this->array_size = new(std::nothrow) int;
    this->extended_size = new(std::nothrow) int;
    if (!this->extended_size || !this->array_size) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    *this->array_size = size;
    *this->extended_size = size + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType [this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<size; i++) {
        this->arr[i] = value; 
    }
}





template <typename _ArrayType>
pif::array<_ArrayType>::array(const std::string &str) {
    this->array_size = new(std::nothrow) int;
    this->extended_size = new(std::nothrow) int;
    if (!this->array_size || !this->extended_size) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    *this->array_size = str.size();
    *this->extended_size = str.size() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType[this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->arr[i] = str[i];
    }
}





template <typename _ArrayType>
pif::array<_ArrayType>::~array() {
    if (this->arr) {
        delete[] this->arr;
    }
    if (this->array_size) {
        delete this->array_size;
    }
    if (this->extended_size) {
        delete this->extended_size;
    }
}





template <typename _ArrayType>
_ArrayType pif::array<_ArrayType>::get(const int index) const {
    if (index >= 0 && index < this->length()) {
        return this->arr[index];
    }

    std::cout << "Invalid Index Position." << std::endl;
    this->~array();
    exit(0);
}





template <typename _ArrayType>
typename pif::array<_ArrayType>::iterator pif::array<_ArrayType>::get_iter(const int index) const {
    if (index > (this->length()-1) || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->~array();
        exit(0);
    }

    return this->begin() + index;
}





template <typename _ArrayType>
typename pif::array<_ArrayType>::const_iterator pif::array<_ArrayType>::get_citer(const int index) const {
    if (index > (this->length()-1) || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->~array();
        exit(0);
    }
    
    return this->cbegin() + index;
}





template <typename _ArrayType>
inline int pif::array<_ArrayType>::length() const {
    return *this->array_size;
}





template <typename _ArrayType>
inline int pif::array<_ArrayType>::size() const {
    return *this->extended_size;
}





template <typename _ArrayType>
inline _ArrayType *pif::array<_ArrayType>::data() const {
    return this->arr;
}





template <typename _ArrayType>
void pif::array<_ArrayType>::set_size(const int size, const _ArrayType value) {
    if (size < 0) {
        std::cout << "Cannot compress the array to negative size." << std::endl;
        this->~array();
        exit(0);
    }

    if (size >= this->length()) {
        for (int i=this->length(); i<size; i++) {
            this->push_back(value);
        }
    }
    else {
        const int total_deletions = this->length() - size;
        for (int i=0; i<total_deletions; i++) {
            this->pop_back();
        }
    }
}





template <typename _ArrayType>
void pif::array<_ArrayType>::change_capacity(const int new_extended_size) {
    if (new_extended_size < this->length()) {
        std::cout << "New memory size must be highter than the actual one." << std::endl;
        this->~array();
        exit(0);
    }

    _ArrayType *temp = new(std::nothrow) _ArrayType[this->length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        temp[i] = this->arr[i];
    }

    if (this->arr) {
        delete[] this->arr;
    }

    *this->extended_size = new_extended_size;

    this->arr = new(std::nothrow) _ArrayType[this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->arr[i] = temp[i];
    }

    delete[] temp;
}





template <typename _ArrayType>
inline void pif::array<_ArrayType>::shrink() {
    *this->extended_size = *this->array_size;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::push_back(const _ArrayType value) {
    if (this->length() == this->size()) {
        (*this->array_size) ++;
        *this->extended_size = this->length() + ARRAY_GAP;

        _ArrayType *temp = new(std::nothrow) _ArrayType [this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length()-1; i++) {
            temp[i] = this->arr[i];
        }
        temp[this->length()-1] = value;

        if (this->arr) {
            delete[] this->arr;
        }

        this->arr = new(std::nothrow) _ArrayType [this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}
        
        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;
    }
    else {
        (*this->array_size) ++;

        if (this->length() - 1 == 0) {
            this->arr = new(std::nothrow) _ArrayType [this->size()];
            if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}
            
            this->arr[0] = value;
        }
        else {
            this->arr[this->length() - 1] = value;
        }
    }

    return *this;
}




template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::push_front(const _ArrayType value) {
    if (this->length() == this->size()) {
        (*this->array_size) ++;
        *this->extended_size = this->length() + ARRAY_GAP;

        _ArrayType *temp = new(std::nothrow) _ArrayType [this->size()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length()-1; i++) {
            temp[i+1] = this->arr[i];
        }
        temp[0] = value;

        if (this->arr) {
            delete[] this->arr;
        }

        this->arr = new(std::nothrow) _ArrayType [this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;
    }
    else {
        (*this->array_size) ++;

        if (this->length() - 1 == 0) {
            this->arr = new(std::nothrow) _ArrayType [this->size()];
            if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

            this->arr[0] = value;
        }
        else {
            for (int i=this->length()-2; i>=0; i--) {
                this->arr[i+1] = this->arr[i];
            }
            this->arr[0] = value;
        }
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::insert(const int index, const _ArrayType value) {
    if (index > (this->length()) || index < 0) {
        std::cout << "Invalid index position." << std::endl;
        this->~array();
        exit(0);
    }

    if (this->length() == 0) {
        (*this->array_size) ++;

        this->arr = new(std::nothrow) _ArrayType[this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        this->arr[0] = value;
    }
    else {
        if (this->length() == this->size()) {
            (*this->array_size) ++;
            *this->extended_size = this->length() + ARRAY_GAP;
            
            _ArrayType *temp = new(std::nothrow) _ArrayType[this->length()];
            if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

            int j = 0;
            for (int i=0; i<this->length(); i++) {
                if (i == index) {
                    temp[i] = value;
                }
                else {
                    temp[i] = this->arr[j];
                    j++;
                }
            }

            if (this->arr) {
                delete[] this->arr;
            }

            this->arr = new(std::nothrow) _ArrayType[this->size()];
            if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

            for (int i=0; i<this->length(); i++) {
                this->arr[i] = temp[i];
            }

            delete[] temp;
        }
        else {
            (*this->array_size) ++;

            for (int i=this->length()-2; i>=index; i--) {
                this->arr[i+1] = this->arr[i];
            }
            this->arr[index] = value;
        }
    }

    return *this;
}





template <typename _ArrayType> 
pif::array<_ArrayType> pif::array<_ArrayType>::insert(pif::array<_ArrayType>::iterator &position, const _ArrayType new_value) {
    if (!pif::iter_link_to_array(*this, position)) {
        std::cout << "The iterator that has be passed is either is not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    this->insert(this->at(position), new_value);

    return *this;
}





template <typename _ArrayType> 
pif::array<_ArrayType> pif::array<_ArrayType>::insert(pif::array<_ArrayType>::const_iterator &position, const _ArrayType new_value) {
    if (!pif::iter_link_to_array(*this, position)) {
        std::cout << "The iterator that has be passed is either is not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    this->insert(this->at(position), new_value);

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::extend(const array<_ArrayType> &aArray) {
    const int prior_size = aArray.length();
    for (int i=0; i<prior_size; i++) {
        this->push_back(aArray.get(i));
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::extend(const pif::array<_ArrayType> &aArray, const int start) {
    if (start > this->length() || start < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->~array();
        exit(0);
    }

    _ArrayType *temp = new(std::nothrow) _ArrayType[this->length() + aArray.length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    int j = 0;
    int k = 0;
    for (int i=0; i<this->length()+aArray.length(); i++) {
        if (i >= start && i < aArray.length() + start) {
            temp[i] = aArray[j];
            j++;
        }
        else {
            temp[i] = this->arr[k];
            k++;
        }
    }
    delete[] this->arr;

    *this->array_size = this->length() + aArray.length();
    *this->extended_size = this->length() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType[this->length()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->arr[i] = temp[i];
    }
    delete[] temp;

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::extend(const std::vector<_ArrayType> &aVector) {
    for (int i=0; i<aVector.size(); i++) {
        this->push_back(aVector[i]);
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::extend(const std::vector<_ArrayType> &aVector, const int start) {
    if (start > this->length() || start < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->~array();
        exit(0);
    }
    
    for (int i=aVector.size()-1; i>=0; i--) {
        this->insert(start, aVector[i]);
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::extend(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end, const pif::array<_ArrayType> &iters_object) {
    if (!pif::iter_link_to_array(iters_object, start) || !pif::iter_link_to_array(iters_object, end)) {
        std::cout << "The iterators that have be passed are either are not created by the 'iters_object' or are out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    int start_i = iters_object.at(start);
    int end_i = iters_object.at(end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }

    for (pif::array<_ArrayType>::iterator it=start; it!=end; ++it) {
        this->push_back(*it);
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::extend(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end, const pif::array<_ArrayType> &iters_object) {
    if (!pif::iter_link_to_array(iters_object, start) || !pif::iter_link_to_array(iters_object, end)) {
        std::cout << "The iterators that have be passed are either are not created by the 'iters_object' or are out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    int start_i = iters_object.at(start);
    int end_i = iters_object.at(end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }

    for (pif::array<_ArrayType>::const_iterator it=start; it!=end; ++it) {
        this->push_back(*it);
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::extend(typename std::vector<_ArrayType>::iterator &start, typename std::vector<_ArrayType>::iterator &end, std::vector<_ArrayType> &iters_object) {
    if (!pif::iter_link_to_array(iters_object, start) || !pif::iter_link_to_array(iters_object, end)) {
        std::cout << "The iterators that have be passed are either are not created by the 'iters_object' or are out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    int start_i = std::distance(iters_object.begin(), start);
    int end_i = std::distance(iters_object.begin(), end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }

    for (typename std::vector<_ArrayType>::iterator it=start; it!=end; ++it) {
        this->push_back(*it);
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::extend(typename std::vector<_ArrayType>::const_iterator &start, typename std::vector<_ArrayType>::const_iterator &end, std::vector<_ArrayType> &iters_object) {
    if (!pif::iter_link_to_array(iters_object, start) || !pif::iter_link_to_array(iters_object, end)) {
        std::cout << "The iterators that have be passed are either are not created by the 'iters_object' or are out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    int start_i = std::distance(iters_object.cbegin(), start);
    int end_i = std::distance(iters_object.cbegin(), end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }

    for (typename std::vector<_ArrayType>::const_iterator it=start; it!=end; ++it) {
        this->push_back(*it);
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::pop_back() {
    if (this->length() == 0) {
        std::cout << "No elements to delete." << std::endl;
        this->~array();
        exit(0);
    }
    else {
        (*this->array_size) --;
        *this->extended_size = this->length() + ARRAY_GAP;

        _ArrayType *temp = new(std::nothrow) _ArrayType [this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            temp[i] = this->arr[i];
        }
        delete[] this->arr;

        this->arr = new(std::nothrow) _ArrayType [this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }
        delete[] temp;
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::pop_front() {
    if (this->length() == 0) {
        std::cout << "No elements to delete." << std::endl;
        this->~array();
        exit(0);
    }
    else {
        (*this->array_size) --;
        *this->extended_size = this->length() + ARRAY_GAP;

        _ArrayType *temp = new(std::nothrow) _ArrayType [this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            temp[i] = this->arr[i+1];
        }

        delete[] this->arr;

        this->arr = new(std::nothrow) _ArrayType [this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}
        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }
        delete[] temp;
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::clear() {
    *this->array_size = 0;
    *this->extended_size = ARRAY_GAP;

    if (this->arr) {
        delete[] this->arr;
    }

    this->arr = new(std::nothrow) _ArrayType [this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::pop(const int index, const int total_pos) {
    if (index < 0 || total_pos < 0 || index + total_pos > this->length() - 1) {
        std::cout << "Invalid Index Position." << std::endl;
        this->~array();
        exit(0);
    }
    else {
        (*this->array_size) -= (total_pos + 1);
        *this->extended_size = this->length() + ARRAY_GAP;
        
        _ArrayType *temp = new(std::nothrow) _ArrayType [this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        int j=0;
        for (int i=0; i<this->length()+total_pos+1; i++) {
            if (i < index || i > index + total_pos) {
                temp[j] = this->arr[i];
                j ++;
            }
        }
        delete[] this->arr;

        this->arr = new(std::nothrow) _ArrayType [this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }
        delete[] temp;
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::remove(const _ArrayType value, const bool dupl) {
    if (this->length() == 0) {
        std::cout << "Array is empty." << std::endl;
        this->~array();
        exit(0);
    }

    for (int i=0; i<this->length(); i++) {
        if (this->arr[i] == value) {
            this->pop(i, 0);
            if (dupl == true) {i --;} else {break;}
        }
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::remove(const pif::array<_ArrayType> &arr, const bool dupl) {
    _ArrayType *temp = new(std::nothrow) _ArrayType[this->length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}
    
    pif::array<int> indexes = this->indexes(arr);
    bool stop_del = (dupl) ? false : true;
    bool skip;
    int p = 0;

    for (int i=0; i<this->length(); i++) {
        skip = false;
        for (int j=0; j<indexes.length(); j++) {
            if (i == indexes[j]) {
                skip = true;
                if (stop_del) {
                    indexes.clear();
                }
                break;
            }
        }
        if (skip) {
            i += arr.length() - 1;
        }
        else {
            temp[p] = this->arr[i];
            p++;
        }
    }

    delete[] this->arr;

    *this->array_size = p;
    *this->extended_size = this->length() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType[this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->arr[i] = temp[i];
    }

    delete[] temp;

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::remove(const std::vector<_ArrayType> &vect, const bool dupl) {
    _ArrayType *temp = new(std::nothrow) _ArrayType[this->length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}
    
    pif::array<int> indexes = this->indexes(vect);
    bool stop_del = (dupl) ? false : true;
    bool skip;
    int p = 0;

    for (int i=0; i<this->length(); i++) {
        skip = false;
        for (int j=0; j<indexes.length(); j++) {
            if (i == indexes[j]) {
                skip = true;
                if (stop_del) {
                    indexes.clear();
                }
                break;
            }
        }
        if (skip) {
            i += vect.size() - 1;
        }
        else {
            temp[p] = this->arr[i];
            p++;
        }
    }

    delete[] this->arr;

    *this->array_size = p;
    *this->extended_size = this->length() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType[this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->arr[i] = temp[i];
    }

    delete[] temp;

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::remove_last(const _ArrayType value) {
    if (this->length() == 0) {
        std::cout << "Array is empty." << std::endl;
        this->~array();
        exit(0);
    }

    for (int i=this->length()-1; i>=0; i--) {
        if (this->arr[i] == value) {
            this->pop(i, 0);
            break;
        }
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::remove_last(const pif::array<_ArrayType> &arr) {
    pif::array<_ArrayType> temp = arr;

    this->rev_array();
    temp.rev_array();

    this->remove(temp, false);

    this->rev_array();

    return *this;    
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::remove_last(const std::vector<_ArrayType> &vect) {
    pif::array<_ArrayType> temp = vect;

    this->remove_last(temp);

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::pop(pif::array<_ArrayType>::iterator &position) {
    if (!pif::iter_link_to_array(*this, position)) {
        std::cout << "The iterator that has be passed is either is not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    this->pop(this->at(position), 0);

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::pop(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end) {
    if (!pif::iter_link_to_array(*this, start) || !pif::iter_link_to_array(*this, end)) {
        std::cout << "The iterators that have be passed ar either are not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    int start_i = this->at(start);
    int end_i = this->at(end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }

    this->pop(start_i, (end_i-start_i-1));

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::pop(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end) {
    if (!pif::iter_link_to_array(*this, start) || !pif::iter_link_to_array(*this, end)) {
        std::cout << "The iterators that have be passed ar either are not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    int start_i = this->at(start);
    int end_i = this->at(end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }

    this->pop(start_i, (end_i-start_i-1));

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::pop(pif::array<_ArrayType>::const_iterator &position) {
    if (!pif::iter_link_to_array(*this, position)) {
        std::cout << "The iterator that has be passed is either is not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    this->pop(this->at(position), 0);

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> &pif::array<_ArrayType>::delete_dupls() {
    for (int i=0; i<this->length(); i++) {
        if (i < 0) {i = 0;}
        for (int j=i+1; j<this->length(); j++) {
            if (this->arr[i] == this->arr[j]) {
                this->pop(i, 0);
                i --;
                j --;
            }
        }
    }
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::set() {
    this->sort();
    this->delete_dupls();

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::sort(const int sorting_alg, const bool rev) {
    switch (sorting_alg) {
        case 0:
            this->selection_sort(rev);
            break;
        case 1:
            this->bubble_sort(rev);
            break;
        case 2:
            this->insertion_sort(rev);
            break;
        case 3:
            this->improved_selection_sort(rev);
            break;
        default:
            std::cout << "Invalid Option: Allowed is 0-3." << std::endl;
            this->~array();
            exit(0);
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::rev_array() {
    for (int i=0; i<this->length()/2; i++) {
        _ArrayType temp = arr[i];
        arr[i] = arr[this->length()-1-i];
        arr[this->length()-1-i] = temp;
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::rev_array(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end) {
    if (!pif::iter_link_to_array(*this, start) || !pif::iter_link_to_array(*this, end)) {
        std::cout << "The iterators that have be passed are either are not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    int start_i = this->at(start);
    int end_i = this->at(end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }
    
    pif::array<_ArrayType> temp = this->slice(start_i, end_i);
    temp.rev_array();

    int j = 0;
    for (int i=0; i<this->length(); i++) {
        if (i >= start_i && i < end_i) {
            this->arr[i] = temp[j];
            j ++;
        }
    }
    
    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::rev_array(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end) {
    if (!pif::iter_link_to_array(*this, start) || !pif::iter_link_to_array(*this, end)) {
        std::cout << "The iterators that have be passed are either are not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    int start_i = this->at(start);
    int end_i = this->at(end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }
    
    pif::array<_ArrayType> temp = this->slice(start_i, end_i);
    temp.rev_array();

    int j = 0;
    for (int i=0; i<this->length(); i++) {
        if (i >= start_i && i < end_i) {
            this->arr[i] = temp[j];
            j ++;
        }
    }
    
    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::shuffle() {
    srand(time(NULL));

    _ArrayType *temp = new(std::nothrow) _ArrayType[this->length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        temp[i] = this->arr[i];
    }

    std::random_shuffle(temp, temp+this->length());

    for (int i=0; i<this->length(); i++) {
        this->arr[i] = temp[i];
    }
    delete[] temp;

    return *this;
}





template <typename _ArrayType>
bool pif::array<_ArrayType>::is_sorted(const int sorting_algorithm, const bool rev) const {
    pif::array<_ArrayType> temp = *this;

    return (*this == temp.sort(sorting_algorithm, rev));
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::copy(const pif::array<_ArrayType> &ob) {
    *this = ob;

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::copy(const pif::array<_ArrayType> &ob, const int start_i, const int end_i) {
    if (start_i < 0 || end_i < 0 || end_i > ob.length() || start_i > end_i) {
        std::cout << "Invalid Index Position." << std::endl;
        this->~array();
        exit(0);
    }

    *this = ob.slice(start_i, end_i);

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::copy(const std::vector<_ArrayType> &ob) {
    *this = ob;

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::copy(const std::vector<_ArrayType> &ob, const int start_i, const int end_i) {
    if (start_i < 0 || end_i < 0 || end_i > ob.size() || start_i > end_i) {
        std::cout << "Invalid Index Position." << std::endl;
        this->~array();
        exit(0);
    }

    _ArrayType *temp = new(std::nothrow) _ArrayType[ob.size()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    int j = 0;
    for (int i=start_i; i<end_i; i++) {
        temp[j] = ob[i];
        j ++;
    }

    if (this->arr) {
        delete[] this->arr;
    }

    *this->array_size = j;
    *this->extended_size = this->length() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType[this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->arr[i] = temp[i];
    }

    delete[] temp;

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::copy(pif::array<_ArrayType>::iterator &start, pif::array<_ArrayType>::iterator &end, const pif::array<_ArrayType> &iters_object) {
    int start_i = iters_object.at(start);
    int end_i = iters_object.at(end);

    if ((start_i == -1) || (end_i == -1)) {
        std::cout << "Invalid Iterator Position: Iterator out of bounds." << std::endl;
        this->~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }

    this->copy(iters_object.slice(start_i, end_i));

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::copy(pif::array<_ArrayType>::const_iterator &start, pif::array<_ArrayType>::const_iterator &end, const pif::array<_ArrayType> &iters_object) {
    int start_i = iters_object.at(start);
    int end_i = iters_object.at(end);

    if ((start_i == -1) || (end_i == -1)) {
        std::cout << "Invalid Iterator Position: Iterator out of bounds." << std::endl;
        this->~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0);
    }

    this->copy(iters_object.slice(start_i, end_i));

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::copy(typename std::vector<_ArrayType>::iterator &start, typename std::vector<_ArrayType>::iterator &end, std::vector<_ArrayType> &iters_object) {
    int start_i = std::distance(iters_object.begin(), start);
    int end_i = std::distance(iters_object.begin(), end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0); 
    }
    else if ((start_i > iters_object.size()) || (end_i > iters_object.size())) {
        std::cout << "Invalid Iterator Position: Iterator out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    delete[] this->arr;
    
    *this->array_size = end_i - start_i;
    *this->extended_size = this->length() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType[this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    int j = 0;
    for (int i=0; i<iters_object.size(); i++) {
        if (i >= start_i && i < end_i) {
            this->arr[j] = iters_object[i];
            j ++;
        }
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::copy(typename std::vector<_ArrayType>::const_iterator &start, typename std::vector<_ArrayType>::const_iterator &end, std::vector<_ArrayType> &iters_object) {
    int start_i = std::distance(iters_object.cbegin(), start);
    int end_i = std::distance(iters_object.cbegin(), end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Position: Starting iterator must be lower than the ening one." << std::endl;
        this->~array();
        exit(0); 
    }
    else if ((start_i > iters_object.size()) || (end_i > iters_object.size())) {
        std::cout << "Invalid Iterator Position: Iterator out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    delete[] this->arr;
    
    *this->array_size = end_i - start_i;
    *this->extended_size = this->length() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType[this->size()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    int j = 0;
    for (int i=0; i<iters_object.size(); i++) {
        if (i >= start_i && i < end_i) {
            this->arr[j] = iters_object[i];
            j ++;
        }
    }

    return *this;
}





template <typename _ArrayType>
std::vector<_ArrayType> pif::array<_ArrayType>::to_vector() {
    std::vector<_ArrayType> v;
    for (int i=0; i<this->length(); i++) {
        v.push_back(this->arr[i]);
    }

    this->clear();

    return v;
}





template <typename _ArrayType>
const std::vector<_ArrayType> pif::array<_ArrayType>::to_cvector() {
    std::vector<_ArrayType> temp;
    for (int i=0; i<this->length(); i++) {
        temp.push_back(this->arr[i]);
    }

    this->clear();

    const std::vector<_ArrayType> v = temp;

    return v;
}





template <typename _ArrayType>
const pif::array<_ArrayType> pif::array<_ArrayType>::to_carray() {
    const pif::array<_ArrayType> arr = *this;

    this->clear();

    return arr;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::invoke(_ArrayType (*funct)(_ArrayType)) {
    for (int i=0; i<this->length(); i++) {
        this->arr[i] = funct(this->arr[i]);
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::filter(bool (*funct)(_ArrayType)) {
    _ArrayType *temp = new(std::nothrow) _ArrayType[this->length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    int j = 0;
    for (int i=0; i<this->length(); i++) {
        if (funct(this->arr[i])) {
            temp[j] = this->arr[i];
            j++;
        }
    }

    delete[] this->arr;

    *this->array_size = j;
    *this->extended_size = this->length() + ARRAY_GAP;

    this->arr = new(std::nothrow) _ArrayType[this->length()];
    if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->arr[i] = temp[i];
    }

    delete[] temp;

    return *this;
}





template <typename _ArrayType>
int pif::array<_ArrayType>::count(const _ArrayType value) const {
    int count_var = 0;

    for (int i=0; i<this->length(); i++) {
        if (this->arr[i] == value) {
            count_var ++;
        }
    }

    return count_var; 
}





template <typename _ArrayType>
int pif::array<_ArrayType>::b_search(const _ArrayType value) const {
    if (!this->is_sorted(0, false)) {
        std::cout << "This methods works only if the array is sorted, normally." << std::endl;
        this->~array();
        exit(0);
    }

    int max_steps = log2(this->length()) + 1;
    int count = 1;
    int start = 0;
    int end = this->length();

    while (true) {
        int middle = (start + end) / 2;

        if (value == this->arr[middle]) {
            return middle;
        }
        else if (value > this->arr[middle]) {
            start = middle + 1;
        }
        else if (value < this->arr[middle]) {
            end = middle - 1;
        }

        if (count == max_steps) {
            return -1;
        }
        count ++;
    }
}





template <typename _ArrayType>
int pif::array<_ArrayType>::index(const _ArrayType value) const {
    int index_var = -1;

    for (int i=0; i<this->length(); i++) {
        if (this->arr[i] == value) {
            index_var = i;
            break;
        }
    }

    return index_var;
}





template <typename _ArrayType>
int pif::array<_ArrayType>::index(const _ArrayType value, const int start, const int end, const int step) const {
    if (step > 0) {
        if (start >= 0 && end <= this->length() && start < end) {
            for (int i=start; i<end; i+=step) {
                if (this->arr[i] == value) {
                    return i;
                }
            }
        }
    }
    else if (step < 0) {
        if (end >= 0 && start < this->length() && start > end) {
            for (int i=start; i>=end; i+=step) {
                if (this->arr[i] == value) {
                    return i;
                }
            }
        }
    }

    return -1;
}





template <typename _ArrayType>
int pif::array<_ArrayType>::index(const pif::array<_ArrayType> &ob) const {
    if (ob.length() * this->length() == 0 || ob.length() > this->length()) {
        return -1;
    }

    for (int i=0; i<this->length(); i++) {
        if (ob == this->slice(i, i+ob.length())) {
            return i;
        }
    }

    return -1;
}





template <typename _ArrayType>
int pif::array<_ArrayType>::index(const std::vector<_ArrayType> &ob) const {
    if (ob.size() * this->length() == 0 || ob.size() > this->length()) {
        return -1;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->slice(i, i+ob.size()) == ob) {
            return i;
        }
    }

    return -1;
}





template <typename _ArrayType>
pif::array<int> pif::array<_ArrayType>::indexes(const _ArrayType value) const {
    pif::array<int> indexes_array;

    for (int i=0; i<this->length(); i++) {
        if (this->arr[i] == value) {
            indexes_array.push_back(i);
        }
    }

    return indexes_array;
}





template <typename _ArrayType>
pif::array<int> pif::array<_ArrayType>::indexes(const pif::array<_ArrayType> &ob) const {
    pif::array<int> temp;

    if (ob.length() * this->length() == 0 || ob.length() > this->length()) {
        return temp;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->slice(i, i+ob.length()) == ob) {
            temp.push_back(i);
        }
    }

    return temp;
}





template <typename _ArrayType>
pif::array<int> pif::array<_ArrayType>::indexes(const std::vector<_ArrayType> &ob) const {
    pif::array<int> temp;

    if (ob.size() * this->length() == 0 || ob.size() > this->length()) {
        return temp;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->slice(i, i+ob.size()) == ob) {
            temp.push_back(i);
        }
    }

    return temp;
}





template <typename _ArrayType>
int pif::array<_ArrayType>::last_index(const _ArrayType value) const {
    pif::array<int> indexes = this->indexes(value);

    if (indexes.length() != 0) {
        return indexes.get(indexes.length() - 1);
    }
    return -1;
}





template <typename _ArrayType>
int pif::array<_ArrayType>::last_index(const pif::array<_ArrayType> &ob) const {
    pif::array<int> indexes = this->indexes(ob);

    return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
}





template <typename _ArrayType>
int pif::array<_ArrayType>::last_index(const std::vector<_ArrayType> &ob) const {
    pif::array<int> indexes = this->indexes(ob);

    return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::swap(const int first_index, const int second_index) {
    if ((first_index <= this->length() - 1 && first_index >= 0) && (second_index >= 0 && second_index <= this->length() - 1)) {
        _ArrayType temp = this->arr[first_index];
        this->arr[first_index] = this->arr[second_index];
        this->arr[second_index] = temp;
    }
    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::swap(pif::array<_ArrayType>::iterator &first, pif::array<_ArrayType>::iterator &second) {
    if (!pif::iter_link_to_array(*this, first) || !pif::iter_link_to_array(*this, second)) {
        std::cout << "The iterators that have be passed are either are not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    this->swap(this->at(first), this->at(second));

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::swap(pif::array<_ArrayType>::const_iterator &first, pif::array<_ArrayType>::const_iterator &second) {
    if (!pif::iter_link_to_array(*this, first) || !pif::iter_link_to_array(*this, second)) {
        std::cout << "The iterators that have be passed are either are not created by the 'this' or is out of bounds." << std::endl;
        this->~array();
        exit(0);
    }

    this->swap(this->at(first), this->at(second));

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::swap(pif::array<_ArrayType> &other_arr) {
    const int this_length = this->length();
    const int other_length = other_arr.length();

    for (int i=0; i<other_length; i++) {
        this->push_back(other_arr[i]);
    }

    for (int i=0; i<this_length; i++) {
        other_arr.push_back(this->arr[i]);
    }

    for (int i=0; i<this_length; i++) {
        this->pop_front();
    }

    for (int i=0; i<other_length; i++) {
        other_arr.pop_front();
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::swap(std::vector<_ArrayType> &vect) {
    const int this_length = this->length();
    const int other_length = vect.size();

    for (int i=0; i<other_length; i++) {
        this->push_back(vect[i]);
    }

    for (int i=0; i<this_length; i++) {
        vect.push_back(this->arr[i]);
    }

    for (int i=0; i<this_length; i++) {
        this->pop_front();
    }

    std::reverse(vect.begin(), vect.end());
    for (int i=0; i<other_length; i++) {
        vect.pop_back();
    }
    std::reverse(vect.begin(), vect.end());

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::slice(const int start, const int end, const int step) const {
    pif::array<_ArrayType> arr;
    
    if (step > 0) {
        if (start >= 0 && end <= this->length() && start < end) {
            for (int i=start; i<end; i+=step) {
                arr.push_back(this->get(i));
            }
        }
    }
    else if (step < 0) {
        if (end >= 0 && start < this->length() && start > end) {
            for (int i=start; i>=end; i+=step) {
                arr.push_back(this->get(i));
            }
        }
    }

    return arr;
}





template <typename _ArrayType>
std::string pif::array<_ArrayType>::join(const std::string &seperator) const {
    std::string ret_str;
    for (int i=0; i<this->length(); i++) {
        if (i != (this->length()-1)) {
            ret_str += std::to_string(this->arr[i]);
            ret_str += seperator;
        }
        else {
            ret_str += std::to_string(this->arr[i]);
        }
    }

    return ret_str;
}





template <typename _ArrayType>
std::string pif::array<_ArrayType>::join(const char seperator) const {
    std::string ret_str;
    for (int i=0; i<this->length(); i++) {
        if (i != (this->length()-1)) {
            ret_str += std::to_string(this->arr[i]);
            ret_str += seperator;
        }
        else {
            ret_str += std::to_string(this->arr[i]);
        }
    }

    return ret_str;
}





template <typename _ArrayType>
_ArrayType pif::array<_ArrayType>::first() const {
    if (this->length() == 0) {
        std::cout << "Array is empty." << std::endl;
        exit(0);
    }

    return arr[0];
}





template <typename _ArrayType>
_ArrayType pif::array<_ArrayType>::last() const {
    if (this->length() == 0) {
        std::cout << "Array is empty." << std::endl;
        exit(0);
    }

    return arr[this->array_size - 1];
}




template <typename _ArrayType>
inline bool pif::array<_ArrayType>::is_equal(const pif::array<_ArrayType> &right) const {
    return (*this == right) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::is_equal(const std::vector<_ArrayType> &right) const {
    return (*this == right) ? true : false;
}





template <typename _ArrayType>
bool pif::array<_ArrayType>::is_symmetric() const {
    pif::array<_ArrayType> temp = *this;

    return (*this == temp.rev_array()) ? true : false;
}





template <typename A>
inline bool pif::array<A>::is_empty() const {
    return (this->length() == 0) ? true : false;
}





template <typename _ArrayType>
bool pif::array<_ArrayType>::is_inside(const _ArrayType value) const {
    for (int i=0; i<this->length(); i++) {
        if (this->arr[i] == value) {
            return true;
        }
    }

    return false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::is_inside(const pif::array<_ArrayType> &ob) const {
    return (this->index(ob) == -1) ? false : true;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::is_inside(const std::vector<_ArrayType> &ob) const {
    return (this->index(ob) == -1) ? false : true;
}





template <typename _ArrayType>
pif::array<_ArrayType> &pif::array<_ArrayType>::operator=(const pif::array<_ArrayType> &left) { 
    if (*this != left) {

        if (this->arr) {
            delete [] this->arr;
        }
        
        *this->array_size = left.length();
        *this->extended_size = left.size();

        this->arr = new(std::nothrow) _ArrayType [this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = left.arr[i];
        }
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> &pif::array<_ArrayType>::operator=(const std::vector<_ArrayType> &ob) {
    if (*this != ob) {

        if (this->arr) {
            delete [] this->arr;
        }

        *this->array_size = ob.size();
        *this->extended_size = ob.capacity();

        this->arr = new(std::nothrow) _ArrayType [this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = ob[i];
        }
    }

    return *this; 
}





template <typename _ArrayType>
bool pif::array<_ArrayType>::operator==(const pif::array<_ArrayType> &left) const {
    if (this->length() != left.length()) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->arr[i] != left.arr[i]) {
            return false;
        }
    }

    return true;
}





template <typename _ArrayType>
bool pif::array<_ArrayType>::operator==(const std::vector<_ArrayType> &left) const {
    if (this->length() != left.size()) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->arr[i] != left[i]) {
            return false;
        }
    }

    return true;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator!=(const pif::array<_ArrayType> &left) const {
    return (*this == left) ? false : true;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator!=(const std::vector<_ArrayType> &left) const {
    return (*this == left) ? false : true;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator>(const pif::array<_ArrayType> &right) const {
    return (this->length() > right.length()) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator>(const std::vector<_ArrayType> &right) const {
    return (this->length() > right.size()) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator>=(const pif::array<_ArrayType> &right) const {
    return (this->length() >= right.length()) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator>=(const std::vector<_ArrayType> &right) const {
    return (this->length() >= right.size()) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator<=(const pif::array<_ArrayType> &right) const {
    return (this->length() <= right.length()) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator<=(const std::vector<_ArrayType> &right) const {
    return (this->length() <= right.size()) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator<(const pif::array<_ArrayType> &right) const {
    return (this->length() < right.length()) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::operator<(const std::vector<_ArrayType> &right) const {
    return (this->length() < right.size()) ? true : false;
}





template <typename _ArrayType>
_ArrayType &pif::array<_ArrayType>::operator[](const int index) {
    if (index < 0 || index > (this->length()-1)) {
        std::cout << "Invalid Index Position." << std::endl;
        exit(0);
    } 

    return this->arr[index];
}





template <typename _ArrayType>
inline const _ArrayType pif::array<_ArrayType>::operator[](const int index) const {
    return this->get(index);
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator+=(const int value) {
    if (value <= 0) {
        std::cout << "Given value must be bigger than 0." << std::endl;
        this->~array();
        exit(0);
    }
    else {
        _ArrayType *temp = new(std::nothrow) _ArrayType[this->length() + value];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        char template_type = *typeid(temp[0]).name(); // Getting the type of _ArrayType.
        std::string type;

        if (template_type == 'i') {
            type = "int";
        }
        else if (template_type == 's') {
            type = "short int";
        }
        else if (template_type == 'l') {
            type = "long int";
        }
        else if (template_type == 'x') {
            type = "long long int";
        }
        else if (template_type == 'y') {
            type = "unsigned long long int";
        }
        else if (template_type == 'm') {
            type = "unsigned long int";
        }
        else if (template_type == 't') {
            type = "unsigned short int";
        }
        else if (template_type == 'j') {
            type = "unsigned int";
        }
        else if (template_type == 'f') {
            type = "float";
        }
        else if (template_type == 'd') {
            type = "double";
        }
        else if (template_type == 'e') {
            type = "long double";
        }
        else if (template_type == 'c') {
            type = "char";
        }
        else if (template_type == 'b') {
            type = "bool";
        }
        else if (template_type == 'N') {
            type = "string";
        }
        else {
            std::cout << "No such type supported." << std::endl;
            this->~array();
            exit(0);
        }

        for (int i=0; i<this->length()+value; i++) {
            if (i >= this->length()) {
                if (type == "string" || type == "char") {
                    temp[i] = '_';
                }
                else {
                    temp[i] = ' ' - 32;
                }
            }
            else {
                temp[i] = this->arr[i];
            }
        }

        if (this->arr) {
            delete[] this->arr;
        }

        (*this->array_size) += value;
        *this->extended_size = this->length() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType[this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator+=(const pif::array<_ArrayType> &right) {
    *this = this->extend(right);

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator+=(const std::vector<_ArrayType> &right) {
    *this = this->extend(right);

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator-=(const int total_indexes) {
    if (this->length() < total_indexes) {
        std::cout << "No such elements to delete." << std::endl;
        this->~array();
        exit(0);
    }
    for (int i=0; i<total_indexes; i++) {
        this->pop_back();
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator-=(const pif::array<_ArrayType> &right) {
    if (*this == right) {
        this->clear();
    }
    else {
        for (int j=0; j<right.length(); j++) {
            for (int i=0; i<this->length(); i++) {
                if (this->arr[i] == right.arr[j]) {
                    this->pop(i, 0);
                    i --;
                    j --;
                }
            }
        }
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator-=(const std::vector<_ArrayType> &right) {
    if (*this == right) {
        this->clear();
    }
    else {
        for (int i=0; i<this->array_size; i++) {
            for (int j=0; j<right.size(); j++) {
                if (this->arr[i] == right[j]) {
                    this->pop(i, 0);
                    i --;
                    j --;
                }
            }
        }
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator*=(const int total_copies) {
    if (total_copies < 0) {
        std::cout << "Only positive values are accepted." << std::endl;
        this->~array();
        exit(0);
    }
    else if (total_copies == 0) {
        this->clear();
    }
    else {
        int original_size = this->length();
        for (int i=0; i<total_copies - 1; i++) {
            for (int j=0; j<original_size; j++) {
                this->push_back(this->arr[j]);
            }
        }
    }

    return *this; 
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator+(const _ArrayType value) const {
    pif::array<_ArrayType> temp = *this;
    
    return temp.push_back(value);
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator+(const pif::array<_ArrayType> &right) const {
    pif::array<_ArrayType> temp = *this;

    return temp.extend(right);
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator+(const std::vector<_ArrayType> &right) const {
    pif::array<_ArrayType> temp = *this;

    return temp.extend(right);
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator-(const int value) const {
    pif::array<_ArrayType> temp = *this;

    if (value > temp.length()) {
        std::cout << "No such elements to delete." << std::endl;
        this->~array();
        exit(0);
    }

    for (int i=0; i<value; i++) {
        temp.pop_back();
    }

    return temp;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator-(const pif::array<_ArrayType> &right) const {
    pif::array<_ArrayType> temp = *this;

    return (temp -= right);
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator-(const std::vector<_ArrayType> &right) const {
    pif::array<_ArrayType> temp = *this;

    return (temp -= right);
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator*(const int value) const {
    pif::array<_ArrayType> temp = *this;

    return (temp *= value);
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator++(int) {
    (*this) += 1;

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator++() {
    (*this) ++;

    for (int i=0; i<this->length(); i++) {
        _ArrayType temp = this->arr[i];
        this->arr[i] = this->arr[this->length() - 1];
        this->arr[this->length() - 1] = temp;
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator--(int) {
    if (this->array_size == 0) {
        std::cout << "Array is empty." << std::endl;
        this->~array();
        exit(0);
    }
    this->pop_back();

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::operator--() {
    if (this->array_size == 0) {
        std::cout << "Array is empty." << std::endl;
        this->~array();
        exit(0);
    }
    this->pop_front();

    return *this;
}





template <typename _ArrayType>
typename pif::array<_ArrayType>::iterator pif::array<_ArrayType>::begin() const {
    return iterator(this->arr);
}





template <typename _ArrayType>
typename pif::array<_ArrayType>::iterator pif::array<_ArrayType>::end() const {
    return iterator(this->arr + this->length());
}





template <typename _ArrayType>
typename pif::array<_ArrayType>::iterator pif::array<_ArrayType>::rbegin() const {
    return iterator(this->arr + this->length() - 1);
}





template <typename _ArrayType>
typename pif::array<_ArrayType>::iterator pif::array<_ArrayType>::rend() const {
    return iterator(this->arr - 1);
}





template <typename _ArrayType>
const typename pif::array<_ArrayType>::const_iterator pif::array<_ArrayType>::cbegin() const {
    return const_iterator(this->arr);
}





template <typename _ArrayType>
const typename pif::array<_ArrayType>::const_iterator pif::array<_ArrayType>::cend() const {
    return const_iterator(this->arr + this->length());
}





template <typename _ArrayType>
const typename pif::array<_ArrayType>::const_iterator pif::array<_ArrayType>::crbegin() const {
    return const_iterator(this->arr + this->length() - 1);
}





template <typename _ArrayType>
const typename pif::array<_ArrayType>::const_iterator pif::array<_ArrayType>::crend() const {
    return const_iterator(this->arr - 1);
}





template <typename _ArrayType>
int pif::array<_ArrayType>::at(pif::array<_ArrayType>::iterator &it) const {
    for (int i=0; i<this->length(); i++) {
        if (it == (this->begin()+i)) {
            return i;
        }
    }

    return -1;
}





template <typename _ArrayType>
int pif::array<_ArrayType>::at(pif::array<_ArrayType>::const_iterator &it) const {
    for (int i=0; i<this->length(); i++) {
        if (it == (this->begin()+i)) {
            return i;
        }
    }

    return -1;
}





template <typename _ArrayType>
bool pif::array<_ArrayType>::__common_iterator::operator!=(const pif::array<_ArrayType>::__common_iterator &element) const {
    if (this->current != element.current) {
        return true;
    }
    return false;
}






template <typename _ArrayType>
bool pif::array<_ArrayType>::__common_iterator::operator==(const pif::array<_ArrayType>:: __common_iterator &element) const {
    if (*this != element) {
        return false;
    }
    return true;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::__common_iterator::operator>(const pif::array<_ArrayType>::__common_iterator &_it) const {
    return (this->current > _it.current) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::__common_iterator::operator>=(const pif::array<_ArrayType>::__common_iterator &_it) const {
    return (this->current >= _it.current) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::__common_iterator::operator<(const pif::array<_ArrayType>::__common_iterator &_it) const {
    return (this->current < _it.current) ? true : false;
}





template <typename _ArrayType>
inline bool pif::array<_ArrayType>::__common_iterator::operator<=(const pif::array<_ArrayType>::__common_iterator &_it) const {
    return (this->current <= _it.current) ? true : false;
}





template <typename _ArrayType>
typename pif::array<_ArrayType>::__common_iterator &pif::array<_ArrayType>::__common_iterator::operator++() {
    ++ this->current;

    return *this;
}






template <typename _ArrayType>
typename pif::array<_ArrayType>::__common_iterator &pif::array<_ArrayType>::__common_iterator::operator--() {
    -- this->current;

    return *this;
}






template <typename _ArrayType>
typename pif::array<_ArrayType>::__common_iterator &pif::array<_ArrayType>::__common_iterator::operator++(int) {
    this->current ++;

    return *this;
}






template <typename _ArrayType>
typename pif::array<_ArrayType>::__common_iterator &pif::array<_ArrayType>::__common_iterator::operator--(int) {
    this->current --;

    return *this;
}




template<typename _ArrayType>
pif::array<_ArrayType>::const_iterator::const_iterator() {}





template<typename _ArrayType>
pif::array<_ArrayType>::const_iterator::const_iterator(_ArrayType *elem) {
    this->current = elem;
}





template<typename _ArrayType>
const _ArrayType &pif::array<_ArrayType>::const_iterator::operator*() const {
    return *this->current;
}





template<typename _ArrayType>
const typename pif::array<_ArrayType>::const_iterator pif::array<_ArrayType>::const_iterator::operator+(int value) const {
    pif::array<_ArrayType>::const_iterator temp = this->current + value;

    return temp;
}





template<typename _ArrayType>
const typename pif::array<_ArrayType>::const_iterator pif::array<_ArrayType>::const_iterator::operator-(int value) const {
    pif::array<_ArrayType>::const_iterator temp = this->current - value;

    return temp;
}




template<typename _ArrayType>
pif::array<_ArrayType>::iterator::iterator() {}




template<typename _ArrayType>
pif::array<_ArrayType>::iterator::iterator(_ArrayType *elem) {
    this->current = elem;
}




template<typename _ArrayType>
_ArrayType& pif::array<_ArrayType>::iterator::operator*() {
    return *this->current;
}




template<typename _ArrayType>
typename pif::array<_ArrayType>::iterator& pif::array<_ArrayType>::iterator::operator+=(int value) {
    this->current += value;

    return *this;
}




template<typename _ArrayType>
typename pif::array<_ArrayType>::iterator& pif::array<_ArrayType>::iterator::operator-=(int value) {
    this->current -= value;

    return *this;
}




template<typename _ArrayType>
typename pif::array<_ArrayType>::iterator pif::array<_ArrayType>::iterator::operator+(int value) {
    pif::array<_ArrayType>::iterator temp;

    return this->current + value;
}




template<typename _ArrayType>
typename pif::array<_ArrayType>::iterator pif::array<_ArrayType>::iterator::operator-(int value) {
    pif::array<_ArrayType>::iterator temp;

    return this->current - value;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::selection_sort(const bool rev) {
    if (!rev) {
        for (int i=0; i<this->length(); i++) {
            int j = i;
            _ArrayType min = this->arr[j];

            for (int k=i+1; k<this->length(); k++) {
                if (this->arr[k] < min) {
                    j = k;
                    min = this->arr[j];
                }
            }

            _ArrayType temp = this->arr[i];
            this->arr[i]= this->arr[j];
            this->arr[j] = temp;
        }
    }
    else {
        for (int i=0; i<this->length(); i++) {
            int j = i;
            _ArrayType max = this->arr[j];

            for (int k=i+1; k<this->length(); k++) {
                if (this->arr[k] > max) {
                    j = k;
                    max = this->arr[j];
                }
            }

            _ArrayType temp = this->arr[i];
            this->arr[i]= this->arr[j];
            this->arr[j] = temp;
        }
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::bubble_sort(const bool rev) {
    if (!rev) {
        for (int i=this->length(); i>0; i--) {
            for (int j=this->length()-1; j>0; j--) {

                if (this->arr[j] < this->arr[j-1]) {
                    _ArrayType temp = this->arr[j];
                    this->arr[j] = this->arr[j-1];
                    this->arr[j-1] = temp;
                }
            }
        }
    }
    else {
        for (int i=this->length(); i>0; i--) {
            for (int j=this->length()-1; j>0; j--) {

                if (this->arr[j] > this->arr[j-1]) {
                    _ArrayType temp = this->arr[j];
                    this->arr[j] = this->arr[j-1];
                    this->arr[j-1] = temp;
                }
            }
        }
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::insertion_sort(const bool rev) {
    if (!rev) {
        int j;
        _ArrayType key;
        for (int i=1; i<this->length(); i++) {
            key = this->arr[i];
            j = i - 1;
            while ((key < this->arr[j]) && (j >= 0)) {
                this->arr[j+1] = this->arr[j];
                j --;
            }
            this->arr[j+1] = key;
        }
    }
    else {
        int j;
        _ArrayType key;
        for (int i=1; i<this->length(); i++) {
            key = this->arr[i];
            j = i - 1;
            while ((key > this->arr[j]) && (j >= 0)) {
                this->arr[j+1] = this->arr[j];
                j --;
            }
            this->arr[j+1] = key;
        }
    }

    return *this;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::array<_ArrayType>::improved_selection_sort(const bool rev) {
    if (!rev) {
        _ArrayType temp;
        int max_i;
        int start = 0;

        while (start < this->length()) {
            max_i = start;
            for (int i=start; i<this->length(); i++) {
                if (this->arr[i] < this->arr[max_i]) {
                    max_i = i;
                }
            }
            temp = this->arr[max_i];
            this->arr[max_i] = this->arr[start];
            this->arr[start] = temp;

            start ++;
        }
    }
    else {
        _ArrayType temp;
        int max_i;
        int start = 0;

        while (start < this->length()) {
            max_i = start;
            for (int i=start; i<this->length(); i++) {
                if (this->arr[i] > this->arr[max_i]) {
                    max_i = i;
                }
            }
            temp = this->arr[max_i];
            this->arr[max_i] = this->arr[start];
            this->arr[start] = temp;

            start ++;
        }
    }

    return *this;
}





template <typename _ArrayType>
bool pif::iter_link_to_array(const pif::array<_ArrayType> &arr, typename pif::array<_ArrayType>::iterator &it) {
    for (typename pif::array<_ArrayType>::iterator arr_it=arr.begin(); arr_it!=arr.end(); arr_it++) {
        if (arr_it == it) {
            return true;
        }
    }
    return false;
}





template <typename _ArrayType>
bool pif::iter_link_to_array(const pif::array<_ArrayType> &arr, typename pif::array<_ArrayType>::const_iterator &it) {
    for (typename pif::array<_ArrayType>::const_iterator arr_it=arr.cbegin(); arr_it!=arr.cend(); arr_it++) {
        if (arr_it == it) {
            return true;
        }
    }
    return false;
}





template <typename _ArrayType>
bool pif::iter_link_to_array(const std::vector<_ArrayType> &vect, typename std::vector<_ArrayType>::iterator &it) {
    for (typename std::vector<_ArrayType>::const_iterator vect_it=vect.begin(); vect_it!=vect.end(); vect_it++) {
        if (vect_it == it) {
            return true;
        }
    }
    return false;
}





template <typename _ArrayType>
bool pif::iter_link_to_array(const std::vector<_ArrayType> &vect, typename std::vector<_ArrayType>::const_iterator &it) {
    for (typename std::vector<_ArrayType>::const_iterator vect_it=vect.cbegin(); vect_it!=vect.cend(); vect_it++) {
        if (vect_it == it) {
            return true;
        }
    }
    return false;
}





template <typename _ArrayType>
std::vector<_ArrayType> pif::to_vector(const pif::array<_ArrayType> &arr) {
    std::vector<_ArrayType> temp;
    for (int i=0; i<arr.length(); i++) {
        temp.push_back(arr[i]);
    }

    return temp;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::to_array(const std::vector<_ArrayType> &vect) {
    return pif::array<_ArrayType> (vect);
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::to_array(const _ArrayType arr[], const int size) {
    pif::array<_ArrayType> temp;
    for (int i=0; i<size; i++) {
        temp.push_back(arr[i]);
    }

    return temp;
}





template <typename _ArrayType>
std::vector<_ArrayType> pif::to_vector(const _ArrayType arr[], const int size) {
    std::vector<_ArrayType> temp;
    for (int i=0; i<size; i++) {
        temp.push_back(arr[i]);
    }

    return temp;
}





template <typename _CheckType, typename _ObjectType> 
inline bool pif::isinstance(const _ObjectType &obj) {
    return (*typeid(_CheckType).name() == *typeid(_ObjectType).name()) ? true : false;
}





template <typename _ArrayType>
int pif::sum(const pif::array<_ArrayType> &arr) {
    if (arr.is_empty()) {
        std::cout << "Array is empty." << std::endl;
        return -1;
    }

    if (*typeid(_ArrayType).name() == *typeid(int).name()) {
        int x = 0;
        for (int elem: arr) {
            x += elem;
        }
        return x;
    }

    std::cout << "Only 'int' type arrays are quilified for 'sum' function." << std::endl;
    return -1;
}





template <typename _ArrayType>
int pif::sum(const std::vector<_ArrayType> &vect) {
    if (vect.size() == 0) {
        std::cout << "Vector is empty." << std::endl;
        return -1;
    }

    if (*typeid(_ArrayType).name() == *typeid(int).name()) {
        int x = 0;
        for (int elem: vect) {
            x += elem;
        }
        return x;
    }

    std::cout << "Only 'int' type arrays are quilified for 'sum' function." << std::endl;
    return -1;
}





template <typename _ArrayType>
int pif::max(const pif::array<_ArrayType> &arr) {
    if (arr.is_empty()) {
        std::cout << "Array is empty." << std::endl;
        return -1;
    }

    if (*typeid(_ArrayType).name() == *typeid(int).name()) {
        int max = arr[0];
        for (int elem: arr) {
            if (elem > max) {
                max = elem;
            }
        }
        return max;
    }

    std::cout << "Only 'int' type arrays are quilified for 'max' function." << std::endl;
    return -1;
}





template <typename _ArrayType>
int pif::max(const std::vector<_ArrayType> &vect) {
    if (vect.size() == 0) {
        std::cout << "vector is empty." << std::endl;
        return -1;
    }

    if (*typeid(_ArrayType).name() == *typeid(int).name()) {
        int max = vect[0];
        for (int elem: vect) {
            if (elem > max) {
                max = elem;
            }
        }
        return max;
    }

    std::cout << "Only 'int' type arrays are quilified for 'max' function." << std::endl;
    return -1;
}





template <typename _ArrayType>
int pif::min(const pif::array<_ArrayType> &arr) {
    if (arr.is_empty()) {
        std::cout << "Array is empty." << std::endl;
        return -1;
    }

    if (*typeid(_ArrayType).name() == *typeid(int).name()) {
        int min = arr[0];
        for (size_t elem: arr) {
            if (elem < min) {
                min = elem;
            }
        }
        return min;
    }

    std::cout << "Only 'int' type arrays are quilified for 'min' function." << std::endl;
    return -1;
}





template <typename _ArrayType>
int pif::min(const std::vector<_ArrayType> &vect) {
    if (vect.size() == 0) {
        std::cout << "Vector is empty." << std::endl;
        return -1;
    }

    if (*typeid(_ArrayType).name() == *typeid(int).name()) {
        int min = vect[0];
        for (size_t elem: vect) {
            if (elem < min) {
                min = elem;
            }
        }
        return min;
    }

    std::cout << "Only 'int' type arrays are quilified for 'min' function." << std::endl;
    return -1;   
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::invoke(pif::array<_ArrayType> &arr, _ArrayType (*funct)(_ArrayType)) {
    for (int i=0; i<arr.length(); i++) {
        arr[i] = funct(arr[i]);
    }

    return arr;
}





template <typename _ArrayType>
std::vector<_ArrayType> pif::invoke(std::vector<_ArrayType> &vect, _ArrayType (*funct)(_ArrayType)) {
    for (int i=0; i<vect.size(); i++) {
        vect[i] = funct(vect[i]);
    }

    return vect;
}





template <typename _ArrayType>
pif::array<_ArrayType> pif::filter(pif::array<_ArrayType> &arr, bool (*funct)(_ArrayType)) {
    _ArrayType *temp = new(std::nothrow) _ArrayType[arr.length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; exit(0);}

    int j = 0;
    for (int i=0; i<arr.length(); i++) {
        if (funct(arr[i])) {
            temp[j] = arr[i];
            j++;
        }
    }

    arr.clear();

    for (int i=0; i<j; i++) {
        arr.push_back(temp[i]);
    }

    delete[] temp;

    return arr;
}





template <typename _ArrayType>
std::vector<_ArrayType> pif::filter(std::vector<_ArrayType> &vect, bool (*funct)(_ArrayType)) {
    _ArrayType *temp = new(std::nothrow) _ArrayType[vect.size()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; exit(0);}

    int j = 0;
    for (int i=0; i<vect.size(); i++) {
        if (funct(vect[i])) {
            temp[j] = vect[i];
            j++;
        }
    }

    vect.clear();

    for (int i=0; i<j; i++) {
        vect.push_back(temp[i]);
    }

    delete[] temp;

    return vect;
}





int pif::get_cstring_size(const char* string) {
    int index = 0;
    while (string[index] != '\0') {
        index ++;
    }

    return index;
}
