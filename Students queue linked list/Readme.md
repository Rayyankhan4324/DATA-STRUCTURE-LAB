# 🚌 Passenger Queue Management using Linked List  

A **C++ project** that implements a **dynamic passenger queue system** using a **singly linked list**.  
This program demonstrates core **data structure concepts** like insertion, deletion, traversal, and dynamic memory allocation.

---

## 📘 Project Overview  

This project simulates a **real-time passenger queue** similar to those in public transport systems or event management lines.  
It allows passengers (students) to join, leave, or be served dynamically — showcasing the flexibility and efficiency of **linked lists**.

---

## ⚙️ Features  

- ➕ **Add Student** → Insert a new passenger at the end of the queue.  
- ✅ **Serve Student** → Serve (remove) the first passenger in line.  
- ❌ **Student Leaves** → Remove a passenger by their ID.  
- 👥 **Display Queue** → View all passengers currently waiting.  
- 🔢 **Count Students** → Display total number of passengers in the queue.  

---

## 🧩 Data Structure Design  

### 🔹 Struct: `Node`  
Each node represents a passenger and contains:  
- `int ID` → Passenger’s unique identifier  
- `string name` → Passenger’s name  
- `Node* next` → Pointer to the next passenger in the queue  

### 🔹 Class: `LinkedList`  
Handles all queue operations using dynamic memory and linked list logic.  
Main functions include:  
- `add_student()` → Add new passenger  
- `serve_student()` → Serve the first passenger  
- `leave_student(int id)` → Remove passenger by ID  
- `display_queue()` → Print all passengers  
- `count_students()` → Show total passengers  

---

## ▶️ Example Execution  

```text
1. Add Student
2. Serve Student
3. Student Leaves (by ID)
4. Display Queue
5. Count Students
6. Exit
