#include <iostream>
#include <vector>

void print_vector(std::vector <int> numbers) {
    // Any changes we make to this vector does not apply to the original one

    for (int i=0; i<numbers.size(); i++) {
        std::cout << numbers[i] << std::endl;
    }
}

int main() {
    std::vector <int> data = {1,2,3,4};

    // Call the function
    print_vector(data);
}