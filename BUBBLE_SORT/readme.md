# Bubble Sort Program

A C++ implementation of the Bubble Sort algorithm that reads numbers from a file, sorts them, and measures the execution time.

## Description

This program demonstrates the Bubble Sort algorithm by:
- Reading comma-separated integers from a text file
- Sorting them using an optimized bubble sort
- Measuring and displaying the time taken to sort
- Displaying the sorted array

## Features

- File-based input handling
- Dynamic memory allocation for array
- Optimized bubble sort with early termination (checks if array is already sorted)
- Performance measurement using `<chrono>` library
- Time complexity: O(n²) worst case, O(n) best case

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
g++ -o bubble_sort bubble_sort.cpp
```

Or with C++11 flag explicitly:

```bash
g++ -std=c++11 -o bubble_sort bubble_sort.cpp
```

## Usage

1. Create `numbers.txt` with your comma-separated numbers
2. Compile the program
3. Run the executable:

```bash
./bubble_sort
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

Bubble Sort works by:
1. Comparing adjacent elements in the array
2. Swapping them if they are in the wrong order
3. Repeating this process for each element
4. Using a flag to detect if any swaps occurred in a pass
5. If no swaps occurred, the array is sorted and the algorithm terminates early

## Time Complexity

- **Best Case:** O(n) - when array is already sorted (thanks to the swapped flag optimization)
- **Average Case:** O(n²)
- **Worst Case:** O(n²) - when array is sorted in reverse order
- **Space Complexity:** O(1)

## Optimization

This implementation includes an optimization using a `swapped` flag. If no swaps occur during a complete pass through the array, it means the array is already sorted, and the algorithm terminates early. This improves the best-case time complexity from O(n²) to O(n).

## Memory Management

The program uses dynamic memory allocation with `new[]`. The allocated memory is automatically freed when the program terminates, though adding `delete[] arr;` before `return 0;` would be a best practice for proper cleanup.

## When to Use Bubble Sort

Bubble sort is best used for:
- Small datasets
- Nearly sorted data (due to early termination optimization)
- Educational purposes to understand sorting algorithms
- Situations where simplicity is more important than efficiency

For larger datasets, consider more efficient algorithms like Quick Sort, Merge Sort, or Heap Sort.
