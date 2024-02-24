#include <iostream>
#include <vector>

void set_without_sort(std::vector <int> &v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[i] == v[j]) {
                v.erase(v.begin()+j, v.begin()+j+1);
            }
        }
    }
}

int main() {
    std::vector <int> v = {5,1,1,2,1,5,3,1,4,3,2,2,5,4,4,3,3,2,1,2,4,5,5,3,4};

    set_without_sort(v);

    for (int i=0; i<v.size(); i++ ) {
        std::cout << v[i] << std::endl;
    }
}