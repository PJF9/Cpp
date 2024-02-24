#include "array.hpp"


namespace pif {
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
    // pif::string make_string(const int value);
    // pif::string make_string(const double value);
    // pif::string make_string(const long double value);
    // pif::string make_string(const char &letter);
    // pif::string make_string(const char *cstring);
    // pif::string make_string(const std::string &str);
    // pif::string make_string(const pif::string &str);
    // bool iter_link_to_string(const pif::string &str, typename pif::string::iterator &it);
    // bool iter_link_to_string(const pif::string &str, typename pif::string::const_iterator &it);
    // int get_iter_index(const pif::string &str, typename pif::string::iterator &it);
    // int get_iter_index(const pif::string &str, typename pif::string::const_iterator &it);
    // int get_iter_index(std::string &str, typename std::string::iterator &it);
    // int get_iter_index(const std::string &str, typename std::string::const_iterator &it);
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
bool pif::isinstance(const _ObjectType &obj) {
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





// string make_string(const int value) {
//     string temp = std::to_string(value);

//     return temp;
// }





// string make_string(const double value) {
//     string temp = std::to_string(value);

//     return temp;
// }





// string make_string(const long double value) {
//     string temp = std::to_string(value);

//     return temp;
// }





// string make_string(const char &letter) {
//     return string(letter);
// }





// string make_string(const char *cstring) {
//     return string(cstring);
// }





// string make_string(const std::string &str) {
//     return string(str);
// }





// string make_string(const string &str) {
//     return str;
// }





// bool iter_link_to_string(const string &str, typename string::iterator &it) {
//     for (typename string::iterator temp_it=str.begin(); temp_it!=str.end(); ++temp_it) {
//         if (temp_it == it) {
//             return true;
//         }
//     }
//     return false;
// }





// bool iter_link_to_string(const string &str, typename string::const_iterator &it) {
//     for (typename string::const_iterator temp_it=str.cbegin(); temp_it!=str.cend(); ++temp_it) {
//         if (temp_it == it) {
//             return true;
//         }
//     }
//     return false;
// }





// int get_iter_index(const string &str, typename string::iterator &it) {
//     int index = 0;
//     for (typename string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
//         if (temp_it == it) {
//             break;
//         }
//         index ++;
//     }
//     return index;
// }





// int get_iter_index(const string &str, typename string::const_iterator &it) {
//     int index = 0;
//     for (typename string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
//         if (temp_it == it) {
//             break;
//         }
//         index ++;
//     }
//     return index;
// }





// int get_iter_index(std::string &str, typename std::string::iterator &it) {
//     int index = 0;
//     for (typename std::string::iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
//         if (temp_it == it) {
//             break;
//         }
//         index ++;
//     }
//     return index;  
// }





// int get_iter_index(const std::string &str, typename std::string::const_iterator &it) {
//     int index = 0;
//     for (typename std::string::const_iterator temp_it=str.begin(); temp_it!=(str.end()+1); ++temp_it) {
//         if (temp_it == it) {
//             break;
//         }
//         index ++;
//     }
//     return index;  
// }