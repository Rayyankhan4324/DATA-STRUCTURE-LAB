🧩 Doubly Linked List Implementation in C++
📘 Overview

This C++ program demonstrates the implementation of a Doubly Linked List (DLL).
It includes major operations such as:

Insertion (at beginning, at end, and at specific position)

Deletion (from front)

Searching for a node

Displaying the list (simple and detailed with memory addresses)

Destructor for memory cleanup

The program also visually prints memory addresses to help understand how nodes are linked in memory.

🧠 Key Features
Feature	Description
Insert at Beginning	Adds a new node at the start of the list
Insert at End	Adds a new node at the end of the list
Insert at Position	Inserts a node at a specific position
Delete from Front	Deletes the first node of the list
Search Node	Finds and displays a specific node
Display (Detailed)	Prints addresses of previous, current, and next nodes
Destructor	Automatically deletes all nodes to free memory
🧮 Example Output
---------------- INSERTING AT BEGIN ----------------
------------------------------------------------------
     Prev Address        |   Data   |     Next Address |   Node Address
------------------------------------------------------
                   0 |      10 |      0x1ddd31017f0 |        0x1ddd3101850
       0x1ddd3101850 |      20 |      0x1ddd3101890 |        0x1ddd31017f0
       0x1ddd31017f0 |      30 |                  0 |        0x1ddd3101890
Tail: 0x1ddd3101890
------------------------------------------------------

🧩 Class Structure
class Node

Represents a single node of the doubly linked list.

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value);
};

class DLL

Represents the full doubly linked list with its operations.

class DLL {
public:
    Node* head;
    Node* tail;

    DLL();
    ~DLL();
    void insertAtBegin(int value);
    void insertAtEnd(int value);
    void insertAtPos(int position, int value);
    void deleteFB();
    void search(int value);
    void display();
    void Display();
    void DisplayNode(Node* node);
};

⚙️ How to Run
For Windows (Command Prompt / PowerShell)
g++ main.cpp -o dll
./dll

For Linux / Ubuntu
g++ main.cpp -o dll
./dll

🧠 Concepts Demonstrated

Dynamic memory allocation (new / delete)

Object-Oriented Programming (constructors, destructors)

Pointer manipulation

Data structure traversal

Memory address visualization

✨ Sample Use Cases

This program is ideal for:

Learning pointer-based data structures

Understanding how linked lists work internally

Practicing debugging and visualization of memory links

OS Lab assignments and Data Structure courses

👨‍💻 Author

Rayyan Khan
3rd Semester — Artificial Intelligence
Institute of Management Sciences (IMSciences), Peshawar
