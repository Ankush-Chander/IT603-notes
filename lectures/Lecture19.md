---
delivery date: 2024-09-18
---
#### Quick recap
1. Iterators

---
#### Agenda
1. Time complexity of an algorithm

---
#### Time Complexity

**Time complexity** is a measure of *the amount of time an algorithm takes to complete as a function of the length of the input*. It helps evaluate the efficiency of an algorithm by estimating how the runtime scales with input size.

**Big O Notation**: The most common notation for expressing time complexity is **Big O Notation**, which describes an upper bound on the growth rate of an algorithm's runtime.

---
![](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fpaper-attachments.dropbox.com%2Fs_2D428973624E7FC84C7D69D11421DE762BEA6B6F3361231FCDCAE0425D14526F_1664885448372_Untitled.drawio%2B17.png&f=1&nofb=1&ipt=029c1463fddbf99e75abd09ad7a4c471f28a71142b186e4150b4d97c547add2f&ipo=images)
Image Credits: https://ejeplo.com/article/big-o-cheat-sheet-time-complexity-chart

---

### Common Time Complexities
1. **O(1) - Constant Time:**
   - The algorithm takes the same amount of time, regardless of the input size.
   - Example: Accessing an element in an array by its index.

2. **O(log n) - Logarithmic Time:**
   - The algorithm’s time grows logarithmically in relation to the input size.
   - Example: Binary search.
---
3. **O(n) - Linear Time:**
   - The algorithm's time grows linearly with the input size. Example: A loop through an array of size `n`.

4. **O(n log n) - Log-Linear Time:**
   - The algorithm performs linear work on each step, and the number of steps grows logarithmically. Example: Merge sort, quicksort (average case).
---
5. **O(n^2) - Quadratic Time:**
   - The time grows quadratically with the input size. Example: Bubble sort  

	![](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)
---

6. **O(2^n) - Exponential Time:**
   - The runtime doubles with each additional element in the input. Example: Solving the subset sum problem with brute force.

7. **O(n!) - Factorial Time:**
   - The time grows factorially with the input size. Example: Generating all permutations of a set.
---
#### Asymptotic Behaviour

Time complexity is concerned with the asymptotic behaviour of algorithms, which refers to their performance as the input size becomes very large. This allows us to ignore constants and lower-order terms, focusing only on the dominant term, as it has the greatest impact on growth.

For example, if an algorithm has a time complexity of $T(n) = 5n^2+3n+2$, we consider only the largest term, $n^2$, so the time complexity is **O($n^2$)**.

---

#### References
1. [Time complexity - Wikipedia](https://en.wikipedia.org/wiki/Time_complexity)