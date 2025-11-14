# 🎓 Student Queue Management System using Linked List  

A **C++ console-based project** that implements a **dynamic student queue system** using a **singly linked list**.  
This system simulates real-world queue handling — where students can join, leave, or be served in real time.

---

## 📘 Project Overview  

During events like *Code-a-Thon* or university distributions, students form queues for services (e.g., T-shirts or registration).  
This program helps organizers manage that queue efficiently without using fixed-size arrays — ensuring **flexibility** and **dynamic memory allocation**.

---

## ⚙️ Features  

- ➕ **Add Student** → Add a new student at the end of the queue.  
- ✅ **Serve Student** → Serve and remove the first student from the queue.  
- ❌ **Student Leaves** → Remove any student by their ID.  
- 👥 **Display Queue** → Show all students currently in the queue.  
- 🔢 **Count Students** → Display the total number of students waiting.  

---

## 🧩 Data Structure Design  

### 🔹 Struct: `Node`  
Each student is represented as a node containing:  
- `int ID` → Student’s unique ID  
- `string name` → Student’s name  
- `Node* next` → Pointer to the next student  

### 🔹 Class: `LinkedList`  
Manages the queue dynamically using linked list operations:  
- `add_student()` → Add new student  
- `serve_student()` → Serve first student  
- `leave_student(int id)` → Remove a student by ID  
- `display_queue()` → Show all students  
- `count_students()` → Show total count  

---

## ▶️ Example Execution  

```text
1. Add Student
2. Serve Student
3. Student Leaves (by ID)
4. Display Queue
5. Count Students
6. Exit
