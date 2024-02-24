#include <iostream>
#include <vector>



void basics();
double power(double base, int exp);
template <typename T> void swap(T &x, T& y);
template <typename dType> void swap(std::vector<dType> &v1, std::vector<dType> &v2);
template <typename dType> std::string print_array(dType *a, int size);
template <typename dType> std::string print_vector(std::vector<dType> v);
template <typename dType> std::string print_vector(std::vector<std::vector<dType>> v);
std::string to_string(int x);
std::vector<std::vector<int>> combinations(std::vector<int> v);
int delete_values(int *array, int size, int value);
int delete_duplicates(int array[], int size);
bool is_sorted(int array[], int size);
void sort(int array[], int size);
int binary_search(int array[], int size, int value);
void pointers();


int main() {
    basics();

    std::cout << power(2, 4) << std::endl << std::endl;

    int x = 9;
    int y = 3;
    std::cout << "x: " << x << ", y: " << y << std::endl;
    swap(x, y);
    std::cout << "x: " << x << ", y: " << y << std::endl << std::endl;

    std::vector<std::string> v1 = {"one", "two", "three"};
    std::vector<std::string> v2 = {"ONE", "TWO", "THREE"};
    std::cout << "v1: " << print_vector(v1) << ", v2: " << print_vector(v2) << std::endl;
    swap(v1, v2);
    std::cout << "v1: " << print_vector(v1) << ", v2: " << print_vector(v2) << std::endl << std::endl;

    std::vector<int> v = {1, 2, 1, 3};
    std::vector<std::vector<int>> combs = combinations(v);
    std::cout << print_vector(combs) << std::endl << std::endl;

    int array[] = {1,2,1,3,1,4,1,5,1,6,1,7,1,8,1,9,1,0,1};
    int new_size = delete_values(array, sizeof(array)/sizeof(int), 1);
    std::cout << print_array(array, new_size) << std::endl << std::endl;

    int arr[] = {2, 1, 6, 4, 3, 5};
    int index = binary_search(arr, sizeof(arr)/sizeof(int), 2);
    std::cout << index << std::endl << std::endl;

    int arr1[] = {1,1,2,9,11,11,11,9,9,2,1,1,2,2,3,3,4,4,10,10,10,5,5,3,3,4,6,6,7,7,4,5,12,12,12,5,8,8,8};
    int new_size1 = delete_duplicates(arr1, sizeof(arr1)/sizeof(int));
    std::cout << print_array(arr1, new_size1) << std::endl << std::endl;

    pointers();
}



void basics() {
    // 1. Exceptions
    try {
        int x = 19;
        int y = 10;

        if (x < y) {
            throw 9;
        }

        std::cout << x + y << std::endl;
    }
    catch(int x) {
        if (x == 9) {
            std::cout << "Error Code Number: " << x << std::endl;
        }
    }
    // Exceptions


    std::cout << std::endl;


    // 2. For Loops
    int array[] = {3, 6, 9};

    for (int i=0; i<(sizeof(array) / sizeof(int)); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    for (int el: array) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    // For Loops


    std::cout << std::endl;


    // 3. Switch Statement
    int num = 9;

    switch (num) {
        case 0:
            std::cout << "Case: 0" << std::endl; break;
        case 9:
            std::cout << "Case: 9" << std::endl; break;
        default:
            std::cout << "Default Case" << std::endl;
    }
    // Switch Statement

    
    std::cout << std::endl;
}


double power(double base, int exp=0) {
    double res = 1;

    if (base == 0) return 0;
    if (exp == 0) return 1;
    if (exp < 0) {
        std::cout << "`exp` must be higher or equal to 0..." << std::endl;
        return 1;
    }

    for (int i=0; i<exp; i++) {
        res *= base;
    }

    return res;
}


template <typename T>
void swap(T &x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}


template <typename dType>
void swap(std::vector<dType> &v1, std::vector<dType> &v2) {
    for (int i=0; i<v1.size(); i++) {
        dType temp = v1[i];
        v1[i] = v2[i];
        v2[i] = temp;
    }
}


template <typename dType>
std::string print_array(dType *a, int size) {
    std::string s = "[";
    for (int i=0; i<size; i++) {
        if (i == size - 1) {
            s += to_string(*(a++)) + "]";
        }
        else {
            s += to_string(*(a++)) + ", ";
        }
    }

    return s;
}


template <typename dType>
std::string print_vector(std::vector<dType> v) {
    std::string s = "[";
    for (int i=0; i<v.size(); i++) {
        if (i == v.size() - 1) {
            s += v[i] + "]";
        }
        else {
            s += v[i] + ", ";
        }
    }

    return s;
}

template <typename dType>
std::string print_vector(std::vector<std::vector<dType>> v) {
    if (v.size() == 0) {
        return "[]";
    }

    std::string s = "[";
    for (int i=0; i<v.size(); i++) {
        if (v[i].size() == 0) {
            s += "()";
        }
        else {
            s += "(";
            for (int j=0; j<v[i].size(); j++) {
                if (j == v[i].size() - 1) {
                    s += to_string(v[i][j]) + ")";
                }
                else {
                    s += to_string(v[i][j]) + ", ";
                }
            }
        }

        if (i == v.size() - 1) {
            s += "]";
        }
        else {
            s += ", ";
        }
    }

    return s;
}


std::string to_string(int x) {
    int digit;
    std::string s;
    do {
        digit = x % 10;
        s += (char) (digit + 48);
        x /= 10;
    } while (x > 0);

    for (int i=0; i<s.size()/2; i++){
        char temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;
    }

    return s;
}


std::vector<std::vector<int>> combinations(std::vector<int> v) {
    std::vector<std::vector<int>> combs;

    for (int k=1; k<v.size(); k++) {
        for (int i=0; i<v.size(); i++) {
            for (int j=i+k; j<v.size(); j++) {
                std::vector<int> temp;
                for (int p=0; p<k; p++){
                    temp.push_back(v[i+p]);
                }
                temp.push_back(v[j]);
                combs.push_back(temp);
            }
        }
    }

    return combs;
}


int delete_values(int *array, int size, int value) {
    int j = 0;
    int *temp = array;
    for (int i=0; i<size; i++) {
        if (*(temp++) == value) {
            j ++;
        }
    }

    if (j == 0) {
        return size;
    }

    int k = 0;
    temp = array;
    for (int i=0; i<size; i++) {
        if (*temp != value) {
            array[k++] = *temp;
        }
        temp++;
    }

    return k;
}


int delete_duplicates(int array[], int size) {
    int temp[size];
    for (int i=0; i<size; i++) {
        temp[i] = array[i];
    }

    int k;
    int dupls = 0;
    int t = 0;
    for (int i=0; i<size-dupls; i++) {
        k = i+1;
        for (int j=i+1; j<size-dupls; j++) {
            if (temp[j] != temp[i]) {
                temp[k++] = temp[j];
            }
            else {
                t ++;
            }
        }

        dupls = t;
    }

    for (int i=0; i<k; i++) {
        array[i] = temp[i];
    }

    return k;
}


bool is_sorted(int array[], int size) {
    for (int i=0; i<size-1; i++) {
        if (array[i] > array[i+1]) {
            return false;
        }
    }

    return true;
}


void sort(int array[], int size) {
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


int binary_search(int array[], int size, int value) {
    if (!is_sorted(array, size)) {
        sort(array, size);
    }

    int first = 0;
    int last = size-1;
    int mid;
    while ((first <= size - 1) && (last >= 0)) {
        mid = (first + last) / 2;
        if (array[mid] == value) {
            return mid;
        }

        if (array[mid] < value) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }

    return -1;
}


void pointers() {
    // 1. Pointer Number
    int* ptr = nullptr;
    int x = 9;

    ptr = &x;

    std::cout << "ptr = " << ptr << ", &number = " << &x << std::endl;
    std::cout << "*ptr = " << *ptr << ", number = " << x << std::endl << std::endl;


    // 2. Dynamic Pointer
    int *p = new int;
    if (p == nullptr) std::cout << "Error Allocating Memory" << std::endl;

    *p = x;

    std::cout << "p = " << p << ", &x = " << &x << std::endl;
    std::cout << "*p = " << *p << ", x = " << x << std::endl << std::endl;    

    delete p;


    // 3. Pointer Array
    int *arr = new int [9];
    if (!arr) std::cout << "Error Allocating Memory" << std::endl;

    for (int i=0; i<9; i++) {
        arr[i] = i*i;
    }

    std::cout << print_array(arr, 9) << std::endl << std::endl;

    delete [] arr;


    // 3. 2-d Pointer Array
    int rows = 2;
    int columns = 3;
    int **arr_2d = new int*[rows];
    if (!arr_2d) std::cout << "Error Allocating Memory" << std::endl;

    for (int i=0; i<rows; i++) {
        arr_2d[i] = new int [columns];
        if (!arr_2d[i]) std::cout << "Error Allocating Memory" << std::endl;
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            arr_2d[i][j] = i + j;
        }
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            std::cout << arr_2d[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i=0; i<rows; i++) {
        delete [] arr_2d[i];
    }

    delete [] arr_2d;
}
