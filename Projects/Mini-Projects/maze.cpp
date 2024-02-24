#include <iostream>
#include <vector>


void print_v(std::vector<std::vector<int>> &v) {
    std::cout << std::endl << "-----------------------------------------" << std::endl;
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++) {
            if (j == 0) {
                std::cout << "| " << v[i][j] << " | ";
            }
            else {
                std::cout << v[i][j] << " | ";
            }
        }
        std::cout << std::endl << "-----------------------------------------" << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> v = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
    };

    print_v(v);
}
