#include "add.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int a = 10, b = 20;
    cout << add(a, b) << endl;
    
    float c = 10.1, d = 20.2;
    cout << add(c, d) << endl;
    
    double e = 10.5, f = 20.4;
    cout << add(e, f) << endl;

    // What happens when you add float and double??
    //cout << add(c, f) << endl;

    // explicit template instantiation
    cout << add<double>(c, f) << endl;

    return 0;
}
