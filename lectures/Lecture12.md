---
delivery date:
  - 2024-08-20
  - "[[2025-08-14]]"
---
# Agenda
1. Memory Hierarchy
2. Arrays and multidimensional arrays
---
#### Storage devices
1. **Random Access Memory**
	1. Static RAM(SRAM) is used for cache memories, both on and off the CPU chip.
	2. DRAM(Dynamic RAM) is used for the main memory plus the frame buffer of a graphics system.
2. **HDD(Magnetic Storage)** use spinning magnetic platters to store data. A read/write head moves over the platters to read or write data. 
3. **Solid state disks(SSD)** store data on interconnected flash memory chips that retain data even when powered off. 

---
#### Memory hierarchy and Cache
The storage devices in every computer system are organised as a memory hierarchy. As we move from the top of the hierarchy to the bottom, the devices become slower, larger, and less costly per byte.

The main idea of a memory hierarchy is that *storage at one level serves as a cache for storage at the next lower level*. Thus, the register ﬁle is a cache for the L1 cache. Caches L1 and L2 are caches for L2 and L3, respectively. The L3 cache is a cache for the main memory, which is a cache for the disk.
```bash
lscpu | grep cache;getconf -a | grep CACHE
```

---
![Memory hierarchy](https://raw.githubusercontent.com/Ankush-Chander/IT603-notes/6678e9b7bcc58cd88b6feb98a6e216d8d7743365/lectures/images/memory_hierarchy.png)
Picture credits: CSAPP

---
#### Caching

- Hardware : Registers, L1, L2, L3  act as cache for main memory.   
- Operating system: Main memory acts as cache for disc while implementing virtual memory.  
- Application programs: Browser cache recently accessed web pages for faster loading. 

---
#### Locality principles
Cache leads to improved performance because of following principles:

**Temporal locality:**  a memory location that is referenced once is likely to be referenced again multiple times in the near future.  
**Spatial locality:**  if a memory location is referenced once, then the program is likely to reference a nearby memory location in the near future.


---
#### Relative latencies
![](https://github.com/Ankush-Chander/Tech-Talks/blob/main/img/relative-time-latencies-computer-programming.jpg?raw=true)  
Pic credits:  [relative-time-latencies-and-computer-programming](https://alvinalexander.com/photos/relative-time-latencies-and-computer-programming/)

---
An Array is a **fixed size** collection of data of the **same data type**, stored at a **contiguous memory location**.  

Why do we need arrays?
1. Out of order access
2. Too many items to be named explicitly. 


---
Array definitions

```c++
int x = 10; 
// const int x = 10;
int arr[x]; // global array declaration expects a constant expression.
int main(int argc, char const *argv[])
{
	// local scope
	// int x = 10;
	// int arr[x];
	return 0;
}
```

---
#### Explicit Array initialization
```c++
const unsigned sz = 3;
int ia1[sz] = {0,1,2}; // array of three ints with values 0, 1, 2
int a2[] = {0, 1, 2}; // an array of dimension 3
int a3[5] = {0, 1, 2}; // equivalent to a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"hi", "bye"}; // same as a4[] =  {"hi", "bye", ""}
int a5[2] = {0,1,2}; // error: too many initializers
```

---
#### Char array initialization
```c++
char a1[] = {'C', '+', '+'}; // list initialization, no null
char a2[] = {'C', '+', '+', '\0'}; // list initialization, explicit null
char a3[] = "C++"; // null terminator added automatically
const char a4[6] = "Daniel";  // error: no space for the null!
```
---

#### Arrays and pointers
```c++
int arr[5] = {0,2,3,4,5}
cout << arr; // returns the address of the first element
int *p = arr; // equivalent to int *ip = &arr[0]
cout << arr[1] << " " << *(arr + 1)
// arr[1] is equivalent to *(arr + 1)
cout << *(arr +1) << endl; // prints 2
cout << (*arr +1) << endl; // prints 1
```
---
#### Pointers as iterators
```c++
void print_array_using_iterator(int arr[], int size){
	int *begin = arr;
	int *end = arr + size;
	for(int *i = begin; i != end; i++){
	cout << *i << " ";
	}
	cout << endl;
}
```
---
#### Multidimensional Arrays
##### Initialization
```c++
// definition without initialization
int arr[2][3];
// explicit initialization
int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
int arr3[][3] = {{1, 2, 3}, {4, 5, 6}};// also valid
int arr4[2][] = {{1, 2, 3}, {4, 5, 6}};// not valid
int arr5[2][3] = {{1,2},{3,4,5}} // valid
// stores 
//1 2 0
//3 4 5
int arr6[2][3] = {1,2,3,4} // valid
// stores 
//1 2 3
//4 0 0
```
---

|           | Col 0       | Col 1       | Col 2       |
| --------- | ----------- | ----------- | ----------- |
| **Row 0** | `arr[0][0]` | `arr[0][1]` | `arr[0][0]` |
| **Row 1** | `arr[1][0]` | `arr[1][1]` | `arr[1][2]` |
| **Row 2** | `arr[2][0]` | `arr[2][1]` | `arr[2][2]` |

---
##### Pointer Arithmetic
```c++
int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
// address of first row
cout << "long(arr)" << long(arr) << endl;
// address of 2nd row
cout << "long(arr + 1): "<< long(arr + 1) << endl;
// address of first element
cout << "long(arr[0])"<< long(arr[0]) << endl;
// address of 2nd element of the first row
cout << "long(arr[0] + 1): " << long(arr[0]+1) << endl; 
// first element of the first row
cout << arr[0][0] << endl;
```

---

|      | 1             | 2             | 3             | 4             | 5             |
| ---- | ------------- | ------------- | ------------- | ------------- | ------------- |
| val  | $$arr[0][0]$$ | $$arr[0][1]$$ | $$arr[0][2]$$ | $$arr[1][0]$$ | $$arr[1][1]$$ |
| addr | $$arr$$       |               |               | $$arr+1$$     |               |
| addr | $$arr[0]$$    | $$arr[0]+1$$  | $$arr[0]+2$$  | $$arr[1]$$    | $$arr[1]+1$$  |


---
Cache-friendly code
```c++
/* code */
int marray[100000][100000];
for (int i = 0; i < 100000; i++)
	{
		for (int j = 0; j < 100000; j++)
		{
			marray[i][j] = i +j;
		}
	}
```

|                  |          |          |          |          |          |          |
| ---------------- | -------- | -------- | -------- | -------- | -------- | -------- |
| Address Contents | $a_{00}$ | $a_{01}$ | $a_{02}$ | $a_{10}$ | $a_{11}$ | $a_{12}$ |
| Access order     | 1        | 2        | 3        | 4        | 5        | 6        |

Program has good spatial locality as variables are accessed in the same order they are laid out in memory.

---
Not so cache-friendly code
```c++
/* code */
int marray[100000][100000];
for (int j = 0; j < 100000; j++)
	{
		for (int i = 0; i < 100000; i++)
		{
			marray[i][j] = i +j;
		}
	}
```

|                  |          |          |          |          |          |          |
| ---------------- | -------- | -------- | -------- | -------- | -------- | -------- |
| Address Contents | $a_{00}$ | $a_{01}$ | $a_{02}$ | $a_{10}$ | $a_{11}$ | $a_{12}$ |
| Access order     | 1        | 3        | 5        | 2        | 4        | 6        |
|                  |          |          |          |          |          |          |

Program has poor spatial locality as variables are accessed in the same order they are laid out in memory.

---
#### Tictactoe example
```c++
// setup board
string cells = "123456789";
char board[3][3];
for (int i = 0; i < 3; i++){
	for (int j = 0; j < 3; j++){
		board[i][j] = cells[i*3 + j];
	}
}
// board looks like
//1 2 3
//4 5 6
//7 8 9

```

---
```c++
// print board
void print_board(char board[][3]){

for (int i = 0; i < 3; i++){
	for (int j = 0; j < 3; j++){
		cout << board[i][j] << " ";
	}
	cout << endl;
}
}

```


---
```c++
// check if game over(1)
for(int i = 0; i < 3; i++){
	// check ith row
	if(board[i][0] == board[i][1] &&
	 board[i][0] == board[i][2]){
		return board[i][0];
	}
	// check ith column
	if(board[0][i] == board[1][i] &&
	 board[0][i] == board[2][i]){
		return board[0][i];
	}
}
```
---
```c++
// check if game over(2)
// check diagonals
if(board[0][0] == board[1][1] && 
   board[0][0] == board[2][2]){
	return board[0][0];
}
if(board[0][2] == board[1][1] && 
   board[0][2] == board[2][0]){
	return board[0][2];
```
---
```c++
// game play
char inp[2]= {'X', 'O'};
int turn = 0;
int num, x, y;
while(check_winner(board) == ' '){
	cout << "Player " << (turn%2) + 1 << ", enter cell number: ";
	cin >> num;
	// convert input into coordinates
	x = (num-1) / 3;
	y = (num-1) %3 ;
	cout << x << " " <<y << endl;
	board[x][y] = inp[(turn%2)];
	print_board(board);
	turn++;
}
```
---
#### References
1. Memory hierarchy CSAPP (6.1-6.4)
2. [3.5. Arrays | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/034-3.5._arrays.html)
3. [3.6. Multidimensional Arrays | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/035-3.6._multidimensional_arrays.html)
---
