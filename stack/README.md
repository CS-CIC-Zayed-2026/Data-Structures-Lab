# Stack

## Overview
A Stack is a linear data structure that follows the LIFO (Last In, First Out) principle.

This means that the last element added to the stack is the first element removed.

## Operations

| Operation | Description | Time Complexity |
|---|---|---|
| `push(x)` | Adds element `x` to the top of the stack. | `O(1)` |
| `pop()` | Removes the top element. | `O(1)` |
| `top()` / `peek()` | Returns the top element without removing it. | `O(1)` |
| `isEmpty()` | Checks whether the stack is empty. | `O(1)` |

> **Note:** These complexities assume a standard stack implementation. A dynamically resizing array may occasionally require `O(n)` time for an individual `push()` operation, although its amortized time complexity is `O(1)`.

## Some Applications of Stack

###  Function Calls and Recursion

Programming languages use a **call stack** to manage function calls.

When a function is called, its execution information is stored in a stack frame. When the function returns, its frame is removed from the call stack.

**Example:**
```cpp
void first() {
    second();
}

void second() {
    third();
}

void third() {
    // Do some work
}
```
The calls are nested in this order:

1. `first()` calls `second()`.
2. `second()` calls `third()`.
3. `third()` returns first, followed by `second()`, then `first()`.

This is a natural example of LIFO behavior.

---

### Undo and Redo Operations

Text editors and drawing applications use stacks to manage actions.

**Example:**

Suppose a user performs these actions:

1. Types `Hello`.
2. Changes the text to `Hello World`.
3. Changes the text to `Hello World!`.

An undo operation reverses the most recent action first.

A common design uses:
- An undo stack to store previous actions.
- A redo stack to store actions that have been undone.

---

### Browser Back Navigation

A browser can use a stack-like history mechanism to track visited pages.

**Example:**

```text
Page A -> Page B -> Page C
```

Pressing Back moves from Page C to Page B, then from Page B to Page A.

A stack can implement this behavior, although real browsers may use more sophisticated history structures.

## When Should You Use a Stack?

**A stack is a good choice when:**

- You need **Last In, First Out** behavior.
- You need to reverse the order of elements.
- You need to track nested operations.
- You need to return to a previous state.
- You need to explore a path and backtrack.
- You need to process opening and closing symbols.
- You need to implement an iterative algorithm that would otherwise use recursion.

## Stack vs. Array

A stack and an array are not the same thing.

| Feature | Stack | Array |
|---|---|---|
| Main concept | Abstract data type (ADT) | Data storage structure |
| Access | Normally through the top element | Direct access by index |
| Insertion | At the top | At a specified index or position, depending on the operation |
| Removal | From the top | From a specified index or position, depending on the operation |
| Ordering principle | LIFO | No inherent LIFO restriction |
| Implementation | Can use an array or linked list | Uses contiguous storage in the traditional array model |

**Important:** An array can be used to implement a stack. The stack interface restricts how elements are accessed, while the underlying array provides the storage.

## Implementation
- [Array Implementation - Without OOP](implementation/array_stack_without_oop.cpp)
- [Array Implementation - Using class](implementation/array_stack.cpp)


## Problems
- [Dynamic Stack using Array](problems/dynamic_array_stack.cpp)
- [Valid Parentheses](problems/valid_parentheses.cpp)
- [Remove All Adjacent Duplicates In String](problems/remove_all_adjacent_duplicates_in_string.cpp)
- [Min Stack]()
