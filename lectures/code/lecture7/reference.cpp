#include <iostream>
using namespace std;    
int main(int argc, char const *argv[])
{
    /* code */
    int i = 10;
    // create a reference for an existing variable
    int &j = i;
    std::cout << "i=" << i << std::endl << "j=" << j << std::endl;
    std::cout << "&i=" << &i << std::endl << "&j=" << &j << std::endl;
    
    // change the reference
    cout << "change reference j to 20"<< endl;
    j=20;
    std::cout << "i=" << i << std::endl << "j=" << j << std::endl;
    std::cout << "&i=" << &i << std::endl << "&j=" << &j << std::endl;

    // declare a reference without initializing it. ???  
    // int &k;
    

    return 0;
}