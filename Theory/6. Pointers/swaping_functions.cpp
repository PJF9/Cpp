#include <iostream>
#include <string>
#include <vector>


void swap(std::string str1, std::string str2) {
    std::string temp = str1;
    str1 = str2;
    str2 = temp;
}

void swap(std::string *str1, std::string *str2) {
    std::string *temp = new std::string;

    *temp = *str1;
    *str1 = *str2;
    *str2 = *temp;

    delete temp;
}


int main() {
    std::string *s1 = new std::string;
    std::string *s2 = new std::string;

    std::string t1 = "Hello";
    std::string t2 = "There";

    s1 = &t1;
    s2 = &t2;

    std::cout << "Before Swaping: s1=" << *s1 << ", s2=" << *s2 << std::endl;

    swap(s1, s2);

    std::cout << "After Swaping: s1=" << *s1 << ", s2=" << *s2 << std::endl;

    delete s1;
    delete s2;
}
