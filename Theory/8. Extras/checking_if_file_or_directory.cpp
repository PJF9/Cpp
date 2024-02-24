#include <iostream>
#include <sys/stat.h>


std::string check(const std::string path) {
    struct stat buffer;

    // If extsts
    if (stat(path.c_str(), &buffer) == 0) {
        if (buffer.st_mode & S_IFDIR) {
            return "D";
        }
        return "F";
    }
    return "NE";
}


int main() {
    std::cout << check("c:\\Users\\jacob\\Documents\\USB\\test1\\new.txt");
}
