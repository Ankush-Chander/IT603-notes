#include <iostream>
using namespace std;

// Function to print a 2D vector stored in an array
void print(const float v[2]) {
    cout << "(" << v[0] << ", " << v[1] << ")";
}

// Function to add two 2D vectors
void add(const float a[2], const float b[2], float result[2]) {
    result[0] = a[0] + b[0];
    result[1] = a[1] + b[1];
}

// Function to subtract two 2D vectors
void subtract(const float a[2], const float b[2], float result[2]) {
    result[0] = a[0] - b[0];
    result[1] = a[1] - b[1];
}

// Function for scalar multiplication
void scalarMultiply(const float v[2], float scalar, float result[2]) {
    result[0] = v[0] * scalar;
    result[1] = v[1] * scalar;

}

int main() {
    // Define 2D vectors as arrays
    float a[2] = {3.0f, 4.0f};
    float b[2] = {1.0f, 2.0f};
    float c[2], d[2], e[2];

    cout << "Vector a = "; print(a); cout << endl;
    cout << "Vector b = "; print(b); cout << endl;

    cout << "Vector c = "; print(c); cout << endl;
    cout << "Vector d = "; print(d); cout << endl;
    

    add(a, b, c);
    // c = add(a, b);
    cout << "a + b = "; print(c); cout << endl;

    subtract(a, b, d);
    cout << "a - b = "; print(d); cout << endl;

    scalarMultiply(a, 2.5f, e);
    cout << "a * 2.5 = "; print(e); cout << endl;

    return 0;
}
