---
date: 2024-08-21
---

**Objective:**
1. Hands-on shell scripting
2. Apply IO-redirection, pipes, shell commands
   
**Commands you need to be aware of :** `cat`, `head`, `tail`, `cut`, `sort`, `uniq`, `grep`, `date`, `more` and then some more...

# Lab 1 revision assignment (use `timetable.csv`)

### **1. Count the Number of Classes for Each Instructor**
**Question:**  
Create a Bash script that counts how many classes each instructor has in a week and displays the instructor's name along with the count.

**Example Output:**
```bash
Instructor | Number of Classes
Dr. Smith  | 5
Prof. Brown | 4
```

### **2. Find Available Rooms at a Specific Time**
**Question:**  
Write a Bash script that prompts the user to input a time (e.g., 11:00-12:00) and then lists all rooms that are free during that time.

**Example Output:**
```bash
Enter the time slot: 11:00-12:00
Available Rooms: Room 101, Lab 3, Lecture Hall 2
```

### **3. Find the Course with the Most Classes**
**Question:**  
Write a Bash script that determines which course is scheduled the most frequently during the week and displays the course name along with the number of classes.

**Example Output:**
```bash
Course    | Number of Classes
CS 101    | 7
```

### **4. Filter Courses by Room**
**Question:**  
Write a Bash script that prompts the user to enter a room number and displays all the courses scheduled in that room throughout the week.

**Example Output:**
```bash
Enter the room number: Lab 2
Day      | Time       | Course  | Instructor
Monday   | 10:00-11:00 | CS 101  | Prof. Brown
Tuesday  | 09:00-10:00 | CS 201  | Dr. White
```


### **5. Find the Instructor with the Earliest Class**
**Question:**  
Write a Bash script that finds and displays the instructor who has the earliest scheduled class during the week.

**Example Output:**
```bash
Earliest Class: Dr. Smith, 08:00-09:00 on Monday
```

### **6. Calculate Total Hours Taught by Each Instructor**
**Question:**  
Create a Bash script that calculates the total number of hours each instructor teaches in a week and displays the instructor's name along with the total hours.

**Example Output:**
```bash
Instructor | Total Hours
Dr. Smith  | 10
Prof. Brown | 8
```
