#include <iostream>
#include <vector>


void delete_by_value(std::vector<int> &v, int value) {
    for (int i=0; i<v.size(); i++) {
        if (v[i] == value) {
            v.erase(v.begin()+i, v.begin()+i+1);
            i --;
        }
    }
}


int main() {
    std::vector<int> v = {1,2,1,3,1,4,1,5,1,6,1,7,1,8,1,9,1,0,1};
    delete_by_value(v, 1);

    for (int i=0; i<v.size(); i++) {
        std::cout << v[i] << ' ';
    }
}
