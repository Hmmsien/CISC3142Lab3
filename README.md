# CISC3142Lab3-
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
The provided CSV files require summarization. Each of the data files contains rosters showing students’ enrollment in courses and grades. Each file contains records for one course number of all sections across multiple terms. These are the main data files to use for generating a report that shows for each instructor (for each course and term).\
The data that should be added as a git submodule is at:\
https://gist.github.com/d279545d975c1652689e8195e2426adf.git \
Please link the submodule as a sub directory named data\
• Data CSV files fields: StudentId, CourseNumber*, InstructorId, TermId,
Section_Id, Grade
• CourseNumber is either 1115, 3115, 3130. There are 3 CSV files, one corresponding to each course
number.

## Run Instructions
Due to the inclusion of a submodule, the repository should be cloned using
git clone --recurse-submodules <repo link>. 
Assuming g++ and make are present on our machine, all that is required to run the included code is to execute the command make lab3 from the root directory of the repository. The Makefile is designed such that it will cd into and compile the code inside the Lab-3 directory, then run the program from there. The Makefile will also automatically clean up the .o and .gch files from the src folder.
  
  
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
