---
delivery date: 2024-09-24
---
#### Quick recap
1. Time complexity of an algorithm
2. std::map
---
#### Agenda
1. Associative containers

---
#### map vs unordered map 
| Feature             | `std::map`                             | `std::unordered_map`                      |
| ------------------- | -------------------------------------- | ----------------------------------------- |
| **Ordering**        | Keys are sorted                        | Keys are not sorted (unordered)           |
| **Implementation**  | *balanced binary search tree*          | *hash tables*                             |
| **Time Complexity** | O(log n)                               | O(1) average, (O(n) in worst case)        |
| **Traversal**       | Elements are traversed in sorted order | Elements are traversed in arbitrary order |

---
#### Inner working of `std::unordered_map`
---
####  Hash tables
![](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fmiro.medium.com%2Fv2%2Fresize%3Afit%3A900%2F1*-BjbJwNd34nP6OYk2TbCdw.png&f=1&nofb=1&ipt=505fa3575cf9574c3917f414f203d27495677b9a07f0e9520c1a0ea0ebb11d52&ipo=images)
---
**Buckets**:
- The hash table consists of **buckets**, which are essentially slots in an array where key-value pairs are stored.
- Each bucket can store one or more key-value pairs.
- The goal is to distribute key-value pairs evenly among the buckets to minimize the load factor and avoid collisions.

---
**Hash Function**:

- The hash function is a function that takes a key as input and returns an index (hash code) corresponding to the bucket where the key-value pair should be placed.
- In C++, `std::unordered_map` uses the default `std::hash` function, which is defined for common data types (e.g., integers, strings). For custom types, you can provide a custom hash function.
- The hash function needs to be fast, deterministic, and should distribute keys evenly.
---
**Load Factor**:
- $$load factor=  \frac{\text{number of elements in the hash table}}{\text{number of buckets}}$$.
- A high load factor increases the likelihood of collisions, degrading performance.
- A low load factor wastes space because many buckets are unused.
- When the load factor exceeds a certain threshold, `std::unordered_map` automatically resizes (rehashes) the table by increasing the number of buckets to maintain performance.
---
**Collision Resolution**:
- **Collisions** occur when two different keys are hashed to the same bucket.
- `std::unordered_map` uses  **separate chaining** for collision resolution.
    - **Separate Chaining**:
        - Each bucket contains a linked list (or a similar structure like a dynamic array), and when multiple keys hash to the same bucket, they are appended to the linked list.
        - The lookup process will scan the list to find the desired key.
---
**Rehashing**
- When the load factor exceeds a predefined threshold (often 1.0), the hash table will **rehash**.
- Rehashing involves:
    - Creating a new array of buckets
    - Recalculating the hash of each key and inserting it into the new bucket array.
    - This process is expensive, but it happens infrequently.
---
#### Managing buckets

| Code                   | Description                                           |
| ---------------------- | ----------------------------------------------------- |
| `c.bucket_count()`     | Number of buckets in use.                             |
| `c.max_bucket_count()` | Largest number of buckets this container can hold.    |
| `c.bucket_size(n)`     | Number of elements in the nth bucket.                 |
| `c.bucket(k)`          | Bucket in which elements with key `k` would be found. |

---
#### Requirements on Key Type for Unordered Containers
An object can be a key in an `std::unordered_map` in C++ if it meets two requirements:

1. **Hashable**: There must be a way to compute a hash value for the object. By default, `std::unordered_map` uses `std::hash` for primitive types (like `int`, `string`, etc.), but for custom objects, you need to provide a custom hash function.
    
2. **Equality Comparable**: The object must support comparison for equality(`operator==`). 

---

#### References
1. [Chapter 11. Associative Containers | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/106-chapter_11._associative_containers.html)
2. [How does C++ STL unordered_map resolve collisions? - Stack Overflow](https://stackoverflow.com/a/21519560/2893777)
