#ifdef STRING


namespace pif {

    inline int string::iget(const int index) const {
        return (int) this->get(index);
    }



    inline int string::length() const {
        return this->s.length();
    }



    inline int string::size() const {
        return this->s.size();
    }



    inline char *string::data() const {
        return this->s.arr;
    }



    inline void string::shrink() {
        this->s.shrink();
    }



    inline char string::first() const {
        return (this->is_empty()) ? '_' : this->s.arr[0];
    }



    inline char string::last() const {
        return (this->is_empty()) ? '_' : this->s.arr[this->length() - 1];
    }



    inline string::iterator string::begin() const {
        return iterator(this->s.arr);    
    }



    inline string::iterator string::end() const {
        return iterator(this->s.arr + this->length());
    }



    inline string::iterator string::rbegin() const {
        return iterator(this->s.arr + this->length() - 1);
    }



    inline string::iterator string::rend() const {
        return iterator(this->s.arr - 1);
    }



    inline const string::const_iterator string::cbegin() const {
        return const_iterator(this->s.arr);    
    }



    inline const string::const_iterator string::cend() const {
        return const_iterator(this->s.arr + this->length());
    }



    inline const string::const_iterator string::crbegin() const {
        return const_iterator(this->s.arr + this->length() - 1);
    }



    inline const string::const_iterator string::crend() const {
        return const_iterator(this->s.arr - 1);
    }



    inline bool string::is_inside(const char &letter) const {
        return (this->index(letter) != -1) ? true : false;
    }



    inline bool string::is_inside(const char *cstring) const {
        return (this->index(cstring) != -1) ? true : false;
    }



    inline bool string::is_inside(const std::string &str) const {
        return (this->index(str) != -1) ? true : false;
    }



    inline bool string::is_inside(const string &str) const {
        return (this->index(str) != -1) ? true : false;
    }



    inline bool string::is_empty() const {
        return (this->length() == 0) ? true : false;
    }



    inline bool string::is_longer(const char &letter) const {
        return (this->length() > 1) ? true : false;
    }



    inline bool string::is_longer(const char *cstring) const {
        return (this->length() > this->__get_cstring_size(cstring)) ? true : false;
    }



    inline bool string::is_longer(const std::string &str) const {
        return (this->length() > str.size()) ? true : false;
    }



    inline bool string::is_longer(const string &str) const {
        return (this->length() > str.length()) ? true : false;
    }



    inline bool string::is_longer_or_equal(const char &letter) const {
        return (this->length() >= 1) ? true : false;
    }



    inline bool string::is_longer_or_equal(const char *cstring) const {
        return (this->length() >= this->__get_cstring_size(cstring)) ? true : false;
    }



    inline bool string::is_longer_or_equal(const std::string &str) const {
        return (this->length() >= str.size()) ? true : false;
    }



    inline bool string::is_longer_or_equal(const string &str) const {
        return (this->length() >= str.length()) ? true : false;
    }



    inline bool string::is_shorter(const char &letter) const {
        return (this->length() < 1) ? true : false;
    }



    inline bool string::is_shorter(const char *cstring) const {
        return (this->length() < this->__get_cstring_size(cstring)) ? true : false;
    }



    inline bool string::is_shorter(const std::string &str) const {
        return (this->length() < str.size()) ? true : false;
    }



    inline bool string::is_shorter(const string &str) const {
        return (this->length() < str.length()) ? true : false;
    }



    inline bool string::is_shorter_or_equal(const char &letter) const {
        return (this->length() <= 1) ? true : false;
    }



    inline bool string::is_shorter_or_equal(const char *cstring) const {
        return (this->length() <= this->__get_cstring_size(cstring)) ? true : false;
    }



    inline bool string::is_shorter_or_equal(const std::string &str) const {
        return (this->length() <= str.size()) ? true : false;
    }



    inline bool string::is_shorter_or_equal(const string &str) const {
        return (this->length() <= str.length()) ? true : false;
    }



    inline bool string::same_length(const char &letter) const {
        return (this->length() == 1);
    }


    inline bool string::same_length(const char *cstring) const {
        return (this->length() == this->__get_cstring_size(cstring));
    }



    inline bool string::same_length(const std::string &str) const {
        return (this->length() == str.size());
    }



    inline bool string::same_length(const string &str) const {
        return (this->length() == str.length());
    }



    inline char string::operator[](const int index) const {
        return this->get(index);
    }



    inline bool string::operator!=(const char &letter) const {
        return (*this == letter) ? false : true;
    }



    inline bool string::operator!=(const char *cstring) const {
        return (*this == cstring) ? false : true;
    }



    inline bool string::operator!=(const std::string &str) const {
        return (*this == str) ? false : true;
    }



    inline bool string::operator!=(const string &str) const {
        return (*this == str) ? false : true;
    }
}


#endif
