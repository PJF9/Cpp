#ifndef STRING
#define STRING

#include "array.hpp"


namespace pif {

    class string {
        private:
            pif::array<char> s;

            int __char_to_int(const char &letter) const;
            int __get_cstring_size(const char *cstring) const;
            int __get_iter_index(std::string &str, typename std::string::iterator &it) const;
            int __get_iter_index(const std::string &str, typename std::string::const_iterator &it) const;

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

            int __get_iter_index(string &str, typename string::iterator &it) const;
            int __get_iter_index(const string &str, typename string::const_iterator &it) const;
            bool __iter_link_to_string(string &str, string::iterator &it) const;
            bool __iter_link_to_string(const string &str, string::const_iterator &it) const;


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
}


#include "string_in.inl"
#include "string_code.cpp"
#endif
