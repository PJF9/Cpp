#ifdef STRING


namespace pif {
    
    string::string() {
        *this->s.array_size = 0;
        *this->s.extended_size = ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}
    }





    string::string(const char &lettter) {
        *this->s.array_size = 1;
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        this->s.arr[0] = lettter;
    }





    string::string(const char *cstring) {
        *this->s.array_size = this->__get_cstring_size(cstring);
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->s.arr[i] = cstring[i];
        }
    }





    string::string(const string &str) {
        *this->s.array_size = str.s.length();
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->s.arr[i] = str.s.get(i);
        }
    }





    string::string(const std::string &str) {
        *this->s.array_size = str.size();
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->s.arr[i] = str[i];
        }
    }





    string::string(const array<int> &ascii_arr) {
        *this->s.array_size = ascii_arr.length();
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->s.arr[i] = (char) ascii_arr[i];
        }
    }





    string::~string() {}





    char string::get(const int index) const {
        if (index > this->length() || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        return this->s.get(index);
    }





    string::iterator string::get_iter(const int index) const {
        if (index > this->length() - 1 || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        return iterator(this->begin() + index);
    }





    string::const_iterator string::get_citer(const int index) const {
        if (index > this->length() - 1 || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        return const_iterator(this->cbegin() + index);
    }





    void string::set_size(const int new_size, const char &elem) {
        if (new_size < 0) {
            std::cout << "Cannot compress the string to negative size." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.set_size(new_size, elem);
    }





    void string::change_capacity(const int new_extended_size) {
        if (new_extended_size < this->length()) {
            std::cout << "New memory size must be highter than the length of the string." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.change_capacity(new_extended_size);
    }





    string string::push_back(const char &letter) {
        this->s.push_back(letter);

        return *this;
    }





    string string::push_front(const char &letter) {
        this->s.push_front(letter);

        return *this;
    }





    string string::insert(const int index, const char &letter) {
        if (index > this->length() || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.insert(index, letter);

        return *this;
    }





    string string::insert(string::iterator &position, const char &new_letter) {
        const int index = this->__get_iter_index(*this, position);

        if (index == this->length()+1) {
            std::cout << "The iterator that have been passed is either not created by the 'this' string or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->insert(index, new_letter);
    }





    string string::insert(string::const_iterator &position, const char &new_letter) {
        const int index = this->__get_iter_index(*this, position);

        if (index == this->length()+1) {
            std::cout << "The iterator that have been passed is either not created by the 'this' string or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->insert(index, new_letter);
    }





    string string::extend(const char *cstring) {
        for (int i=0; i<this->__get_cstring_size(cstring); i++) {
            this->push_back(cstring[i]);
        }

        return *this;
    }





    string string::extend(const std::string &str) {
        for (int i=0; i<str.size(); i++) {
            this->push_back(str[i]);
        }

        return *this;
    }





    string string::extend(const string &str) {
        this->s.extend(str.s);

        return *this;
    }





    string string::extend(const char *cstring, const int index) {
        if (index > this->length() || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        for (int i=this->__get_cstring_size(cstring)-1; i>=0; i--) {
            this->insert(index, cstring[i]);
        }

        return *this;
    }





    string string::extend(const std::string &str, const int index) {
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





    string string::extend(const string &str, const int index) {
        if (index > this->length() || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.extend(str.s, index);

        return *this;
    }





    string string::extend(string::iterator &start, string::iterator &end, string &iters_object) {
        const int start_i = this->__get_iter_index(iters_object, start);
        const int end_i = this->__get_iter_index(iters_object, end);

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

        for (string::iterator it=start; it!=end; ++it) {
            this->push_back(*it);
        }

        return *this;
    }





    string string::extend(string::const_iterator &start, string::const_iterator &end, string &iters_object) {
        const int start_i = this->__get_iter_index(iters_object, start);
        const int end_i = this->__get_iter_index(iters_object, end);

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

        for (string::const_iterator it=start; it!=end; ++it) {
            this->push_back(*it);
        }

        return *this;
    }





    string string::extend(std::string::iterator &start, std::string::iterator &end, std::string &iters_object) {
        const int start_i = this->__get_iter_index(iters_object, start);
        const int end_i = this->__get_iter_index(iters_object, end);

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





    string string::extend(std::string::const_iterator &start, std::string::const_iterator &end, std::string &iters_object) {
        const int start_i = this->__get_iter_index(iters_object, start);
        const int end_i = this->__get_iter_index(iters_object, end);

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





    string string::replace_back(const char &letter) {
        if (this->length() == 0) {
            std::cout << "String is empty." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s[this->length() - 1] = letter;

        return *this;
    }





    string string::replace_front(const char &letter) {
        if (this->length() == 0) {
            std::cout << "String is empty." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s[0] = letter;

        return *this;
    }





    string string::replace(const int index, const char &letter) {
        if (index > (this->length() - 1) || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s[index] = letter;

        return *this;
    }





    string string::replace(const int index, const char *cstring) {
        if (index > (this->length() - 1) || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        for (int i=index; i<index + this->__get_cstring_size(cstring); i++) {
            if (i >= this->length()) {
                this->push_back(cstring[i - index]);
            }
            else {
                this->s[i] = cstring[i - index];
            }
        }

        return *this;
    }





    string string::replace(const int index, const std::string &str) {
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





    string string::replace(const int index, const string &str) {
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





    string string::replace(const int index, const int total_pos, const char &letter) {
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





    string string::replace(typename string::iterator &it, const char &new_letter) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, new_letter);

        return *this;
    }





    string string::replace(typename string::iterator &it, const char *cstring) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, cstring);

        return *this;
    }





    string string::replace(typename string::iterator &it, const std::string &str) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, str);

        return *this;
    }





    string string::replace(typename string::iterator &it, const string &str) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, str);

        return *this;
    }





    string string::replace(typename string::const_iterator &it, const char &new_letter) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, new_letter);

        return *this;
    }





    string string::replace(typename string::const_iterator &it, const char *cstring) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, cstring);

        return *this;
    }





    string string::replace(typename string::const_iterator &it, const std::string &str) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, str);

        return *this;
    }





    string string::replace(typename string::const_iterator &it, const string &str) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created by the 'this' object or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, str);

        return *this;
    }





    string string::replace(typename string::iterator &it, const int total_pos, const char &letter) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created be th 'this' string or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, total_pos, letter);

        return *this;
    }





    string string::replace(typename string::const_iterator &it, const int total_pos, const char &letter) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has been passed is either not created be th 'this' string or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->replace(index, total_pos, letter);

        return *this;
    }





    string string::pop_back() {
        if (this->length() == 0) {
            std::cout << "String is empty." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.pop_back();

        return *this;
    }





    string string::pop_front() {
        if (this->length() == 0) {
            std::cout << "String is empty." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.pop_front();

        return *this;
    }





    string string::clear() {
        this->s.clear();

        return *this;
    }





    string string::pop(const int index, const int total_pos) {
        if (index + total_pos > this->length() || index < 0 || total_pos < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.pop(index, total_pos);

        return *this;
    }





    string string::pop(typename string::iterator &it) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has beem passed is either not created by the 'this' string or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->pop(index);

        return *this;
    }





    string string::pop(typename string::const_iterator &it) {
        if (!this->__iter_link_to_string(*this, it)) {
            std::cout << "The iterator that has beem passed is either not created by the 'this' string or is out of bounds." << std::endl;
            this->s.~array();
            exit(0);
        }

        const int index = this->at(it);

        this->pop(index);

        return *this;
    }





    string string::pop(typename string::iterator &start, typename string::iterator &end) {
        if (!this->__iter_link_to_string(*this, start) || !this->__iter_link_to_string(*this, end)) {
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





    string string::pop(typename string::const_iterator &start, typename string::const_iterator &end) {
        if (!this->__iter_link_to_string(*this, start) || !this->__iter_link_to_string(*this, end)) {
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





    string string::remove(const char &letter, const bool dupl) {
        this->s.remove(letter, dupl);

        return *this;
    }





    string string::remove(const char *cstring, const bool dupl) {
        char *temp = new(std::nothrow) char[this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        array<int> indexes = this->indexes(cstring);
        bool stop_del = (dupl) ? false : true;
        bool skip;
        int p = 0;
        const int cstring_length = this->__get_cstring_size(cstring);

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





    string string::remove(const std::string &str, const bool dupl) {
        char *temp = new(std::nothrow) char[this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        array<int> indexes = this->indexes(str);
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





    string string::remove(const string &str, const bool dupl) {
        this->s.remove(str.s, dupl);

        return *this;
    }





    string string::remove_last(const char &letter) {
        this->s.remove_last(letter);

        return *this;
    }





    string string::remove_last(const char *cstring) {
        string temp = cstring;

        this->rev_string();
        temp.rev_string();

        this->remove(temp, false);

        this->rev_string();

        return *this;
    }





    string string::remove_last(const std::string &str) {
        string temp = str;

        this->remove_last(temp);

        return *this;
    }





    string string::remove_last(const string &str) {
        this->s.remove_last(str.s);

        return *this;
    }





    string string::delete_dupls() {
        this->s.delete_dupls();

        return *this;
    }





    string string::rev_string() {
        this->s.rev_array();

        return *this;
    }





    string string::rev_string(typename string::iterator &start, typename string::iterator &end) {
        const int start_i = this->__get_iter_index(*this, start);
        const int end_i = this->__get_iter_index(*this, end);

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

        string temp = this->slice(start_i, end_i);
        temp.rev_string();

        for (int i=0; i<temp.length(); i++) {
            this->s.arr[start_i+i] = temp[i];
        }

        return *this;
    }





    string string::rev_string(typename string::const_iterator &start, typename string::const_iterator &end) {
        const int start_i = this->__get_iter_index(*this, start);
        const int end_i = this->__get_iter_index(*this, end);

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

        string temp = this->slice(start_i, end_i);
        temp.rev_string();

        for (int i=0; i<temp.length(); i++) {
            this->s.arr[start_i+i] = temp[i];
        }

        return *this;
    }





    string string::shuffle() {
        this->s.shuffle();

        return *this;
    }





    string string::adjust_left(const int new_length, const char &filler) {
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





    string string::adjust_right(const int new_length, const char &filler) {
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
    string string::format(const std::initializer_list<_Type> &il) {
        array<int> indexes_arr = this->indexes("{}");

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

        array<string> arr = this->split("{");
        this->clear();

        int j = 0;
        for (int i=0; i<arr.length(); i++) {
            if (arr[i].startswith('}')) {
                arr[i].pop(0);
                arr[i].extend(make_string(*(il.begin() + j)), 0);
                j ++;
            }
            this->extend(arr[i]);
        }

        return *this;
    }





    string string::copy(const char &letter) {
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





    string string::copy(const char *cstring) {
        char *temp = new(std::nothrow) char[this->__get_cstring_size(cstring)];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->__get_cstring_size(cstring); i++) {
            temp[i] = cstring[i];
        }

        if (this->s.arr) {
            delete[] this->s.arr;
        }

        *this->s.array_size = this->__get_cstring_size(cstring);
        *this->s.extended_size = this->length() + ARRAY_GAP;

        this->s.arr = new(std::nothrow) char[this->size()];
        if (!this->s.arr) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->s.arr[i] = temp[i];
        }

        delete[] temp;

        return *this;
    }





    string string::copy(const char *cstring, const int start_i, const int end_i) {
        if (start_i < 0 || end_i < 0 || end_i > this->__get_cstring_size(cstring) || start_i > end_i) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        char *temp = new(std::nothrow) char[this->__get_cstring_size(cstring)];
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





    string string::copy(const std::string &str) {
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





    string string::copy(const std::string &str, const int start_i, const int end_i) {
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





    string string::copy(const string &str) {
        this->s.copy(str.s);

        return *this;
    }





    string string::copy(const string &str, const int start_i, const int end_i) {
        if (start_i < 0 || end_i < 0 || end_i > str.length() || start_i > end_i) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.copy(str.s, start_i, end_i);

        return *this;
    }





    string string::copy(typename string::iterator &start, typename string::iterator &end, string &iters_object) {
        const int start_i = this->__get_iter_index(iters_object, start);
        const int end_i = this->__get_iter_index(iters_object, end);

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





    string string::copy(typename string::const_iterator &start, typename string::const_iterator &end, string &iters_object) {
        const int start_i = this->__get_iter_index(iters_object, start);
        const int end_i = this->__get_iter_index(iters_object, end);

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





    string string::copy(typename std::string::iterator &start, typename std::string::iterator &end, std::string &iters_object) {
        const int start_i = this->__get_iter_index(iters_object, start);
        const int end_i = this->__get_iter_index(iters_object, end);

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





    string string::copy(typename std::string::const_iterator &start, typename std::string::const_iterator &end, const std::string &iters_object) {
        const int start_i = this->__get_iter_index(iters_object, start);
        const int end_i = this->__get_iter_index(iters_object, end);

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





    std::string string::to_std_string() {
        std::string temp;
        for (int i=0; i<this->length(); i++) {
            temp += this->s.arr[i];
        }

        this->clear();

        return temp;
    }





    const char* string::to_cstring() {
        char* temp = new(std::nothrow) char[this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->s.~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            temp[i] = this->s.arr[i];
        }
        temp[this->length()] = '\0';

        this->clear();

        return temp;
    }





    array<char> string::to_array() {
        array<char> temp;
        for (int i=0; i<this->length(); i++) {
            temp.push_back(this->s.arr[i]);
        }

        this->clear();

        return temp;
    }





    array<int> string::give_ascii() const {
        array<int> arr;

        for (int i=0; i<this->length(); i++) {
            arr.push_back((int) this->s.arr[i]);
        }

        return arr;
    }





    string string::to_upper() {
        for (int i=0; i<this->length(); i++) {
            if ((int) this->get(i) >= 97 && (int) this->get(i) <= 122) {
                (*this)[i] = (char)((*this)[i] - 32);
            }
        }

        return *this;
    }





    string string::to_upper(const int start_i, const int end_i) {
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





    string string::to_lower() {
        for (int i=0; i<this->length(); i++) {
            if ((int) this->get(i) >= 65 && (int) this->get(i) <= 90) {
                (*this)[i] = (char)((*this)[i] + 32);
            }
        }

        return *this;
    }





    string string::to_lower(const int start_i, const int end_i) {
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





    string string::swap_case() {
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





    string string::swap_case(const int start_i, const int end_i) {
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





    int string::to_int() {
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





    string string::capitalize() {
        if (this->length() != 0 && (this->s.arr[0] >= 97 && this->s.arr[0] <= 122)) {
            (*this)[0] = (char)((*this)[0] - 32);
        }

        return *this;
    }





    string string::title() {
        this->to_lower();
        if (this->length() != 0 && (this->s.arr[0] >= 97 && this->s.arr[0] <= 122)) {
            (*this)[0] = (char)((*this)[0] - 32);
        }

        return *this;
    }





    string string::swap(const int first_i, const int second_i) {
        if (first_i < 0 || second_i < 0 || second_i > this->length()-1 || first_i > this->length()-1) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        this->s.swap(first_i, second_i);

        return *this;
    }





    string string::swap(string &str) {
        string temp = *this;
        *this = str;
        str = temp;

        return *this;
    }





    string string::swap(std::string &str) {
        string temp = *this;
        *this = str;

        str.clear();
        
        for (int i=0; i<temp.length(); i++) {
            str.push_back(temp[i]);
        }

        return *this;
    }





    string string::slice(const int start, const int end, const int step) const {
        string temp;
        temp.s = this->s.slice(start, end, step);

        return temp;
    }





    string string::center(const int new_length, const char &filler) {
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





    string string::expandtabs(const int tab_size) {
        array<int> indexes_arr = this->indexes('\t');

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





    string string::ltrim() {
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





    string string::rtrim() {
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





    string string::trim() {
        this->rtrim();
        this->ltrim();

        return *this;
    }





    int string::count(const char &letter) const {
        int counts = 0;

        for (int i=0; i<this->length(); i++) {
            if (this->s.arr[i] == letter) {
                counts ++;
            }
        }

        return counts;
    }





    int string::index(const char &letter) const {
        for (int i=0; i<this->length(); i++) {
            if (this->s.arr[i] == letter) {
                return i;
            }
        }

        return -1;
    }





    int string::index(const char *cstring) const {
        const int cstring_length = this->__get_cstring_size(cstring);

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





    int string::index(const std::string &str) const {
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





    int string::index(const string &str) const {
        return this->s.index(str.s);
    }





    array<int> string::indexes(const char &letter) const {
        array<int> temp;
        for (int i=0; i<this->length(); i++) {
            if (this->s.arr[i] == letter) {
                temp.push_back(i);
            }
        }

        return temp;
    }





    array<int> string::indexes(const char *cstring) const {
        const int cstring_length = this->__get_cstring_size(cstring);
        array<int> temp;

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





    array<int> string::indexes(const std::string &str) const {
        array<int> temp;

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





    array<int> string::indexes(const string &str) const {
        return this->s.indexes(str.s);
    }





    int string::last_index(const char &letter) const {
        array<int> indexes = this->indexes(letter);

        return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
    }





    int string::last_index(const char *cstring) const {
        array<int> indexes = this->indexes(cstring);

        return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
    }





    int string::last_index(const std::string &str) const {
        array<int> indexes = this->indexes(str);

        return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
    }





    int string::last_index(const string &str) const {
        array<int> indexes = this->indexes(str);

        return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
    }





    array<char> string::split() const {
        array<char> temp;
        for (int i=0; i<this->length(); i++) {
            temp.push_back(this->s.arr[i]);
        }

        return temp;
    }





    array<string> string::split(const char &letter) const {
        array<int> indexes_arr = this->indexes(letter);
        array<string> temp;

        if (indexes_arr.index(0) == -1) {
            indexes_arr.push_front(0);
        }
        if (indexes_arr.index(this->length() - 1) == -1) {
            indexes_arr.push_back(this->length() - 1);
        }

        for (int i=0; i<indexes_arr.length()-1; i++) {
            string str = this->slice(indexes_arr[i], indexes_arr[i+1]+1);

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





    array<string> string::split(const char *cstring) const {
        array<int> indexes_arr = this->indexes(cstring);
        array<string> temp;
        string st;
        const int cstring_length = this->__get_cstring_size(cstring);

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





    array<string> string::split(const std::string &str) const {
        array<int> indexes_arr = this->indexes(str);
        array<string> temp;
        string st;

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





    array<string> string::split(const string &str) const {
        array<int> indexes_arr = this->indexes(str);
        array<string> temp;
        string st;

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





    array<string> string::splitlines() const {
        array<string> temp;
        string str;

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





    array<string> string::partion(const char &letter) const {
        array<string> temp = {"", "", ""};
        array<int> index_arr = this->indexes(letter);

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
    string string::join(const array<_ArrayType> &arr) const {
        string temp;
        for (int i=0; i<arr.length(); i++) {
            if (i == arr.length() - 1) {
                temp.extend(make_string(arr[i]));
            }
            else {
                temp.extend(make_string(arr[i]));
                temp.extend(*this);
            }
        }

        return temp;
    }





    template <typename _ArrayType>
    string string::join(const std::vector<_ArrayType> &arr) const {
        string temp;
        for (int i=0; i<arr.size(); i++) {
            if (i == arr.size() - 1) {
                temp.extend(make_string(arr[i]));
            }
            else {
                temp.extend(make_string(arr[i]));
                temp.extend(*this);
            }
        }

        return temp;
    }





    int string::at(string::iterator &it) const {
        for (int i=0; i<this->length(); i++) {
            if (it == (this->begin() + i)) {
                return i;
            }
        }

        return -1;
    }





    int string::at(string::const_iterator &it) const {
        for (int i=0; i<this->length(); i++) {
            if (it == (this->cbegin() + i)) {
                return i;
            }
        }

        return -1;
    }





    bool string::startswith(const char &letter) const {
        if (this->is_empty()) {
            return false;
        }

        return (this->s.arr[0] == letter);
    }





    bool string::startswith(const char *cstring) const {
        const int cstring_length = this->__get_cstring_size(cstring);

        if (cstring_length <= this->length() && cstring_length > 0) {
            if (this->slice(0, cstring_length) == cstring) {
                return true;
            }
        }
        return false;
    }





    bool string::startswith(const std::string &str) const {
        if (this->length() >= str.size() && str.size() > 0) {
            if (this->slice(0, str.size()) == str) {
                return true;
            }
        }
        return false;
    }





    bool string::startswith(const string &str) const {
        if (this->length() >= str.length() && str.length() > 0) {
            if (this->slice(0, str.length()) == str) {
                return true;
            }
        }
        return false;
    }





    bool string::endswith(const char &letter) const {
        if (this->is_empty()) {
            return false;
        }

        return (this->s.arr[this->length() - 1] == letter);
    }





    bool string::endswith(const char *cstring) const {
        const int cstring_length = this->__get_cstring_size(cstring);

        if (cstring_length <= this->length() && cstring_length > 0) {
            if (this->slice(this->length()-cstring_length, this->length()) == cstring) {
                return true;
            }
        }
        return false;
    }





    bool string::endswith(const std::string &str) const {
        if (this->length() >= str.size() && str.size() > 0) {
            if (this->slice(this->length() - str.size(), this->length()) == str) {
                return true;
            }
        }
        return false;
    }





    bool string::endswith(const string &str) const {
        if (this->length() >= str.length() && str.length() > 0) {
            if (this->slice(this->length() - str.length(), this->length()) == str) {
                return true;
            }
        }
        return false;
    }





    bool string::is_digit() const {
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





    bool string::is_num() const {
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





    bool string::is_special() const {
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





    bool string::is_alpharithmetic() const {
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





    bool string::is_space() const {
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





    bool string::is_upper() const {
        string temp = *this;

        return (*this == temp.to_upper());
    }





    bool string::is_lower() const {
        string temp = *this;

        return (*this == temp.to_lower());
    }





    bool string::is_capitalize() const {
        string temp = *this;

        return (*this == temp.capitalize());
    }





    bool string::is_title() const {
        string temp = *this;

        return (*this == temp.title());
    }





    bool string::is_palindrome() const {
        string temp = *this;

        return (*this == temp.rev_string());
    }





    bool string::non_case_comparison(const char *symbol, const char &letter) const {
        string temp = *this;
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





    bool string::non_case_comparison(const char *symbol, const char *cstring) const {
        string temp1 = *this;
        string temp2 = cstring;
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





    bool string::non_case_comparison(const char *symbol, const std::string &str) const {
        string temp1 = *this;
        string temp2 = str;
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





    bool string::non_case_comparison(const char *symbol, const string &str) const {
        string temp1 = *this;
        string temp2 = str;
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





    char &string::operator[](const int index) {
        if (index > this->length() - 1 || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->s.~array();
            exit(0);
        }

        return this->s.arr[index];
    }





    string &string::operator=(const char &letter) {
        this->copy(letter);

        return *this;
    }





    string &string::operator=(const char *cstring) {
        this->copy(cstring);

        return *this;
    }





    string &string::operator=(const std::string &str) {
        this->copy(str);

        return *this;
    }





    string &string::operator=(const string &str) {
        if (*this != str) {
            this->copy(str);
        }

        return *this;
    }





    bool string::operator==(const char &letter) const {
        if (this->length() != 1) {
            return false;
        }

        return (this->s.arr[0] == letter);
    }





    bool string::operator==(const char *cstring) const {
        if (this->length() != this->__get_cstring_size(cstring)) {
            return false;
        }

        for (int i=0; i<this->length(); i++) {
            if (this->s.arr[i] != cstring[i]) {
                return false;
            }
        }

        return true;
    }





    bool string::operator==(const std::string &str) const {
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





    bool string::operator==(const string &str) const {
        return this->s == str.s;
    }





    bool string::operator<(const char &letter) const {
        return (*this >= letter && this->length() >= 1) ? false : true;
    }





    bool string::operator<(const char *cstring) const {
        return (*this > cstring || *this == cstring) ? false : true;
    }





    bool string::operator<(const std::string &str) const {
        return (*this > str || *this == str) ? false : true;
    }





    bool string::operator<(const string &str) const {
        return (*this > str || *this == str) ? false : true;
    }





    bool string::operator>(const char &letter) const {
        if (this->is_empty()) {
            return false;
        }

        return (this->s.arr[0] > letter);
    }





    bool string::operator>(const char *cstring) const {
        const int min_length = std::min(this->length(), this->__get_cstring_size(cstring));

        for (int i=0; i<min_length; i++) {
            if (this->s.arr[i] > cstring[i]) {
                return true;
            }
            else if (this->s.arr[i] == cstring[i]) {
                continue;
            }
            return false;
        }

        return (this->length() > this->__get_cstring_size(cstring)) ? true : false;
    }





    bool string::operator>(const std::string &str) const {
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





    bool string::operator>(const string &str) const {
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





    bool string::operator>=(const char &letter) const {
        if (this->is_empty()) {
            return false;
        }

        return (this->s.arr[0] >= letter);
    }





    bool string::operator>=(const char *cstring) const {
        const int min_length = std::min(this->length(), this->__get_cstring_size(cstring));

        for (int i=0; i<min_length; i++) {
            if (this->s.arr[i] > cstring[i]) {
                return true;
            }
            else if (this->s.arr[i] == cstring[i]) {
                continue;
            }
            return false;
        }

        return (this->length() >= this->__get_cstring_size(cstring)) ? true : false;
    }





    bool string::operator>=(const std::string &str) const {
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





    bool string::operator>=(const string &str) const {
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





    bool string::operator<=(const char &letter) const {
        if (*this == letter) {
            return true;
        }

        return (*this >= letter) ? false : true;
    }





    bool string::operator<=(const char *cstring) const {
        return (*this > cstring) ? false : true;
    }





    bool string::operator<=(const std::string &str) const {
        return (*this > str) ? false : true;
    }





    bool string::operator<=(const string &str) const {
        return (*this > str) ? false : true;
    }





    string string::operator+=(const int positions) {
        if (positions < 0) {
            (*this) -= (positions*-1);
        }

        for (int i=0; i<positions; i++) {
            this->push_back('_');
        }

        return *this;
    }





    string string::operator+=(const char &letter) {
        this->push_back(letter);

        return *this;
    }





    string string::operator+=(const char *cstring) {
        this->extend(cstring);

        return *this;
    }





    string string::operator+=(const std::string &str) {
        this->extend(str);

        return *this;
    }





    string string::operator+=(const string &str) {
        this->extend(str);

        return *this;
    }





    string string::operator-=(const int positions) {
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





    string string::operator-=(const char &letter) {
        this->remove(letter, true);

        return *this;
    }





    string string::operator-=(const char *cstring) {
        this->remove(cstring, true);

        return *this;
    }





    string string::operator-=(const std::string &str) {
        this->remove(str, true);

        return *this;
    }





    string string::operator-=(const string &str) {
        this->remove(str, true);

        return *this;
    }





    string string::operator*=(const int total_times) {
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





    string string::operator+(const int positions) const {
        string temp = *this;
        temp += positions;

        return temp;
    }





    string string::operator+(const char &letter) const {
        string temp = *this;
        temp += letter;

        return temp;
    }





    string string::operator+(const char *cstring) const {
        string temp = *this;
        temp += cstring;

        return temp;
    }





    string string::operator+(const std::string &str) const {
        string temp = *this;
        temp += str;

        return temp;
    }





    string string::operator+(const string &str) const {
        string temp = *this;
        temp += str;

        return temp;
    }





    string string::operator-(const int positions) const {
        string temp = *this;
        temp -= positions;

        return temp;
    }





    string string::operator-(const char &letter) const {
        string temp = *this;
        temp -= letter;

        return temp;
    }






    string string::operator-(const char *cstring) const {
        string temp = *this;
        temp -= cstring;

        return temp;
    }





    string string::operator-(const std::string &str) const {
        string temp = *this;
        temp -= str;

        return temp;
    }





    string string::operator-(const string &str) const {
        string temp = *this;
        temp -= str;

        return temp;
    }





    string string::operator*(const int total_times) const {
        string temp = *this;
        temp *= total_times;

        return temp;
    }





    string string::operator++(int) {
        this->push_back('_');

        return *this;
    }





    string string::operator++() {
        this->push_front('_');

        return *this;
    }





    string string::operator--(int) {
        this->pop_back();

        return *this;
    }





    string string::operator--() {
        this->pop_front();

        return *this;
    }





    bool string::__common_iterator::operator==(const string::__common_iterator &_it) const {
        return (this->current == _it.current) ? true : false;
    }





    bool string::__common_iterator::operator!=(const string::__common_iterator &_it) const {
        return (this->current != _it.current) ? true : false;
    }





    bool string::__common_iterator::operator>(const string::__common_iterator &_it) const {
        return (this->current > _it.current) ? true : false;
    }





    bool string::__common_iterator::operator>=(const string::__common_iterator &_it) const {
        return (this->current >= _it.current) ? true : false;
    }





    bool string::__common_iterator::operator<(const string::__common_iterator &_it) const {
        return (this->current < _it.current) ? true : false;
    }





    bool string::__common_iterator::operator<=(const string::__common_iterator &_it) const {
        return (this->current <= _it.current) ? true : false;
    }





    string::__common_iterator &string::__common_iterator::operator++() {
        ++ this->current;

        return *this;
    }





    string::__common_iterator &string::__common_iterator::operator++(int) {
        this->current ++;

        return *this;
    }





    string::__common_iterator &string::__common_iterator::operator--() {
        -- this->current;

        return *this;
    }





    string::__common_iterator &string::__common_iterator::operator--(int) {
        this->current --;

        return *this;
    }





    string::const_iterator::const_iterator() {}





    string::const_iterator::const_iterator(char *elem) {
        this->current = elem;
    }





    const char &string::const_iterator::operator*() const {
        return *this->current;
    }





    const string::const_iterator string::const_iterator::operator+(int value) const {
        string::const_iterator temp = this->current + value;

        return temp;
    }





    const string::const_iterator string::const_iterator::operator-(int value) const {
        string::const_iterator temp = this->current - value;

        return temp;
    }





    string::iterator::iterator() {}





    string::iterator::iterator(char *elem) {
        this->current = elem;
    }





    char &string::iterator::operator*() const {
        return *this->current;
    }





    string::iterator &string::iterator::operator+=(const int value) {
        this->current += value;

        return *this;
    }





    string::iterator &string::iterator::operator-=(const int value) {
        this->current -= value;

        return *this;
    }





    string::iterator string::iterator::operator+(const int value) const {
        string::iterator it = *this;
        it += value;

        return it;
    }





    string::iterator string::iterator::operator-(const int value) const {
        string::iterator it = *this;
        it -= value;

        return it;
    }





    int string::__char_to_int(const char &letter) const {
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





    int string::__get_cstring_size(const char *cstring) const {
        int index = 0;
        while (cstring[index] != '\0') {
            index ++;
        }

        return index;
    }





    int string::__get_iter_index(string &str, typename string::iterator &it) const {
        int index = 0;
        for (typename pif::string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
            if (temp_it == it) {
                break;
            }
            index ++;
        }
        return index;
    }





    int string::__get_iter_index(const string &str, typename string::const_iterator &it) const {
        int index = 0;
        for (typename pif::string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
            if (temp_it == it) {
                break;
            }
            index ++;
        }
        return index;
    }





    int string::__get_iter_index(std::string &str, typename std::string::iterator &it) const {
        int index = 0;
        for (typename std::string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
            if (temp_it == it) {
                break;
            }
            index ++;
        }
        return index;
    }





    int string::__get_iter_index(const std::string &str, typename std::string::const_iterator &it) const {
        int index = 0;
        for (typename std::string::const_iterator temp_it=str.cbegin(); temp_it!=(str.cend()+1); ++temp_it) {
            if (temp_it == it) {
                break;
            }
            index ++;
        }
        return index;
    }





    bool string::__iter_link_to_string(string &str, string::iterator &it) const {
        for (typename pif::string::iterator temp_it=str.begin(); temp_it!=str.end(); ++temp_it) {
            if (temp_it == it) {
                return true;
            }
        }
        return false;
    }





    bool string::__iter_link_to_string(const string &str, string::const_iterator &it) const {
        for (typename pif::string::const_iterator temp_it=str.cbegin(); temp_it!=str.cend(); ++temp_it) {
            if (temp_it == it) {
                return true;
            }
        }
        return false;
    }
}

#endif
