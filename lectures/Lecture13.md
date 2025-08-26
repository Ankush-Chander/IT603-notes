---
delivery date:
  - 2024-08-22
  - "[[2025-08-19]]"
  - "[[2025-08-26]]"
---
### Quick Recap
1. Memory Hierarchy
2. Arrays and multidimensional arrays
---
## Agenda
1. Structures
2. Classes  
Refer code [here](../code/lecture/13)

---
#### Structures
Structures are a fundamental C++ mechanism for creating **compound values** or **compound types**. Unlike basic data types (integers, booleans, floating-point numbers) that represent a single value, structures allow you to **group multiple, related pieces of data into a single, cohesive unit.**

---
##### Defining and using structures
```c++
struct Point {
double x, y;
};

# Once defined, variables of this new type can be created:
Point blank;
blank.x = 3.0;
blank.y = 4.0;
```

---
##### Operations on Structures
- **Initialization:** Values can be assigned to instance variables during declaration using curly braces in order:
```c++
// initialization
Point blank = { 3.0, 4.0 }; // initialization 
// assignment
Point v3;
v3 = {1.0, 2.0}; // Modern C++ (C++11+)
v3.x = 1.0; v3.y = 2.0; //C-style / pre-C++11
```

- **Copying:** One structure can be assigned to another of the same type, effectively copying all instance variable values:
```c++
Point p1 = { 3.0, 4.0 };
Point p2 = p1; // Copies p1's x and y to p2
```

---
##### Structures as Function Parameters
- **Pass by Value:**
	- The "value of the structure (or other type) that gets passed to the function."
	- A copy of the structure is made for the function's parameter.
	- Changes made to the parameter inside the function **do not affect the original argument** in the caller. This ensures "isolation between the two functions."
- **Pass by Reference:**
	- The parameter becomes a **reference** to the original argument variable. This means "any changes that reflect makes in p will also affect blank."
	- Allows functions to **modify the original structure** passed as an argument.
	- Generally "more versatile" and "faster" (avoids copying), but "less safe" due to potential side effects.
	- In C++ programs, "almost all structures are passed by reference almost all the time."
---

```c++
void printPoint (Point p); // pass by value, no change to original struct

void reflect (Point& p){ // pass by reference; modifies original struct 
float temp = p.x;
p.x = p.y;
p.y=temp;
}
```
---

#### Classes
Classes in C++ are **user-defined data types** that allow you to **group variables and functions together**. This encapsulation helps in organizing code, modeling real-world entities, and promoting reusability.

---
##### Encapsulation
Encapsulation is a fundamental concept in object-oriented programming (OOP) that involves **bundling the data (attributes) and the methods (functions) that operate on the data into a single unit, typically a class**.   
Encapsulation provides two important advantages:
- User code cannot inadvertently corrupt the state of an encapsulated object.
- The implementation of an encapsulated class can change over time without requiring changes in user-level code.

---

##### Constructor
A **constructor** is a special member function that is automatically called when an object is created. Constructors are used to initialize objects.

```c++
Vector2D(float x = 0, float y = 0){
	// call member function using -> operator
	this->setX(x);// this is a pointer to the object
	this->setY(y);
}
```
---
##### Destructor
- Called automatically when an object goes out of scope or is deleted.
- Same name as the class, preceded by `~`.
- Used for cleanup tasks.

```cpp
class Vector2D {
// ...
public:
	// destructor
	~Vector2D(){
	std::cout << "destructor called" << std::endl;
	}
// ...
}
```
---

##### Access Control

In C++ we use **[access specifiers](https://cpp-primer.pages.dev/book/080-defined_terms.html#filepos2054821)** to enforce encapsulation:
- - **public**: Members defined after a `public` specifier are **accessible to all parts of the program**. The `public` members define the interface to the class.
- - **private**: Members defined after a `private` specifier are **accessible to the member functions of the class but are not accessible to code that uses the class**. The `private` sections encapsulate (i.e., hide) the implementation.
- - **protected**: Members defined after a `protected` specifier are  Accessible within the class and its derived classes.
---
```c++
private:
float x, y;

public:
// setter of x
Vector2D setX(float x){this->x = x; return *this;}
// setter of y
Vector2D setY(float y){this->y = y; return *this;}
// getter of x
float getX(){return this->x;}

// getter of y
float getY(){return this->y;}
```
---

**Method Chaining**: In the example above, the `setX()` and `setY()` methods return `*this`, which allows the methods to be chained together like `vec.setX(3.0).setY(4.0);`. Without returning `*this`, chaining wouldn’t be possible.

---
##### Access operators (".", "->")
```c++
Vector2D v = Vector2D(1, 2);
Vector2D* vp = &v;
cout << v.getX() << endl;// v is a reference. use "." operator
cout << vp->getX() << endl;// vp is a pointer. use "->" operator
```

---
##### Operator overloading
Operator overloading is a feature in C++ that **allows you to define custom behaviours for operators when they are used with user-defined types (like classes).** This means you can give special meanings to operators (such as `+`, `-`, `*`, `==`, etc.) when they are applied to objects of your classes, **making your classes more intuitive and easier to use**.

---
```c++
class Vector2D {
private:
	float x, y;
public:
	Vector2D operator+(Vector2D& v){
		return Vector2D(x + v.x, y + v.y);
	}
}
// usage: Vector2D v3 = v1+v2;
```
instead of 
```c++
// instead of 
Vector2D addVectors(Vector2D v) const {
	return Vector2D(this->x + v.x, this->y + v.y);
}
// usage: Vector2D v3 = v1.addVectors(v2);
```
---
##### The Three Basic Rules of Operator Overloading
1. _**Whenever the meaning of an operator is not obviously clear and undisputed, it should not be overloaded.**_ _Instead, provide a function with a well-chosen name._  
    Basically, the first and foremost rule for overloading operators, at its very heart, says: _Don’t do it_.
2. _**Always stick to the operator’s well-known semantics.**_  
3. _**Always provide all out of a set of related operations.**_  
    _Operators are related to each other_ and to other operations. If your type supports `a + b`, users will expect to be able to call `a += b`, too. 
---
##### Friend functions
A **friend function** in C++ is a function that is **not a member** of a class but has access to the class's **private and protected members**. 

**Why friend functions?**  
- allow external functions to work closely with the internals of a class, often for purposes like operator overloading, accessing private data for computations, or implementing related utility functions.

---
#### References
1. [Chapter 8 and 9, Think C++](https://www.greenteapress.com/thinkcpp/thinkCScpp.pdf)
2. [Chapter 7. Classes | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/072-chapter_7._classes.html)
---
