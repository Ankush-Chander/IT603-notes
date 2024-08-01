---
date: "[[2024-07-25]]"
---
### Lecture 3

Quick recap
1. Abstractions (processes, files, virtual memory, instruction set, virtual machine)
2. investigate processes using ps, htop
3. Parent child processes
4. GUI vs CLI process launching
---
#### Filesystem navigation(1)
1. `pwd`: Prints current directory
2. `ls` : list directories
3. `cd` change directory
4. `mkdir` create directory
6. `touch`: Create empty file
7. `rm`: remove files
8. `rmdir`: removes directory

---
#### Filesystem navigation(2)

| Absolute addressing                                          | Relative addressing                                                                                                      |     |
| ------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------ | --- |
| Specify full path of the file/directory                      | Specify paths relative to current directory using 2 special symbols: **.**(current directory) & **..**(parent directory) |     |
| **Pros:**<br>- Precision<br>- Stability:<br>- Easy Debugging | **Pros:**<br>- Flexibility<br>- Portability<br>- Simplified Maintenance                                                  |     |
|                                                              |                                                                                                                          |     |

---
#### File exploration using ls
1. `ls ` command is the one of the most used commands on terminal. It is used to list the directory content.
	Two main options are:
	- `ls -a`: Show all files including hidden files
	- `ls -l` : List content of the directory in the long format. 

---
#### Understanding ls command output

| Field           | Meaning                                    |
| --------------- | ------------------------------------------ |
| -rw-rw-r--      | Access rights                              |
| 2               | File's number of hard links.               |
| ankush          | The user name of the file's owner.         |
| ankush          | The name of the group which owns the file. |
| 26              | Size of the files in byte                  |
| 26 Jul 25 06:48 | Last modified date                         |
| hello.txt       | name of the file                           |

---
#### Filesystem 
A filesystem is a method and data structure that an operating system uses to manage and organize files on a storage device such as a hard drive, SSD, or USB flash drive.  
Eg: ext3, ext4, ntfs, fat32  

Related commands/utilities: `gparted`

---
#### Organisation of files
**Inode:** It is a data structure that stores metadata about a file or a directory, except for its name and actual data content.   When you create a file, the filesystem allocates an inode and assigns it an inode number.
- **Unique Identification**: Each inode has a unique number within the filesystem, called the inode number.
- **Mapping**: filenames => inode numbers. When you access a file by name, the filesystem looks up the inode number in the directory.  
---
#### Hard links vs softlinks

| Feature                 | Hard Link               | Soft Link             |
| ----------------------- | ----------------------- | --------------------- |
| Points to               | Inode                   | Path                  |
| Can link to directories | No                      | Yes                   |
| Deleting original file  | Data remains accessible | Link becomes broken   |
| Filesystem limitations  | Same filesystem only    | Can cross filesystems |

---
#### File ownership
In Linux file ownership happens at 3 levels:
1. User: Every file is owned by a single user. By default it"S the creator of the dile 
2. Group: In case multiple users needs to be shared the same files. Groups are created. Users are added to that group and group is also made the owner of the file.
3. Others: Rest of the users  
Relevant commands: `id`,  `umask`, `chown`, `chgroup`

---
#### File Permissions
Access rights to files and directories are defined in terms of read access, write access, and execution access.

---
#### File and Directory Permissions(1)

| Access | Files                          | Directories                                                         |
| ------ | ------------------------------ | ------------------------------------------------------------------- |
| **r**  | can  be opened and read.       | Allows a directory's contents to be listed(r+x).                    |
| **w**  | can be written to or truncated | Allows files within a directory to be created/deleted/renamed (w+x) |
| **x**  | can be executed.               | Allows a directory to be entered, e.g., `cd directory`.             |

---
#### File and Directory Permissions(2)
1. `chmod`:
```bash
# adds x permission to file
   chmod +x hello.txt 
   # change permissions using binary notation
   chmod 755 hello.txt 
```
2. `umask`: default permissions a file get upon creation
```bash
umask
# outputs: 0002
```

