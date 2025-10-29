#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <chrono>

using namespace std;

bool customCompare(const pair<string, int>& a, const pair<string, int>& b) {
    // Sort primarily by frequency in descending order
    if (a.second != b.second) {
        return a.second > b.second;
    }
    // If frequencies are the same, sort alphabetically
    return a.first < b.first;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <top_k>" << endl;
        return 1;
    }

    int k = stoi(argv[1]);
    // map<string, int> wordCount; // solution1 : use ordered map
    // unordered_map<string, int> wordCount; // solution2 : use unordered map
    // solution 3: use unordered map with predefined bucket count to avoid rehasing and memory allocation
    size_t bucket_count = 10000;
    unordered_map<string, int> wordCount(bucket_count);
    string line, word;

    // calculate using chronos time in seconds to measure time it takes to read text from standard input
    auto start = chrono::high_resolution_clock::now();
    // Read text from standard input. Complexity O(N)
    while (getline(cin, line)) {
        stringstream ss(line);
        while (ss >> word) {
            // Increment the word count
            ++wordCount[word];
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken to read text: " << duration.count()/1e9 << " s" << endl;
    
    // Move pairs to a vector
    vector<pair<string, int>> freqVector(wordCount.begin(), wordCount.end());
    
    // Sort the vector using customCompare function Complexity O(NlogN)
    auto start2 = chrono::high_resolution_clock::now();
    sort(freqVector.begin(), freqVector.end(), customCompare);
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);
    cout << "Time taken to sort vector: " << duration2.count()/1e9 << " s" << endl;
    
    // Print the top k frequent words
    for (int i = 0; i < k && i < freqVector.size(); ++i) {
        cout << freqVector[i].first << ": " << freqVector[i].second << endl;
    }

    return 0;
}