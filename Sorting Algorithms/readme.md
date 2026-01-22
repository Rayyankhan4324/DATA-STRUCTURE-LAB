# 🎓 Student Record Management System (C++ Linked List)

This project is a **C++ console-based application** that manages student academic records using a **Singly Linked List**.  
It reads data from a file, stores it dynamically, sorts students based on **CGPA and Credits**, and generates a **ranked output file**.

---

## 📌 Features

- 📂 Reads student records from a text file
- 🔗 Uses **Singly Linked List** for dynamic data storage
- 🔁 Clones the linked list to preserve original data
- 📊 Sorts students by:
  - **CGPA (Descending)**
  - **Credits (Descending) if CGPA is equal**
- 🏆 Generates a ranked list of students
- 🧹 Proper memory management using destructor
- ❌ Ignores invalid records automatically

---

## 🧠 Concepts Used

- Structures (`struct`)
- Singly Linked List
- File Handling (`ifstream`, `ofstream`)
- Dynamic Memory Allocation
- Bubble Sort Algorithm
- Deep Copy (Clone Function)
- Data Validation
- Output Formatting (`iomanip`)

---

## 📁 Project Structure
├── main.cpp
├── students_data.txt
├── ranked_by_cgpa.txt
└── README.md

--

## 📝 Student Data File Format (`students_data.txt`)

The first line contains the **total number of student records**.  
Each subsequent line contains student information in the following format:


### Example
3
101 Ali CS 3 3.45 18 2023
102 Sara AI 2 3.90 20 2024
103 Ahmed SE 4 3.90 22 2022

## Output Description.
====================================================
        STUDENTS RANKED BY CGPA
====================================================
Rank | ID | Name | Dept | Sem | CGPA | Credits | Year

