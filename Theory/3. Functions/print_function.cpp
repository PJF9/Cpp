#include <iostream>
#include <string>


void print(std::initializer_list<std::string> il, std::string end="\n") {
    for (auto elem=il.begin(); elem<il.end(); elem ++) {

        if (elem == (il.end() - 1)) {
            std::cout << elem->data();
        }
        else {
            std::cout << elem->data() << " ";
        }
    }

    std::cout << end;
}


int main() {
    print({"Hey", "There", "Sir"});
}
