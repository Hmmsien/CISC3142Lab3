# CISC3142Lab3
This programming assignment will be exposed to OOP paradigm, as well as practice with refactoring code to make it more maintainable.

1. Use object-oriented style of coding with C++, including procedural and data abstraction design patterns.  
This enables composability and reusability.  
2. Use Google C++ Guidelines (https://google.github.io/styleguide/cppguide.html)
Specifically, the following sections  
• Self-Contained Headers  
• Names and Order of Includes - Include headers in the following order: Related header, C system
headers, C++ standard library headers, other libraries' headers, your project's headers.  
• Scoping – namespaces
• Local Variables
• Static and Global Variables
3. Format output nicely with printf (or similar feature) instead of std::cout  
4. Work with multiple data input files. Ideally specified from args instead of hard coded  
5. More practice using version control with git, specifically:  
a. Branches for managing feature changes. Work on a new branch, and merge once you’re finalizing
the code (should have no more than a few commits after merging).  
b. Use the submodule feature for managing dependencies  

## Problem Description:
The provided CSV files require summarization. Each of the data files contains rosters showing students’ enrollment in courses and grades. Each file contains records for one course number of all sections across multiple terms. These are the main data files to use for generating a report that shows for each instructor (for each course and term).  
The data that should be added as a git submodule is at:  
https://gist.github.com/d279545d975c1652689e8195e2426adf.git
Please link the submodule as a sub directory named data  
• Data CSV files fields: StudentId, CourseNumber*, InstructorId, TermId,
Section_Id, Grade  
• CourseNumber is either 1115, 3115, 3130. There are 3 CSV files, one corresponding to each course
number.

# Run
Using C++14 compiler

Due to the inclusion of a submodule, the repository should be cloned using 
```sh
$ git clone --recurse-submodules <repo link>
```
To run this project: make sure you are in the root of the project repository and run
```sh
$ make lab3
```
 
## Source code Specifications 
(i.e. must have, as opposed to requirements in the next section):  
• All source code in a src folder  
o Main function in its own file main.cpp  
o Functions in separate files (to be included in your main.cpp file)  
▪ One file dedicated to functions for file reading and writing  
▪ One file dedicated to aggregation functions (i.e. count(), max(), pass_rate(), etc.)  
o Declarations and prototypes should be saved in separate header file(s)  
• All data in a data folder  
• All report outputs should be in output folder. Ideally, you should include a timestamp with a
filename and one specific report per file.  

## Output 
Output 3 report under output folder. All filename contain the date time when created.

Example:
### W_rate_2022-04-27-17-45-55.csv<br/>
|Column Name|Data Type|Description|
|-----------|---------|-----------|
|instructorID|TEXT|Unique ID number identifying each instructor|
|courseID|INT|Unique ID number identifying each course|
|W_rate|TEXT|The rate of grade 'W'|

### fall_vs_spring_pass_rate_2022-04-27-17-45-55.csv<br/>
|Column Name|Data Type|Description|
|-----------|---------|-----------|
|courseID|INT|Unique ID number identifying each course|
|Fall vs Spring|TEXT|Semester as Fall or Spring|
|pass_rate|TEXT|The rate of passing the course during the sepecify semester|

### pass_rate_2022-04-27-17-45-55.csv<br/>
|Column Name|Data Type|Description|
|-----------|---------|-----------|
|instructorID|TEXT|Unique ID number identifying each instructor|
|courseID|INT|Unique ID number identifying each course|
|pass_rate|TEXT|The rate of passing the course under specify instructor|



