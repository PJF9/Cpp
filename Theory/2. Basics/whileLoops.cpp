#include <iostream>

using namespace std;

int main() {
    // While loops are the exact same as python
    int index = 1;
    while (index <= 6) {
        cout << index << endl;
        index++;
    }

    // But is c++ we can use another type of while loop
    int Number = 7;
    do{
        cout << Number << endl;
        Number++;
    } while (Number <= 5);
}