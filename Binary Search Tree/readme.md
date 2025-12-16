# Binary Search Tree (BST) Implementation in C++

## 📌 Overview
This program implements a **Binary Search Tree (BST)** in C++.  
It supports insertion, searching, deletion, and tree traversals including:

- Inorder Traversal
- Preorder Traversal
- Postorder Traversal

The program demonstrates core **Data Structures** concepts commonly required in DSA and OS labs.

---

## 🌳 Features
- Check if tree is empty
- Insert nodes into BST
- Search for a value
- Delete a node from BST
- Traversals:
  - Inorder (Left → Root → Right)
  - Preorder (Root → Left → Right)
  - Postorder (Left → Right → Root)

---

## ⚙️ How the BST Works
- Left subtree contains values **smaller** than the root
- Right subtree contains values **greater** than the root
- No duplicate values are inserted

---

## 🧠 Algorithms Used

### Insertion
- Recursively finds the correct position
- Time Complexity: **O(log n)** (average)

### Searching
- Uses BST property for efficient lookup
- Time Complexity: **O(log n)** (average)

### Deletion
Handles three cases:
1. Node with no children
2. Node with one child
3. Node with two children (inorder successor)

---

## 🔁 Tree Traversals

### Inorder Traversal
- Outputs values in **sorted order**
- Format: `Left → Root → Right`

### Preorder Traversal
- Useful for copying the tree
- Format: `Root → Left → Right`

### Postorder Traversal
- Useful for deleting the tree
- Format: `Left → Right → Root`

---

## ▶️ How to Compile and Run

### Compile:
```bash
g++ bst.cpp -o bst
