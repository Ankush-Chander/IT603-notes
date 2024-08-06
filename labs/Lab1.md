**End goal:** Build [Marauder"s map](https://harrypotter.fandom.com/wiki/Marauder%27s_Map) for DAIICT
**Objective:**
1. Hands-on shell scripting
2. Apply IO-redirection, pipes, shell commands
   
**Commands you need to be aware of :** `cat`, `head`, `tail`, `cut`, `sort`, `uniq`, `grep`, `date`, `more` and then some more...

<img src="https://pm1.narvii.com/7884/88786ffddf4fc254d64f4ee034da43d7719e1d1br1-1600-1600v2_uhq.jpg" alt="drawing" style="width:400px;"/>

---
# Data preparation(already done):
1. Use [Short timetable](http://intranet.daiict.ac.in/~daiict_nt01/Academic/Autumn_2024-25_TimeTable/Autumn%20Semester%202024-25.pdf) to create 2 sheets(sheet1.csv, sheet.csv).
2. Join two sheets to get final timetable.
 
```python
import pandas as pd
s1 = pd.read_csv("sheet1.csv")
s2 = pd.read_csv("sheet2.csv")
```


```python
timetable_df = s2.merge(s1, left_on='Slot', right_on='Slot')
timetable_df = timetable_df[["Day",	"Time",	"Course", "Instructor","Room"]]
timetable_df.to_csv("timetable.csv", index=False)
```

---

# Lab 1 assignment (use `timetable.csv`)

#### Basic Operations

1. Display Specific Day's Schedule:  
Write a bash script(`todays_schedule.sh`) that displays the schedule for  `today`.  
Usage: `todays_schedule.sh`

2. Count Courses per Instructor:
Write a bash script that counts the number of courses each instructor is teaching.  
Usage: `instructor_course_count.sh instructor_name`


4. List Courses in a Specific Room:
Write a bash script that lists all the courses that are held in a specific room.  
Usage: `room_course_list.sh room_name`

5. Extract Timetable for a Specific Course:  
Write a bash script that extracts and displays the timetable for a specific course.  
Usage: `course_timetable.sh`

#### Intermediate
1. Find out when a room is empty during the week.  
Usage: `room_empty_slots.sh CEP-207`

2. Count Classes per Room per Day:
Write a bash script to count how many classes are held in each room for each day.  
Usage: `room_class_count.sh`
Output:
```
Room, Day, Count 
CEP-207, Monday,3
CEP-103, Tuesday,5
...
```

3. Find out where an instructor would be at current time? Display "office" in case not in class hard-code daytime to test.  
	Usage: `instructor_location.sh instructor_name`


#### Advanced (Worthy of being added into CV if completed)
1. Write a script that takes student id and locate that student in college in real time.
	- Augment csv file and add batch_ids(202412, 202411 etc) corresponding to each course.
	- Write script to locate the batch , batch gives away the student

#### Future work
Map people to actual positions on a graphical map. 
