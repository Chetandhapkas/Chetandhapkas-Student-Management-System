Student Tracker & Marksheet Management System (C Language)
Introduction

This project is a menu-driven Student Tracker and Marksheet Management System developed using the C programming language.
It is designed to manage student records efficiently, including personal details, skills, academic performance, and marksheet generation.

The system is fully console-based and suitable for engineering students, C programming practice, and academic mini-projects.

Objective of the Project

The main objectives of this project are:

To understand array-based data management in C

To implement real-world student record handling

To practice functions, loops, conditions, and string handling

To generate marksheets with grades, SGPA, and CGPA

To build a complete, menu-driven system without file handling

Technologies Used

Programming Language: C

Compiler: Turbo C / GCC / MinGW

Header Files Used:

stdio.h

string.h

conio.h

Project Features
1. Add Student

Adds a new student record

Input validation for:

Roll number

Mobile number (10 digits)

Skills limit up to 5 skills

Students are stored in sorted order by roll number

2. Display Students

Displays all student details one by one

Shows:

Roll Number

Name

Semester

SGPA

Mobile Number

Skills

Skill Level (High / Moderate / Low)

3. Search Student by Roll Number

Search using roll number

Shows complete student details

Maximum 3 attempts allowed

Prevents infinite wrong input attempts

4. Search Student by Skill

Displays all available skills dynamically

User selects a skill

Shows all students having that skill

Allows viewing full details of selected student

5. Display All Students (Row-Wise)

Displays all students in table format

Skills are shown neatly in rows

Easy to read and compare data

6. Delete Student

Deletes student using roll number

Shows student details before deletion

Asks for confirmation

Maximum 3 incorrect attempts allowed

7. Update Student Details

Update:

Name

Semester

Mobile number

SGPA

Skills

Or all fields at once

Shows comparison table of old vs new values

Helps in understanding data changes clearly

8. Show Students by Level

Students are classified based on skill count:

Skill Count	Level
More than 3	High Level
Exactly 3	Moderate Level
Less than 3	Low Level

Displays level-wise student list

Allows:

Search by roll number

View students of a particular level

9. Generate Marksheet

Generates marksheet for selected students

Subjects:

BT

DAA

DBMS

DSA

OOPJ

Calculates:

Total marks

Percentage

Grade

SGPA

CGPA (including previous semesters)

Displays semester-wise SGPA table

Generates summary table for multiple students

Grade Calculation Logic
Percentage	Grade
90 and above	A++
85 – 89	A
75 – 84	B++
70 – 74	B
60 – 69	C
50 – 59	D
Below 50	F
Data Managed in the System

For each student, the following information is stored:

Roll Number

Name

Semester

Mobile Number

SGPA

Skills (Maximum 5)

Subject Marks (5 subjects)

Program Structure

Uses global arrays to store student data

Modular design using separate functions

Each operation has its own function:

Add

Search

Update

Delete

Display

Marksheet generation

How to Run the Program
Using Turbo C

Open Turbo C

Create a new .c file

Paste the source code

Compile and Run

Using GCC / MinGW
gcc student_tracker.c -o student_tracker
student_tracker

Limitations

Data is not saved permanently (no file handling)

Maximum student limit is fixed

Console-based interface only

Future Improvements

Add file handling to store data permanently

Add login system (Admin / User)

Convert project to C++ or Java

Create GUI or Web version

Export marksheet to file or PDF

Conclusion

This project successfully demonstrates how C language can be used to build a complete real-world application using basic concepts such as arrays, functions, loops, and conditions.
It is a good project for learning, practice, and academic submission.

Author

Chetan Dhapkas
Engineering Student
Interested in C Programming, Web Development, and System Design

⭐ If you find this project useful, feel free to star the repository.