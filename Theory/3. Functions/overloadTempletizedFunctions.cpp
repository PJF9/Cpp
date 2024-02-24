#include <iostream>
#include <string>
#include <vector>


template <typename dType>
void swap(dType &x, dType &y) {
    dType temp = x;
    x = y;
    y = temp;
}

template <typename dType>
void swap(std::vector <dType> &a, std::vector <dType> &b) {
    for (int i=0; i<a.size(); i++) {
        dType temp = a[i];
        a[i] = b[i];
        b[i] = temp; 
    }
}

int main() {
    int x = 10;
    int y = 20;

    std::string a = "10";
    std::string b = "20";

    swap(x, y);
    swap(a, b);

    std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
    std::cout << "a = " << a << "\t" << "b = " << b << std::endl;


    std::vector <int> aV = {1,2,3,4};
    std::vector <int> bV = {5,6,7,8};
    
    swap(aV, bV);

    for (int i=0; i<aV.size(); i++) {
        std::cout << aV[i] << "\t";
    }
    std::cout << std::endl;

    for (int j=0; j<bV.size(); j++) {
        std::cout << bV[j] << "\t";
    }
    std::cout << std::endl;
}