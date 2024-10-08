---
delivery date: 2024-08-22
---
### Quick Recap
1. Memory Hierarchy
2. Arrays and multidimensional arrays
---
### Agenda
1. Classes

---
#### Classes
Classes in C++ are **user-defined data types** that allow you to **group variables and functions together**. This encapsulation helps in organizing code, modeling real-world entities, and promoting reusability.

---
#### Encapsulation
Encapsulation is a fundamental concept in object-oriented programming (OOP) that involves **bundling the data (attributes) and the methods (functions) that operate on the data into a single unit, typically a class**.   
Encapsulation provides two important advantages:
- User code cannot inadvertently corrupt the state of an encapsulated object.
- The implementation of an encapsulated class can change over time without requiring changes in user-level code.

---

#### Constructors
A **constructor** is a special member function that is automatically called when an object is created. Constructors are used to initialize objects.

```c++
Vector2D(float x = 0, float y = 0){
	// call member function using -> operator
	this->setX(x);// this is a pointer to the object
	this->setY(y);
}
```
---

#### Access Control

In C++ we use **[access specifiers](https://cpp-primer.pages.dev/book/080-defined_terms.html#filepos2054821)** to enforce encapsulation:
- Members defined after a `public` specifier are **accessible to all parts of the program**. The `public` members define the interface to the class.
- Members defined after a `private` specifier are **accessible to the member functions of the class but are not accessible to code that uses the class**. The `private` sections encapsulate (i.e., hide) the implementation.
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

**Method Chaining**: In the example above, the `setX()` and `setY()` methods return `*this`, which allows the methods to be chained together like `vec.setX(3.0).setY(4.0);`. Without returning `*this`, chaining wouldn’t be possible.

---
#### Access operators (".", "->")
```c++
Vector2D v = Vector2D(1, 2);
Vector2D* vp = &v;
cout << v.getX() << endl;// v is a reference. use "." operator
cout << vp->getX() << endl;// vp is a pointer. use "->" operator
```

---
#### Operator overloading
Operator overloading is a feature in C++ that **allows you to define custom behaviours for operators when they are used with user-defined types (like classes).** This means you can give special meanings to operators (such as `+`, `-`, `*`, `==`, etc.) when they are applied to objects of your classes, **making your classes more intuitive and easier to use**.

```c++
ReturnType operator<symbol>(ParameterList) { 
// Custom implementation 
}
```

---
#### References
2. [Chapter 7. Classes | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/072-chapter_7._classes.html)
---