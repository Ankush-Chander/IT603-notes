#include <iostream>
#include <array>
using namespace std;

void cStyleFunc(int arr[3]) {   // actually int* arr
    cout << "C-style first element = " << arr[0] << endl;
    // sizeof(arr) here is size of pointer, not 3 * sizeof(int)
    int retArray[3];
    // retArray = arr; // not allowed
    // return retArray; // not allowed
}

array<int,3> cppStyleFunc(array<int,3> arr) {
    cout << "C++ std::array first element = " << arr[0] << endl;
    cout << "C-style first element = " << arr[0] << endl;
    cout << "Size = " << arr.size() << endl;  // knows size
    array<int, 3> retArray = arr;
    return retArray;
}

int main() {
    int cArr[3] = {1,2,3};
    array<int,3> cppArr = {1,2,3};

    cStyleFunc(cArr);   // decays to int*
    cppStyleFunc(cppArr); // keeps full type info
    // show example of returnablity
    return 0;
}
