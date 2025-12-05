📘 CHRONOS TIME STABILIZER — BST TimeCapsule System

A C++ console application that stores, searches, deletes, and reports historical events using a Binary Search Tree (BST).
Each node in the tree represents a Time Capsule containing a year and an associated event.

🚀 Features
✅ 1. Insert Event — INJECT <year> <event>

Adds a new historical event into the BST while maintaining ordering.

✅ 2. Delete Event — PARADOX <year>

Removes a year from the timeline using standard BST deletion rules:

Leaf node

One child

Two children (inorder successor replacement)

✅ 3. Search Event — SEARCH <year>

Finds whether a specific year exists in the timeline.

✅ 4. Chronological Report — REPORT

Displays all events sorted by year using inorder traversal.

✅ 5. Time Span Calculation — calculateTimeSpan()

Finds the difference between the minimum and maximum stored years.

🧹 6. Automatic Memory Cleanup

The destructor recursively deletes the entire tree.

🛠️ How It Works

The BST is built from nodes of the following structure:

struct TimeCapsule {
    int year;
    string eventName;
    TimeCapsule* left;
    TimeCapsule* right;
};


The TimeTree class manages:
✔ Insert (INJECT)
✔ Delete (PARADOX)
✔ Search
✔ Traversal (REPORT)
✔ Time span
✔ Destructor

📥 Supported Commands
Command	Description
INJECT <year> <event>	Insert a new event
PARADOX <year>	Delete an event
SEARCH <year>	Search for an event
REPORT	Print all events in sorted order
EXIT	Close program
🧪 Example Input
INJECT 1947 Independence of Pakistan
INJECT 1965 Indo-Pak War
SEARCH 1947
REPORT
PARADOX 1965
REPORT
EXIT

📤 Example Output
> System: Injecting 1947... Timeline stable.
> System: Injecting 1965... Timeline stable.
> Query: Searching for 1947...
> Result: Event Found! [1947: Independence of Pakistan]

> COMMAND: CHRONOLOGICAL REPORT
-------------------------------
1947 → Independence of Pakistan
1965 → Indo-Pak War
-------------------------------

> Alert: Paradox detected at 1965!
> System: Paradox resolved. Year removed.

> COMMAND: CHRONOLOGICAL REPORT
-------------------------------
1947 → Independence of Pakistan
-------------------------------

🧩 File Structure

main() handles user input and maps commands to actions

TimeTree contains all BST operations

TimeCapsule stores one event

📚 Concepts Practiced

Binary Search Trees (BST)

Recursion

Inorder traversal

BST insertion & deletion (3 cases)

Memory management in C++

Parsing user input with getline & cin >> ws

👨‍💻 Author

Created for educational use—perfect for Data Structures, BST practice, or Operating System lab extensions.
