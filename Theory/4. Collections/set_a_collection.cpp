#include <iostream>
#include <vector>

void sort(std::vector <int> &v) {
    for (int i=0; i<v.size(); i++) {
        int k = i;
        int min = v[k];

        for (int j=i+1; j<v.size(); j++) {
            if (v[j] < min) {
                k = j;
                min = v[k];
            }
        }
        int temp = v[i];
        v[i] = v[k];
        v[k] = temp;
    }
}

void set(std::vector <int> &v) {
    int s[100];
    int index = 0;

    sort(v);

    for (int i=0; i<v.size(); i++) {
        if (v[i] != v[i+1]) {
            s[index] = v[i];
            index ++;
        }
    }       

    v.clear(); 

    for (int i=0; i<index; i++) {
        // std::cout << s[i] << std::endl;
    }
    
}

int main() {
    std::vector <int> v = {5,4,1,2,6,4,2,5,1,2,5,3,2,3,6,4,1,3,4,1,6,3,5};
    
    set(v);

    for (int i=0; i<v.size(); i++) {
        std::cout << v[i] << std::endl; 
    }
}