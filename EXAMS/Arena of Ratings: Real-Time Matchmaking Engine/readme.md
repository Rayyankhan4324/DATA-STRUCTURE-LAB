# Arena of Ratings – Binary Search Tree (C++)

This project implements a **player matchmaking and leaderboard system** using a **Binary Search Tree (BST)** in **C++**.  
The program processes commands from standard input and performs various operations based on player ratings.

This project was developed for a **Data Structures Lab** to practice BST operations such as insertion, deletion, searching, and traversal.

---

## 📌 Overview

- Each player is identified by a **unique rating**
- Players are stored in a **BST ordered by rating**
- Supports real-time updates and queries
- No STL ordered containers are used

---

## 🧠 Data Structure Used

- **Binary Search Tree (BST)**
- Pointer-based implementation
- Recursive algorithms
- Ordering is done **only by rating**

---

## 🧾 Player Structure

Each player node contains:
- `rating` (int) – unique key
- `name` (string)
- `hp` (long long) – health points
- `left` and `right` child pointers

---

## ⚙️ Supported Commands

| Command | Description |
|------|------------|
| JOIN | Add a new player |
| LEAVE | Remove an existing player |
| STATUS | Display player details |
| DAMAGE | Reduce player health |
| HEAL | Increase player health |
| NEXT | Find next higher rated player |
| PREV | Find previous lower rated player |
| MATCH | Find closest rating match |
| RANGE | Print players within a range |
| RANK | Count players with lower rating |
| KTH | Find k-th smallest rating |
| DUEL | Distance between two players |
| STATS | Display tree statistics |

---

## 📊 Tree Statistics (STATS)

The `STATS` command prints:
- Total number of players
- Minimum rating
- Maximum rating
- Height of the BST
- Number of leaf nodes

---

## ▶️ Compilation and Execution

```bash
g++ main.cpp -o arena
./arena


SAMPLE INPUT
5
JOIN 50 Alex 100
JOIN 20 Sam 80
MATCH 25
RANK 50
STATS


SAMPLE OUTPUT
JOINED
JOINED
20 Sam 80
1
PLAYERS 2
MIN 20
MAX 50
HEIGHT 1
LEAVES 1
