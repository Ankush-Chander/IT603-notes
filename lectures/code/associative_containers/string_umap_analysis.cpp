#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<std::string, int> map;
    std::hash<std::string> str_hash;
    
    std::vector<std::string> keys = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
    
    for (const auto& key : keys) {
        map[key] = key.length();
    }
    
    std::cout << "\nBucket count: " << map.bucket_count() << "\n";
    
    for (size_t i = 0; i < map.bucket_count(); ++i) {
        if (map.bucket_size(i) > 0) {
            std::cout << "Bucket " << i << " contains: ";
            for (const auto& pair : map) {
                if (map.bucket(pair.first) == i) {
                    std::cout << "(" << pair.first << ", " << pair.second << ", Hash: " << str_hash(pair.first) << ") ";
                }
            }
            std::cout << "\n";
        }
    }
    
    return 0;
}