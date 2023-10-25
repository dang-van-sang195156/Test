#include <iostream>

class Point {
public:
    int x;
    int y;

    // Constructor
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    Point p1(2, 3);
    Point p2 = p1; // Memberwise assignment, sao chép giá trị từ p1 sang p2

    std::cout << "p1: (" << p1.x << ", " << p1.y << ")" << std::endl;
    std::cout << "p2: (" << p2.x << ", " << p2.y << ")" << std::endl;

    return 0;
}
