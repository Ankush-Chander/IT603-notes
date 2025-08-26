#include <iostream>

class Vector2D {
private:
    float x, y;

public:
    // Parameterized constructor
    Vector2D(float x, float y) : x(x), y(y) {
        std::cout << "Constructor called (" << x << ", " << y << ")" << std::endl;
    }

    // Default constructor
    Vector2D() : x(0), y(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // Destructor
    ~Vector2D() {
        std::cout << "Destructor called (" << x << ", " << y << ")" << std::endl;
    }

    // Overloading '+' operator for vector addition
    Vector2D operator+(const Vector2D& v) const { // v1 + v2 =>v1.operator+(v2)
        return Vector2D(x + v.x, y + v.y);
    }

    // Overloading '-' operator for vector subtraction
    Vector2D operator-(const Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }

    // Overloading '*' operator for scalar multiplication
    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // Overloading += operator for vector addition assignment
    Vector2D& operator+=(const Vector2D& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    // Overloading *= operator for scalar multiplication assignment
    Vector2D& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // Overloading -= operator for vector subtraction assignment
    Vector2D& operator-=(const Vector2D& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    friend Vector2D operator*(int scalar, Vector2D& vec) {
        return vec * scalar;
    }

    // Overloading '<' operator for vector comparison (based on magnitude)
    bool operator<(const Vector2D& v) const {
        return (x * x + y * y) < (v.x * v.x + v.y * v.y);
    }

    // overloading '==' operator for vector comparison
    bool operator==(const Vector2D& v) const {
        return x == v.x && y == v.y;
    }

    // Display vector
    void displayVector() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// Example usage
int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    Vector2D v3 = v1 + v2;
    std::cout << "v1 + v2 = ";
    v3.displayVector();

    Vector2D v4 = v1 - v2;
    std::cout << "v1 - v2 = ";
    v4.displayVector();

    Vector2D v5 = v1 * 2;
    std::cout << "v1 * 2 = ";
    v5.displayVector();

    Vector2D v6 =  2 * v1 ;
    std::cout << "2 * v1 = ";
    v5.displayVector();

    if (v1 < v2) {
        std::cout << "v1 is smaller than v2" << std::endl;
    } else {
        std::cout << "v1 is not smaller than v2" << std::endl;
    }

    return 0;
}