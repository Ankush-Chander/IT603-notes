#include <iostream>
#include <unordered_map>
#include <chrono>

int main() {
    std::unordered_map<int, int> map;
    
    std::cout << "Initial bucket count: " << map.bucket_count() << std::endl;
    std::cout << "Max bucket count: " << map.max_bucket_count() << std::endl;
    
    for (int i = 0; i < 30; ++i) {
        // log time taken to insert element
        auto start = std::chrono::high_resolution_clock::now();        
        map[i] = i * 10;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        std::cout << "Time taken to insert " << (i + 1) << " element: " << duration.count() << " ns" << std::endl;
        
        std::cout << "\nAfter inserting " << (i + 1) << " elements:" << std::endl;
        std::cout << "Bucket count: " << map.bucket_count() << std::endl;
        std::cout << "Load factor: " << map.load_factor()  << std::endl;
        
        if (!map.empty()) {
            // print bucket corresponding to each element
            for (int j = 0; j < map.bucket_count(); ++j) {
                std::cout << "Bucket " << j << ": ";
                for (auto it = map.cbegin(j); it != map.cend(j); ++it) {
                    std::cout << it->first << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}
