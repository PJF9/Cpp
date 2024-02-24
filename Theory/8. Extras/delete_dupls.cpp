#include <iostream>
#include <vector>


void delete_dupl(std::vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[i] == v[j]) {
                v.erase(v.begin()+i, v.begin()+i+1);
                i --;
                j --;
            }
        }
    }
}


int main() {
    std::vector<int> v = {1,2,1,3,1,4,1,5,1,6,1,7,1,8,9,9,0,1};
    delete_dupl(v);

    for (int i=0; i<v.size(); i++) {
        std::cout << v[i] << ' ';
    }
}
