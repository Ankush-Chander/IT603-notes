#include <iostream>
using namespace std;
// define vector class

class Vector2D {
    private:
        float x, y;
    public:
        Vector2D(float x, float y){
            cout << "constructor called" << "(" << x << ", " << y << ")" << endl;
            this->x = x;
            this->y = y;
        }
        // default constructor
        Vector2D(){
            cout << "default constructor called" << endl;
            this->x = 0;
            this->y = 0;
        }

        // destructor
        ~Vector2D(){
            
            cout << "destructor called" << "(" << x << ", " << y << ")" <<  endl;
            
        }

        // Function to add two vectors
        Vector2D addVectors(Vector2D v) const {
            return Vector2D(this->x + v.x, this->y + v.y);
        }

        // Function to subtract two vectors
        Vector2D subtractVectors(Vector2D v) {
            return Vector2D(this->x - v.x, this->y - v.y);
        }

        Vector2D scalarMultiply(float scalar) {
            return Vector2D(this->x * scalar, this->y * scalar);
        }

        void displayVector(){
            cout << "(" << this->x << ", " << this->y << ")" << endl;
}
};

int main(int argc, char const *argv[])
{
    
    // initialise vector v1
    Vector2D v1(3.0, 4.0);
    cout << "Vector 1: ";
    v1.displayVector();
    


    // initialise vector v2
    Vector2D v2(1.0, 2.0);
    cout << "Vector 2: ";
    v2.displayVector();

    cout << "calling addVectors" << endl;
    Vector2D sum = v1.addVectors(v2);
    cout << "called addVectors" << endl;
    cout << "Sum: ";
    sum.displayVector();
    
    cout << "calling scalarMultiply" << endl;
    Vector2D scaled = v1.scalarMultiply(2.5);
    cout << "called scalarMultiply" << endl;
    cout << "Scaled: ";
    scaled.displayVector();

    // Vector2D difference = v1.subtractVectors(v2);
    // cout << "Difference: ";
    // difference.displayVector();

    
    Vector2D *v3 = new Vector2D(5, 7);
    // cout << "calling addVectors" << endl;
    // Vector2D sum2 = v3->addVectors(v1);
    // cout << "called addVectors" << endl;
    
    // v1 used last time
    // cout << "Sum2: ";
    // sum2.displayVector();
    delete v3;

    // Vector2D v1_copy = v1;
    // Vector2D v2_copy = v2;
    
    // cout << v2.x << endl;

    return 0;
}