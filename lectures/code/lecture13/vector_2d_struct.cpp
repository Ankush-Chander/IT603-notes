#include <iostream>

// C-style struct definition
struct Vector2D {
    double x;
    double y;
};

// Function to create a new vector
Vector2D createVector(double x, double y) {
    Vector2D v;
    v.x = x;
    v.y = y;
    return v;
}

// Function to add two vectors
Vector2D add(const Vector2D& a, const Vector2D& b) {
    Vector2D result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

// Function to subtract two vectors
Vector2D subtract(const Vector2D& a, const Vector2D& b) {
    Vector2D result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

// Function to multiply vector by scalar
Vector2D scalarMultiply(const Vector2D& v, double scalar) {
    Vector2D result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    return result;
}

// Function to print vector
void printVector(const Vector2D& v) {
    std::cout << "(" << v.x << ", " << v.y << ")";
}

int main() {
    // Illustrating struct usage
    Vector2D v1 = createVector(3.0, 4.0);   // Initialize struct using function
    Vector2D v2 = {1.0, 2.0};               // Direct aggregate initialization (C-style)
    Vector2D v3;
    v3 = {1.0, 2.0};
    std::cout << "Vector v1 = "; printVector(v1); std::cout << "\n";
    std::cout << "Vector v2 = "; printVector(v2); std::cout << "\n";

    Vector2D sum = add(v1, v2);
    Vector2D diff = subtract(v1, v2);
    Vector2D scaled = scalarMultiply(v1, 2.5);

    std::cout << "v1 + v2 = "; printVector(sum); std::cout << "\n";
    std::cout << "v1 - v2 = "; printVector(diff); std::cout << "\n";
    std::cout << "v1 * 2.5 = "; printVector(scaled); std::cout << "\n";
    
    // access struct members via -> operator
    Vector2D *v4 = new Vector2D;
    
    v4->x = 5.0;
    v4->y = 6.0;
    std::cout << "Vector v3 = "; printVector(*v4); std::cout << "\n";
    return 0;
}
