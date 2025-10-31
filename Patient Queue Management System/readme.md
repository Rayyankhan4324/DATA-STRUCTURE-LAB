🏥 ER Patient Management System (Doubly Linked List)
📌 Overview

This project implements an Emergency Room (ER) Patient Management System using a Doubly Linked List (DLL) in C++.
Each patient is represented by a node containing a patient ID, and the system maintains a queue where:

Critical patients are added to the front.

Normal patients are added to the end.

Patients can also be added at specific positions in the list.

Treated patients are removed from the front.

This simulates the priority management system in a real ER queue.

🧠 Concepts Used

Doubly Linked List (with prev and next pointers)

Dynamic Memory Allocation

Class and Object-Oriented Programming

Menu-driven program

🧩 Features

✅ Add a critical patient at the beginning
✅ Add a normal patient at the end
✅ Add a patient at a specific position
✅ Remove a treated patient from the beginning
✅ Display the current ER queue (forward traversal)

🧱 Data Structure
struct Node {
    int patientID;
    Node* next;
    Node* prev;
};


next → points to the next patient in the queue

prev → points to the previous patient in the queue

⚙️ Class Definition
Function Name	Description
addFront(int id)	Add a critical patient at the beginning
addEnd(int id)	Add a normal patient at the end
addAt(int id, int pos)	Add a patient at a specific position
removeFront()	Remove the first (treated) patient
display()	Display all patients currently in the queue

💻 Menu (Main Program)
=== ER Patient Management System ===
1. Add critical patient at beginning
2. Add normal patient at end
3. Add patient at specific position
4. Remove treated patient from beginning
5. Display all patients
6. Exit
Enter your choice (1-6):

🧮 Example Run

Input:

1
Enter patient ID: 200
2
Enter patient ID: 101
2
Enter patient ID: 102
3
Enter patient ID: 150
Enter position: 2
5
4
5
6


Output:

Critical patient added. Updated ER Queue:
200

Normal patient added. Updated ER Queue:
200 <-> 101

Normal patient added. Updated ER Queue:
200 <-> 101 <-> 102

Patient added at position 2. Updated ER Queue:
200 <-> 150 <-> 101 <-> 102

Current ER Queue:
200 <-> 150 <-> 101 <-> 102

Patient Ended: 200
Patient treated and removed from queue.
Updated ER Queue:
150 <-> 101 <-> 102

Thank you for using ER Management System. Exiting...

🔍 Dry Run Example

Initial State:
Empty list → head = nullptr, tail = nullptr

Operations:

addEnd(101)

addEnd(102)

addFront(200)

addAt(150, 2)

removeFront()

addEnd(300)

Final List:

head → [150] <-> [101] <-> [102] <-> [300] ← tail


Results:

(a) Head = 150

(b) Tail = 300

(c) Forward: 150 → 101 → 102 → 300

(d) Backward: 300 → 102 → 101 → 150

🧾 How to Compile and Run
Using Terminal or Command Prompt
g++ ERQueue.cpp -o ERQueue
./ERQueue

Using Code::Blocks or Dev-C++

Create a new C++ project.

Paste the code into the main file.

Build and Run.

🧑‍💻 Author

Name: [Muhammad Rayyan]
Course: Data Structures (C++)
Instructor: [Sir Shayan Ali Shah].
