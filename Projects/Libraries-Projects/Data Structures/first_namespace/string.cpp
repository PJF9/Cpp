#include "array.cpp"
#include <string>


//! Error: The string class is not updated to a new array.hpp file, so it needs modifications.

//Todo: convert some methods to functions.


namespace pif {

    class string {
        private:
            pif::array<char> s;

            int __char_to_int(const char &letter);

        public:
            class __common_iterator;
            class iterator;
            class const_iterator;

            string();
            string(const char &lettter);
            string(const char *cstring);
            string(const pif::string &str);
            string(const std::string &str);
            string(const pif::array<int> &ascii_arr);
            ~string();

            char get(const int index) const;
            inline int iget(const int index) const;
            pif::string::iterator get_iter(const int index) const;
            pif::string::const_iterator get_citer(const int index) const;

            inline int length() const;
            inline int size() const;
            inline char *data() const;
            void set_size(const int new_size, const char &letter);
            void change_capacity(const int new_extended_size);
            inline void shrink();

            pif::string push_back(const char &letter);
            pif::string push_front(const char &letter);
            pif::string insert(const int index, const char &letter);
            pif::string insert(pif::string::iterator &position, const char &new_letter);
            pif::string insert(pif::string::const_iterator &position, const char &new_letter);
            pif::string extend(const char *cstring);
            pif::string extend(const std::string &str);
            pif::string extend(const pif::string &str);
            pif::string extend(const char *cstring, const int index);
            pif::string extend(const std::string &str, const int index);
            pif::string extend(const pif::string &str, const int index);
            pif::string extend(pif::string::iterator &start, pif::string::iterator &end, pif::string &iters_object);
            pif::string extend(pif::string::const_iterator &start, pif::string::const_iterator &end, pif::string &iters_object);
            pif::string extend(std::string::iterator &start, std::string::iterator &end, std::string &iters_object);
            pif::string extend(std::string::const_iterator &start, std::string::const_iterator &end, std::string &iters_object);

            pif::string replace_back(const char &letter);
            pif::string replace_front(const char &letter);
            pif::string replace(const int index, const char &letter);
            pif::string replace(const int index, const char *cstring);
            pif::string replace(const int index, const std::string &str);
            pif::string replace(const int index, const pif::string &str);
            pif::string replace(const int index, const int total_pos, const char &letter);
            pif::string replace(typename pif::string::iterator &it, const char &new_letter);
            pif::string replace(typename pif::string::iterator &it, const char *cstring);
            pif::string replace(typename pif::string::iterator &it, const std::string &str);
            pif::string replace(typename pif::string::iterator &it, const pif::string &str);
            pif::string replace(typename pif::string::const_iterator &it, const char &new_letter);
            pif::string replace(typename pif::string::const_iterator &it, const char *cstring);
            pif::string replace(typename pif::string::const_iterator &it, const std::string &str);
            pif::string replace(typename pif::string::const_iterator &it, const pif::string &str);
            pif::string replace(typename pif::string::iterator &it, const int total_pos, const char &letter);
            pif::string replace(typename pif::string::const_iterator &it, const int total_pos, const char &letter);

            pif::string pop_back();
            pif::string pop_front();
            pif::string clear();
            pif::string pop(const int index, const int total_pos=0);
            pif::string pop(typename pif::string::iterator &it);
            pif::string pop(typename pif::string::const_iterator &it);
            pif::string pop(typename pif::string::iterator &start, typename pif::string::iterator &end);
            pif::string pop(typename pif::string::const_iterator &start, typename pif::string::const_iterator &end);
            pif::string remove(const char &letter, const bool dupl=false);
            pif::string remove(const char *cstring, const bool dupl=false);
            pif::string remove(const std::string &str, const bool dupl=false);
            pif::string remove(const pif::string &str, const bool dupl=false);
            pif::string remove_last(const char &letter);
            pif::string remove_last(const char *cstring);
            pif::string remove_last(const std::string &str);
            pif::string remove_last(const pif::string &str);
            pif::string delete_dupls();

            pif::string rev_string();
            pif::string rev_string(typename pif::string::iterator &start, typename pif::string::iterator &end);
            pif::string rev_string(typename pif::string::const_iterator &start, typename pif::string::const_iterator &end);
            pif::string shuffle();
            pif::string adjust_left(const int new_length, const char &filler='_');
            pif::string adjust_right(const int new_length, const char &filler='_');
            template <typename _Type> pif::string format(const std::initializer_list<_Type> &il);
            pif::string copy(const char &letter);
            pif::string copy(const char *cstring);
            pif::string copy(const char *cstring, const int start_i, const int end_i);
            pif::string copy(const std::string &str);
            pif::string copy(const std::string &str, const int start_i, const int end_i);
            pif::string copy(const pif::string &str);
            pif::string copy(const pif::string &str, const int start_i, const int end_i);
            pif::string copy(typename pif::string::iterator &start, typename pif::string::iterator &end, pif::string &iters_object);
            pif::string copy(typename pif::string::const_iterator &start, typename pif::string::const_iterator &end, pif::string &iters_object);
            pif::string copy(typename std::string::iterator &start, typename std::string::iterator &end, std::string &iters_object);
            pif::string copy(typename std::string::const_iterator &start, typename std::string::const_iterator &end, const std::string &iters_object);

            std::string to_std_string();
            const char* to_cstring();
            pif::array<char> to_array();
            pif::array<int> give_ascii() const;
            pif::string to_upper();
            pif::string to_upper(const int start_i, const int end_i);
            pif::string to_lower();
            pif::string to_lower(const int start_i, const int end_i);
            pif::string swap_case();
            pif::string swap_case(const int start_i, const int end_i);
            int to_int();
            pif::string capitalize();
            pif::string title();

            pif::string swap(const int first_i, const int second_i);
            pif::string swap(pif::string &str);
            pif::string swap(std::string &str);
            pif::string slice(const int start, const int end, const int step=1) const;
            pif::string center(const int new_length, const char &filler=' ');
            pif::string expandtabs(const int tab_size=4);
            pif::string ltrim();
            pif::string rtrim();
            pif::string trim();

            int count(const char &letter) const;
            int index(const char &letter) const;
            int index(const char *cstring) const;
            int index(const std::string &str) const;
            int index(const pif::string &str) const;
            pif::array<int> indexes(const char &letter) const;
            pif::array<int> indexes(const char *cstring) const;
            pif::array<int> indexes(const std::string &str) const;
            pif::array<int> indexes(const pif::string &str) const;
            int last_index(const char &letter) const;
            int last_index(const char *cstring) const;
            int last_index(const std::string &str) const;
            int last_index(const pif::string &str) const;

            pif::array<char> split() const;
            pif::array<pif::string> split(const char &letter) const;
            pif::array<pif::string> split(const char *cstring) const;
            pif::array<pif::string> split(const std::string &str) const;
            pif::array<pif::string> split(const pif::string &str) const;
            pif::array<pif::string> splitlines() const;
            pif::array<pif::string> partion(const char &letter) const;
            template <typename _ArrayType> pif::string join(const pif::array<_ArrayType> &arr) const;
            template <typename _ArrayType> pif::string join(const std::vector<_ArrayType> &arr) const;

            inline char first() const;
            inline char last() const;

            inline iterator begin() const;
            inline iterator end() const;
            inline iterator rbegin() const;
            inline iterator rend() const;
            int at(pif::string::iterator &it) const;
            inline const const_iterator cbegin() const;
            inline const const_iterator cend() const;
            inline const const_iterator crbegin() const;
            inline const const_iterator crend() const;
            int at(pif::string::const_iterator &it) const;

            inline bool is_inside(const char &letter) const;
            inline bool is_inside(const char *cstring) const;
            inline bool is_inside(const std::string &str) const;
            inline bool is_inside(const pif::string &str) const;
            inline bool is_empty() const;
            bool startswith(const char &letter) const;
            bool startswith(const char *cstring) const;
            bool startswith(const std::string &str) const;
            bool startswith(const pif::string &str) const;
            bool endswith(const char &letter) const;
            bool endswith(const char *cstring) const;
            bool endswith(const std::string &str) const;
            bool endswith(const pif::string &str) const;
            bool is_digit() const;
            bool is_num() const;
            bool is_special() const;
            bool is_alpharithmetic() const;
            bool is_space() const;
            bool is_upper() const;
            bool is_lower() const;
            bool is_capitalize() const;
            bool is_title() const;
            inline bool is_palindrome() const;

            bool non_case_comparison(const char *symbol, const char &letter) const;
            bool non_case_comparison(const char *symbol, const char *cstring) const;
            bool non_case_comparison(const char *symbol, const std::string &str) const;
            bool non_case_comparison(const char *symbol, const pif::string &str) const;

            inline bool is_longer(const char &letter) const;
            inline bool is_longer(const char *cstring) const;
            inline bool is_longer(const std::string &str) const;
            inline bool is_longer(const pif::string &str) const;
            inline bool is_longer_or_equal(const char &letter) const;
            inline bool is_longer_or_equal(const char *cstring) const;
            inline bool is_longer_or_equal(const std::string &str) const;
            inline bool is_longer_or_equal(const pif::string &str) const;
            inline bool is_shorter(const char &letter) const;
            inline bool is_shorter(const char *cstring) const;
            inline bool is_shorter(const std::string &str) const;
            inline bool is_shorter(const pif::string &str) const;
            inline bool is_shorter_or_equal(const char &letter) const;
            inline bool is_shorter_or_equal(const char *cstring) const;
            inline bool is_shorter_or_equal(const std::string &str) const;
            inline bool is_shorter_or_equal(const pif::string &str) const;
            inline bool same_length(const char &letter) const;
            inline bool same_length(const char *cstring) const;
            inline bool same_length(const std::string &str) const;
            inline bool same_length(const pif::string &str) const;

            char &operator[](const int index);
            inline char operator[](const int index) const;

            pif::string &operator=(const char &letter);
            pif::string &operator=(const char *cstring);
            pif::string &operator=(const std::string &str);
            pif::string &operator=(const pif::string &str);

            bool operator==(const char &letter) const;
            bool operator==(const char *cstring) const;
            bool operator==(const std::string &str) const;
            bool operator==(const pif::string &str) const;
            inline bool operator!=(const char &letter) const;
            inline bool operator!=(const char *cstring) const;
            inline bool operator!=(const std::string &str) const;
            inline bool operator!=(const pif::string &str) const;
            bool operator>(const char &letter) const;
            bool operator>(const char *cstring) const;
            bool operator>(const std::string &str) const;
            bool operator>(const pif::string &str) const;
            bool operator>=(const char &letter) const;
            bool operator>=(const char *cstring) const;
            bool operator>=(const std::string &str) const;
            bool operator>=(const pif::string &str) const;
            bool operator<(const char &letter) const;
            bool operator<(const char *cstring) const;
            bool operator<(const std::string &str) const;
            bool operator<(const pif::string &str) const;
            bool operator<=(const char &letter) const;
            bool operator<=(const char *cstring) const;
            bool operator<=(const std::string &str) const;
            bool operator<=(const pif::string &str) const;

            pif::string operator+=(const int positions);
            pif::string operator+=(const char &letter);
            pif::string operator+=(const char *cstring);
            pif::string operator+=(const std::string &str);
            pif::string operator+=(const pif::string &str);
            pif::string operator-=(const int positions);
            pif::string operator-=(const char &letter);
            pif::string operator-=(const char *cstring);
            pif::string operator-=(const std::string &str);
            pif::string operator-=(const pif::string &str);
            pif::string operator*=(const int total_times);

            pif::string operator+(const int positions) const;
            pif::string operator+(const char &letter) const;
            pif::string operator+(const char *cstring) const;
            pif::string operator+(const std::string &str) const;
            pif::string operator+(const pif::string &str) const;
            pif::string operator-(const int positions) const;
            pif::string operator-(const char &letter) const;
            pif::string operator-(const char *cstring) const;
            pif::string operator-(const std::string &str) const;
            pif::string operator-(const pif::string &str) const;
            pif::string operator*(const int total_times) const;

            pif::string operator++(int);
            pif::string operator++();
            pif::string operator--(int);
            pif::string operator--();


            class __common_iterator {
                public:
                    char *current;

                    inline bool operator==(const __common_iterator &_it) const;
                    inline bool operator!=(const __common_iterator &_it) const;
                    inline bool operator>(const __common_iterator &_it) const;
                    inline bool operator>=(const __common_iterator &_it) const;
                    inline bool operator<(const __common_iterator &_it) const;
                    inline bool operator<=(const __common_iterator &_it) const;
                    __common_iterator &operator++();
                    __common_iterator &operator++(int);
                    __common_iterator &operator--();
                    __common_iterator &operator--(int);
            };

            class const_iterator: public pif::string::__common_iterator {
                public:
                    const_iterator();
                    const_iterator(char *elem);
                    inline const char &operator*() const;
                    const const_iterator operator+(const int value) const;
                    const const_iterator operator-(const int value) const;
            };

            class iterator: public pif::string::__common_iterator {
                public:
                    iterator();
                    iterator(char *elem);
                    inline char &operator*() const;
                    iterator &operator+=(const int value);
                    iterator &operator-=(const int value);
                    iterator operator+(const int value) const;
                    iterator operator-(const int value) const;
            };


            friend std::ostream &operator<<(std::ostream &left, const pif::string &str) {
                if (str.length() <= 1) {
                    left << "\'";
                    for (int i=0; i<str.length(); i++) {
                        left << str.get(i);
                    }
                    left << "\'";
                }
                else {
                    left << "\"";
                    for (int i=0; i<str.length(); i++) {
                        left << str.get(i);
                    }
                    left << "\"";
                }

                return left;
            }
    
            friend std::istream &operator>>(std::istream &left, pif::string &str) {
                std::string user_input;
                getline(left, user_input);

                str += user_input;

                return left;
            }
    };


    pif::string make_string(const int value);
    pif::string make_string(const double value);
    pif::string make_string(const long double value);
    pif::string make_string(const char &letter);
    pif::string make_string(const char *cstring);
    pif::string make_string(const std::string &str);
    pif::string make_string(const pif::string &str);
    bool iter_link_to_string(const pif::string &str, typename pif::string::iterator &it);
    bool iter_link_to_string(const pif::string &str, typename pif::string::const_iterator &it);
    int get_iter_index(const pif::string &str, typename pif::string::iterator &it);
    int get_iter_index(const pif::string &str, typename pif::string::const_iterator &it);
    int get_iter_index(std::string &str, typename std::string::iterator &it);
    int get_iter_index(const std::string &str, typename std::string::const_iterator &it);
}









pif::string::string() {
    *this->s.array_size = 0;
    *this->s.extended_size = ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}
}





pif::string::string(const char &lettter) {
    *this->s.array_size = 1;
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    this->s.arr[0] = lettter;
}





pif::string::string(const char *cstring) {
    *this->s.array_size = pif::get_cstring_size(cstring);
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = cstring[i];
    }
}





pif::string::string(const pif::string &str) {
    *this->s.array_size = str.s.length();
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = str.s.get(i);
    }
}





pif::string::string(const std::string &str) {
    *this->s.array_size = str.size();
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = str[i];
    }
}





pif::string::string(const pif::array<int> &ascii_arr) {
    *this->s.array_size = ascii_arr.length();
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = (char) ascii_arr[i];
    }
}





pif::string::~string() {}





char pif::string::get(const int index) const {
    if (index > this->length() || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    return this->s.get(index);
}





pif::string::iterator pif::string::get_iter(const int index) const {
    if (index > this->length() - 1 || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    return iterator(this->begin() + index);
}





pif::string::const_iterator pif::string::get_citer(const int index) const {
    if (index > this->length() - 1 || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    return const_iterator(this->cbegin() + index);
}






inline int pif::string::iget(const int index) const {
    return (int) this->get(index);
}





inline int pif::string::length() const {
    return this->s.length();
}





inline int pif::string::size() const {
    return this->s.size();
}





inline char *pif::string::data() const {
    return this->s.arr;
}






void pif::string::set_size(const int new_size, const char &elem) {
    if (new_size < 0) {
        std::cout << "Cannot compress the string to negative size." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.set_size(new_size, elem);
}





void pif::string::change_capacity(const int new_extended_size) {
    if (new_extended_size < this->length()) {
        std::cout << "New memory size must be highter than the length of the string." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.change_capacity(new_extended_size);
}





inline void pif::string::shrink() {
    this->s.shrink();
}





pif::string pif::string::push_back(const char &letter) {
    this->s.push_back(letter);

    return *this;
}





pif::string pif::string::push_front(const char &letter) {
    this->s.push_front(letter);

    return *this;
}





pif::string pif::string::insert(const int index, const char &letter) {
    if (index > this->length() || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.insert(index, letter);

    return *this;
}





pif::string pif::string::insert(pif::string::iterator &position, const char &new_letter) {
    const int index = pif::get_iter_index(*this, position);

    if (index == this->length()+1) {
        std::cout << "The iterator that have been passed is either not created by the 'this' string or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->insert(index, new_letter);
}





pif::string pif::string::insert(pif::string::const_iterator &position, const char &new_letter) {
    const int index = pif::get_iter_index(*this, position);

    if (index == this->length()+1) {
        std::cout << "The iterator that have been passed is either not created by the 'this' string or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->insert(index, new_letter);
}





pif::string pif::string::extend(const char *cstring) {
    for (int i=0; i<pif::get_cstring_size(cstring); i++) {
        this->push_back(cstring[i]);
    }

    return *this;
}





pif::string pif::string::extend(const std::string &str) {
    for (int i=0; i<str.size(); i++) {
        this->push_back(str[i]);
    }

    return *this;
}





pif::string pif::string::extend(const pif::string &str) {
    this->s.extend(str.s);

    return *this;
}





pif::string pif::string::extend(const char *cstring, const int index) {
    if (index > this->length() || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (int i=pif::get_cstring_size(cstring)-1; i>=0; i--) {
        this->insert(index, cstring[i]);
    }

    return *this;
}





pif::string pif::string::extend(const std::string &str, const int index) {
    if (index > this->length() || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (int i=str.size()-1; i>=0; i--) {
        this->insert(index, str[i]);
    }

    return *this;
}





pif::string pif::string::extend(const pif::string &str, const int index) {
    if (index > this->length() || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.extend(str.s, index);

    return *this;
}





pif::string pif::string::extend(pif::string::iterator &start, pif::string::iterator &end, pif::string &iters_object) {
    const int start_i = pif::get_iter_index(iters_object, start);
    const int end_i = pif::get_iter_index(iters_object, end);

    if (start_i == iters_object.length() + 1 || end_i == iters_object.length() + 1) {
        std::cout << "Invalid Iterator Positions: Iterators are out ouf bounds or have not been created by 'iters_object'." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (pif::string::iterator it=start; it!=end; ++it) {
        this->push_back(*it);
    }

    return *this;
}





pif::string pif::string::extend(pif::string::const_iterator &start, pif::string::const_iterator &end, pif::string &iters_object) {
    const int start_i = pif::get_iter_index(iters_object, start);
    const int end_i = pif::get_iter_index(iters_object, end);

    if (start_i == iters_object.length() + 1 || end_i == iters_object.length() + 1) {
        std::cout << "Invalid Iterator Positions: Iterators are out ouf bounds or have not been created by 'iters_object'." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (pif::string::const_iterator it=start; it!=end; ++it) {
        this->push_back(*it);
    }

    return *this;
}





pif::string pif::string::extend(std::string::iterator &start, std::string::iterator &end, std::string &iters_object) {
    const int start_i = pif::get_iter_index(iters_object, start);
    const int end_i = pif::get_iter_index(iters_object, end);

    if (start_i == iters_object.length() + 1 || end_i == iters_object.length() + 1) {
        std::cout << "Invalid Iterator Positions: Iterators are out ouf bounds or have not been created by 'iters_object'." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (std::string::iterator it=start; it!=end; ++it) {
        this->push_back(*it);
    }

    return *this;
}





pif::string pif::string::extend(std::string::const_iterator &start, std::string::const_iterator &end, std::string &iters_object) {
    const int start_i = pif::get_iter_index(iters_object, start);
    const int end_i = pif::get_iter_index(iters_object, end);

    if (start_i == iters_object.length() + 1 || end_i == iters_object.length() + 1) {
        std::cout << "Invalid Iterator Positions: Iterators are out ouf bounds or have not been created by 'iters_object'." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (std::string::const_iterator it=start; it!=end; ++it) {
        this->push_back(*it);
    }

    return *this;
}





pif::string pif::string::replace_back(const char &letter) {
    if (this->length() == 0) {
        std::cout << "String is empty." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s[this->length() - 1] = letter;

    return *this;
}





pif::string pif::string::replace_front(const char &letter) {
    if (this->length() == 0) {
        std::cout << "String is empty." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s[0] = letter;

    return *this;
}





pif::string pif::string::replace(const int index, const char &letter) {
    if (index > (this->length() - 1) || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s[index] = letter;

    return *this;
}





pif::string pif::string::replace(const int index, const char *cstring) {
    if (index > (this->length() - 1) || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (int i=index; i<index + pif::get_cstring_size(cstring); i++) {
        if (i >= this->length()) {
            this->push_back(cstring[i - index]);
        }
        else {
            this->s[i] = cstring[i - index];
        }
    }

    return *this;
}





pif::string pif::string::replace(const int index, const std::string &str) {
    if (index > (this->length() - 1) || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (int i=index; i<index + str.size(); i++) {
        if (i >= this->length()) {
            this->push_back(str[i - index]);
        }
        else {
            this->s[i] = str[i - index];
        }
    }

    return *this;  
}





pif::string pif::string::replace(const int index, const pif::string &str) {
    if (index > (this->length() - 1) || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    if (*this != str) {
        for (int i=index; i<index + str.length(); i++) {
            if (i >= this->length()) {
                this->push_back(str.get(i - index));
            }
            else {
                this->s[i] = str.get(i - index);
            }
        }
    }
    else {
        char *temp = new(std::nothrow) char[this->length() * 2];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        int j = 0;
        for (int i=0; i<this->length() + j; i++) {
            if (i >= index) {
                temp[i] = this->s.arr[i - index];
            }
            else {
                temp[i] = this->s.arr[i];
                j ++;
            }
        }
        delete[] this->s.arr;

        *this->s.array_size = this->length() + j;
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->s.arr[i] = temp[i];
        }
        delete[] temp;
    }

    return *this;  
}





pif::string pif::string::replace(const int index, const int total_pos, const char &letter) {
    if (index + total_pos > (this->length() - 1) || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (int i=index; i<index + total_pos + 1; i++) {
        this->s[i] = letter;
    }

    return *this;
}





pif::string pif::string::replace(typename pif::string::iterator &it, const char &new_letter) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, new_letter);

    return *this;
}





pif::string pif::string::replace(typename pif::string::iterator &it, const char *cstring) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, cstring);

    return *this;
}





pif::string pif::string::replace(typename pif::string::iterator &it, const std::string &str) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, str);

    return *this;
}





pif::string pif::string::replace(typename pif::string::iterator &it, const pif::string &str) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, str);

    return *this;
}





pif::string pif::string::replace(typename pif::string::const_iterator &it, const char &new_letter) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, new_letter);

    return *this;
}





pif::string pif::string::replace(typename pif::string::const_iterator &it, const char *cstring) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, cstring);

    return *this;
}





pif::string pif::string::replace(typename pif::string::const_iterator &it, const std::string &str) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, str);

    return *this;
}





pif::string pif::string::replace(typename pif::string::const_iterator &it, const pif::string &str) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, str);

    return *this;
}





pif::string pif::string::replace(typename pif::string::iterator &it, const int total_pos, const char &letter) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created be th 'this' string or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, total_pos, letter);

    return *this;
}





pif::string pif::string::replace(typename pif::string::const_iterator &it, const int total_pos, const char &letter) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has been passed is either not created be th 'this' string or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->replace(index, total_pos, letter);

    return *this;
}





pif::string pif::string::pop_back() {
    if (this->length() == 0) {
        std::cout << "String is empty." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.pop_back();

    return *this;
}





pif::string pif::string::pop_front() {
    if (this->length() == 0) {
        std::cout << "String is empty." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.pop_front();

    return *this;
}





pif::string pif::string::clear() {
    this->s.clear();

    return *this;
}





pif::string pif::string::pop(const int index, const int total_pos) {
    if (index + total_pos > this->length() || index < 0 || total_pos < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.pop(index, total_pos);

    return *this;
}





pif::string pif::string::pop(typename pif::string::iterator &it) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has beem passed is either not created by the 'this' string or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->pop(index);

    return *this;
}





pif::string pif::string::pop(typename pif::string::const_iterator &it) {
    if (!pif::iter_link_to_string(*this, it)) {
        std::cout << "The iterator that has beem passed is either not created by the 'this' string or is out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int index = this->at(it);

    this->pop(index);

    return *this;
}





pif::string pif::string::pop(typename pif::string::iterator &start, typename pif::string::iterator &end) {
    if (!pif::iter_link_to_string(*this, start) || !pif::iter_link_to_string(*this, end)) {
        std::cout << "The iterators that have been passed are either not been craeted by the 'this' string or are out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int start_i = this->at(start);
    const int end_i = this->at(end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->pop(start_i, (end_i - start_i - 1));

    return *this;
}





pif::string pif::string::pop(typename pif::string::const_iterator &start, typename pif::string::const_iterator &end) {
    if (!pif::iter_link_to_string(*this, start) || !pif::iter_link_to_string(*this, end)) {
        std::cout << "The iterators that have been passed are either not been craeted by the 'this' string or are out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int start_i = this->at(start);
    const int end_i = this->at(end);

    if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->pop(start_i, (end_i - start_i - 1));

    return *this;
}





pif::string pif::string::remove(const char &letter, const bool dupl) {
    this->s.remove(letter, dupl);

    return *this;
}





pif::string pif::string::remove(const char *cstring, const bool dupl) {
    char *temp = new(std::nothrow) char[this->length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    pif::array<int> indexes = this->indexes(cstring);
    bool stop_del = (dupl) ? false : true;
    bool skip;
    int p = 0;
    const int cstring_length = pif::get_cstring_size(cstring);

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
            i += cstring_length - 1;
        }
        else {
            temp[p] = this->s.arr[i];
            p++;
        }
    }

    delete[] this->s.arr;

    *this->s.array_size = p;
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->length()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = temp[i];
    }

    delete[] temp;

    return *this;
}





pif::string pif::string::remove(const std::string &str, const bool dupl) {
    char *temp = new(std::nothrow) char[this->length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    pif::array<int> indexes = this->indexes(str);
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
            i += str.size() - 1;
        }
        else {
            temp[p] = this->s.arr[i];
            p++;
        }
    }

    delete[] this->s.arr;

    *this->s.array_size = p;
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->length()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = temp[i];
    }

    delete[] temp;

    return *this;
}





pif::string pif::string::remove(const pif::string &str, const bool dupl) {
    this->s.remove(str.s, dupl);

    return *this;
}





pif::string pif::string::remove_last(const char &letter) {
    this->s.remove_last(letter);

    return *this;
}





pif::string pif::string::remove_last(const char *cstring) {
    pif::string temp = cstring;

    this->rev_string();
    temp.rev_string();

    this->remove(temp, false);

    this->rev_string();

    return *this;
}





pif::string pif::string::remove_last(const std::string &str) {
    pif::string temp = str;

    this->remove_last(temp);

    return *this;
}





pif::string pif::string::remove_last(const pif::string &str) {
    this->s.remove_last(str.s);

    return *this;
}





pif::string pif::string::delete_dupls() {
    this->s.delete_dupls();

    return *this;
}





pif::string pif::string::rev_string() {
    this->s.rev_array();

    return *this;
}





pif::string pif::string::rev_string(typename pif::string::iterator &start, typename pif::string::iterator &end) {
    const int start_i = pif::get_iter_index(*this, start);
    const int end_i = pif::get_iter_index(*this, end);

    if (start_i == this->length()+1 || end_i == this->length()+1) {
        std::cout << "The iterators that have been passed are either not been craeted by the 'this' string or are out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    pif::string temp = this->slice(start_i, end_i);
    temp.rev_string();

    for (int i=0; i<temp.length(); i++) {
        this->s.arr[start_i+i] = temp[i];
    }

    return *this;
}





pif::string pif::string::rev_string(typename pif::string::const_iterator &start, typename pif::string::const_iterator &end) {
    const int start_i = pif::get_iter_index(*this, start);
    const int end_i = pif::get_iter_index(*this, end);

    if (start_i == this->length()+1 || end_i == this->length()+1) {
        std::cout << "The iterators that have been passed are either not been craeted by the 'this' string or are out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    pif::string temp = this->slice(start_i, end_i);
    temp.rev_string();

    for (int i=0; i<temp.length(); i++) {
        this->s.arr[start_i+i] = temp[i];
    }

    return *this;
}





pif::string pif::string::shuffle() {
    this->s.shuffle();

    return *this;
}





pif::string pif::string::adjust_left(const int new_length, const char &filler) {
    if (new_length < this->length()) {
        std::cout << "New length must be highter than the prior one." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int prior_length = this->length();
    for (int i=0; i<(new_length-prior_length); i++) {
        this->push_back(filler);
    }

    return *this;
}





pif::string pif::string::adjust_right(const int new_length, const char &filler) {
    if (new_length < this->length()) {
        std::cout << "New length must be highter than the prior one." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int prior_length = this->length();
    for (int i=0; i<(new_length-prior_length); i++) {
        this->push_front(filler);
    }

    return *this;
}





template <typename _Type>
pif::string pif::string::format(const std::initializer_list<_Type> &il) {
    pif::array<int> indexes_arr = this->indexes("{}");

    int list_size = 0;
    const _Type *p = il.begin();

    while (p != il.end()) {
        p = il.begin() + list_size;
        list_size ++;
    }
    list_size --;
    

    if (indexes_arr.length() > list_size) {
        std::cout << "The arguments that have beed passed are less than expected." << std::endl;
        std::cout << "Expected: " << indexes_arr.length() << ", but got: " << list_size << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (indexes_arr.length() < list_size) {
        std::cout << "The arguments that have been passed are more than expected." << std::endl;
        std::cout << "Expected: " << indexes_arr.length() << ", but got: " << list_size << std::endl;
        this->s.~array();
        exit(0);
    }

    pif::array<pif::string> arr = this->split("{");
    this->clear();

    int j = 0;
    for (int i=0; i<arr.length(); i++) {
        if (arr[i].startswith('}')) {
            arr[i].pop(0);
            arr[i].extend(pif::make_string(*(il.begin() + j)), 0);
            j ++;
        }
        this->extend(arr[i]);
    }

    return *this;
}





pif::string pif::string::copy(const char &letter) {
    if (this->s.arr) {
        delete[] this->s.arr;
    }

    *this->s.array_size = 1;
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    this->s.arr[0] = letter;

    return *this;
}





pif::string pif::string::copy(const char *cstring) {
    char *temp = new(std::nothrow) char[pif::get_cstring_size(cstring)];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<pif::get_cstring_size(cstring); i++) {
        temp[i] = cstring[i];
    }

    if (this->s.arr) {
        delete[] this->s.arr;
    }

    *this->s.array_size = pif::get_cstring_size(cstring);
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = temp[i];
    }

    delete[] temp;

    return *this;
}





pif::string pif::string::copy(const char *cstring, const int start_i, const int end_i) {
    if (start_i < 0 || end_i < 0 || end_i > pif::get_cstring_size(cstring) || start_i > end_i) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    char *temp = new(std::nothrow) char[pif::get_cstring_size(cstring)];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    int j = 0;
    for (int i=start_i; i<end_i; i++) {
        temp[j] = cstring[i];
        j ++;
    }

    if (this->s.arr) {
        delete[] this->s.arr;
    }

    *this->s.array_size = j;
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = temp[i];
    }

    delete[] temp;

    return *this;
}





pif::string pif::string::copy(const std::string &str) {
    char *temp = new(std::nothrow) char[str.size()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<str.size(); i++) {
        temp[i] = str[i];
    }

    if (this->s.arr) {
        delete[] this->s.arr;
    }

    *this->s.array_size = str.size();
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = temp[i];
    }

    delete[] temp;

    return *this; 
}





pif::string pif::string::copy(const std::string &str, const int start_i, const int end_i) {
    if (start_i < 0 || end_i < 0 || end_i > str.size() || start_i > end_i) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    char *temp = new(std::nothrow) char[str.size()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    int j = 0;
    for (int i=start_i; i<end_i; i++) {
        temp[j] = str[i];
        j ++;
    }

    if (this->s.arr) {
        delete[] this->s.arr;
    }

    *this->s.array_size = j;
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = temp[i];
    }

    delete[] temp;

    return *this;   
}





pif::string pif::string::copy(const pif::string &str) {
    this->s.copy(str.s);

    return *this;
}





pif::string pif::string::copy(const pif::string &str, const int start_i, const int end_i) {
    if (start_i < 0 || end_i < 0 || end_i > str.length() || start_i > end_i) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.copy(str.s, start_i, end_i);

    return *this;
}





pif::string pif::string::copy(typename pif::string::iterator &start, typename pif::string::iterator &end, pif::string &iters_object) {
    const int start_i = pif::get_iter_index(iters_object, start);
    const int end_i = pif::get_iter_index(iters_object, end);

    if (start_i == iters_object.length() + 1 || end_i == iters_object.length() + 1) {
        std::cout << "The iterators that beve been passed are either not created by the 'iters_object' string or out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->copy(iters_object.slice(start_i, end_i));

    return *this;
}





pif::string pif::string::copy(typename pif::string::const_iterator &start, typename pif::string::const_iterator &end, pif::string &iters_object) {
    const int start_i = pif::get_iter_index(iters_object, start);
    const int end_i = pif::get_iter_index(iters_object, end);

    if (start_i == iters_object.length() + 1 || end_i == iters_object.length() + 1) {
        std::cout << "The iterators that beve been passed are either not created by the 'iters_object' string or out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->copy(iters_object.slice(start_i, end_i));

    return *this;
}





pif::string pif::string::copy(typename std::string::iterator &start, typename std::string::iterator &end, std::string &iters_object) {
    const int start_i = pif::get_iter_index(iters_object, start);
    const int end_i = pif::get_iter_index(iters_object, end);

    if (start_i == iters_object.size() + 1 || end_i == iters_object.size() + 1) {
        std::cout << "The iterators that beve been passed are either not created by the 'iters_object' string or out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    char *temp = new(std::nothrow) char[iters_object.size()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    int j = 0;
    for (int i=start_i; i<end_i; i++) {
        temp[j] = iters_object[i];
        j++;
    }

    delete[] this->s.arr;

    *this->s.array_size = j;
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = temp[i];
    }
    delete[] temp;

    return *this;
}





pif::string pif::string::copy(typename std::string::const_iterator &start, typename std::string::const_iterator &end, const std::string &iters_object) {
    const int start_i = pif::get_iter_index(iters_object, start);
    const int end_i = pif::get_iter_index(iters_object, end);

    if (start_i == iters_object.size() + 1 || end_i == iters_object.size() + 1) {
        std::cout << "The iterators that beve been passed are either not created by the 'iters_object' string or out of bounds." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (start_i > end_i) {
        std::cout << "Invalid Iterator Positions." << std::endl;
        this->s.~array();
        exit(0);
    }

    char *temp = new(std::nothrow) char[iters_object.size()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    int j = 0;
    for (int i=start_i; i<end_i; i++) {
        temp[j] = iters_object[i];
        j++;
    }

    delete[] this->s.arr;

    *this->s.array_size = j;
    *this->s.extended_size = this->length() + ARRAY_GAP;

    this->s.arr = new(std::nothrow) char[this->size()];
    if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        this->s.arr[i] = temp[i];
    }
    delete[] temp;

    return *this;
}





std::string pif::string::to_std_string() {
    std::string temp;
    for (int i=0; i<this->length(); i++) {
        temp += this->s.arr[i];
    }

    this->clear();

    return temp;
}





const char* pif::string::to_cstring() {
    char* temp = new(std::nothrow) char[this->length()];
    if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

    for (int i=0; i<this->length(); i++) {
        temp[i] = this->s.arr[i];
    }
    temp[this->length()] = '\0';

    this->clear();

    return temp;
}





pif::array<char> pif::string::to_array() {
    pif::array<char> temp;
    for (int i=0; i<this->length(); i++) {
        temp.push_back(this->s.arr[i]);
    }

    this->clear();

    return temp;
}





pif::array<int> pif::string::give_ascii() const {
    pif::array<int> arr;

    for (int i=0; i<this->length(); i++) {
        arr.push_back((int) this->s.arr[i]);
    }

    return arr;
}





pif::string pif::string::to_upper() {
    for (int i=0; i<this->length(); i++) {
        if ((int) this->get(i) >= 97 && (int) this->get(i) <= 122) {
            (*this)[i] = (char)((*this)[i] - 32);
        }
    }

    return *this;
}





pif::string pif::string::to_upper(const int start_i, const int end_i) {
    if (start_i < 0 || end_i > this->length() || start_i > end_i) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (int i=start_i; i<end_i; i++) {
        if ((int) this->get(i) >= 97 && (int) this->get(i) <= 122) {
            (*this)[i] = (char)((*this)[i] - 32);
        }
    }

    return *this;
}





pif::string pif::string::to_lower() {
    for (int i=0; i<this->length(); i++) {
        if ((int) this->get(i) >= 65 && (int) this->get(i) <= 90) {
            (*this)[i] = (char)((*this)[i] + 32);
        }
    }

    return *this;
}





pif::string pif::string::to_lower(const int start_i, const int end_i) {
    if (start_i < 0 || end_i > this->length() || start_i > end_i) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (int i=start_i; i<end_i; i++) {
        if ((int) this->get(i) >= 65 && (int) this->get(i) <= 90) {
            (*this)[i] = (char)((*this)[i] + 32);
        }
    }

    return *this;
}





pif::string pif::string::swap_case() {
    for (int i=0; i<this->length(); i++) {
        if ((int) this->get(i) >= 65 && (int) this->get(i) <= 90) {
            (*this)[i] = (char)((*this)[i] + 32);
        }
        else if ((int) this->get(i) >= 97 && (int) this->get(i) <= 122) {
            (*this)[i] = (char)((*this)[i] - 32);
        }
    }

    return *this;
}





pif::string pif::string::swap_case(const int start_i, const int end_i) {
    if (start_i < 0 || end_i > this->length() || start_i > end_i) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    for (int i=start_i; i<end_i; i++) {
        if ((int) this->get(i) >= 65 && (int) this->get(i) <= 90) {
            (*this)[i] = (char)((*this)[i] + 32);
        }
        else if ((int) this->get(i) >= 97 && (int) this->get(i) <= 122) {
            (*this)[i] = (char)((*this)[i] - 32);
        }
    }

    return *this;
}





int pif::string::to_int() {
    int num = 0;

    for (int i=0; i<this->length(); i++) {
        int temp = 1;
        for (int j=0; j<this->length()-1-i; j++) {
            temp *= 10;
        }
        num += this->__char_to_int(this->s.arr[i]) * temp;
    }

    this->clear();

    return num;
}





pif::string pif::string::capitalize() {
    if (this->length() != 0 && (this->s.arr[0] >= 97 && this->s.arr[0] <= 122)) {
        (*this)[0] = (char)((*this)[0] - 32);
    }

    return *this;
}





pif::string pif::string::title() {
    this->to_lower();
    if (this->length() != 0 && (this->s.arr[0] >= 97 && this->s.arr[0] <= 122)) {
        (*this)[0] = (char)((*this)[0] - 32);
    }

    return *this;
}





pif::string pif::string::swap(const int first_i, const int second_i) {
    if (first_i < 0 || second_i < 0 || second_i > this->length()-1 || first_i > this->length()-1) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    this->s.swap(first_i, second_i);

    return *this;
}





pif::string pif::string::swap(pif::string &str) {
    pif::string temp = *this;
    *this = str;
    str = temp;

    return *this;
}





pif::string pif::string::swap(std::string &str) {
    pif::string temp = *this;
    *this = str;

    str.clear();
    
    for (int i=0; i<temp.length(); i++) {
        str.push_back(temp[i]);
    }

    return *this;
}





pif::string pif::string::slice(const int start, const int end, const int step) const {
    pif::string temp;
    temp.s = this->s.slice(start, end, step);

    return temp;
}





pif::string pif::string::center(const int new_length, const char &filler) {
    if (new_length < this->length()) {
        std::cout << "New length must be highter than the current one." << std::endl;
        this->s.~array();
        exit(0);
    }

    const int difference = new_length - this->length();

    for (int i=0; i<difference/2; i++) {
        this->push_back(filler);
        this->push_front(filler);
    }

    return *this;
}





pif::string pif::string::expandtabs(const int tab_size) {
    pif::array<int> indexes_arr = this->indexes('\t');

    if (indexes_arr.length() != 0) {
        char *temp = new(std::nothrow) char[this->length() + (indexes_arr.length() * tab_size)];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        int j = 0;
        int p = 0;
        for (int i=0; i<this->length(); i++) {
            if (i == indexes_arr[j]) {
                for (int k=0; k<tab_size; k++) {
                    if (j > indexes_arr.length() - 1) {
                        break;
                    }
                    temp[p] = ' ';
                    p ++;
                }
                j ++;
            }
            else {
                temp[p] = this->s.arr[i];
                p ++;
            }
        }
        delete[] this->s.arr;

        *this->s.array_size = p;
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->s.arr[i] = temp[i];
        }
        delete[] temp;
    }

    return *this;
}





pif::string pif::string::ltrim() {
    for (int i=0; i<this->length(); i++) {
        if (this->s.arr[i] == ' ') {
            this->pop_front();
            i --;
        }
        else {
            break;
        }
    }

    return *this;
}





pif::string pif::string::rtrim() {
    for (int i=0; i<this->length(); i++) {
        if (this->s.arr[this->length() - i - 1] == ' ') {
            this->pop_back();
            i --;
        }
        else {
            break;
        }
    }

    return *this;
}





pif::string pif::string::trim() {
    this->rtrim();
    this->ltrim();

    return *this;
}





int pif::string::count(const char &letter) const {
    int counts = 0;

    for (int i=0; i<this->length(); i++) {
        if (this->s.arr[i] == letter) {
            counts ++;
        }
    }

    return counts;
}





int pif::string::index(const char &letter) const {
    for (int i=0; i<this->length(); i++) {
        if (this->s.arr[i] == letter) {
            return i;
        }
    }

    return -1;
}





int pif::string::index(const char *cstring) const {
    const int cstring_length = pif::get_cstring_size(cstring);

    if (cstring_length > this->length() || cstring_length * this->length() == 0) {
        return -1;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->slice(i, i+cstring_length) == cstring) {
            return i;
        }
    }

    return -1;
}





int pif::string::index(const std::string &str) const {
    if (this->length() < str.size() || this->length() * str.size() == 0) {
        return -1;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->slice(i, i+str.size()) == str) {
            return i;
        }
    }

    return -1;
}





int pif::string::index(const pif::string &str) const {
    return this->s.index(str.s);
}





pif::array<int> pif::string::indexes(const char &letter) const {
    pif::array<int> temp;
    for (int i=0; i<this->length(); i++) {
        if (this->s.arr[i] == letter) {
            temp.push_back(i);
        }
    }

    return temp;
}





pif::array<int> pif::string::indexes(const char *cstring) const {
    const int cstring_length = pif::get_cstring_size(cstring);
    pif::array<int> temp;

    if (this->length() < cstring_length || this->length() * cstring_length == 0) {
        return temp;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->slice(i, i+cstring_length) == cstring) {
            temp.push_back(i);
        }
    }

    return temp;
}





pif::array<int> pif::string::indexes(const std::string &str) const {
    pif::array<int> temp;

    if (this->length() < str.size() || this->length() * str.size() == 0) {
        return temp;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->slice(i, i+str.size()) == str) {
            temp.push_back(i);
        }
    }

    return temp;
}





pif::array<int> pif::string::indexes(const pif::string &str) const {
    return this->s.indexes(str.s);
}





int pif::string::last_index(const char &letter) const {
    pif::array<int> indexes = this->indexes(letter);

    return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
}





int pif::string::last_index(const char *cstring) const {
    pif::array<int> indexes = this->indexes(cstring);

    return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
}





int pif::string::last_index(const std::string &str) const {
    pif::array<int> indexes = this->indexes(str);

    return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
}





int pif::string::last_index(const pif::string &str) const {
    pif::array<int> indexes = this->indexes(str);

    return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
}





pif::array<char> pif::string::split() const {
    pif::array<char> temp;
    for (int i=0; i<this->length(); i++) {
        temp.push_back(this->s.arr[i]);
    }

    return temp;
}





pif::array<pif::string> pif::string::split(const char &letter) const {
    pif::array<int> indexes_arr = this->indexes(letter);
    pif::array<pif::string> temp;

    if (indexes_arr.index(0) == -1) {
        indexes_arr.push_front(0);
    }
    if (indexes_arr.index(this->length() - 1) == -1) {
        indexes_arr.push_back(this->length() - 1);
    }

    for (int i=0; i<indexes_arr.length()-1; i++) {
        pif::string str = this->slice(indexes_arr[i], indexes_arr[i+1]+1);

        if (str[0] == letter) {
            str.pop_front();
        }
        if (str[str.length() - 1] == letter) {
            str.pop_back();
        }

        temp.push_back(str);
    }

    if (temp.length() == 0) {
        temp.push_back(*this);
    }

    return temp;
}





pif::array<pif::string> pif::string::split(const char *cstring) const {
    pif::array<int> indexes_arr = this->indexes(cstring);
    pif::array<pif::string> temp;
    pif::string st;
    const int cstring_length = pif::get_cstring_size(cstring);

    if (indexes_arr.index(0) == -1) {
        indexes_arr.push_front(0);
    }
    if (indexes_arr.index(this->length() - 1) == -1) {
        indexes_arr.push_back(this->length() - 1);
    }

    for (int i=0; i<indexes_arr.length()-1; i++) {
        if (i == indexes_arr.length()-2) {
            st = this->slice(indexes_arr[i], indexes_arr[i+1]+1);
        }
        else {
            st = this->slice(indexes_arr[i], indexes_arr[i+1]);
        }

        if (st.slice(0, cstring_length) == cstring) {
            st.pop(0, cstring_length-1);
        }

        temp.push_back(st);
    }

    if (temp.length() == 0) {
        temp.push_back(*this);
    }

    return temp; 
}





pif::array<pif::string> pif::string::split(const std::string &str) const {
    pif::array<int> indexes_arr = this->indexes(str);
    pif::array<pif::string> temp;
    pif::string st;

    if (indexes_arr.index(0) == -1) {
        indexes_arr.push_front(0);
    }
    if (indexes_arr.index(this->length() - 1) == -1) {
        indexes_arr.push_back(this->length() - 1);
    }

    for (int i=0; i<indexes_arr.length()-1; i++) {
        if (i == indexes_arr.length()-2) {
            st = this->slice(indexes_arr[i], indexes_arr[i+1]+1);
        }
        else {
            st = this->slice(indexes_arr[i], indexes_arr[i+1]);
        }

        if (st.slice(0, str.size()) == str) {
            st.pop(0, str.size()-1);
        }

        temp.push_back(st);
    }

    if (temp.length() == 0) {
        temp.push_back(*this);
    }

    return temp;
}





pif::array<pif::string> pif::string::split(const pif::string &str) const {
    pif::array<int> indexes_arr = this->indexes(str);
    pif::array<pif::string> temp;
    pif::string st;

    if (indexes_arr.index(0) == -1) {
        indexes_arr.push_front(0);
    }
    if (indexes_arr.index(this->length() - 1) == -1) {
        indexes_arr.push_back(this->length() - 1);
    }

    for (int i=0; i<indexes_arr.length()-1; i++) {
        if (i == indexes_arr.length()-2) {
            st = this->slice(indexes_arr[i], indexes_arr[i+1]+1);
        }
        else {
            st = this->slice(indexes_arr[i], indexes_arr[i+1]);
        }

        if (st.slice(0, str.length()) == str) {
            st.pop(0, str.length()-1);
        }

        temp.push_back(st);
    }

    if (temp.length() == 0) {
        temp.push_back(*this);
    }

    return temp;  
}





pif::array<pif::string> pif::string::splitlines() const {
    pif::array<pif::string> temp;
    pif::string str;

    for (int i=0; i<this->length(); i++) {
        if (this->s.arr[i] == '\n') {
            temp.push_back(str);
            str = "";
        }
        else {
            str += this->s.arr[i];
        }
    }
    temp.push_back(str);

    return temp;  
}





pif::array<pif::string> pif::string::partion(const char &letter) const {
    pif::array<pif::string> temp = {"", "", ""};
    pif::array<int> index_arr = this->indexes(letter);

    if (index_arr.length() == 0) {
        temp[0] = *this;
    }
    else {
        temp[0] = this->slice(0, index_arr[0]);
        temp[1] = letter;
        temp[2] = this->slice(index_arr[0]+1, this->length());
    }

    return temp;
}





template <typename _ArrayType>
pif::string pif::string::join(const pif::array<_ArrayType> &arr) const {
    pif::string temp;
    for (int i=0; i<arr.length(); i++) {
        if (i == arr.length() - 1) {
            temp.extend(pif::make_string(arr[i]));
        }
        else {
            temp.extend(pif::make_string(arr[i]));
            temp.extend(*this);
        }
    }

    return temp;
}





template <typename _ArrayType>
pif::string pif::string::join(const std::vector<_ArrayType> &arr) const {
    pif::string temp;
    for (int i=0; i<arr.size(); i++) {
        if (i == arr.size() - 1) {
            temp.extend(pif::make_string(arr[i]));
        }
        else {
            temp.extend(pif::make_string(arr[i]));
            temp.extend(*this);
        }
    }

    return temp;
}





inline char pif::string::first() const {
    return (this->is_empty()) ? '_' : this->s.arr[0];
}





inline char pif::string::last() const {
    return (this->is_empty()) ? '_' : this->s.arr[this->length() - 1];
}





inline pif::string::iterator pif::string::begin() const {
    return iterator(this->s.arr);    
}





inline pif::string::iterator pif::string::end() const {
    return iterator(this->s.arr + this->length());
}





inline pif::string::iterator pif::string::rbegin() const {
    return iterator(this->s.arr + this->length() - 1);
}





inline pif::string::iterator pif::string::rend() const {
    return iterator(this->s.arr - 1);
}





int pif::string::at(pif::string::iterator &it) const {
    for (int i=0; i<this->length(); i++) {
        if (it == (this->begin() + i)) {
            return i;
        }
    }

    return -1;
}





inline const pif::string::const_iterator pif::string::cbegin() const {
    return const_iterator(this->s.arr);    
}





inline const pif::string::const_iterator pif::string::cend() const {
    return const_iterator(this->s.arr + this->length());
}





inline const pif::string::const_iterator pif::string::crbegin() const {
    return const_iterator(this->s.arr + this->length() - 1);
}





inline const pif::string::const_iterator pif::string::crend() const {
    return const_iterator(this->s.arr - 1);
}





int pif::string::at(pif::string::const_iterator &it) const {
    for (int i=0; i<this->length(); i++) {
        if (it == (this->cbegin() + i)) {
            return i;
        }
    }

    return -1;
}





inline bool pif::string::is_inside(const char &letter) const {
    return (this->index(letter) != -1) ? true : false;
}





inline bool pif::string::is_inside(const char *cstring) const {
    return (this->index(cstring) != -1) ? true : false;
}





inline bool pif::string::is_inside(const std::string &str) const {
    return (this->index(str) != -1) ? true : false;
}





inline bool pif::string::is_inside(const pif::string &str) const {
    return (this->index(str) != -1) ? true : false;
}





inline bool pif::string::is_empty() const {
    return (this->length() == 0) ? true : false;
}





bool pif::string::startswith(const char &letter) const {
    if (this->is_empty()) {
        return false;
    }

    return (this->s.arr[0] == letter);
}





bool pif::string::startswith(const char *cstring) const {
    const int cstring_length = pif::get_cstring_size(cstring);

    if (cstring_length <= this->length() && cstring_length > 0) {
        if (this->slice(0, cstring_length) == cstring) {
            return true;
        }
    }
    return false;
}





bool pif::string::startswith(const std::string &str) const {
    if (this->length() >= str.size() && str.size() > 0) {
        if (this->slice(0, str.size()) == str) {
            return true;
        }
    }
    return false;
}





bool pif::string::startswith(const pif::string &str) const {
    if (this->length() >= str.length() && str.length() > 0) {
        if (this->slice(0, str.length()) == str) {
            return true;
        }
    }
    return false;
}





bool pif::string::endswith(const char &letter) const {
    if (this->is_empty()) {
        return false;
    }

    return (this->s.arr[this->length() - 1] == letter);
}





bool pif::string::endswith(const char *cstring) const {
    const int cstring_length = pif::get_cstring_size(cstring);

    if (cstring_length <= this->length() && cstring_length > 0) {
        if (this->slice(this->length()-cstring_length, this->length()) == cstring) {
            return true;
        }
    }
    return false;
}





bool pif::string::endswith(const std::string &str) const {
    if (this->length() >= str.size() && str.size() > 0) {
        if (this->slice(this->length() - str.size(), this->length()) == str) {
            return true;
        }
    }
    return false;
}





bool pif::string::endswith(const pif::string &str) const {
    if (this->length() >= str.length() && str.length() > 0) {
        if (this->slice(this->length() - str.length(), this->length()) == str) {
            return true;
        }
    }
    return false;
}





bool pif::string::is_digit() const {
    if (this->is_empty()) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if (!((*this)[i] >= 33 && (*this)[i] <= 64 || (*this)[i] >= 91 && (*this)[i] <= 96 || (*this)[i] >= 123 && (*this)[i] <= 126)) {
            return false;
        }
    }
    return true;
}





bool pif::string::is_num() const {
    if (this->is_empty()) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if (!((*this)[i] >= 48 && (*this)[i] <= 57)) {
            return false;
        }
    }
    return true;
}





bool pif::string::is_special() const {
    if (this->is_empty()) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if (!((*this)[i] >= 33 && (*this)[i] <= 47 || (*this)[i] >= 58 && (*this)[i] <= 64 || (*this)[i] >= 91 && (*this)[i] <= 96 || (*this)[i] >= 123 && (*this)[i] <= 126)) {
            return false;
        }
    }
    return true;
}





bool pif::string::is_alpharithmetic() const {
    if (this->is_empty()) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if (!((*this)[i] >= 65 && (*this)[i] <= 90 || (*this)[i] >= 97 && (*this)[i] <= 122 || (*this)[i] == 32)) {
            return false;
        }
    }
    return true;
}





bool pif::string::is_space() const {
    if (this->is_empty()) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if ((*this)[i] != 32) {
            return false;
        }
    }
    return true;
}





bool pif::string::is_upper() const {
    pif::string temp = *this;

    return (*this == temp.to_upper());
}





bool pif::string::is_lower() const {
    pif::string temp = *this;

    return (*this == temp.to_lower());
}





bool pif::string::is_capitalize() const {
    pif::string temp = *this;

    return (*this == temp.capitalize());
}





bool pif::string::is_title() const {
    pif::string temp = *this;

    return (*this == temp.title());
}





bool pif::string::is_palindrome() const {
    pif::string temp = *this;

    return (*this == temp.rev_string());
}





bool pif::string::non_case_comparison(const char *symbol, const char &letter) const {
    pif::string temp = *this;
    char lower_case_letter = letter;
    temp.to_lower();

    if (letter >= 65 && letter <= 90) {
        lower_case_letter = letter + 32;
    }

    if (symbol == ">") {
        return (temp > lower_case_letter);
    }
    else if (symbol == ">=") {
        return (temp >= lower_case_letter);
    }
    else if (symbol == "<") {
        return (temp < lower_case_letter);
    }
    else if (symbol == "<=") {
        return (temp <= lower_case_letter);
    }
    else if (symbol == "==") {
        return (temp == lower_case_letter);
    }
    else if (symbol == "!=") {
        return (temp != lower_case_letter);
    }
    return false;
}





bool pif::string::non_case_comparison(const char *symbol, const char *cstring) const {
    pif::string temp1 = *this;
    pif::string temp2 = cstring;
    temp1.to_lower();
    temp2.to_lower();

    if (symbol == ">") {
        return (temp1 > temp2);
    }
    else if (symbol == ">=") {
        return (temp1 >= temp2);
    }
    else if (symbol == "<") {
        return (temp1 < temp2);
    }
    else if (symbol == "<=") {
        return (temp1 <= temp2);
    }
    else if (symbol == "==") {
        return (temp1 == temp2);
    }
    else if (symbol == "!=") {
        return (temp1 != temp2);
    }
    return false;
}





bool pif::string::non_case_comparison(const char *symbol, const std::string &str) const {
    pif::string temp1 = *this;
    pif::string temp2 = str;
    temp1.to_lower();
    temp2.to_lower();

    if (symbol == ">") {
        return (temp1 > temp2);
    }
    else if (symbol == ">=") {
        return (temp1 >= temp2);
    }
    else if (symbol == "<") {
        return (temp1 < temp2);
    }
    else if (symbol == "<=") {
        return (temp1 <= temp2);
    }
    else if (symbol == "==") {
        return (temp1 == temp2);
    }
    else if (symbol == "!=") {
        return (temp1 != temp2);
    }
    return false;
}





bool pif::string::non_case_comparison(const char *symbol, const pif::string &str) const {
    pif::string temp1 = *this;
    pif::string temp2 = str;
    temp1.to_lower();
    temp2.to_lower();

    if (symbol == ">") {
        return (temp1 > temp2);
    }
    else if (symbol == ">=") {
        return (temp1 >= temp2);
    }
    else if (symbol == "<") {
        return (temp1 < temp2);
    }
    else if (symbol == "<=") {
        return (temp1 <= temp2);
    }
    else if (symbol == "==") {
        return (temp1 == temp2);
    }
    else if (symbol == "!=") {
        return (temp1 != temp2);
    }
    return false;
}





inline bool pif::string::is_longer(const char &letter) const {
    return (this->length() > 1) ? true : false;
}





inline bool pif::string::is_longer(const char *cstring) const {
    return (this->length() > pif::get_cstring_size(cstring)) ? true : false;
}





inline bool pif::string::is_longer(const std::string &str) const {
    return (this->length() > str.size()) ? true : false;
}





inline bool pif::string::is_longer(const pif::string &str) const {
    return (this->length() > str.length()) ? true : false;
}





inline bool pif::string::is_longer_or_equal(const char &letter) const {
    return (this->length() >= 1) ? true : false;
}





inline bool pif::string::is_longer_or_equal(const char *cstring) const {
    return (this->length() >= pif::get_cstring_size(cstring)) ? true : false;
}





inline bool pif::string::is_longer_or_equal(const std::string &str) const {
    return (this->length() >= str.size()) ? true : false;
}





inline bool pif::string::is_longer_or_equal(const pif::string &str) const {
    return (this->length() >= str.length()) ? true : false;
}





inline bool pif::string::is_shorter(const char &letter) const {
    return (this->length() < 1) ? true : false;
}





inline bool pif::string::is_shorter(const char *cstring) const {
    return (this->length() < pif::get_cstring_size(cstring)) ? true : false;
}





inline bool pif::string::is_shorter(const std::string &str) const {
    return (this->length() < str.size()) ? true : false;
}





inline bool pif::string::is_shorter(const pif::string &str) const {
    return (this->length() < str.length()) ? true : false;
}





inline bool pif::string::is_shorter_or_equal(const char &letter) const {
    return (this->length() <= 1) ? true : false;
}





inline bool pif::string::is_shorter_or_equal(const char *cstring) const {
    return (this->length() <= pif::get_cstring_size(cstring)) ? true : false;
}





inline bool pif::string::is_shorter_or_equal(const std::string &str) const {
    return (this->length() <= str.size()) ? true : false;
}





inline bool pif::string::is_shorter_or_equal(const pif::string &str) const {
    return (this->length() <= str.length()) ? true : false;
}





inline bool pif::string::same_length(const char &letter) const {
    return (this->length() == 1);
}




inline bool pif::string::same_length(const char *cstring) const {
    return (this->length() == pif::get_cstring_size(cstring));
}





inline bool pif::string::same_length(const std::string &str) const {
    return (this->length() == str.size());
}





inline bool pif::string::same_length(const pif::string &str) const {
    return (this->length() == str.length());
}





char &pif::string::operator[](const int index) {
    if (index > this->length() - 1 || index < 0) {
        std::cout << "Invalid Index Position." << std::endl;
        this->s.~array();
        exit(0);
    }

    return this->s.arr[index];
}





inline char pif::string::operator[](const int index) const {
    return this->get(index);
}





pif::string &pif::string::operator=(const char &letter) {
    this->copy(letter);

    return *this;
}





pif::string &pif::string::operator=(const char *cstring) {
    this->copy(cstring);

    return *this;
}





pif::string &pif::string::operator=(const std::string &str) {
    this->copy(str);

    return *this;
}





pif::string &pif::string::operator=(const pif::string &str) {
    if (*this != str) {
        this->copy(str);
    }

    return *this;
}





bool pif::string::operator==(const char &letter) const {
    if (this->length() != 1) {
        return false;
    }

    return (this->s.arr[0] == letter);
}





bool pif::string::operator==(const char *cstring) const {
    if (this->length() != pif::get_cstring_size(cstring)) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->s.arr[i] != cstring[i]) {
            return false;
        }
    }

    return true;
}





bool pif::string::operator==(const std::string &str) const {
    if (this->length() != str.size()) {
        return false;
    }

    for (int i=0; i<this->length(); i++) {
        if (this->s.arr[i] != str[i]) {
            return false;
        }
    }

    return true;
}





bool pif::string::operator==(const pif::string &str) const {
    return this->s == str.s;
}





inline bool pif::string::operator!=(const char &letter) const {
    return (*this == letter) ? false : true;
}





inline bool pif::string::operator!=(const char *cstring) const {
    return (*this == cstring) ? false : true;
}





inline bool pif::string::operator!=(const std::string &str) const {
    return (*this == str) ? false : true;
}





inline bool pif::string::operator!=(const pif::string &str) const {
    return (*this == str) ? false : true;
}





bool pif::string::operator>(const char &letter) const {
    if (this->is_empty()) {
        return false;
    }

    return (this->s.arr[0] > letter);
}





bool pif::string::operator>(const char *cstring) const {
    const int min_length = std::min(this->length(), pif::get_cstring_size(cstring));

    for (int i=0; i<min_length; i++) {
        if (this->s.arr[i] > cstring[i]) {
            return true;
        }
        else if (this->s.arr[i] == cstring[i]) {
            continue;
        }
        return false;
    }

    return (this->length() > pif::get_cstring_size(cstring)) ? true : false;
}





bool pif::string::operator>(const std::string &str) const {
    const int min_length = std::min(this->length(), (int) str.size());

    for (int i=0; i<min_length; i++) {
        if (this->s.arr[i] > str[i]) {
            return true;
        }
        else if (this->s.arr[i] == str[i]) {
            continue;
        }
        return false;
    }

    return (this->length() > str.size()) ? true : false;
}





bool pif::string::operator>(const pif::string &str) const {
    const int min_length = std::min(this->length(), str.length());

    for (int i=0; i<min_length; i++) {
        if (this->s.arr[i] > str[i]) {
            return true;
        }
        else if (this->s.arr[i] == str[i]) {
            continue;
        }
        return false;
    }

    return (this->length() > str.length()) ? true : false;
}





bool pif::string::operator>=(const char &letter) const {
    if (this->is_empty()) {
        return false;
    }

    return (this->s.arr[0] >= letter);
}





bool pif::string::operator>=(const char *cstring) const {
    const int min_length = std::min(this->length(), pif::get_cstring_size(cstring));

    for (int i=0; i<min_length; i++) {
        if (this->s.arr[i] > cstring[i]) {
            return true;
        }
        else if (this->s.arr[i] == cstring[i]) {
            continue;
        }
        return false;
    }

    return (this->length() >= pif::get_cstring_size(cstring)) ? true : false;
}





bool pif::string::operator>=(const std::string &str) const {
    const int min_length = std::min(this->length(), (int) str.size());

    for (int i=0; i<min_length; i++) {
        if (this->s.arr[i] > str[i]) {
            return true;
        }
        else if (this->s.arr[i] == str[i]) {
            continue;
        }
        return false;
    }

    return (this->length() >= str.size()) ? true : false;
}





bool pif::string::operator>=(const pif::string &str) const {
    const int min_length = std::min(this->length(), str.length());

    for (int i=0; i<min_length; i++) {
        if (this->s.arr[i] > str[i]) {
            return true;
        }
        else if (this->s.arr[i] == str[i]) {
            continue;
        }
        return false;
    }

    return (this->length() >= str.length()) ? true : false;
}





bool pif::string::operator<(const char &letter) const {
    return (*this >= letter && this->length() >= 1) ? false : true;
}





bool pif::string::operator<(const char *cstring) const {
    return (*this > cstring || *this == cstring) ? false : true;
}





bool pif::string::operator<(const std::string &str) const {
    return (*this > str || *this == str) ? false : true;
}





bool pif::string::operator<(const pif::string &str) const {
    return (*this > str || *this == str) ? false : true;
}





bool pif::string::operator<=(const char &letter) const {
    if (*this == letter) {
        return true;
    }

    return (*this >= letter) ? false : true;
}





bool pif::string::operator<=(const char *cstring) const {
    return (*this > cstring) ? false : true;
}





bool pif::string::operator<=(const std::string &str) const {
    return (*this > str) ? false : true;
}





bool pif::string::operator<=(const pif::string &str) const {
    return (*this > str) ? false : true;
}





pif::string pif::string::operator+=(const int positions) {
    if (positions < 0) {
        (*this) -= (positions*-1);
    }

    for (int i=0; i<positions; i++) {
        this->push_back('_');
    }

    return *this;
}





pif::string pif::string::operator+=(const char &letter) {
    this->push_back(letter);

    return *this;
}





pif::string pif::string::operator+=(const char *cstring) {
    this->extend(cstring);

    return *this;
}





pif::string pif::string::operator+=(const std::string &str) {
    this->extend(str);

    return *this;
}





pif::string pif::string::operator+=(const pif::string &str) {
    this->extend(str);

    return *this;
}





pif::string pif::string::operator-=(const int positions) {
    if (positions > this->length()) {
        std::cout << "Invalid 'intager' passed." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (positions < 0) {
        (*this) += (positions*-1);

        return *this;
    }

    if (positions == this->length()) {
        this->clear();
    }
    else {
        char *temp = new(std::nothrow) char[this->length()-positions];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length()-positions; i++) {
            temp[i] = this->s.arr[i];
        }

        delete[] this->s.arr;

        *this->s.array_size = this->length() - positions;
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->s.arr[i] = temp[i];
        }

        delete[] temp;
    }

    return *this;
}





pif::string pif::string::operator-=(const char &letter) {
    this->remove(letter, true);

    return *this;
}





pif::string pif::string::operator-=(const char *cstring) {
    this->remove(cstring, true);

    return *this;
}





pif::string pif::string::operator-=(const std::string &str) {
    this->remove(str, true);

    return *this;
}





pif::string pif::string::operator-=(const pif::string &str) {
    this->remove(str, true);

    return *this;
}





pif::string pif::string::operator*=(const int total_times) {
    const int original_length = this->length();

    if (total_times < 0) {
        std::cout << "Only possitive numbers are allowed." << std::endl;
        this->s.~array();
        exit(0);
    }
    else if (total_times == 0) {
        this->clear();
    }
    else {
        for (int i=0; i<total_times-1; i++) {
            this->extend(this->slice(0, original_length));
        }
    }

    return *this;
}





pif::string pif::string::operator+(const int positions) const {
    pif::string temp = *this;
    temp += positions;

    return temp;
}





pif::string pif::string::operator+(const char &letter) const {
    pif::string temp = *this;
    temp += letter;

    return temp;
}





pif::string pif::string::operator+(const char *cstring) const {
    pif::string temp = *this;
    temp += cstring;

    return temp;
}





pif::string pif::string::operator+(const std::string &str) const {
    pif::string temp = *this;
    temp += str;

    return temp;
}





pif::string pif::string::operator+(const pif::string &str) const {
    pif::string temp = *this;
    temp += str;

    return temp;
}





pif::string pif::string::operator-(const int positions) const {
    pif::string temp = *this;
    temp -= positions;

    return temp;
}





pif::string pif::string::operator-(const char &letter) const {
    pif::string temp = *this;
    temp -= letter;

    return temp;
}






pif::string pif::string::operator-(const char *cstring) const {
    pif::string temp = *this;
    temp -= cstring;

    return temp;
}





pif::string pif::string::operator-(const std::string &str) const {
    pif::string temp = *this;
    temp -= str;

    return temp;
}





pif::string pif::string::operator-(const pif::string &str) const {
    pif::string temp = *this;
    temp -= str;

    return temp;
}





pif::string pif::string::operator*(const int total_times) const {
    pif::string temp = *this;
    temp *= total_times;

    return temp;
}





pif::string pif::string::operator++(int) {
    this->push_back('_');

    return *this;
}





pif::string pif::string::operator++() {
    this->push_front('_');

    return *this;
}





pif::string pif::string::operator--(int) {
    this->pop_back();

    return *this;
}





pif::string pif::string::operator--() {
    this->pop_front();

    return *this;
}





inline bool pif::string::__common_iterator::operator==(const pif::string::__common_iterator &_it) const {
    return (this->current == _it.current) ? true : false;
}





inline bool pif::string::__common_iterator::operator!=(const pif::string::__common_iterator &_it) const {
    return (this->current != _it.current) ? true : false;
}





inline bool pif::string::__common_iterator::operator>(const pif::string::__common_iterator &_it) const {
    return (this->current > _it.current) ? true : false;
}





inline bool pif::string::__common_iterator::operator>=(const pif::string::__common_iterator &_it) const {
    return (this->current >= _it.current) ? true : false;
}





inline bool pif::string::__common_iterator::operator<(const pif::string::__common_iterator &_it) const {
    return (this->current < _it.current) ? true : false;
}





inline bool pif::string::__common_iterator::operator<=(const pif::string::__common_iterator &_it) const {
    return (this->current <= _it.current) ? true : false;
}





pif::string::__common_iterator &pif::string::__common_iterator::operator++() {
    ++ this->current;

    return *this;
}





pif::string::__common_iterator &pif::string::__common_iterator::operator++(int) {
    this->current ++;

    return *this;
}





pif::string::__common_iterator &pif::string::__common_iterator::operator--() {
    -- this->current;

    return *this;
}





pif::string::__common_iterator &pif::string::__common_iterator::operator--(int) {
    this->current --;

    return *this;
}





pif::string::const_iterator::const_iterator() {}





pif::string::const_iterator::const_iterator(char *elem) {
    this->current = elem;
}





inline const char &pif::string::const_iterator::operator*() const {
    return *this->current;
}





const pif::string::const_iterator pif::string::const_iterator::operator+(int value) const {
    pif::string::const_iterator temp = this->current + value;

    return temp;
}





const pif::string::const_iterator pif::string::const_iterator::operator-(int value) const {
    pif::string::const_iterator temp = this->current - value;

    return temp;
}





pif::string::iterator::iterator() {}





pif::string::iterator::iterator(char *elem) {
    this->current = elem;
}





inline char &pif::string::iterator::operator*() const {
    return *this->current;
}





pif::string::iterator &pif::string::iterator::operator+=(const int value) {
    this->current += value;

    return *this;
}





pif::string::iterator &pif::string::iterator::operator-=(const int value) {
    this->current -= value;

    return *this;
}





pif::string::iterator pif::string::iterator::operator+(const int value) const {
    pif::string::iterator it = *this;
    it += value;

    return it;
}





pif::string::iterator pif::string::iterator::operator-(const int value) const {
    pif::string::iterator it = *this;
    it -= value;

    return it;
}




pif::string pif::make_string(const int value) {
    pif::string temp = std::to_string(value);

    return temp;
}





pif::string pif::make_string(const double value) {
    pif::string temp = std::to_string(value);

    return temp;
}





pif::string pif::make_string(const long double value) {
    pif::string temp = std::to_string(value);

    return temp;
}





pif::string pif::make_string(const char &letter) {
    return pif::string(letter);
}





pif::string pif::make_string(const char *cstring) {
    return pif::string(cstring);
}





pif::string pif::make_string(const std::string &str) {
    return pif::string(str);
}





pif::string pif::make_string(const pif::string &str) {
    return str;
}





bool pif::iter_link_to_string(const pif::string &str, typename pif::string::iterator &it) {
    for (typename pif::string::iterator temp_it=str.begin(); temp_it!=str.end(); ++temp_it) {
        if (temp_it == it) {
            return true;
        }
    }
    return false;
}





bool pif::iter_link_to_string(const pif::string &str, typename pif::string::const_iterator &it) {
    for (typename pif::string::const_iterator temp_it=str.cbegin(); temp_it!=str.cend(); ++temp_it) {
        if (temp_it == it) {
            return true;
        }
    }
    return false;
}





int pif::get_iter_index(const pif::string &str, typename pif::string::iterator &it) {
    int index = 0;
    for (typename pif::string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
        if (temp_it == it) {
            break;
        }
        index ++;
    }
    return index;
}





int pif::get_iter_index(const pif::string &str, typename pif::string::const_iterator &it) {
    int index = 0;
    for (typename pif::string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
        if (temp_it == it) {
            break;
        }
        index ++;
    }
    return index;
}





int pif::get_iter_index(std::string &str, typename std::string::iterator &it) {
    int index = 0;
    for (typename std::string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
        if (temp_it == it) {
            break;
        }
        index ++;
    }
    return index;  
}





int pif::get_iter_index(const std::string &str, typename std::string::const_iterator &it) {
    int index = 0;
    for (typename std::string::const_iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
        if (temp_it == it) {
            break;
        }
        index ++;
    }
    return index;  
}






int pif::string::__char_to_int(const char &letter) {
    switch (letter) {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}
