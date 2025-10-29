#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;

// Custom comparator for BST (std::set)
struct Compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        // Order by frequency ascending (min on left)
        if (a.first == b.first)
            return a.second < b.second;  // lexicographic order for tie
        return a.first < b.first;
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <top_k>" << endl;
        return 1;
    }

    int k = stoi(argv[1]);
    unordered_map<string, int> wordCount;
    string line, word;

    // measure time to read text
    auto start = chrono::high_resolution_clock::now();

    while (getline(cin, line)) {
        stringstream ss(line);
        while (ss >> word) {
            ++wordCount[word];
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken to read text: " << duration.count() / 1e9 << " s" << endl;

    // measure time to insert into BST
    auto start2 = chrono::high_resolution_clock::now();

    set<pair<int, string>, Compare> bst;

    for (const auto& entry : wordCount) {
        pair<int, string> node = {entry.second, entry.first};

        if ((int)bst.size() < k) {
            bst.insert(node);
        } else {
            // smallest element is at begin()
            auto smallest = *bst.begin();
            // If current has higher frequency or same freq but lexicographically earlier
            if (Compare()(smallest, node)) { 
                bst.erase(bst.begin());
                bst.insert(node);
            }
        }
    }

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);
    cout << "Time taken to insert elements into BST: " << duration2.count() / 1e9 << " s" << endl;

    // print results in descending frequency order
    vector<pair<int, string>> result(bst.rbegin(), bst.rend());
    for (const auto& entry : result) {
        cout << entry.second << ": " << entry.first << endl;
    }

    return 0;
}
