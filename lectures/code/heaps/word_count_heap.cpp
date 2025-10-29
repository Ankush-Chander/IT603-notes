#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <sstream>
#include <functional>
#include <chrono>

using namespace std;

// Define a comparator for the priority queue
struct Compare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        // If frequencies are the same, use lexicographical order (min-heap)
        if (a.second == b.second) {
            return a.first > b.first;
        }
        // Return true if 'a' should be after 'b' in the priority queue
        return a.second > b.second; // for min-heap by frequency
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <top_k>" << endl;
        return 1;
    }

    int k = stoi(argv[1]);
    size_t bucket_count = 10000;
    unordered_map<string, int> wordCount(bucket_count);
    string line, word;

    // calculate using chrono::high_resolution_clock::now() to measure time it takes to read text from standard input

    auto start = std::chrono::high_resolution_clock::now();
    
    // Read text from standard input
    while (getline(cin, line)) {
        stringstream ss(line);
        while (ss >> word) {
            ++wordCount[word];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Time taken to read text: " << duration.count()/1e9 << " s" << std::endl;
    // Use a min-heap to keep the top k elements
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

    // calculate using chrono::high_resolution_clock::now() to measure time it takes to insert elements into the priority queue

    auto start2 = std::chrono::high_resolution_clock::now();
    for (const auto& entry : wordCount) {
        // cout << "pq size: " << pq.size() << endl;
        // cout << entry.first << ": " << entry.second << endl;
        if (pq.size() < k) {
            
            pq.push(entry);
            // cout << pq.top().first << ": " << pq.top().second << endl;
        
        } else if (entry.second > pq.top().second) {
            // If the new entry has a higher frequency, replace the top
            pq.pop();
            pq.push(entry);
            // cout << "pq size: " << pq.size() << endl;
            // cout << entry.first << ":" << entry.second << "replaced " << pq.top().first << ":" << pq.top().second << endl;
        }
        // else{
        //     cout << entry.first << ":" << entry.second << " didnt replace " << pq.top().first << ":" << pq.top().second << endl;
            
        // }
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
    std::cout << "Time taken to insert elements into the priority queue: " << duration2.count()/1e9 << " s" << std::endl;
    // Collect results into a vector (in sorted order)
    vector<pair<string, int>> result;
    while (!pq.empty()) {
        result.emplace_back(pq.top());
        pq.pop();
    }
    
    // Print the top k frequent words in correct order (highest frequency first)
    // sort(result.rbegin(), result.rend(), Compare());
    for (const auto& entry : result) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}