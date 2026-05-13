*This project has been created as part of the 42 curriculum by luferna3.*

# push_swap

A sorting algorithm project from 42 focused on sorting integers using two stacks and a limited set of operations.

---

# Overview

`push_swap` takes a list of integers as arguments and sorts them in ascending order using only predefined stack operations.

The goal is not only to sort correctly, but to do so with the **lowest number of operations possible**.

This implementation uses the **K Sort algorithm**, an efficient chunk-based sorting strategy commonly used in `push_swap`.

---

# Features

- Integer parsing and validation
- Duplicate detection
- Stack-based sorting
- Optimized sorting for small datasets
- K Sort implementation for larger datasets
- Error handling
- Memory-safe implementation
- 42 Norm compliant

---

# Allowed Operations

## Swap

```bash
sa  # swap first 2 elements of stack A
sb  # swap first 2 elements of stack B
ss  # sa and sb simultaneously
```

## Push

```bash
pa  # push top of B to A
pb  # push top of A to B
```

## Rotate

```bash
ra  # rotate A upwards
rb  # rotate B upwards
rr  # ra and rb simultaneously
```

## Reverse Rotate

```bash
rra # rotate A downwards
rrb # rotate B downwards
rrr # rra and rrb simultaneously
```

---

# K Sort Algorithm

## How It Works

The K Sort algorithm works in two main phases:

### Phase 1 — Push from A to B

Elements are pushed from stack A to stack B according to a decision median.

The algorithm creates a "K" formation inside stack B:

- Smaller values are rotated deeper into B
- Medium values stay near the top
- Larger values remain in A temporarily

This distribution improves retrieval efficiency later.

---

### Phase 2 — Push Back to A

Once all values are inside stack B:

1. Find the biggest value in B
2. Rotate or reverse rotate B to bring it to the top
3. Push it back to A using `pa`
4. Repeat until B is empty

At the end, stack A is fully sorted.

---

# Decision Median

The decision median is usually calculated using:

```c
const_decision_median = 1.3 * sqrt(total_numbers);
```

This value determines how aggressively elements are pushed and rotated during the sorting process.

---

# Compilation

## Clone the repository

```bash
git clone <repository_url>
cd push_swap
```

## Compile

```bash
make
```

## Other Rules

```bash
make clean
make fclean
make re
```

---

# Usage

## Run the program

```bash
./push_swap 4 67 3 87 23
```

## Example Output

```bash
pb
ra
pb
rra
pa
```

---

# Error Handling

The program outputs:

```bash
Error
```

when encountering:

- Non-numeric arguments
- Integer overflow/underflow
- Duplicate numbers
- Invalid formatting

---

# Performance Goals

Typical targets for evaluation:

| Numbers | Expected Operations |
|----------|---------------------|
| 100      | < 700               |
| 500      | < 5500              |

---

# Example

## Input

```bash
./push_swap 5 2 8 1 3
```

## Sorted Result

```bash
1 2 3 5 8
```

---

# Resources

- 42 Subject PDF
- Stack sorting algorithms
- Turk Sort
- K Sort
- Radix Sort

---
