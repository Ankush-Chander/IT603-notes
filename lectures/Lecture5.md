---
delivery date: 2024-07-30
---

# Quick recap:
1. IO redirection using `>`,`<` operators
2. Command pipelines using `|` operator
3. Shell scripting  
  i. taking command line arguments into a variable  
  ii. taking input from a stream  


# Agenda:
1. Thorough understanding of compilation process
2. How C++ programs do IO?



## Compilation process

Programs are translated by other programs into different forms:
Different stages of compilation process:
1. **Preprocessing phase:** In this phase, the preprocessor is responsible for handling directives such as #include, #define, and #ifdef. It processes these directives and modifies the source code accordingly. It also removes comments and whitespace, and incorporates header files into the source code.

2. **Compilation phase:** In this phase, the preprocessed source code is translated into assembly language. The compiler parses the code, checks it for errors, and translates it into a low-level intermediate representation. This phase also involves optimizations to improve the efficiency of the generated code.



3. **Assembly phase:** In this phase, the assembly code generated in the compilation phase is translated into machine code ([[Object code]]) by the assembler. The assembler converts the symbolic instructions and addresses into binary code that can be understood by the computer's processor.

4. **Linking phase:** In this final phase, the linker links all the Object code files generated in the compilation phase and resolves external references. It combines the object code files with any necessary system libraries and generates the final executable file. The linker also performs any necessary relocations and generates a symbol table for the program.

Hello World program:
```c++
// main.cpp
// locate header file using: find /usr/include -name iostream -type f -print
#include <iostream>

int main()
{
    std::cout << "hello world"<< std::endl;
    return 1;
}
```


# Compilation steps
```bash

# **Preprocessing:**
g++ -E main.cpp -o main.i

# Compilation
g++ -S main.i -o main.s

# Assembly
g++ -c main.s -o main.o

#Linking 
g++ main.o -o main

# Combined
g++ main.cpp -o main
```

# Entry point 
The entry point of a C++ program is the function where execution starts. This is typically the `main function`. The main function has a special significance and specific rules regarding its declaration, return type, and parameters.

**Parameters**  
*argc (Argument Count):* An integer representing the number of command-line arguments passed to the program, including the program's name.  
*argv (Argument Vector):* An array of C-strings (char*) representing the actual arguments. argv[0] is the name of the program, and argv[1] through argv[argc-1] are the additional arguments.

**Return Type**  
The return type of main is int, which allows the program to return a status code to the operating system.  
By convention:  
return 0; indicates successful execution.  
Non-zero values indicate errors or abnormal termination.

# Standard output

```c++
#include <iostream>

// note: main has mandatory return type int 
int main(int argc, char* argv[]) {
    // Print the number of arguments
    // std::endl write a newline and flush the stream.
    std::cout << "Number of arguments: " << argc << std::endl;
    // equivalent to 
    // std::cout << "Number of arguments: ";
    // std::cout << argc;
    // std::cout << std::endl;

    // Loop through each argument and print it
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
```

# Standard input

1. **Input Buffer**: `std::cin` uses an internal buffer to temporarily hold the input data. When the user enters data and presses `Enter`, the entire line is flushed to standard output.
2. **Extraction operator** takes item from input stream and put it in the target variable(provided item is of consistent type). Extraction operator returns object of left operand type ie `istream` hence we can do chaining like 
   ```c++
   cin >>x >> y;
   // equivalent to
   cin >> x;
   cin >> y;
	```  
   i.e  x picks first item from input stream, y picks up next.
3. **Type conversion and parsing:** *tries to convert* input into expected datatype: 
   When used in if condition and while loop:
   `istream` object remains in good state till input is consistent with expected datatype. if extraction fails(invalid input or end of input), the stream's fail bit is set, and it evaluates to `false`

```c++
#include <iostream>
int main()
{
    int sum = 0, value = 0;
    // read until end-of-file, calculating a running total of all values read
    std::cin >> value => std::cin;

	while(std::cin){
	std::cin = std::cin >> value;
	}
    while (std::cin >> value){        
        sum += value; // equivalent to sum = sum + value
    }        
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}
```

| Case:                                                                  | Flag values                                                        | Boolean value | Comments                                                                                  |
| ---------------------------------------------------------------------- | ------------------------------------------------------------------ | ------------- | ----------------------------------------------------------------------------------------- |
| consistent data<br>---<br>Eg: number of type `int` user entered 1234   | cin.good(): 1<br>cin.fail(): 0<br>cin.eof(): 0<br>cin.bad(): 0<br> | True          | Input stream remains in good state                                                        |
| inconsistent data<br>---<br>Eg: number of type `int` user entered abcd | cin.good(): 0<br>cin.fail(): 1<br>cin.eof(): 0<br>cin.bad(): 0<br> | False         | expression returns false and default value of data is stored in variable                  |
| CTRL-D                                                                 | cin.good(): 0<br>cin.fail(): 1<br>cin.eof(): 1<br>cin.bad(): 0<br> | False         | Input stream sets `fail_state` . expression returns false. random value stored in number. |
| consistent input follwed by inconsistent input                         | cin.good(): 0<br>cin.fail(): 1<br>cin.eof(): 0<br>cin.bad(): 0<br> | False         | Data till consistent input is stored in variable. Remainder is ignored                    |

# References
1. CSAPP - Chapter 1  
2. [CPPPrimer- Chapter 1](https://cpp-primer.pages.dev/book/012-1.2._a_first_look_at_inputoutput.html)