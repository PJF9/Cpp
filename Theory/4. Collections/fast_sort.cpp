#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


void sort(std::vector<int> &v, int start=0) {
    int max_i, temp;

    while (start < v.size()) {
        max_i = start;

        for (int i=start; i<v.size(); i++) {
            if (v[i] > v[max_i]) {
                max_i = i;
            }
        }

        temp = v[max_i];
        v[max_i] = v[start];
        v[start] = temp;

        start ++;
    }
}


int main() {
    srand(time(NULL));
    std::vector<int> vect;

    for (int i=0; i<1000000; i++) {
        vect.push_back(rand() % 1000001);

    }
    sort(vect);

    for (int elem: vect) {
        std::cout << elem << " ";
    }
}
