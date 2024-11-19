---
delivery date:
  - "[[2024-10-03]]"
  - "[[2024-10-01]]"
---
#### Quick recap
1. insert iterators (back inserter)
2. copy algorithms(copy, replace, replace_copy)
3. reordering algorithms (sort, stable_sort, unique)
	
---
#### Agenda
1. Problem statement: Given a text from standard input, find out top k most frequently occurring words in it.
---
#### `std::pair`

A `pair` holds two data members. Like the containers, `pair` is a template from which we generate specific types. We must supply two type names when we create a `pair`. The data members of the `pair` have the corresponding types. There is no requirement that the two types be the same.
```c++
// holds two strings
pair<string, string> anon;       
// holds a string and an size_t
pair<string, size_t> word_count; 

// create a pair
word_count wc = make_pair("hello", 10);
// access first element
wc.first
// access second element
wc.second

```

---
#### Operations on a map
```c++
// insertions
word_count.insert(make_pair(word, 1));
word_count.insert(pair<string, size_t>(word, 1));

// traverse over all elements of a map
for(auto kv_pair: word_count){
	cout << kv_pair.first << ":" << kv_pair.second << endl;
}

```
---
Version 1  
Refer `topk_freq_words_v1.cpp`

---
#### `std::priority_queue`
A `priority_queue` lets us **establish a priority among the elements** held in the queue. Newly added elements are placed ahead of all the elements with a lower priority.   
Eg: A restaurant that seats people according to their reservation time, regardless of when they arrive, is an example of a priority queue.

---
![](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.zenalc.com%2Fwp-content%2Fuploads%2F2021%2F01%2FminMaxHeap-1200x620.png&f=1&nofb=1&ipt=c35815d046f2041267707c7f0a6be575c66ec1719cf5b754361539e3112831e6&ipo=images)

---
#### Nodes calculation
1. **Parent of a Node:** For a node at index `i`, the index of its parent is:

$$Parent(i)=\lfloor{\frac{i−1}{2}}\rfloor$$
2. **Left Child of a Node:** For a node at index `i`, the index of its left child is:

$$ \text{Left Child}(i) = 2i + 1$$

3. **Right Child of a Node:**
For a node at index `i`, the index of its right child is:

$$ \text{Right Child}(i) = 2i + 2$$
---
#### Comparison with Binary search tree

| **Operation** | **Type** | **BST (*)** | **Heap** |
| ------------- | -------- | ----------- | -------- |
| **Insert**    | Average  | log(n)      | 1        |
| **Insert**    | Worst    | log(n)      | log(n)   |
| **Find any**  | Worst    | log(n)      | n        |
| **Find max**  | Worst    | 1 (**)      | 1        |
| **Create**    | Worst    | n log(n)    | n        |
| **Delete**    | Worst    | log(n)      | log(n)   |

---
#### Operations on a priority queue

#### Initialization

```c++
// Initialization (Max-Heap)
priority_queue<int> pq;
// Initialization (Min-Heap)
priority_queue<int, vector<int>, greater<int>> pq;
// For user-defined objects, a custom comparator can be defined.
struct compare {
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
	// Min-heap: a is greater than b if a.second > b.second
	return a.second > b.second; 
}
};
priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
//(custom comparator using a `struct` or `lambda`)
```
---
##### Operations

```c++
// Inserts an element into the priority queue.
pq.push(3);
// Returns the top (largest in max-heap, smallest in min-heap) element without removing it.
int topElement = pq.top();
// Removes the top element (largest in max-heap, smallest in min-heap).
pq.pop();
//Returns true if the priority queue is empty, otherwise false.	
bool isEmpty = pq.empty();
// Returns the number of elements in the priority queue.
int size = pq.size();
```

---
Refer  `topk_freq_words_v2.cpp`

---
#### References
1. [11.2.3. The `pair` Type  | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/108-11.2._overview_of_the_associative_containers.html#filepos2758977)
2. [Priority Queue in C++ Standard Template Library (STL) - GeeksforGeeks](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl)
3. [std::priority_queue - cppreference.com](https://en.cppreference.com/w/cpp/container/priority_queue)
4. [algorithm - Heap vs Binary Search Tree (BST) - Stack Overflow](https://stackoverflow.com/a/29548834/2893777
5. [Containers library - cppreference.com](https://en.cppreference.com/w/cpp/container)