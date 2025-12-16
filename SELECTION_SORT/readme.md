# Selection Sort Program

A C++ implementation of the Selection Sort algorithm that reads numbers from a file, sorts them, and measures the execution time.

## Description

This program demonstrates the Selection Sort algorithm by:
- Reading comma-separated integers from a text file
- Sorting them using selection sort
- Measuring and displaying the time taken to sort
- Displaying the sorted array

## Features

- File-based input handling
- Dynamic memory allocation for array
- Performance measurement using `<chrono>` library
- Time complexity: O(n²)

## Requirements

- C++ compiler with C++11 support or higher
- Input file named `numbers.txt` in the same directory as the executable

## Input File Format

Create a file named `numbers.txt` with comma-separated integers on a single line:

```
45,23,67,12,89,34,56,78,90,11
```

## Compilation

```bash
g++ -o selection_sort selection_sort.cpp
```

Or with C++11 flag explicitly:

```bash
g++ -std=c++11 -o selection_sort selection_sort.cpp
```

## Usage

1. Create `numbers.txt` with your comma-separated numbers
2. Compile the program
3. Run the executable:

```bash
./selection_sort
```

## Output

The program displays:
- The sorted array
- Time taken to sort (in milliseconds)

Example output:
```
Sorted Array: 11 12 23 34 45 56 67 78 89 90 
time taken by bubble sort: 0 milli second
```

## Algorithm

Selection Sort works by:
1. Finding the minimum element in the unsorted portion
2. Swapping it with the first element of the unsorted portion
3. Moving the boundary between sorted and unsorted portions
4. Repeating until the entire array is sorted

## Time Complexity

- **Best Case:** O(n²)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)
- **Space Complexity:** O(1)

## Note

Despite the output message saying "bubble sort", this program actually implements **Selection Sort**. The comment in the code appears to be a copy-paste error.

## Memory Management

The program uses dynamic memory allocation with `new[]`. The allocated memory is automatically freed when the program terminates, though adding `delete[] arr;` before `return 0;` would be a best practice for proper cleanup.
