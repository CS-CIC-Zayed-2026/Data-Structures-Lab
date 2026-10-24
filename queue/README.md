# Queue

## Overview

A queue is a linear data structure that follows the **FIFO** principle
> FIFO = First In, First Out

The first element added to the queue is the first element removed from it.
---

## Operations

| Operation | Description |
|---|---|
| `enqueue(x)` | Adds element `x` to the end or rear of the queu.
| `dequeue()` | Removes from the front of the queue.
| `front()` / `peek()` | Returns the front element without removing it.
| `isEmpty()` | Checks whether the queu is empty.

---

## Applications of Queue

### Network

- In a network, a queue is used in devices such as a router or a switch. 
- another application of a queue is a mail queue which is a directory that stores data and controls files for mail messages.

### Job Scheduling

- The computer has a task to execute a particular number of jobs that are scheduled to be executed one after another. These jobs are assigned to the processor one by one which is organized using a queue.

### Shared resources

- Queues are used as waiting lists for a single shared resource.

---

## Implementation
### Array-based

- [Circular Queue](../queue/Implementation/circular_queue.cpp)


