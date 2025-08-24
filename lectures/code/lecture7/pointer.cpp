#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    // create a char variable
    char a  = 'x';
    
    // & is the addressof operator
    // Note that same operator when used in left hand side,
    // it"s used as reference operator
    
    // * is the pointer notation which signifies ptr stores the address of an int variable
    
    char *ptr = &a;
    std::cout << "char a=" << a << std::endl; // value of variable
    std::cout << "&a=" << long(&a) << std::endl; // address of variable
    std::cout << "ptr=" << long(ptr) << std::endl; // address of variable stored in a pointer


    std::cout << "*ptr=" << *ptr << std::endl;
    std::cout << "ptr=" << long(ptr) << std::endl;
    std::cout << "ptr+1=" << long(ptr+1) << std::endl;
    std::cout << "char: long(ptr+1) - long(ptr) =" << long(ptr+1) - long(ptr) << std::endl;


    // create an int pointer
    int x  = 10;
    int *ptr2 = &x;
    std::cout << "int x=" << x << std::endl; // value of variable
    std::cout << "&x=" << &x << std::endl; // address of variable
    std::cout << "ptr2=" << ptr2 << std::endl; // address of variable stored in a pointer


    std::cout << "*ptr2=" << *ptr2 << std::endl;
    std::cout << "ptr2=" << long(ptr2) << std::endl;
    std::cout << "ptr2+1=" << long(ptr2+1) << std::endl;
    std::cout << "int: long(ptr2+1) - long(ptr2) =" << long(ptr2+1) - long(ptr2) << std::endl;
    
    return 0;
}
