#include <iostream>
#include <fstream>
#include <vector>

// We can only use 1 method for each file
int main() {
    // Firts we need to create the object of the class ifstream
    std::ifstream file;
    file.open("Petros.txt");


    // Creating the vector
    std::vector <std::string> file_text1;

    // 1
    // Getting all the text from the file and storing them to a vector
    // With this method if the text from the file is lets say 2 strings, the second will be printed at another line 
    std::string names1;
    while (file >> names1) {
         file_text1.push_back(names1);
    }
    // Show data
    for (std::string name1:file_text1) {
        std::cout << name1 << std::endl;
    }

    // 2
    // Creating the next vector
    // Every character goes to a new line
    std::vector <char> file_text2;
    char names2;
    while (file >> names2) {
        file_text2.push_back(names2);
    }
    // Show data
    for (char name2 : file_text2) {
        std::cout << name2 << std::endl;
    }

    // 3
    // The best way
    std::string line;
    do {
        getline(file, line);
        std::cout << line << std::endl;
   } while (line != "");
}
