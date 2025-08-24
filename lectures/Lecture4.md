---
delivery date: 2024-07-29
---

# Quick Recap
1. Abstractions
  - Processes (pid, parent child relationship, GUI vs CLI)
  - Files
    - File ownership (owner, group, others)
    - File Permissions (read, write, execute)
    - File management (filesystem, inode, directoryhard links, softlinks, )

---

# Agenda
1. How does processes and files interact with each other?
2. Shell script basics
---
# Abstraction of I/O devices

```
One of Unix's several groundbreaking advances was abstract devices, which removed the need for a program to know or care what kind of devices it was communicating with. Older operating systems forced upon the programmer a record structure and frequently non-orthogonal data semantics and device control.
```

**Data stream**: An ordered sequence of data bytes which can be read until the end of file. 

---
# Standard I/O
**Standard input:** is a stream from which a program reads its input data. The program requests data transfers by use of the read operation. Not all programs require stream input. Some of them don"t take any input. While other takes input in the form of command line options.

**Standard output** is a stream to which a program writes its output data. The program requests data transfer with the write operation. Not all programs generate output. For example, the file rename command (variously called mv, move, or ren) is silent on success.
Unless redirected, standard output is inherited from the parent process. In the case of an interactive shell, that is usually the text terminal which initiated the program.

**Standard error** is another output stream typically used by programs to output error messages or diagnostics. It is a stream independent of standard output and can be redirected separately. 

---

![Standard streams](https://upload.wikimedia.org/wikipedia/commons/7/70/Stdstreams-notitle.svg)

Pic credits: Wikipedia

---

# I/O redirection
1. **Output redirection**: By using `>` operator next to the command follwed by filename, we can redirect the output the file instead. By using `>>` you can append the output to the file instead of overwriting it.
```bash
ls -lh > ls_output.txt
# result stored in ls_output.txt
```
2. **Input redirection**: Programs that reads from standard input expect it from keyboard. We can redirect the input from another file using `<` operator.
```bash
wc < ls_output.txt
```
3. **Error redirection** Error messages, a program produces are different from the output of the program and by default displayed on terminal. They can be redirected using file descriptor 2.
```bash
ls xyz 2> ls_error.txt
```
---
To pass both standard output and error to same file:
```bash
some_command >file.log 2>&1 
# order matters, below will give error
some_command 2>&1 >file.log 
```
---
# Pipe 
The ability of programs to read from standard input and write to standard output comes handy when combining commands to form pipelines.

By using pipe operator `|`, we can directly pass the output of a command as input to anaother command.

```bash
# count number of lines in ls output
# method1
ls -l > tmp.txt
wc -l tmp.txt

# method2 (using pipeline)
ls -l | wc -l
```

---

![Pipe](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f6/Pipeline.svg/506px-Pipeline.svg.png)

---
# Pipe vs redirection

| Feature          | Pipe                                                               | Redirection Operators <, >                                      |
| ---------------- | ------------------------------------------------------------------ | --------------------------------------------------------------- |
| Purpose          | Connects the output of one command to the input of another command | Redirects the standard input/output of a command to/from a file |
| Syntax           | command1 \| command2                                               | command > file, command < file, command >> file                 |
| Data Flow        | Transfers data directly between commands                           | Transfers data between commands and files                       |
| Usage Example    | ls \| grep "txt"                                                   | ls > output.txt, cat < input.txt                                |
| Output Handling  | The output of command1 becomes the input of command2               | > writes to a file, < reads from a file, >> appends to a file   |
| Common Use Cases | Chaining commands for complex tasks                                | Saving command output to files, reading from files              |

---
# Shell scripting
Shell script is a mini language that allows you to combine/run multiple command collectively. It is commonly used for automation, text manipulation.  

```bash
#!/bin/bash

# This is a comment
echo "Hello, World!"  # Print a message

# Variables
name="Alice"
echo "Hello, $name!"

# Conditional statement
if [ "$name" == "Alice" ]; then
  echo "Welcome, Alice!"
else
  echo "You are not Alice."
fi

# Loop
for i in {1..5}; do
  echo "Number $i"
done

```
---
## Key points
1. `hashbang` operator: first line of the script tells which operator to use to run the script.
    ```bash
    #! /bin/bash
    ```
2. How to take arguments from the command line?
 - Positional parameters: You can access command line arguments via positional parameters(0-9).
   `$0` stands for the command itself  
   `$1` first argument  
   `$2` second argument  
   ...  
   
   ```bash
   echo "$1" #prints first argument

    # loop over all the arguments
   for i in "$@"; do
      echo "Arg: $i"
    done 
   ```
 - `#@` operator lets you access all arguments at once.
3. How to read an input stream?
   ```bash
   #!/bin/bash
    echo "Enter your first and last name:"
    read first_name last_name
    echo "Hello, $first_name $last_name!"
   ```

# Text manipulation
- cat – Concatenate files and print on the standard output
- sort – Sort lines of text files
- uniq – Report or omit repeated lines
- cut – Remove sections from each line of files
- diff – Compare files line by line
- tr – Translate or delete characters
- grep - Search for patterns in a file
- sed – Stream editor for filtering and transforming text
---
# References
1. [Wikipedia - Standard streams](https://en.wikipedia.org/wiki/Standard_streams)
2. The Linux Command line - Ch 7 (IO redirection)
3. The Linux Command line - Ch 29 (Reading Keyboard input)
