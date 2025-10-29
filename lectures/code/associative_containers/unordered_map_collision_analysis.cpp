#include <iostream>
#include <unordered_map>

void print_map_buckets(std::unordered_map<int, int> &mp){
     // Print bucket distribution and elements in each bucket
     for (size_t j = 0; j < mp.bucket_count(); ++j) {
        // if (map.bucket_size(j) > 1) { // Checking collision (more than one element in the bucket)
            std::cout << "Bucket " << j << " (Collision) -> " << mp.bucket_size(j) << " elements: ";
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                if (mp.bucket(it->first) == j) {
                    std::cout << "(" << it->first << ", " << it->second << ") ";
                }
            }
            std::cout << std::endl;
        // }
    }
    std::cout << "Load factor: " << mp.load_factor() << std::endl;
}

int main() {
    std::unordered_map<int, int> map;
    
    std::cout << "Initial bucket count: " << map.bucket_count() << std::endl;
    std::cout << "Max bucket count: " << map.max_bucket_count() << std::endl;
    
    // Insert values that may collide (assuming a simple hash function behavior)
    // int collision_keys[] = {1, 14, 40,53,73, };
    for (int i = 1; i < 14; ++i) {
        map[i*13+1] = i*10;
    }


     
    std::cout << "\nAfter inserting potential collision elements:" << std::endl;
    std::cout << "Bucket count: " << map.bucket_count() << std::endl;
    // Print bucket distribution and elements in each bucket
    print_map_buckets(map);
    
    map[14*13+1] = 14*10;
    print_map_buckets(map);
    
    return 0;
}
