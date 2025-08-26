#include <iostream>
#include <array>
using namespace std;

using Vec2 = array<float, 2>;   // alias for 2D vector type

// Print vector
void print(const Vec2& v) {
    cout << "(" << v[0] << ", " << v[1] << ")";
}

// Add two vectors
Vec2 add(const Vec2& a, const Vec2& b) {
    return { a[0] + b[0], a[1] + b[1] };
}

// Subtract two vectors
Vec2 subtract(const Vec2& a, const Vec2& b) {
    return { a[0] - b[0], a[1] - b[1] };
}

// Scalar multiplication
Vec2 scalarMultiply(const Vec2& v, float scalar) {
    return { v[0] * scalar, v[1] * scalar };
}

int main() {
    Vec2 a = {3.0f, 4.0f}; // equivalent to array<float, 2> a = {3.0f, 4.0f}; 
    Vec2 b = {1.0f, 2.0f};

    cout << "a = "; print(a); cout << endl;
    cout << "b = "; print(b); cout << endl;

    Vec2 c = add(a, b);
    cout << "a + b = "; print(c); cout << endl;

    Vec2 d = subtract(a, b);
    cout << "a - b = "; print(d); cout << endl;

    Vec2 e = scalarMultiply(a, 2.5f);
    cout << "a * 2.5 = "; print(e); cout << endl;

    return 0;
}
