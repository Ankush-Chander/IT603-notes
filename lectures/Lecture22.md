---
delivery date: 2024-09-30
---
#### Quick recap
1. Generic Algorithms
	1. Read-only algorithms(count, find,accumulate)
	2. Write algorithms (fill, copy, generate, replace, transform)
	3. Lambda expressions (capture list, parameter list, return type, function body)
---
#### Agenda
1. Generic Algorithms(continued)
---
**`fill_n`**
```cpp
fill_n(dest, n, val)
```
 `fill_n` function takes a single iterator, a count, and a value. It *assigns the given value* to the *specified number of elements starting at the element* denoted to by the iterator.

---
Note :  Algorithms Do Not Check Write Operations
```c++
// ensure vec has the right number of elements 
//before write operation
vector<int> vec(10); 
fill_n(vec.begin(), 10, 0);

```

```c++
vector<int> vec;  // empty vector
// disaster: attempts to write to ten (nonexistent) elements in vec
fill_n(vec.begin(), 10, 0);

```
---
#### back_inserter
`back_inserter` is a function that takes a reference to a container and returns an **insert iterator** bound to that container. When we assign through that iterator, the assignment  add an element with the given value to the container by calling `push_back`.
```c++
vector<int> vec; // empty vector
auto it = back_inserter(vec); 
// assigning through it adds elements to vec
*it = 42;
// vec now has one element with value 42
```

```cpp
vector<int> vec;  // empty vec
// works with insert iterator
auto it = back_inserter(vec)
fill_n(it, 10, 0);
```
---
#### Food for thought
```cpp
vector<int> vec;  // empty vector
auto it = back_inserter(vec)
fill_n(it, 10, 0);// vector size changed to 10
```
We said that *algorithms do not change the size of the containers over which they operate.*  
Why doesn’t the use of `back_inserter` invalidate this claim?

---

 - Inserters like `back_inserter` is part of `<iterator>` rather than `<algorithm>`.
- `push_back` is being called by iterator, not the  algorithm.   
- So algorithm is not changing the container size directly but it"s a feature of iterator which is being passed to the algorithm

---
#### Copy algorithms
The `copy` algorithm  writes to the elements of an output sequence denoted by a destination iterator. This algorithm takes three iterators: 
- The first two denote an input range;
- the third denotes the beginning of the destination sequence.

---
```c++
vector<int> a1 = {0,1,2,3,4,5,6,7,8,9};

// use normal iterator
// ensure a2 has the same size as a1
vector<int> a2(a1.size());
// copy a1 into a2
auto ret = copy(a1.begin(), a1.end(), a2.begin()); 

// use back_inserter
// no check required as we are using back_inserter
vector<int> a3;
auto ret = copy(a1.begin(), a1.end(), back_inserter(a3)); // copy a1 into a2
cout << a2.size() << endl;
```
---
#### `std::replace` / `std::replace_copy`

```c++
// replace takes as input:
//two iterators denoting the input range,
// two values   
// replace any element with the value 0 with 42
replace(ilst.begin(), ilst.end(), 0, 42);
```
```c++
// `replace_copy` takes a third iterator argument denoting a 
// destination in which to write the adjusted sequence:
// use back_inserter to grow destination as needed
replace_copy(ilst.cbegin(), ilst.cend(),
             back_inserter(ivec), 0, 42);
```
---
#### Quiz
Determine if there are any errors in the following programs and, if so, correct the error(s):
```c++
vector<int> vec; list<int> lst; int i;
while (cin >> i){
	lst.push_back(i);
}
copy(lst.cbegin(), lst.cend(), vec.begin());
```

```c++
vector<int> vec;
vec.reserve(10); 
fill_n(vec.begin(), 10, 0);
```
---
####  Algorithms That Reorder Container Elements

**Sorting Algorithms**  require _**random-access iterators**_. Each of the sorting algorithms provides two overloaded versions. One version uses the element’s operator `<` to compare elements; the other takes an extra parameter that specifies an ordering relation.
```c++
// sort keys using < operator on elements
sort(beg, end)
// if 2 keys equal, maintain the original order  
stable_sort(beg, end)
// sort keys using custom function on elements
sort(beg, end, comp)
// stable sort using custom function on elements
stable_sort(beg, end, comp)
```
---
####  `std::unique`
Removes **all except the first element from every consecutive group of equivalent elements** from the range `[`first`,` last`)` and returns a past-the-end iterator for the new end of the range.  
```c++
vec= {"one", "two", "two", "three", "four", "four", "five","four"}
auto end_unique = unique(vec.begin(), vec.end())
// | one | two | three | four | five | four |  |  |


auto end_unique = unique(vec.begin(), vec.end(),
				[](auto a, auto b){return a.size() == b.size();});
// | one | three | four |  |  | four | five | four |
```

Refer example code: `unique.cpp`, `dedup.cpp`

---
#### References
1. [Chapter 10. Generic Algorithms | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/097-chapter_10._generic_algorithms.html)
