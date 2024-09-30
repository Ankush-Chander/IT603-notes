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
    vector<string> words;
    while (std::cin >> word){
        words.push_back(word);
    }
    cout << "initial vector" << endl;
    print_vector(words);
    
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    cout << "sorted vector" << endl;
    print_vector(words);
    
    // // unique  reorders the input range so that each word appears once in the
    // front portion of the range and returns an iterator one past the unique range
    auto end_unique = unique(words.begin(), words.end());
    cout << "unique vector" << endl;
    print_vector(words);
    
    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());
    cout << "final vector" << endl;
    print_vector(words);
}
