# 🔗 Bracket Balancing Algorithm

A robust C++ implementation of a bracket matching algorithm using a stack data structure to validate balanced parentheses, curly braces, and square brackets in expressions.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Algorithm Explanation](#algorithm-explanation)
- [Code Structure](#code-structure)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Examples](#examples)
- [Complexity Analysis](#complexity-analysis)
- [Requirements](#requirements)
- [Contributing](#contributing)

## 🎯 Overview

This program checks whether brackets in a given string expression are balanced and properly matched. It uses a stack-based approach to track opening brackets and match them with their corresponding closing brackets.

## ✨ Features

- **Multiple Bracket Types**: Supports `()`, `{}`, and `[]`
- **Error Detection**: Identifies three types of bracket errors:
  - Unbalanced brackets (closing without opening)
  - Mismatched bracket pairs
  - Unclosed opening brackets
- **Stack Operations**: Full stack implementation with push, pop, and display methods
- **Overflow Protection**: Checks for stack overflow and underflow conditions
- **Detailed Error Messages**: Provides specific feedback for different error types

## 🧮 Algorithm Explanation

The algorithm follows these steps:

1. **Initialize**: Create an empty stack
2. **Scan**: Traverse the expression from left to right
3. **Opening Brackets**: When encountering `(`, `{`, or `[`, push onto stack
4. **Closing Brackets**: When encountering `)`, `}`, or `]`:
   - Check if stack is empty (unbalanced)
   - Pop from stack and verify it matches
   - If mismatch, report error
5. **Final Check**: After scanning, stack should be empty

## 📁 Code Structure

```cpp
class Stack
{
private:
    int top;              // Points to top element
    char arr[MAX];        // Array to store stack elements
    
public:
    Stack()               // Constructor
    bool isEmpty()        // Check if stack is empty
    bool isFull()         // Check if stack is full
    void push(char x)     // Add element to stack
    char pop()            // Remove and return top element
    void display()        // Display stack contents
    bool areBracketsBalanced(string expression)  // Main algorithm
};
```

## 🔄 How It Works

### Example 1: Balanced Expression
```
Expression: "{[()]}"

Step-by-step:
1. Read '{' → Push to stack: ['{']
2. Read '[' → Push to stack: ['{', '[']
3. Read '(' → Push to stack: ['{', '[', '(']
4. Read ')' → Pop '(' → Match ✓
5. Read ']' → Pop '[' → Match ✓
6. Read '}' → Pop '{' → Match ✓
7. Stack empty → Balanced ✓
```

### Example 2: Unbalanced Expression
```
Expression: "){}["

Step-by-step:
1. Read ')' → Stack is empty → Unbalanced ✗
   Output: "Brackets are not balanced...!"
```

### Example 3: Mismatched Expression
```
Expression: "{[}]"

Step-by-step:
1. Read '{' → Push to stack: ['{']
2. Read '[' → Push to stack: ['{', '[']
3. Read '}' → Pop '[' → Mismatch ✗
   Output: "Mismatched brackets: [ and }"
```

## 💻 Usage

### Compilation

```bash
g++ bracket_balancing.cpp -o bracket_balancing
```

### Execution

```bash
./bracket_balancing
```

### Modifying Input

Change the expression in `main()`:

```cpp
int main() 
{
    Stack obj;
    string expression = "{[()]}";  // Change this line
    
    if (obj.areBracketsBalanced(expression)) {
        cout << "Brackets are balanced!" << endl;
    }
    
    return 0;
}
```

## 📊 Examples

| Expression | Result | Reason |
|------------|--------|--------|
| `{[()]}` | ✅ Balanced | All brackets properly matched |
| `(){}[]` | ✅ Balanced | Sequential valid pairs |
| `{[(])}` | ❌ Mismatched | `]` doesn't match `(` |
| `){` | ❌ Unbalanced | Closing before opening |
| `{[()` | ❌ Unclosed | Opening brackets not closed |
| `((()))` | ✅ Balanced | Nested parentheses |
| `{[}]` | ❌ Mismatched | Wrong closing order |

## ⚡ Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass through the expression
  - Each character processed once
  - Stack operations are O(1)

- **Space Complexity**: O(n)
  - Stack can hold up to n/2 elements in worst case
  - Where n is the length of the expression

- **Stack Capacity**: MAX = 50 characters

## 🛠️ Requirements

- C++ Compiler (C++11 or later)
- Standard Template Library (STL)
- No external dependencies

### Supported Compilers
- GCC 4.8+
- Clang 3.4+
- MSVC 2015+

## 🔍 Error Handling

The program handles three main error scenarios:

1. **Stack Underflow**: Attempting to pop from empty stack
2. **Stack Overflow**: Exceeding MAX capacity (50 elements)
3. **Bracket Errors**:
   - Unbalanced brackets
   - Mismatched pairs
   - Unclosed brackets

## 🚀 Potential Enhancements

- [ ] Support for additional bracket types (e.g., `<>`)
- [ ] Dynamic stack size
- [ ] Interactive mode for multiple inputs
- [ ] Position tracking for error reporting
- [ ] GUI interface
- [ ] Support for bracket balancing in code files

## 📝 License

This project is open source and available for educational purposes.

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page.

## 👨‍💻 Author

Created as a demonstration of stack-based algorithm implementation in C++.

## 📚 References

- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Bracket Matching Problem](https://en.wikipedia.org/wiki/Matching_brackets)

---

⭐ **Star this repository if you find it helpful!**
