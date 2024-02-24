#ifdef ARRAY


namespace pif {

    template <typename _ArrayType>
        array<_ArrayType>::array() {
            this->array_size = 0;
            this->extended_size = 0;
            this->arr = nullptr;
        }





    template <typename _ArrayType>
    array<_ArrayType>::array(const std::initializer_list<_ArrayType> &init_list) {
        this->array_size = init_list.size();
        this->extended_size = init_list.size() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType [this->extended_size];
        if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; exit(1);}

        for (int i=0; i<init_list.size(); i++) {
            this->arr[i] = *(init_list.begin() + i);
        }
    }





    template <typename _ArrayType>
    array<_ArrayType>::array(const std::vector<_ArrayType> &constructing_vector) {
        this->array_size = constructing_vector.size();
        this->extended_size = constructing_vector.size() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType [this->extended_size];
        if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; exit(1);}

        for (int i=0; i<constructing_vector.size(); i++) {
            this->arr[i] = constructing_vector[i];
        }
    }





    template <typename _ArrayType>
    array<_ArrayType>::array(const array<_ArrayType> &constructing_array) {
        this->array_size = constructing_array.length();
        this->extended_size = constructing_array.size() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType [this->extended_size];
        if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; exit(1);}

        for (int i=0; i<constructing_array.length(); i++) {
            this->arr[i] = constructing_array[i];
        }
    }





    template <typename _ArrayType>
    array<_ArrayType>::array(int total_size, const _ArrayType &value) {
        int size = (total_size > 0) ? total_size : 0;

        this->array_size = size;
        this->extended_size = size + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType [this->extended_size];
        if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; exit(1);}

        for (int i=0; i<size; i++) {
            this->arr[i] = value; 
        }
    }





    template <typename _ArrayType>
    array<_ArrayType>::array(const std::string &constructing_string) {
        this->array_size = constructing_string.size();
        this->extended_size = constructing_string.size() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType[this->extended_size];
        if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; exit(1);}

        for (int i=0; i<constructing_string.size(); i++) {
            this->arr[i] = constructing_string[i];
        }
    }





    template <typename _ArrayType>
    array<_ArrayType>::~array() {
        delete[] this->arr;

        this->arr = nullptr;
        this->array_size = 0;
        this->extended_size = 0;
    }





    template <typename _ArrayType>
    _ArrayType array<_ArrayType>::get(int index) const {
        if ((index < 0) || (index > this->length() - 1)) {
            std::cout << "Invalid Index Position." << std::endl;
            this->~array();
            exit(0);
        }

        return this->arr[index];
    }





    template <typename _ArrayType>
    typename array<_ArrayType>::iterator array<_ArrayType>::get_iter(const int index) const {
        if (index > (this->length()-1) || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->~array();
            exit(0);
        }

        return this->begin() + index;
    }





    template <typename _ArrayType>
    typename array<_ArrayType>::const_iterator array<_ArrayType>::get_citer(const int index) const {
        if (index > (this->length()-1) || index < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->~array();
            exit(0);
        }
        
        return this->cbegin() + index;
    }





    template <typename _ArrayType>
    void array<_ArrayType>::set_length(int new_size, const _ArrayType &value) {
        int size = (new_size > 0) ? new_size : 0;

        _ArrayType *temp = new(std::nothrow) _ArrayType[size];
        if (temp == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

        int temp_size = 0;
        for (int i=0; i<size; i++) {
            if (i > this->array_size - 1) break;

            temp[temp_size++] = this->arr[i];
        }

        if (this->arr != nullptr) {
            delete[] this->arr;
        }

        this->array_size = size;
        this->extended_size = (size > this->extended_size) ? size + ARRAY_GAP : this->extended_size;
        
        this->arr = new(std::nothrow) _ArrayType[this->extended_size];
        if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

        for (int i=0; i<size; i++) {
            this->arr[i] = (i > temp_size) ? value : temp[i];
        }

        delete[] temp;
    }





    template <typename _ArrayType>
    void array<_ArrayType>::set_size(int new_extended_size) {
        if (new_extended_size < 0) {
            if (this->arr != nullptr) delete[] this->arr;

            this->array_size = 0;
            this->extended_size = 0;
            this->arr = nullptr;

            return;
        }

        _ArrayType *temp = new(std::nothrow) _ArrayType[new_extended_size];
        if (temp == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

        int temp_size = 0;
        for (int i=0; i<new_extended_size; i++) {
            if (i > this->array_size - 1) break;

            temp[temp_size++] = this->arr[i];
        }

        if (this->arr != nullptr) delete[] this->arr;

        this->array_size = temp_size;
        this->extended_size = new_extended_size;

        this->arr = new(std::nothrow) _ArrayType[this->extended_size];
        if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

        for (int i=0; i<temp_size; i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::push_back(const _ArrayType &value) {
        if (this->array_size == this->extended_size) {
            this->array_size ++;
            this->extended_size = this->array_size + ARRAY_GAP;

            _ArrayType *temp = new(std::nothrow) _ArrayType [this->array_size];
            if (temp == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

            for (int i=0; i<this->array_size-1; i++) {
                temp[i] = this->arr[i];
            }
            temp[this->array_size - 1] = value;

            if (this->arr != nullptr) delete[] this->arr;

            this->arr = new(std::nothrow) _ArrayType [this->extended_size];
            if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}
            
            for (int i=0; i<this->array_size; i++) {
                this->arr[i] = temp[i];
            }

            delete[] temp;
        }
        else {
            this->array_size ++;

            if (this->array_size == 1) {
                this->arr = new(std::nothrow) _ArrayType [++this->extended_size];
                if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}
                
                this->arr[0] = value;
            }
            else {
                this->arr[this->array_size - 1] = value;
            }
        }

        return *this;
    }




    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::push_front(const _ArrayType &value) {
        if (this->array_size == this->extended_size) {
            this->array_size ++;
            this->extended_size = this->array_size + ARRAY_GAP;

            _ArrayType *temp = new(std::nothrow) _ArrayType [this->array_size];
            if (temp == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

            for (int i=0; i<this->array_size-1; i++) {
                temp[i+1] = this->arr[i];
            }
            temp[0] = value;

            if (this->arr != nullptr) delete[] this->arr;

            this->arr = new(std::nothrow) _ArrayType [this->extended_size];
            if (this->arr== nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

            for (int i=0; i<this->array_size; i++) {
                this->arr[i] = temp[i];
            }

            delete[] temp;
        }
        else {
            this->array_size ++;

            if (this->array_size == 1) {
                this->arr = new(std::nothrow) _ArrayType [++this->extended_size];
                if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

                this->arr[0] = value;
            }
            else {
                for (int i=this->array_size-2; i>=0; i--) {
                    this->arr[i+1] = this->arr[i];
                }
                this->arr[0] = value;
            }
        }

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::insert(int index, const _ArrayType &value) {
        if ((index > this->array_size) || (index < 0)) {
            std::cout << "Invalid index position." << std::endl;
            this->~array();
            exit(0);
        }

        if (this->array_size == this->extended_size) {
            this->array_size ++;
            this->extended_size = this->array_size + ARRAY_GAP;
            
            _ArrayType *temp = new(std::nothrow) _ArrayType[this->array_size];
            if (temp == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

            int i = 0, j = index + 1;
            while (i < index) {
                temp[i] = this->arr[i];
                i++;
            }
            while (j < this->array_size - 1) {
                temp[j++] = this->arr[i++];
            }
            temp[index] = value;

            if (this->arr != nullptr) delete[] this->arr;

            this->arr = new(std::nothrow) _ArrayType[this->extended_size];
            if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

            for (int i=0; i<this->array_size; i++) {
                this->arr[i] = temp[i];
            }

            delete[] temp;
        }
        else {
            this->array_size ++;

            if (this->array_size == 1) {
                if (this->arr != nullptr) delete[] this->arr;

                this->arr = new(std::nothrow) _ArrayType[++this->extended_size];
            }
            else {
                for (int i=this->array_size-2; i>=index; i--) {
                    this->arr[i+1] = this->arr[i];
                }
                this->arr[index] = value;
            }
        }

        return *this;
    }





    template <typename _ArrayType> 
    array<_ArrayType> array<_ArrayType>::insert(array<_ArrayType>::iterator &position, const _ArrayType new_value) {
        if (!this->__link_iter_to_arr(position)) {
            std::cout << "The iterator that has be passed is either is not created by the 'this' or is out of bounds." << std::endl;
            this->~array();
            exit(0);
        }

        this->insert(this->at(position), new_value);

        return *this;
    }





    template <typename _ArrayType> 
    array<_ArrayType> array<_ArrayType>::insert(array<_ArrayType>::const_iterator &position, const _ArrayType new_value) {
        if (!this->__link_iter_to_arr(position)) {
            std::cout << "The iterator that has be passed is either is not created by the 'this' or is out of bounds." << std::endl;
            this->~array();
            exit(0);
        }

        this->insert(this->at(position), new_value);

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::extend(const array<_ArrayType> &aArray) {
        for (_ArrayType elem: aArray) {
            this->push_back(elem);
        }

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::extend(const array<_ArrayType> &aArray, int start) {
        if (start > this->length() || start < 0) {
            std::cout << "Invalid Index Position." << std::endl;
            this->~array();
            exit(0);
        }

        _ArrayType *temp = new(std::nothrow) _ArrayType[this->array_size + aArray.length()];
        if (temp == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

        int i = 0;
        int j = 0;
        int temp_size = 0;
        while (i < start) {
            temp[temp_size++] = this->arr[i++]; 
        }
        while (j < aArray.length()) {
            temp[temp_size++] = aArray[j++];
        }
        while (i< this->array_size) {
            temp[temp_size++] = this->arr[i++];
        }

        if (this->arr != nullptr) delete[] this->arr;

        this->array_size = this->array_size + aArray.length();
        this->extended_size = this->array_size + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType[this->extended_size];
        if (this->arr == nullptr) {BAD_ALLOCATION_MESSAGE; this->~array(); exit(1);}

        for (int i=0; i<this->array_size; i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::extend(const std::vector<_ArrayType> &aVector) {
        for (_ArrayType elem: aVector) {
            this->push_back(elem);
        }

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::extend(const std::vector<_ArrayType> &aVector, int start) {
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
    array<_ArrayType> array<_ArrayType>::extend(array<_ArrayType>::iterator &start, array<_ArrayType>::iterator &end, const array<_ArrayType> &iters_object) {
        if (!iters_object.__link_iter_to_arr(start) || !iters_object.__link_iter_to_arr(end)) {
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

        for (array<_ArrayType>::iterator it=start; it!=end; ++it) {
            this->push_back(*it);
        }

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::extend(array<_ArrayType>::const_iterator &start, array<_ArrayType>::const_iterator &end, const array<_ArrayType> &iters_object) {
        if (!iters_object.__link_iter_to_arr(iters_object, start) || !iters_object.__link_iter_to_arr(iters_object, end)) {
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

        for (array<_ArrayType>::const_iterator it=start; it!=end; ++it) {
            this->push_back(*it);
        }

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::extend(typename std::vector<_ArrayType>::iterator &start, typename std::vector<_ArrayType>::iterator &end, std::vector<_ArrayType> &iters_object) {
        if (!this->__link_iter_to_vector(iters_object, start) || !this->__link_iter_to_vector(iters_object, end)) {
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
    array<_ArrayType> array<_ArrayType>::extend(typename std::vector<_ArrayType>::const_iterator &start, typename std::vector<_ArrayType>::const_iterator &end, std::vector<_ArrayType> &iters_object) {
        if (!this->__link_iter_to_vector(iters_object, start) || !this->__link_iter_to_vector(iters_object, end)) {
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
    array<_ArrayType> array<_ArrayType>::pop_back() {
        if (this->length() == 0) {
            std::cout << "No elements to delete." << std::endl;
            this->~array();
            exit(0);
        }
        else {
            this->array_size --;
            this->extended_size = this->length() + ARRAY_GAP;

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
    array<_ArrayType> array<_ArrayType>::pop_front() {
        if (this->length() == 0) {
            std::cout << "No elements to delete." << std::endl;
            this->~array();
            exit(0);
        }
        else {
            this->array_size --;
            this->extended_size = this->length() + ARRAY_GAP;

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
    array<_ArrayType> array<_ArrayType>::clear() {
        this->array_size = 0;
        this->extended_size = ARRAY_GAP;

        if (this->arr) {
            delete[] this->arr;
        }

        this->arr = new(std::nothrow) _ArrayType [this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        return *this; 
    }




    template <typename _ArrayType>
    void array<_ArrayType>::reset() {
        // this->array_size = new(std::nothrow) int(0);
        // if (this->array_size == nullptr) {std::cout << "Error Allocating Memory." << std::endl; exit(0);}

        // this->extended_size = new(std::nothrow) int(ARRAY_GAP);
        // if (this->extended_size == nullptr) {std::cout << "Error Allocating Memory." << std::endl; delete this->array_size; exit(0);}

        // this->arr = new(std::nothrow) _ArrayType[this->size()];
        // if (this->extended_size == nullptr) {std::cout << "Error Allocating Memory." << std::endl; delete this->array_size; delete this->extended_size; exit(0);}
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::pop(const int index, const int total_pos) {
        if (index < 0 || total_pos < 0 || index + total_pos > this->length() - 1) {
            std::cout << "Invalid Index Position." << std::endl;
            this->~array();
            exit(0);
        }
        else {
            this->array_size -= (total_pos + 1);
            this->extended_size = this->length() + ARRAY_GAP;
            
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
    array<_ArrayType> array<_ArrayType>::remove(const _ArrayType value, const bool dupl) {
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
    array<_ArrayType> array<_ArrayType>::remove(const array<_ArrayType> &arr, const bool dupl) {
        _ArrayType *temp = new(std::nothrow) _ArrayType[this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}
        
        array<int> indexes = this->indexes(arr);
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

        this->array_size = p;
        this->extended_size = this->length() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType[this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::remove(const std::vector<_ArrayType> &vect, const bool dupl) {
        _ArrayType *temp = new(std::nothrow) _ArrayType[this->length()];
        if (!temp) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}
        
        array<int> indexes = this->indexes(vect);
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

        this->array_size = p;
        this->extended_size = this->length() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType[this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::remove_last(const _ArrayType value) {
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
    array<_ArrayType> array<_ArrayType>::remove_last(const array<_ArrayType> &arr) {
        array<_ArrayType> temp = arr;

        this->rev_array();
        temp.rev_array();

        this->remove(temp, false);

        this->rev_array();

        return *this;    
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::remove_last(const std::vector<_ArrayType> &vect) {
        array<_ArrayType> temp = vect;

        this->remove_last(temp);

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::pop(array<_ArrayType>::iterator &position) {
        if (!this->__link_iter_to_arr(position)) {
            std::cout << "The iterator that has be passed is either is not created by the 'this' or is out of bounds." << std::endl;
            this->~array();
            exit(0);
        }

        this->pop(this->at(position), 0);

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::pop(array<_ArrayType>::iterator &start, array<_ArrayType>::iterator &end) {
        if (!this->__link_iter_to_arr(start) || !this->__link_iter_to_arr(end)) {
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
    array<_ArrayType> array<_ArrayType>::pop(array<_ArrayType>::const_iterator &start, array<_ArrayType>::const_iterator &end) {
        if (!this->__link_iter_to_arr(start) || !this->__link_iter_to_arr(end)) {
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
    array<_ArrayType> array<_ArrayType>::pop(array<_ArrayType>::const_iterator &position) {
        if (!this->__link_iter_to_arr(position)) {
            std::cout << "The iterator that has be passed is either is not created by the 'this' or is out of bounds." << std::endl;
            this->~array();
            exit(0);
        }

        this->pop(this->at(position), 0);

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> &array<_ArrayType>::delete_dupls() {
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
    array<_ArrayType> array<_ArrayType>::set() {
        this->sort();
        this->delete_dupls();

        return *this; 
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::sort(const int sorting_alg, const bool rev) {
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
    array<_ArrayType> array<_ArrayType>::rev_array() {
        for (int i=0; i<this->length()/2; i++) {
            _ArrayType temp = arr[i];
            arr[i] = arr[this->length()-1-i];
            arr[this->length()-1-i] = temp;
        }

        return *this; 
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::rev_array(array<_ArrayType>::iterator &start, array<_ArrayType>::iterator &end) {
        if (!this->__link_iter_to_arr(start) || !this->__link_iter_to_arr(end)) {
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
        
        array<_ArrayType> temp = this->slice(start_i, end_i);
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
    array<_ArrayType> array<_ArrayType>::rev_array(array<_ArrayType>::const_iterator &start, array<_ArrayType>::const_iterator &end) {
        if (!this->__link_iter_to_arr(start) || !this->__link_iter_to_arr(end)) {
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
        
        array<_ArrayType> temp = this->slice(start_i, end_i);
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
    array<_ArrayType> array<_ArrayType>::shuffle() {
        pif::array<int> new_indexes = this->__new_indexes();
        pif::array<int> temp;

        for (int i=0; i<this->length(); i++) {
            temp.push_back(this->get(new_indexes[i]));
        }

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }

        return *this;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::is_sorted(const int sorting_algorithm, const bool rev) const {
        array<_ArrayType> temp = *this;

        return (*this == temp.sort(sorting_algorithm, rev));
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::copy(const array<_ArrayType> &ob) {
        *this = ob;

        return *this; 
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::copy(const array<_ArrayType> &ob, const int start_i, const int end_i) {
        if (start_i < 0 || end_i < 0 || end_i > ob.length() || start_i > end_i) {
            std::cout << "Invalid Index Position." << std::endl;
            this->~array();
            exit(0);
        }

        *this = ob.slice(start_i, end_i);

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::copy(const std::vector<_ArrayType> &ob) {
        *this = ob;

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::copy(const std::vector<_ArrayType> &ob, const int start_i, const int end_i) {
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

        this->array_size = j;
        this->extended_size = this->length() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType[this->size()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::copy(array<_ArrayType>::iterator &start, array<_ArrayType>::iterator &end, const array<_ArrayType> &iters_object) {
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
    array<_ArrayType> array<_ArrayType>::copy(array<_ArrayType>::const_iterator &start, array<_ArrayType>::const_iterator &end, const array<_ArrayType> &iters_object) {
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
    array<_ArrayType> array<_ArrayType>::copy(typename std::vector<_ArrayType>::iterator &start, typename std::vector<_ArrayType>::iterator &end, std::vector<_ArrayType> &iters_object) {
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
        
        this->array_size = end_i - start_i;
        this->extended_size = this->length() + ARRAY_GAP;

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
    array<_ArrayType> array<_ArrayType>::copy(typename std::vector<_ArrayType>::const_iterator &start, typename std::vector<_ArrayType>::const_iterator &end, std::vector<_ArrayType> &iters_object) {
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
        
        this->array_size = end_i - start_i;
        this->extended_size = this->length() + ARRAY_GAP;

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
    std::vector<_ArrayType> array<_ArrayType>::to_vector() {
        std::vector<_ArrayType> v;
        for (int i=0; i<this->length(); i++) {
            v.push_back(this->arr[i]);
        }

        this->clear();

        return v;
    }





    template <typename _ArrayType>
    const std::vector<_ArrayType> array<_ArrayType>::to_cvector() {
        std::vector<_ArrayType> temp;
        for (int i=0; i<this->length(); i++) {
            temp.push_back(this->arr[i]);
        }

        this->clear();

        const std::vector<_ArrayType> v = temp;

        return v;
    }





    template <typename _ArrayType>
    const array<_ArrayType> array<_ArrayType>::to_carray() {
        const array<_ArrayType> arr = *this;

        this->clear();

        return arr;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::invoke(_ArrayType (*funct)(_ArrayType)) {
        for (int i=0; i<this->length(); i++) {
            this->arr[i] = funct(this->arr[i]);
        }

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::filter(bool (*funct)(_ArrayType)) {
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

        this->array_size = j;
        this->extended_size = this->length() + ARRAY_GAP;

        this->arr = new(std::nothrow) _ArrayType[this->length()];
        if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

        for (int i=0; i<this->length(); i++) {
            this->arr[i] = temp[i];
        }

        delete[] temp;

        return *this;
    }





    template <typename _ArrayType>
    int array<_ArrayType>::count(const _ArrayType value) const {
        int count_var = 0;

        for (int i=0; i<this->length(); i++) {
            if (this->arr[i] == value) {
                count_var ++;
            }
        }

        return count_var; 
    }





    template <typename _ArrayType>
    int array<_ArrayType>::b_search(const _ArrayType value) const {
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
    int array<_ArrayType>::index(const _ArrayType value) const {
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
    int array<_ArrayType>::index(const _ArrayType value, const int start, const int end, const int step) const {
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
    int array<_ArrayType>::index(const array<_ArrayType> &ob) const {
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
    int array<_ArrayType>::index(const std::vector<_ArrayType> &ob) const {
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
    array<int> array<_ArrayType>::indexes(const _ArrayType value) const {
        array<int> indexes_array;

        for (int i=0; i<this->length(); i++) {
            if (this->arr[i] == value) {
                indexes_array.push_back(i);
            }
        }

        return indexes_array;
    }





    template <typename _ArrayType>
    array<int> array<_ArrayType>::indexes(const array<_ArrayType> &ob) const {
        array<int> temp;

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
    array<int> array<_ArrayType>::indexes(const std::vector<_ArrayType> &ob) const {
        array<int> temp;

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
    int array<_ArrayType>::last_index(const _ArrayType value) const {
        array<int> indexes = this->indexes(value);

        if (indexes.length() != 0) {
            return indexes.get(indexes.length() - 1);
        }
        return -1;
    }





    template <typename _ArrayType>
    int array<_ArrayType>::last_index(const array<_ArrayType> &ob) const {
        array<int> indexes = this->indexes(ob);

        return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
    }





    template <typename _ArrayType>
    int array<_ArrayType>::last_index(const std::vector<_ArrayType> &ob) const {
        array<int> indexes = this->indexes(ob);

        return (indexes.length() != 0) ? indexes[indexes.length() - 1] : -1;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::swap(const int first_index, const int second_index) {
        if ((first_index <= this->length() - 1 && first_index >= 0) && (second_index >= 0 && second_index <= this->length() - 1)) {
            _ArrayType temp = this->arr[first_index];
            this->arr[first_index] = this->arr[second_index];
            this->arr[second_index] = temp;
        }
        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::swap(array<_ArrayType>::iterator &first, array<_ArrayType>::iterator &second) {
        if (!iter_link_to_array(*this, first) || !iter_link_to_array(*this, second)) {
            std::cout << "The iterators that have be passed are either are not created by the 'this' or is out of bounds." << std::endl;
            this->~array();
            exit(0);
        }

        this->swap(this->at(first), this->at(second));

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::swap(array<_ArrayType>::const_iterator &first, array<_ArrayType>::const_iterator &second) {
        if (!iter_link_to_array(*this, first) || !iter_link_to_array(*this, second)) {
            std::cout << "The iterators that have be passed are either are not created by the 'this' or is out of bounds." << std::endl;
            this->~array();
            exit(0);
        }

        this->swap(this->at(first), this->at(second));

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::swap(array<_ArrayType> &other_arr) {
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
    array<_ArrayType> array<_ArrayType>::swap(std::vector<_ArrayType> &vect) {
        pif::array<_ArrayType> temp = *this;
        *this = vect;

        vect.clear();
        
        for (int i=0; i<temp.length(); i++) {
            vect.push_back(temp[i]);
        }

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::slice(const int start, const int end, const int step) const {
        array<_ArrayType> arr;
        
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
    std::string array<_ArrayType>::join(const std::string &seperator) const {
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
    std::string array<_ArrayType>::join(const char seperator) const {
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
    _ArrayType array<_ArrayType>::first() const {
        if (this->length() == 0) {
            std::cout << "Array is empty." << std::endl;
            exit(0);
        }

        return arr[0];
    }





    template <typename _ArrayType>
    _ArrayType array<_ArrayType>::last() const {
        if (this->length() == 0) {
            std::cout << "Array is empty." << std::endl;
            exit(0);
        }

        return arr[this->array_size - 1];
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::is_symmetric() const {
        array<_ArrayType> temp = *this;

        return (*this == temp.rev_array()) ? true : false;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::is_inside(const _ArrayType value) const {
        for (int i=0; i<this->length(); i++) {
            if (this->arr[i] == value) {
                return true;
            }
        }

        return false;
    }





    template <typename _ArrayType>
    array<_ArrayType> &array<_ArrayType>::operator=(const array<_ArrayType> &left) { 
        if (*this != left) {

            if (this->arr) {
                delete [] this->arr;
            }
            
            this->array_size = left.length();
            this->extended_size = left.size();

            this->arr = new(std::nothrow) _ArrayType [this->size()];
            if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

            for (int i=0; i<this->length(); i++) {
                this->arr[i] = left.arr[i];
            }
        }

        return *this; 
    }





    template <typename _ArrayType>
    array<_ArrayType> &array<_ArrayType>::operator=(const std::vector<_ArrayType> &ob) {
        if (*this != ob) {

            if (this->arr) {
                delete [] this->arr;
            }

            this->array_size = ob.size();
            this->extended_size = ob.capacity();

            this->arr = new(std::nothrow) _ArrayType [this->size()];
            if (!this->arr) {std::cout << "Error Allocating Memory." << std::endl; this->~array(); exit(0);}

            for (int i=0; i<this->length(); i++) {
                this->arr[i] = ob[i];
            }
        }

        return *this; 
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::operator==(const array<_ArrayType> &left) const {
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
    bool array<_ArrayType>::operator==(const std::vector<_ArrayType> &left) const {
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
    _ArrayType &array<_ArrayType>::operator[](const int index) {
        if (index < 0 || index > (this->length()-1)) {
            std::cout << "Invalid Index Position." << std::endl;
            exit(0);
        } 

        return this->arr[index];
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator+=(const int value) {
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

            this->array_size += value;
            this->extended_size = this->length() + ARRAY_GAP;

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
    array<_ArrayType> array<_ArrayType>::operator+=(const array<_ArrayType> &right) {
        *this = this->extend(right);

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator+=(const std::vector<_ArrayType> &right) {
        *this = this->extend(right);

        return *this; 
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator-=(const int total_indexes) {
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
    array<_ArrayType> array<_ArrayType>::operator-=(const array<_ArrayType> &right) {
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
    array<_ArrayType> array<_ArrayType>::operator-=(const std::vector<_ArrayType> &right) {
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
    array<_ArrayType> array<_ArrayType>::operator*=(const int total_copies) {
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
    array<_ArrayType> array<_ArrayType>::operator+(const _ArrayType value) const {
        array<_ArrayType> temp = *this;
        
        return temp.push_back(value);
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator+(const array<_ArrayType> &right) const {
        array<_ArrayType> temp = *this;

        return temp.extend(right);
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator+(const std::vector<_ArrayType> &right) const {
        array<_ArrayType> temp = *this;

        return temp.extend(right);
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator-(const int value) const {
        array<_ArrayType> temp = *this;

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
    array<_ArrayType> array<_ArrayType>::operator-(const array<_ArrayType> &right) const {
        array<_ArrayType> temp = *this;

        return (temp -= right);
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator-(const std::vector<_ArrayType> &right) const {
        array<_ArrayType> temp = *this;

        return (temp -= right);
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator*(const int value) const {
        array<_ArrayType> temp = *this;

        return (temp *= value);
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator++(int) {
        (*this) += 1;

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator++() {
        (*this) ++;

        for (int i=0; i<this->length(); i++) {
            _ArrayType temp = this->arr[i];
            this->arr[i] = this->arr[this->length() - 1];
            this->arr[this->length() - 1] = temp;
        }

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator--(int) {
        if (this->array_size == 0) {
            std::cout << "Array is empty." << std::endl;
            this->~array();
            exit(0);
        }
        this->pop_back();

        return *this;
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::operator--() {
        if (this->array_size == 0) {
            std::cout << "Array is empty." << std::endl;
            this->~array();
            exit(0);
        }
        this->pop_front();

        return *this;
    }





    template <typename _ArrayType>
    typename array<_ArrayType>::iterator array<_ArrayType>::begin() const {
        return iterator(this->arr);
    }





    template <typename _ArrayType>
    typename array<_ArrayType>::iterator array<_ArrayType>::end() const {
        return iterator(this->arr + this->length());
    }





    template <typename _ArrayType>
    typename array<_ArrayType>::iterator array<_ArrayType>::rbegin() const {
        return iterator(this->arr + this->length() - 1);
    }





    template <typename _ArrayType>
    typename array<_ArrayType>::iterator array<_ArrayType>::rend() const {
        return iterator(this->arr - 1);
    }





    template <typename _ArrayType>
    const typename array<_ArrayType>::const_iterator array<_ArrayType>::cbegin() const {
        return const_iterator(this->arr);
    }





    template <typename _ArrayType>
    const typename array<_ArrayType>::const_iterator array<_ArrayType>::cend() const {
        return const_iterator(this->arr + this->length());
    }





    template <typename _ArrayType>
    const typename array<_ArrayType>::const_iterator array<_ArrayType>::crbegin() const {
        return const_iterator(this->arr + this->length() - 1);
    }





    template <typename _ArrayType>
    const typename array<_ArrayType>::const_iterator array<_ArrayType>::crend() const {
        return const_iterator(this->arr - 1);
    }





    template <typename _ArrayType>
    int array<_ArrayType>::at(array<_ArrayType>::iterator &it) const {
        for (int i=0; i<this->length(); i++) {
            if (it == (this->begin()+i)) {
                return i;
            }
        }

        return -1;
    }





    template <typename _ArrayType>
    int array<_ArrayType>::at(array<_ArrayType>::const_iterator &it) const {
        for (int i=0; i<this->length(); i++) {
            if (it == (this->begin()+i)) {
                return i;
            }
        }

        return -1;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::__common_iterator::operator!=(const array<_ArrayType>::__common_iterator &element) const {
        if (this->current != element.current) {
            return true;
        }
        return false;
    }






    template <typename _ArrayType>
    bool array<_ArrayType>::__common_iterator::operator==(const array<_ArrayType>:: __common_iterator &element) const {
        if (*this != element) {
            return false;
        }
        return true;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::__common_iterator::operator>(const array<_ArrayType>::__common_iterator &_it) const {
        return (this->current > _it.current) ? true : false;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::__common_iterator::operator>=(const array<_ArrayType>::__common_iterator &_it) const {
        return (this->current >= _it.current) ? true : false;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::__common_iterator::operator<(const array<_ArrayType>::__common_iterator &_it) const {
        return (this->current < _it.current) ? true : false;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::__common_iterator::operator<=(const array<_ArrayType>::__common_iterator &_it) const {
        return (this->current <= _it.current) ? true : false;
    }





    template <typename _ArrayType>
    typename array<_ArrayType>::__common_iterator &array<_ArrayType>::__common_iterator::operator++() {
        ++ this->current;

        return *this;
    }






    template <typename _ArrayType>
    typename array<_ArrayType>::__common_iterator &array<_ArrayType>::__common_iterator::operator--() {
        -- this->current;

        return *this;
    }






    template <typename _ArrayType>
    typename array<_ArrayType>::__common_iterator &array<_ArrayType>::__common_iterator::operator++(int) {
        this->current ++;

        return *this;
    }






    template <typename _ArrayType>
    typename array<_ArrayType>::__common_iterator &array<_ArrayType>::__common_iterator::operator--(int) {
        this->current --;

        return *this;
    }




    template<typename _ArrayType>
    array<_ArrayType>::const_iterator::const_iterator() {}





    template<typename _ArrayType>
    array<_ArrayType>::const_iterator::const_iterator(_ArrayType *elem) {
        this->current = elem;
    }





    template<typename _ArrayType>
    const _ArrayType &array<_ArrayType>::const_iterator::operator*() const {
        return *this->current;
    }





    template<typename _ArrayType>
    const typename array<_ArrayType>::const_iterator array<_ArrayType>::const_iterator::operator+(int value) const {
        array<_ArrayType>::const_iterator temp = this->current + value;

        return temp;
    }





    template<typename _ArrayType>
    const typename array<_ArrayType>::const_iterator array<_ArrayType>::const_iterator::operator-(int value) const {
        array<_ArrayType>::const_iterator temp = this->current - value;

        return temp;
    }




    template<typename _ArrayType>
    array<_ArrayType>::iterator::iterator() {}




    template<typename _ArrayType>
    array<_ArrayType>::iterator::iterator(_ArrayType *elem) {
        this->current = elem;
    }




    template<typename _ArrayType>
    _ArrayType& array<_ArrayType>::iterator::operator*() {
        return *this->current;
    }




    template<typename _ArrayType>
    typename array<_ArrayType>::iterator& array<_ArrayType>::iterator::operator+=(int value) {
        this->current += value;

        return *this;
    }




    template<typename _ArrayType>
    typename array<_ArrayType>::iterator& array<_ArrayType>::iterator::operator-=(int value) {
        this->current -= value;

        return *this;
    }




    template<typename _ArrayType>
    typename array<_ArrayType>::iterator array<_ArrayType>::iterator::operator+(int value) {
        array<_ArrayType>::iterator temp;

        return this->current + value;
    }




    template<typename _ArrayType>
    typename array<_ArrayType>::iterator array<_ArrayType>::iterator::operator-(int value) {
        array<_ArrayType>::iterator temp;

        return this->current - value;
    }





    template <typename _ArrayType>
    std::ostream &operator<<(std::ostream &left, const array<_ArrayType> &ob) {
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






    template <typename _ArrayType>
    std::istream &operator>>(std::istream &left, const array<_ArrayType> &ob) {
        _ArrayType user_input;
        std::cout << "Enter value at " << ob.length() << " index position: ";
        left >> user_input;

        ob.push_back(user_input);    

        return left;
    }





    template <typename _ArrayType>
    template <typename U>
    void array<_ArrayType>::exit_if_not_allocated(U* ptr) {
        if (ptr == nullptr) {
            std::cout << "Error Allocating Memory." << std::endl;
            this->~array();
            exit(0);
        }
    }





    template <typename _ArrayType>
    array<_ArrayType> array<_ArrayType>::selection_sort(const bool rev) {
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
    array<_ArrayType> array<_ArrayType>::bubble_sort(const bool rev) {
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
    array<_ArrayType> array<_ArrayType>::insertion_sort(const bool rev) {
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
    array<_ArrayType> array<_ArrayType>::improved_selection_sort(const bool rev) {
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
    bool array<_ArrayType>::__link_iter_to_arr(array<_ArrayType>::iterator &it) {
        for (typename array<_ArrayType>::iterator arr_it=this->begin(); arr_it!=this->end(); arr_it++) {
            if (arr_it == it) {
                return true;
            }
        }
        return false;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::__link_iter_to_arr(array<_ArrayType>::const_iterator &it) {
        for (typename array<_ArrayType>::iterator arr_it=this->begin(); arr_it!=this->end(); arr_it++) {
            if (arr_it == it) {
                return true;
            }
        }
        return false;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::__link_iter_to_vector(std::vector<_ArrayType> &vect, typename std::vector<_ArrayType>::iterator &it) const {
        for (typename std::vector<_ArrayType>::iterator vect_it=vect.begin(); vect_it!=vect.end(); vect_it++) {
            if (vect_it == it) {
                return true;
            }
        }
        return false;
    }





    template <typename _ArrayType>
    bool array<_ArrayType>::__link_iter_to_vector(const std::vector<_ArrayType> &vect, typename std::vector<_ArrayType>::const_iterator &it) const {
        for (typename std::vector<_ArrayType>::const_iterator vect_it=vect.begin(); vect_it!=vect.end(); vect_it++) {
            if (vect_it == it) {
                return true;
            }
        }
        return false;
    }




    template <typename _ArrayType>
    int array<_ArrayType>::__get_random_number(const int min, const int max) const {
        static double fraction { 1.0 / (RAND_MAX + 1.0) };
        return min + ((max - min + 1) * (std::rand() * fraction));
    }





    template <typename _ArrayType>
    array<int> array<_ArrayType>::__new_indexes() const {
        pif::array<int> new_indexes;

        std::srand(std::time(nullptr));

        int n;
        bool append;
        while (this->length() > new_indexes.length()) {
            append = true;

            n = this->__get_random_number(0, this->length()-1);
            for (int i=0; i<new_indexes.length(); i++) {
                if (n == new_indexes[i]) {
                    append = false;
                    break;
                }
            }
            if (append) {
                new_indexes.push_back(n);
            }
        }

        return new_indexes;
    }
}





#endif
