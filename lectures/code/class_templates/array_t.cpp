#include "arrayTemplate.hpp"
#include <iostream>
#include <algorithm>

using namespace  std;

int main(int argc, char const *argv[])
{
    /* code */
    Array<int> x(10);
    // indexing and assignment
    for (int i = 0; i < x.getLength(); i++)
    {
        x[i] = x.getLength() - i;
    }
    
    // copy constructor
    Array<int> z(x);
    cout << long(&x[0]) << " != "<< long(&z[0]) << endl;
    
    // copy assignment
    Array<int> k = x;
    
    cout << long(&x[0]) << " != "<< long(&k[0]) << endl;


    auto count_it = count(x.begin(), x.end(), 1);
    cout << "count(x.begin(), x.end(), 1): " << count_it << endl;

    auto it = find(x.begin(), x.end(), 6);
    cout << "find(x.begin(), x.end(), 6): " << *it << endl; 

    auto min_it = min_element(x.begin(), x.end());
    cout << "min(x.begin(), x.end()): " << *min_it << endl; 

    
    auto max_it = max_element(x.begin(), x.end());
    cout << "max(x.begin(), x.end()): " << *max_it << endl; 


    // sorting
    cout << "before sorting." << endl;
    x.print();

    //sort x
    // sort(x.begin(), x.end());
    cout << "after sorting." << endl;
    x.print();
    
    
    return 0;

}
