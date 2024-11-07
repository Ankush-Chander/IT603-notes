#include <iostream>

using namespace std;

int add(int a, int b) { // int_add_int
    return a + b;
}

float add(float a, float b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    /*
        name mangling
        function overload resolution
        conversion between types
            exact match
            promotion
            conversion
    */
    int a = 10, b = 20;
    cout << add(a, b) << endl;
    
    float c = 10.1, d = 20.2;
    cout << add(c, d) << endl;
    
    double e = 10.5, f = 20.4;
    cout << add(e, f) << endl;

    //cout << add(a, c) << endl; //What happens when you add int and float??
    
    //cout << add(float(a), c) << endl; //??
    
    return 0;

}
