#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(vector<string> vec){
    cout << "| ";
    for(auto it=vec.begin();it != vec.end();++it){
        cout << *it << " | ";
    }
    cout << endl;

}
int main(int argc, char const *argv[])
{
    string word;
    vector<string> vec;
    while(cin >> word){
        vec.push_back(word);
    }
    print_vector(vec);
    
    // cout << "equivalence relation => same string" << endl;    
    // auto end_unique = unique(vec.begin(), vec.end()); // returns an iterator to the end of unique
    // print_vector(vec);
    // cout << "*end_unique" << *end_unique << endl;
    
    cout << "equivalence relation => string size" << endl;
    auto end_unique = unique(vec.begin(), vec.end(), [](auto a, auto b){return a.size() == b.size();}); 
    print_vector(vec);
    cout << "*end_unique: " << *end_unique << endl;
   
    /* code */
    return 0;
}
