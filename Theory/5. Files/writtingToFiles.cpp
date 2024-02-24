#include <iostream>
#include <vector>
// To work with files we need to inlcude a pakcage
#include <fstream>

int main() {
    // Get the file name from the user
    std::string file_name;
    std::cout << "Give me the name of the file you want to create: ";
    std::cin >> file_name;

    // Create the file
    // First we create the file object from the ofstream class and then we open it like python
    // By default when we open a file the be overwritted by the new text 
    // To prevent that
    std::ofstream file;
    file.open(file_name + ".txt", std::ios::app); 

    // We can know if the fiel open seccesfully
    if (file.is_open()) { std::cout << "Opened Succesfully"; } else { std::cout << "An Error Occured"; return 1; }


    // Create the vector of names
    std::vector <std::string> names = {"Name 1", "Name 2", "Name 3", "Name 4", "Name 5"};
    // Create the range base for loop
    for (std::string name : names) {

        // Append elements to our file
        file << name << std::endl;
    }
    // Close connection ( not nessecary )
    file.close(); 
}
