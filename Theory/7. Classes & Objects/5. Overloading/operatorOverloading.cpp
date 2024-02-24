#include <iostream>

class Position {
    public:
        int x;
        int y;

        // Overloading function
        Position operator+ (Position pos) {
            Position new_pos(0, 0);
            new_pos.x = x + pos.x;
            new_pos.y = y + pos.y;

            return new_pos;
        }

        // Overloading == operator function
        bool operator==(Position pos) {
            if (x == pos.x && y == pos.y) {
                return true;
            }
            return false;
        }

        // Constactor
        Position(int aX, int aY) {
            x = aX;
            y = aY;
        }
};

int main() {
    Position pos1(10, 20);
    Position pos2(5, 15);

    // New position
    Position pos3 = pos1 + pos2;

    std::cout << pos3.x << std::endl;
    std::cout << pos3.y << std::endl;
    
    if (pos1 == pos2) {
        std::cout << "Same" << std::endl;
    } else {
        std::cout << "Not Same" << std::endl;
    }
}