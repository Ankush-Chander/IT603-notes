#include "intArray.hpp"
#include "doubleArray.hpp"


#include <iostream>

using namespace  std;

int main(int argc, char const *argv[])
{
    /* code */
    IntArray x(10);
    
    // indexing and assignment
    for (int i = 0; i < x.getLength(); i++)
    {
        x[i] = i;
    }
    
    // read using index
    for (int i = 0; i < x.getLength(); i++)
    {
        std::cout << x[i] << std::endl;
    }

    cout << long(&x[0]) << endl;

    DoubleArray y(10);
    for (int i = 0; i < y.getLength(); i++)
    {
        y[i] = i + .4;
    }    
    
    for (int i = 0; i < y.getLength(); i++)
    {
        std::cout << y[i] << std::endl;
    }
    // y.print();

    // check out copy issue
    // IntArray y(x);
    // IntArray z = x;
    // cout << long(&y[0]) << endl;
    
    return 0;
}
